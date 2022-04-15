#    Copyright 2020 convexvr
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.


import camera, services, sims4.commands, os
import sims4.reload as r
import helpers.injector as injector
import ctypes
import sys
import ctypes.wintypes
from zone import Zone
import math
import helpers.threedmath as threedmath
from ReadWriteMemory import ReadWriteMemory
import pyautogui
import importlib.util
import datetime



class VPXFLOAT3(ctypes.Structure):
    _fields_ = [
        ("x", ctypes.c_float),
        ("y", ctypes.c_float),
        ("z", ctypes.c_float)
    ]

class VPXFLOAT4(ctypes.Structure):
    _fields_ = [
        ("x", ctypes.c_float),
        ("y", ctypes.c_float),
        ("z", ctypes.c_float),
        ("w", ctypes.c_float)
    ]

class VPX_CONTROLLER_STATE(ctypes.Structure):
    _fields_ = [
        ("IsActive", ctypes.c_ulong),#VPX_BOOL IsActive;				// VPX_TRUE if active, otherwise VPX_FALSE
        ("StickX", ctypes.c_float),#float StickX;					// Thumbstick/pad x-axis [-1|1]
        ("StickY", ctypes.c_float),#float StickY;					// Thumbstick/pad y-axis [-1|1]
        ("Trigger", ctypes.c_float),#float Trigger;					// Trigger axis [0|1]
        ("Grip", ctypes.c_float),#float Grip;						// Grip axis [0|1], on controllers with a grip button (e.g. Vive wands) either 0.0 or 1.0
        ("Extra0", ctypes.c_float),#float Extra0;					// Extra axis (for future use)
        ("Extra1", ctypes.c_float),#float Extra1;					// Extra axis (for future use)
        ("Extra2", ctypes.c_float),#float Extra2;					// Extra axis (for future use)
        ("Extra3", ctypes.c_float),#float Extra3;					// Extra axis (for future use)
        ("Finger0", ctypes.c_float),#float Finger0;					// Finger axis: thumb (for future use)
        ("Finger1", ctypes.c_float),#float Finger1;					// Finger axis: index (for future use)
        ("Finger2", ctypes.c_float),#float Finger2;					// Finger axis: middle (for future use)
        ("Finger3", ctypes.c_float),#float Finger3;					// Finger axis: ring (for future use)
        ("Finger4", ctypes.c_float),#float Finger4;					// Finger axis: pinky (for future use)
        ("ButtonsPressed", ctypes.c_ulong),#unsigned int ButtonsPressed;	// Check with a flag, e.g.: if (ButtonsPressed & VPX_CONTROLLER_BUTTON_0)
        ("ButtonsTouched", ctypes.c_ulong),#unsigned int ButtonsTouched;	// Check with a flag, e.g.: if (ButtonsTouched & VPX_CONTROLLER_BUTTON_0)
    ]


ModFolder = os.path.dirname(os.path.dirname(__file__))

#Function used to print debug information
def dprnt(txt):
    global ModFolder
    txt=str(txt)
    now = datetime.datetime.now()
    log_str = now.strftime("%Y-%m-%d %H:%M:%S")+": "+txt+"\n"
    file_object = open(ModFolder+"\\debug_log.txt", 'a')
    if file_object:
        file_object.write(log_str)
        file_object.close()

dprnt("module loading initiated")
pid = os.getpid()

#function we need is:
_vpxInit = 0
_vpxFree = 0
_vpxIsActive = 0
_vpxGetFloat = 0
_vpxGetFloat3 = 0
_vpxSetFloat3 = 0
_vpxGetFloat4 = 0
_vpxGetControllerState = 0
_vpxYawCorrection = 0
_vpxGetFuncAddress = 0
vpxGetHeadsetRotationEuler = 0
vpxGetHeadsetPosition = 0

vorpx_loaded = False

vpx_active = 0
headset_position = 0
headset_rotation = 0

game_desired_cam_pos = 0

known_sruct_locations = []
chosen_structs = []

origin_sims_camera_pos = 0
origin_sims_camera_rot = 0
#We know that the sims has filled in our address when it is nolonger 4545
sims_camera_address = ctypes.c_ulonglong(4545)
sims_camera_address_compare = ctypes.c_ulonglong(4646)


#code_injection_base_address is the address where we patch the exacutable to change the games behavior 
code_injection_base_address = 0x1401C25BE
code_injection_base2_address = code_injection_base_address - 46

#then we get references to the location where we will patch these are locations in the code that i found with cheat engine
first = ctypes.c_ulonglong.from_address(code_injection_base_address)
second = ctypes.c_ulonglong.from_address(code_injection_base_address+8)

