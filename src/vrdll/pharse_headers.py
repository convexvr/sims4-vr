import re

if False:
    prepro1 = open('Preprocessed_dllmain.cpp')

    is_struct_line = re.compile(r"^typedef\s+struct")

    is_linenr_line = re.compile(r"^#line ")
 

    clenaed1 = open('Preprocessed_dllmain1.cpp', 'w')
    PLines = prepro1.readlines()

    for line in PLines:
        striped_line = line.strip()
        if striped_line != "":
            if not is_linenr_line.match(striped_line):
                clenaed1.write(striped_line+"\n")
        

    clenaed1.close()
    exit(0)

#clang-format -style=WebKit -i Preprocessed_dllmain1.cpp

cpp_structs = {}
if True:
    is_struct_line = re.compile(r"^typedef\s+struct\s(.*)\s{")
    is_struct_line_end = re.compile(r"\s*}\s+(.*);")
    member = re.compile(r"(\S+)\s+(.+);")

    prepro = open('Preprocessed_dllmain1.cpp')
    PLines = prepro.readlines()
    PrintStruct = False
    PrintStructFail = False
    Members = []
    for line in PLines:
        striped_line = line.strip()
        match = is_struct_line.match(striped_line)
        if PrintStruct:
            mtch2 = is_struct_line_end.match(striped_line)
            if mtch2:
                #print(striped_line)
                struct_name = mtch2.groups()[0]
                if not PrintStructFail:
                    #print(f"Struct: {struct_name}")
                    cpp_structs[struct_name] = Members
                    #print(Members)
                #else:
                    #print(f"Failed on Struct: {struct_name}")
                PrintStruct = False
                PrintStructFail = False
                Members = []
            else:
                #print(striped_line)
                vals = member.match(striped_line)
                if vals:
                    tp = vals.groups()[0]
                    nm = vals.groups()[1]
                    names = nm.split(',')
                    for name in names:
                        if "[" not in name:
                            Members.append([tp,name.strip()])
                #else:
                    #PrintStructFail = True
        elif match:#"typedef" in striped_line and "struct" in striped_line:
            struct_name_ = match.groups()[0]
            PrintStruct = True
            #print(f"Struct_: {struct_name_}")

    #exit(0)

    #print(cpp_structs['D3DMATRIX'])

#exit(0);
file1 = open('d3d9_headers.txt', 'r')
Lines = file1.readlines()

# writing to file
defs = open('d3d9_defs.h', 'w')

injects = open('d3d9_injects.h', 'w')

def wr(ln, fileh):
    fileh.write(ln+"\n")
    print(ln)

Ignore = ["SetVertexShaderConstantF","SetPixelShaderConstantF","SetVertexShader", "EndScene"]
Hook = ["#no_SetVertexShaderConstantF","#no_SetPixelShaderConstantF","#no_SetVertexShader", "BeginScene", "EndScene", "Present", "CreateTexture","SetViewport", "GetTransform"]

count = 0
# Strips the newline character
nr = 0
for line in Lines:
    l=line.strip()
    pts = l.split(')(')
    name = pts[0].split('(')[1].strip()
    ret = name.split(',')
    retrn_v = 'HRESULT'
    if(len(ret) > 1):
        retrn_v = ret[0]
        name = ret[len(ret)-1].strip()
    args = pts[1]
    args = args.replace("THIS_", "IDirect3DDevice9* pDevice,").replace(" PURE","")
    args = args.replace("THIS", "IDirect3DDevice9* pDevice")
    args = args.split(')')[0]
    args_list = args.split(',')
    arg_names = []
    arg_types = []
    argnum = 0
    new_args = []
    print_str = []
    print_arg_str = []
    for arg in args_list:
        arg = arg.replace(" *", "* ")
        prts = arg.strip().split(" ")
        
        if "*" in prts[len(prts)-1]:
            prts.append("arg"+str(argnum))
        
        if(len(prts) == 1):
            prts.append("arg"+str(argnum))
            
            
        arg_names.append(prts.pop())
        
        arg_types.append(' '.join(prts))
        
        new_args.append(arg_types[len(arg_types)-1]+" "+arg_names[len(arg_names)-1])
        
        
        
        argnum += 1
    
    prnt_desc_str = ""
    prnt_arg_str = ""
    for idx, arg_type in enumerate(arg_types):
        arg_type_clean = arg_type.strip("*").replace("const ", "").replace("CONST ", "")
        arg_name = arg_names[idx]
        #print (arg_type_clean)
        print_str.append(f'{arg_name}: %u')
        print_arg_str.append(arg_name)
        if arg_type_clean in cpp_structs:
            print(f"arg: {arg_name} type: {arg_type_clean} is known struct")
            for prop in cpp_structs[arg_type_clean]:
                prop_name = prop[1]
                prop_type = prop[0]
                type_conv = "%u"
                arg_type_2_clean = prop_type.strip("*").replace("const ", "").replace("CONST ", "")
                if arg_type_2_clean.lower() == "float":
                    type_conv = "%f"
                if arg_type_2_clean not in cpp_structs:#We dont print secondary structs
                    print_str.append(f'{arg_name}->{prop_name}: {type_conv}')
                    print_arg_str.append(f'({arg_name} == NULL)?0:({arg_name}->{prop_name})')

    arg_names_str = ', '.join(arg_names)
    arg_types_str = ', '.join(arg_types)
    new_args_str = ', '.join(new_args)
    
    print_str = ', '.join(print_str)
    print_arg_str = ', '.join(print_arg_str)
      
    full_name = "IDirect3DDevice9_"+name
    if name not in Ignore:
        wr(f"typedef {retrn_v}(APIENTRY* {full_name})({arg_types_str});", defs)
        wr(f"{full_name} {full_name}_orig = 0;", defs)
        wr(f"{retrn_v} APIENTRY {full_name}_hook({new_args_str})"+'{', defs)
        #wr(f"   vireio::debugf(\"{full_name}\");",defs);
        wr(f"   vireio::debugf(\"{full_name}: {print_str}\", {print_arg_str});",defs);
        wr(f"   return {full_name}_orig({arg_names_str});",defs);
        wr("}",defs);
    
    if name in Hook:
        wr(f"if (MH_CreateHook((DWORD_PTR*)dVtable[{nr}], &{full_name}_hook, reinterpret_cast<void**>(&{full_name}_orig)) != MH_OK)"+"{"+f"vireio::debugf(\"failed to hook {full_name}\");"+"}", injects)
    nr += 1

defs.close()
injects.close()