headset_offset = sims4.math.Vector3(0, 0, 0)

patch_frame_counter = 0
is_patched = False
patch2_active = False
saved_second = 0
saved_first = 0
hold_b_button_frame_counter = 0
holding_grab = False
holding_trig = False
last_btns_press = 0
scale = 1#1.25

game_camera_scale = 0.905
game_camera_scalew = 0.5

#resolution 768/1024=0.75
game_camera_scale = 0.905
game_camera_scalew = 0.68

#the quest has 93 deg vertical fov
#game_camera_scale = math.atan(math.radians(93)/2)


#game_camera_scale = math.atan(math.radians(136)/2)#But for some reason 136 deg gives better result
#game_camera_scalew = game_camera_scale/(1024/768)

org_code = 4545


original_codes = [0,0,0,0,0,0,0,0]

@sims4.commands.Command('scale', command_type=(sims4.commands.CommandType.Live))
def scl(scale_str: str="", _connection=None):
    global scale
    scale = float(scale_str)
    
#Set camera scaling up and down
@sims4.commands.Command('gscale', command_type=(sims4.commands.CommandType.Live))
def gscale(scale_str: str="", _connection=None):
    global game_camera_scale
    global game_camera_scalew
    game_camera_scale = float(scale_str)
    vrdll.set_scale(game_camera_scalew, game_camera_scale)

#Set camera scaling left and right
@sims4.commands.Command('gscalew', command_type=(sims4.commands.CommandType.Live))
def gscalew(scale_str: str="", _connection=None):
    global game_camera_scalew
    global game_camera_scale
    game_camera_scalew = float(scale_str)
    vrdll.set_scale(game_camera_scalew, game_camera_scale)


#Debug: add a render struct address manually
@sims4.commands.Command('addptr', command_type=(sims4.commands.CommandType.Live))
def addptr(ptr: str="", _connection=None):
    global known_sruct_locations
    known_sruct_locations.append(int(ptr))
    tsl()


#Resets the render struct addresses
@sims4.commands.Command('rsts', command_type=(sims4.commands.CommandType.Live))
def rsts(_connection=None):
    global known_sruct_locations
    global chosen_structs
    known_sruct_locations.clear()
    vrdll.set_struct_location(4545)
    chosen_structs.clear()
 
#Gets the camera position from game memmory
def get_cam_pos():
    global chosen_structs
    for structpos in chosen_structs:
        x_pos = ctypes.c_float.from_address(structpos+96)
        y_pos = ctypes.c_float.from_address(structpos+100)
        z_pos = ctypes.c_float.from_address(structpos+104)
        
        return (sims4.math.Vector3(x_pos.value, y_pos.value, z_pos.value))
    dprnt("could not find a camera position, nr of chosen_structs = "+str(len(chosen_structs)))
    return False

#Gets the camera rotation from game memmory
def get_cam_rot():
    global chosen_structs
    for structpos in chosen_structs:
        x_sidevec = ctypes.c_float.from_address(structpos+48)
        y_sidevec = ctypes.c_float.from_address(structpos+52)
        z_sidevec = ctypes.c_float.from_address(structpos+56)
        
        x_upvec = ctypes.c_float.from_address(structpos+64)
        y_upvec = ctypes.c_float.from_address(structpos+68)
        z_upvec = ctypes.c_float.from_address(structpos+72)
        
        x_fwdvec = ctypes.c_float.from_address(structpos+80)
        y_fwdvec = ctypes.c_float.from_address(structpos+84)
        z_fwdvec = ctypes.c_float.from_address(structpos+88)
        mat = [[x_sidevec.value,y_sidevec.value,z_sidevec.value],
            [x_upvec.value,y_upvec.value,z_upvec.value],
            [x_fwdvec.value,y_fwdvec.value,z_fwdvec.value]
        ]
        return threedmath.tpy_rotmat_to_euler(mat)
    dprnt("could not find a camera rotation, nr of chosen_structs = "+str(len(chosen_structs)))
    return False

#figures out what render struct address the mod should use
@sims4.commands.Command('tsl', command_type=(sims4.commands.CommandType.Live))
def tsl(_connection=None):
    global known_sruct_locations
    global chosen_structs
    
    dprnt("Selecting chosen_structs, nr of known_sruct_locations = "+str(len(chosen_structs)))
    chosen_structs = []
    first = True
    for structpos in known_sruct_locations:
        x_pos = ctypes.c_float.from_address(structpos+96)
        y_pos = ctypes.c_float.from_address(structpos+100)
        z_pos = ctypes.c_float.from_address(structpos+104)

        if round(x_pos.value,2) == round(camera._camera_position.x,2) and round(y_pos.value,2) == round(camera._camera_position.y,2) and round(z_pos.value,2) == round(camera._camera_position.z,2):
            if first:
                chosen_structs.append(structpos)
                sims_camera_address_compare.value = structpos
                first = False
            vrdll.set_struct_location(structpos)#The last struct seams to be he one acctually controlling the camera
            dprnt("chosen struct: "+ hex(structpos)+ "pos: "+str(x_pos.value)+", "+str(y_pos.value)+", "+str(z_pos.value))

vrdll = ctypes.CDLL(ModFolder+"\\s4vrlib.dll")
vrdll.set_scale.argtypes = [ctypes.c_float, ctypes.c_float]
vrdll.set_offset.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]
vrdll.set_origin.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]
vrdll.set_added_rotation.argtypes = [ctypes.c_float]
vrdll.set_struct_location.argtypes = [ctypes.c_ulonglong]

vrdll.init()



vrdll.set_scale(game_camera_scalew, game_camera_scale)


using_dll = True
if using_dll:
    address_to_update_function = ctypes.c_ulonglong.from_address(ctypes.addressof(vrdll.update)).value

#Creates a callable function in memory
#Fix the broken VirtualAllocEx before we use it
def create_x86_x64_function(sc):
    rwm = ReadWriteMemory()
    process = rwm.get_process_by_id(pid)
    process.get_all_access_handle()
    ctypes.windll.kernel32.VirtualAllocEx.restype = ctypes.c_ulonglong
    memadr = ctypes.windll.kernel32.VirtualAllocEx(process.handle,0, len(sc), 0x3000, 0x40)
    process.writeByte(memadr, sc)
    process.close()
    return memadr

#Patches the game so that the dll gets called on every rendred frame
def call_patch():

    rwm = ReadWriteMemory()
    process = rwm.get_process_by_id(pid)
    process.get_all_access_handle()
    org_instructions = process.readByte(code_injection_base2_address, 15)#save original code
    #process.close()
    
    #Code that can be jumped to that then jumps back after calling a function
    
    #Save all registers except rbp & rsp before function call
    jump_to_code = b'\x50\x53\x51\x52\x56\x57\x41\x50\x41\x51\x41\x52\x41\x53\x41\x54\x41\x55\x41\x56\x41\x57'
    
    #Add sims specific code
    
    #save the camera position struct pointer
    adr = ctypes.addressof(sims_camera_address)
    cmpadr = ctypes.addressof(sims_camera_address_compare)
    jump_to_code += b'\x49\xb9'
    jump_to_code += adr.to_bytes(8,'little')
    jump_to_code += b'\x49\x89\x11\x90\x90\x90'
    
    #At this point we can compare that address with sims_camera_address_compare
    jump_to_code += b'\x49\xb9'+cmpadr.to_bytes(8,'little')#add cmpadr to r9
    jump_to_code += b'\x49\x39\x11'#cmp rdx, r9
    jump_to_code += b'\x75\x1d'#jne 29 pos forward
    
    #function call
    #COmment out to test if the injeciton works
    jump_to_code += b'\x55\x48\x89\xe5\x48\x83\xEc\x20'#setup for function call "push rbp; mov rbp,rsp; sub rsp,20"
    jump_to_code += b'\xFF\x15\x02\x00\x00\x00\xEB\x08'
    jump_to_code += address_to_update_function.to_bytes(8,'little')
    jump_to_code += b'\x48\x83\xc4\x20\x5d'#clean after function call "add rsp,20;pop rbp"
    
    #restore registers and run the instructions replaced by the injection_code
    jump_to_code += b'\x41\x5f\x41\x5e\x41\x5d\x41\x5c\x41\x5b\x41\x5a\x41\x59\x41\x58\x5f\x5e\x5A\x59\x5b\x58'#pop registers from stack

    jump_to_code += org_instructions
    #jump back
    jump_to_code += b'\xFF\x25\x00\x00\x00\x00'
    jump_to_code += (code_injection_base2_address+14).to_bytes(8,'little')
    
    jump_to = create_x86_x64_function(jump_to_code)
    
    injection_code = b'\xFF\x25\x00\x00\x00\x00'
    injection_code += jump_to.to_bytes(8,'little')
    injection_code += b'\x90'#We add noop after as it is important for the instructions to tatch length
    
    
    dprnt("jmp "+hex(jump_to))
    
    
    process.writeByte(code_injection_base2_address, injection_code)#Write new code
    
    process.close()

if using_dll:
    call_patch()


#Patches the game so that we are informed about where the render struct addresses are located in memmory
@sims4.commands.Command('patch', command_type=(sims4.commands.CommandType.Live))
def patch(_connection=None):
    global sims_camera_address
    global is_patched
    global org_code
    global patch_frame_counter
    global code_injection_base_address
    global saved_first
    global first
    global known_sruct_locations
    global second
    global saved_second
    global pid
    #output = sims4.commands.CheatOutput(_connection) #call 1400F34B0
    
    
    #This is where we will tell the simms to store the pointer to its camera position struct
    adr = ctypes.addressof(sims_camera_address)
    if is_patched == False:
        #first we generate the x86 code that will save the camera position struct pointer
        sc = b'\x49\xb9'
        sc += adr.to_bytes(8,'little')
        sc += b'\x49\x89\x11\x90\x90\x90'
        
        
        
        
        #when we separate it in to two parts cause i dont know how to write it as one chunk
        first_sc = int.from_bytes(sc[0:8],'big')
        second_sc = int.from_bytes(sc[8:16],'big')
        saved_first = first.value
        saved_second = second.value
        #then we check that everything is OK
        if 0x404A100F3041110F != saved_first or 0x5042100F4049110F != saved_second:
            dprnt("the TS4_x64.exe might have been updated it does not match how the exe usally looks ")
            return 0
         
        #Patching done here
        rwm = ReadWriteMemory()
        process = rwm.get_process_by_id(pid)
        process.get_all_access_handle()
        org_code = process.readByte(code_injection_base_address, 16)#save and verify original code
        
        process.writeByte(code_injection_base_address, sc)#Write new code
        
        process.close()
        
        patch_frame_counter = 0
        is_patched = True

#removes the patch that informs us about where the render struct addresses are located in memmory
@sims4.commands.Command('unpatch', command_type=(sims4.commands.CommandType.Live))
def unpatch(_connection=None):
    global is_patched
    global code_injection_base_address
    global pid
    global org_code
    
    #I asume we are done lets reset patch 1
    if is_patched:
        rwm = ReadWriteMemory()
        process = rwm.get_process_by_id(pid)
        process.get_all_access_handle()
        process.writeByte(code_injection_base_address, org_code)#Write new code
        process.close()
        is_patched = False


#For some reason the scaling is overwriten by some operations, so we patch those ops away
@sims4.commands.Command('patch2', command_type=(sims4.commands.CommandType.Live))
def patch2_togle(_connection=None):
    global sims_camera_address
    global original_codes
    global patch2_active
    #output = sims4.commands.CheatOutput(_connection)
    #write 4 bytes of NOP ie byte 0x90 to these locations 
    
    
    #When you patch the scale the mouse ponter no longer points to it "correct" position
    patchlocations = [
        0x140FC1B48, #scaling upp and down
        0x140FC1B35 #scaling left and right

    ]
    patches = [
        b'\x90\x90\x90\x90\x90\x90\x90',
        b'\x90\x90\x90\x90'
    ]
    
    
    
    
    rwm = ReadWriteMemory()
    process = rwm.get_process_by_id(pid)
    process.get_all_access_handle()
    
    if not patch2_active:
        for x, patchlocation in enumerate(patchlocations):
            original_codes[x] = process.readByte(patchlocation, len(patches[x]))
        
        for x, patchlocation in enumerate(patchlocations):
            process.writeByte(patchlocation, patches[x])#Write NOP's
        
        patch2_active = True
    else:
        for x, patchlocation in enumerate(patchlocations):
            process.writeByte(patchlocation, original_codes[x])
        patch2_active = False
        
    process.close()


#sets up python connection to vorpx.
def initate_vorpx():
    global vorpx_loaded
    global _vpxInit
    global _vpxFree
    global _vpxIsActive
    global _vpxGetFloat
    global _vpxGetFloat3
    global _vpxSetFloat3
    global _vpxSetInt
    global _vpxGetFloat4
    global _vpxGetControllerState
    global _vpxYawCorrection
    global _vpxGetFuncAddress
    global vpxGetHeadsetRotationEuler
    global vpxGetHeadsetPosition
    global vpx_active
    global pid
    
    map_file = "Local\\vpxapi_gpa"+str(pid)
    
    
    try:
        fn = ctypes.c_char_p(map_file.encode('utf-8'))
        FILE_MAP_READ = ctypes.wintypes.DWORD(4)
        hmf = ctypes.windll.kernel32.OpenFileMappingA(FILE_MAP_READ, ctypes.wintypes.BOOL(False), fn)
         
        if hmf:
            pmf = ctypes.windll.kernel32.MapViewOfFile(hmf, FILE_MAP_READ, 0, 0, 8)
            if pmf:
                pmf_val = ctypes.c_ulonglong.from_address(pmf).value

                #create _vpxGetFuncAddress function
                adr_functype = ctypes.CFUNCTYPE(ctypes.c_ulonglong, ctypes.c_ulong, ctypes.c_char_p)
                _vpxGetFuncAddress = adr_functype(pmf_val)
                
                #create _vpxInit function
                init_free_functype = ctypes.CFUNCTYPE(ctypes.c_ulong)
                _vpxInit_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiInit".encode('utf-8')))
                _vpxInit = init_free_functype(_vpxInit_adr)
                
                #run vpx init
                vpx_active = _vpxInit()#Craches if headset is connected but works otherwise returns a 0 which means OK
                
                #create _vpxFree function # we never use this since we dont track when the game has turned of
                _vpxFree_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiFree".encode('utf-8')))
                _vpxFree = init_free_functype(_vpxFree_adr)
                
                #create _vpxIsActive function # 
                _vpxIsActive_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiIsActive".encode('utf-8')))
                _vpxIsActive = init_free_functype(_vpxIsActive_adr)
                
                
                
                #create _vpxGetFloat3 function 
                float_functype = ctypes.CFUNCTYPE(ctypes.c_float, ctypes.c_ulong)# takes a uint returns a pointer to a struct with a float
                _vpxGetFloat_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiGetFloat".encode('utf-8')))
                _vpxGetFloat = float_functype(_vpxGetFloat_adr)
                
                #create _vpxGetFloat3 function 
                float3_functype = ctypes.CFUNCTYPE(VPXFLOAT3, ctypes.c_ulong)# takes a uint returns a pointer to a struct with 3 floats
                _vpxGetFloat3_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiGetFloat3".encode('utf-8')))
                _vpxGetFloat3 = float3_functype(_vpxGetFloat3_adr)
                
                #create _vpxGetFloat4 function 
                float4_functype = ctypes.CFUNCTYPE(VPXFLOAT4, ctypes.c_ulong)# takes a uint returns a pointer to a struct with 4 floats
                _vpxGetFloat4_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiGetFloat4".encode('utf-8')))
                _vpxGetFloat4 = float4_functype(_vpxGetFloat4_adr)
                
                #create _vpxYawCorrection function 
                vpxYawCorrection_functype = ctypes.CFUNCTYPE(VPXFLOAT3, VPXFLOAT3, ctypes.c_float)
                _vpxYawCorrection_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiYawCorrection".encode('utf-8')))
                _vpxYawCorrection = vpxYawCorrection_functype(_vpxYawCorrection_adr)
                
                #create _vpxSetFloat3 function 
                vpxSetFloat3_functype = ctypes.CFUNCTYPE(None, ctypes.c_ulong, VPXFLOAT3)
                _vpxSetFloat3_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiSetFloat3".encode('utf-8')))
                _vpxSetFloat3 = vpxSetFloat3_functype(_vpxSetFloat3_adr)
                
                #create _vpxSetInt function 
                vpxSetInt_functype = ctypes.CFUNCTYPE(ctypes.c_ulong, ctypes.c_ulong)
                _vpxSetInt_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiSetInt".encode('utf-8')))
                _vpxSetInt = vpxSetInt_functype(_vpxSetInt_adr)
                
                
                
                #create _vpxGetControllerState function 
                vpxGetControllerState_functype = ctypes.CFUNCTYPE(VPX_CONTROLLER_STATE, ctypes.c_ulong)
                _vpxGetControllerState_adr = _vpxGetFuncAddress(ctypes.c_ulong(pid), ctypes.c_char_p("VorpApiGetControllerState".encode('utf-8')))
                _vpxGetControllerState = vpxGetControllerState_functype(_vpxGetControllerState_adr)
                
                vorpx_loaded = True
                #func
                ctypes.windll.kernel32.UnmapViewOfFile(pmf)
                
                #call to make vorpx disable its own default stuff
                #_vpxGetFloat(100)#get headset fov
                _vpxGetFloat3(103)
                
                #enable edge peek
                _vpxSetInt(400, 1)
                
                _vpxSetInt(206, 1)#Force Controller rendering
            
            else:
                print("failed to open pmf: "+str(pfm))
            ctypes.windll.kernel32.CloseHandle(hmf)
        else:
            print("failed to open hmf: "+str(hmf))
    except Exception as e:
        print("Exception: "+ str(e))

initate_vorpx()

vr_active = False
vr_pos = 1

target_compensation = 2.8
extra_rotate = 0
origin_rotate = 0
controller_state = 0
cam_syncing = False
before_sync_cam_location = 0
keypress_bebounce_count = 0
headset_position_corected = 0
headset_position_uncorected = 0

last_second = "0"
ticks_p_s = 0

#not acctually renderd on every gfx frame (the function is named like this cause of old legacy)
def on_gfx_frame():
    global headset_position_uncorected
    global headset_position
    global headset_rotation
    
    global last_second
    global ticks_p_s
    
    global game_desired_cam_pos
    global extra_rotate
    global origin_rotate
    global headset_offset
    global origin_sims_camera_pos
    
    
    second = datetime.datetime.now().strftime("%S")
    if second != last_second:
        dprnt("fps: "+str(ticks_p_s))
        ticks_p_s = 0
        last_second = second
    
    ticks_p_s += 1
    
    
    if vorpx_loaded:
        try:
            #fov = _vpxGetFloat(100)#always 96.01604461669922 on quest2
            last_headset_rotation = headset_rotation
            headset_position_struct = _vpxGetFloat3(103)
            headset_rotation = _vpxGetFloat3(101)
            headset_quat = _vpxGetFloat4(102)
            
        except Exception as e:
            dprnt("failed using _vpxGetControllerState: "+str(e))
    
    
    if vr_active:
        
        #We should read in game_desired_cam_pos here it is avalible in memmory at this point 2022-01
        
        #save for use when reseting position
        headset_position_uncorected = sims4.math.Vector3(headset_position_struct.x, headset_position_struct.y, headset_position_struct.z)
        
        headset_position_struct.x -= headset_offset.x
        headset_position_struct.y -= headset_offset.y
        headset_position_struct.z -= headset_offset.z
        
        headset_position = _vpxYawCorrection(headset_position_struct, float(origin_rotate+extra_rotate))
        
#Togles "sims4 First person camera mode"
def togle_fps_mode():
    pyautogui.keyDown('shift')
    pyautogui.press('tab')
    pyautogui.keyUp('shift')

#Trys to figure out if we are in "sims4 First person camera mode"
def is_in_fps_mode():

    actual_cam_pos = get_cam_pos()
    if round(actual_cam_pos.x,2) == round(camera._camera_position.x,2) and round(actual_cam_pos.y,2) == round(camera._camera_position.y,2) and round(actual_cam_pos.z,2) == round(camera._camera_position.z,2):
        return False
    return True 


tab_active = False
#When the game informs us that it has executed a game frame
def on_game_frame():
    global patch_frame_counter
    global keypress_bebounce_count
    global cam_syncing
    global vr_active
    global tab_active
    global game_desired_cam_pos
    global game_camera_scalew
    global game_camera_scale
    global hold_b_button_frame_counter
    global last_btns_press
    global holding_grab
    global holding_trig
    global before_sync_cam_location
    global origin_sims_camera_pos
    global origin_sims_camera_pos
    global headset_offset
    global extra_rotate
    global origin_rotate
    global controller_state
    
    global sims_camera_address
    global known_sruct_locations
    
    #Handle input from the debug TCP connection
    handle_dbg_com()
    
    patch_frame_counter += 1
    keypress_bebounce_count += 1
    
    vr_tog = False
    
    if cam_syncing:
        after_sync_cam_location = get_cam_pos()
        if before_sync_cam_location.x != after_sync_cam_location.x or before_sync_cam_location.y != after_sync_cam_location.y:
            vr_act()
            cam_syncing = False
    
    #We wait for 300 frames untill we evaluate the data, unpatch, and apply patch2
    if patch_frame_counter == 20 and is_patched:
        unpatch()
        tsl()
        vr_tog = True
    
    if sims_camera_address.value != 4545:
        if sims_camera_address.value not in known_sruct_locations:
            dprnt("Added new known_sruct_locations: "+str(sims_camera_address.value))
            known_sruct_locations.append(sims_camera_address.value)
    
    if vorpx_loaded:
        controller_state = _vpxGetControllerState(1)#get right controler state
        
        controler_rotation = _vpxGetFloat3(203)
        #controler_pos = _vpxGetFloat3(205)##if we want to create shoot to location
        
        if controller_state.ButtonsPressed != 0:
            hold_b_button_frame_counter += 1
            if hold_b_button_frame_counter == 20:
                dprnt("button hold down for long: "+str(last_btns_press))
                #if last_btns_press == 2:#B was pressed long, 
                #    pyautogui.press('somebutton')
                
                if last_btns_press == 1:#A was pressed long, tell sims4 to toogle GUI (press tab)
                    pyautogui.press('tab')
        else:
            if last_btns_press != controller_state.ButtonsPressed:
                if hold_b_button_frame_counter < 20:
                    dprnt("button was clicked quickly: "+str(last_btns_press))
                    #if last_btns_press == 1:#A was pressed short, click mouse
                    #    pyautogui.click()
                    if last_btns_press == 1:#A was pressed long, reset position
                        cam_syncing = True
                        before_sync_cam_location = get_cam_pos()
                        vr_act()#disable vr and locate real cam
                    
                    if last_btns_press == 2:#B was pressed short, initate vr (should also  press tab+shit to enter fps mode)
                        dprnt("#B was pressed short, start vr")
                        vr_tog = True
        
        if vr_tog:
            if len(chosen_structs) > 0:
                if vr_active:
                    if is_in_fps_mode():
                        togle_fps_mode()
                    vr_act()
                else:
                    if not is_in_fps_mode():
                        cam_syncing = True
                        before_sync_cam_location = get_cam_pos()
                        #vr_act()
                        togle_fps_mode()
                    else:
                        vr_act()
            else:
                patch()
        
        old_holding_trig = holding_trig
        if controller_state.Trigger == 0:
            holding_trig = False
        else:
            holding_trig = True
        
        if holding_trig != old_holding_trig:
            if holding_trig:
                pyautogui.click()#press mouse on trigger
        
        old_holding_grab = holding_grab
        if controller_state.Grip == 0:
            holding_grab = False
        else:
            holding_grab = True
        
        if holding_grab != old_holding_grab and vr_active:
            if holding_grab:
                _vpxSetInt(400, 1)#Enable Edge peek
            else:
                _vpxSetInt(400, 0)#Disable Edge peek
        
        if last_btns_press != controller_state.ButtonsPressed:
            hold_b_button_frame_counter = 0
            last_btns_press = controller_state.ButtonsPressed
            dprnt("button change: "+str(last_btns_press))
        
        #When holding grap we move the cursor
        mouse_speed = 20
        if holding_grab:
            pyautogui.moveRel(controller_state.StickX*mouse_speed, -controller_state.StickY*mouse_speed)
        else:
            #should move in the 3D direction of the controller but we will start with just camera direction first on the plane
            if controller_state.StickY != 0.0:
                cos_len = math.cos(math.radians(controler_rotation.x))
                origin_sims_camera_pos.x += math.sin(math.radians(controler_rotation.y+origin_rotate))*cos_len*0.05*controller_state.StickY
                origin_sims_camera_pos.z += -math.cos(math.radians(controler_rotation.y+origin_rotate))*cos_len*0.05*controller_state.StickY
                origin_sims_camera_pos.y -= math.sin(math.radians(controler_rotation.x))*0.05*controller_state.StickY
                dprnt("controler rot: x: "+str(controler_rotation.x)+" y: "+str(controler_rotation.y))
                vrdll.set_origin(origin_sims_camera_pos.x, origin_sims_camera_pos.y, origin_sims_camera_pos.z)
            
            if controller_state.StickX > 0.5 or controller_state.StickX < -0.5:
                
                #To rotate we need to create a new reference frame
                if headset_rotation == 0:
                    rot = 0
                else:
                    rot = headset_rotation.y
                origin_sims_camera_rot = get_cam_rot()
                origin_rotate = origin_rotate+controller_state.StickX
                vrdll.set_added_rotation(float(origin_rotate))
                new_cam_pos = sims4.math.Vector3(origin_sims_camera_pos.x, origin_sims_camera_pos.y, origin_sims_camera_pos.z)
                new_cam_pos.x += (headset_position.x)*scale#*math.sin(math.radians(extra_rotate))
                new_cam_pos.y += (headset_position.y)*scale#up/down
                new_cam_pos.z -= (headset_position.z)*scale
                origin_sims_camera_pos = new_cam_pos
                vrdll.set_origin(origin_sims_camera_pos.x, origin_sims_camera_pos.y, origin_sims_camera_pos.z)
                if headset_position_uncorected != 0:
                    headset_offset.x = headset_position_uncorected.x
                    headset_offset.y = headset_position_uncorected.y
                    headset_offset.z = headset_position_uncorected.z
                    vrdll.set_offset(headset_offset.x, headset_offset.y, headset_offset.z)


@injector.inject_to(Zone, 'update')
def vr_zone_update(original, self, absolute_ticks):
    global vr_active
    global vr_pos
    global vorpx_loaded
    global extra_rotate
    global keypress_bebounce_count
    global patch_frame_counter
    global is_patched
    global scale
    global game_camera_scale
    global game_camera_scalew
    global headset_position_uncorected
    global headset_position_corected
    global cam_syncing
    global headset_offset
    global controller_state
    global hold_b_button_frame_counter
    global last_btns_press
    global before_sync_cam_location
    global headset_position
    global headset_rotation
    global target_compensation
    global known_sruct_locations
    global sims_camera_address
    original(self, absolute_ticks)
    on_game_frame()
    
    on_gfx_frame()
    
    

#Initiates VR
@sims4.commands.Command('vra', command_type=(sims4.commands.CommandType.Live))
def vr_act(load_fresh=True,_connection=None):
    global vr_active
    global headset_position
    global headset_rotation
    global scale
    global headset_offset
    global origin_sims_camera_pos
    global origin_sims_camera_rot
    global extra_rotate
    global origin_rotate
    if vr_active:
        _vpxSetInt(400, 1)#Enable Edge peek
        new_cam_pos = sims4.math.Vector3(origin_sims_camera_pos.x, origin_sims_camera_pos.y, origin_sims_camera_pos.z)
        new_cam_pos.x += (headset_position.x)*scale
        new_cam_pos.y += (headset_position.y)*scale#up/down
        new_cam_pos.z -= (headset_position.z)*scale
        origin_sims_camera_pos = new_cam_pos
        vrdll.set_origin(origin_sims_camera_pos.x, origin_sims_camera_pos.y, origin_sims_camera_pos.z)
        vr_active = False
        vrdll.set_vr_active(0)
        target = sims4.math.Vector3(origin_sims_camera_pos.x+math.sin(math.radians(headset_rotation.y+origin_rotate)), origin_sims_camera_pos.y, origin_sims_camera_pos.z-math.cos(math.radians(headset_rotation.y+origin_rotate)))
        camera.focus_on_object_from_position(target, origin_sims_camera_pos)
        camera._camera_position = origin_sims_camera_pos
    else:
        _vpxSetInt(400, 0)#Disable Edge peek
        vr_active = True
        vrdll.set_vr_active(1)
        orgiginal_target = camera._target_position
        if headset_rotation == 0:
            rot = 0
        else:
            rot = headset_rotation.y
        origin_sims_camera_rot = get_cam_rot()
        
        origin_rotate = origin_sims_camera_rot.y-rot
        vrdll.set_added_rotation(float(origin_rotate))
        extra_rotate = 0

        origin_sims_camera_pos = get_cam_pos()#sims4.math.Vector3(camera._camera_position.x, camera._camera_position.y, camera._camera_position.z)
        vrdll.set_origin(origin_sims_camera_pos.x, origin_sims_camera_pos.y, origin_sims_camera_pos.z)

        if headset_position_uncorected != 0:
            headset_offset.x = headset_position_uncorected.x
            headset_offset.y = headset_position_uncorected.y
            headset_offset.z = headset_position_uncorected.z
            vrdll.set_offset(headset_offset.x, headset_offset.y, headset_offset.z)
    patch2_togle()

#Debug command to allow executing simple python commands from inside the game
@sims4.commands.Command('py', command_type=sims4.commands.CommandType.Live)
def _py(cmd: str="", cmda: str="", cmdb: str="", cmdc: str="", _connection=None):
    output = sims4.commands.CheatOutput(_connection)
    cmd = cmd +" "+ cmda +" "+ cmdb +" "+ cmdc 
    output("py eval: "+cmd)
    try:
        ret = str(eval(cmd))
        output(ret)
    except Exception as e:
        output("Exception: "+ str(e))


#Initiate Debug TCP connection
if True:
    import socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    connected = False

    try:
        s.connect(('127.0.0.1', 5000))
        s.setblocking(False)
        s.send(b'python shell:')
        connected = True
    except Exception as e:
        dprnt("Failed to connect to debug connection: "+str(e))


#Handle data from Debug TCP connection
def handle_dbg_com():
    global s
    global connected
    
    if connected:
        try:
            cmd = s.recv(2500).decode("utf-8") 
            try:
                ret = str(eval(cmd))
                s.send(bytes(ret, "utf-8"))
            except Exception as e:
                s.send(bytes("Exception: "+ str(e)))
        except Exception as e:
            1#no data from debug conection

dprnt("Loaded VR Mod")

