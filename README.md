# sims4-vr
Sims 4 plugin that adds VR functionality to sims 4.
### It allows you to walk around in sims 4 and do all the things that your sims do in person.

Built for oculus quest 2 but should work with other steamvr compatible headsets to.

The plugin only works on the 64bit windows version of sims 4.
More technical break down here: https://github.com/convexvr/sims4-vr/blob/main/src/README.md

sims4-vr plugin adds full headset tracking and motion controller support to sims 4.



## Install
https://github.com/convexvr/sims4-vr/releases/download/release/convexvr_sims4-vr-bundle.zip

Unzip the **convexvr_sims4-vr-bundle.zip** zip file and place the **convexvr_sims4-vr** folder in the mods folder  **C:\Users\\$USER\Documents\Electronic Arts\The Sims 4\Mods**

Install the Microsoft Visual C++ Redistributable
https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170#visual-studio-2015-2017-2019-and-2022



### Sims 4 settings(The refresh rate is important, set as high as posible!):
```
Resolution:  as close to you headset as you can
Display type: Fullscreen
Refresh rate: As high as you can
```

It is posible to force resolutions by editing C:\Users\ $USER \Documents\Electronic Arts\The Sims 4\Options.ini to get a higher refresh rate and higher resolution.
Alter the variables "resolutionheight", "resolutionwidth" and "resolutionrefresh" to desired values. Then right click the file in the file browser open file properties and set the file to "read only".
Twice the refresh rate of your headset is optimal.(To get one picture per eye to your headset)

*The optimal resolution is the resolution for each eye of your headset 1,832 x 1920 on Quest 2.

## Usage
1. Install mod and enable custom contents and script mods in sims 4 settings menu.
2. Connect VR headset to PC.
3. Start Sims4 
4. When playing press the B-button on your oculus controller once quickly to initate VR mode

If there is errors look at the log file:
C:\Users\\$USER\Documents\Electronic Arts\The Sims 4\Mods\convexvr_sims4-vr\debug_log.txt

## Controls
### Right hand oculus controller

```
Oculus B-button quick press: Toggle VR mode
Oculus a-button quick press: Lock or unlock camera position to active sim.
Oculus A-button long press: Toggle HUD

Oculus Trigger button: mouse press
```

## Stuff that needs improvment(Please help)
```
Move camera and mouse by pointing and shooting with controller.
Need to record a small video to show the mod.
Fix stereo view, currently each frame is renderd one after the other. This causes defects in the render due to movments in the time between right and left frame render.

Fix controls. Version 2 of the mod that is VorpX Free, has bad controls.
```


## Files 


#### sims4-vr/src/vrdll/
Contains the dll that manages the openvr api calls and moves the cammera

sims4-vr/src/vrdll/vrdll.sln
Is the visual studio 2022 solution file for the dll.
Building requires directx9 sdk, called: "Microsoft DirectX SDK (June 2010)"

#### sims4-vr/src/sims4-vr/src/
The sims4 python plugin that loads the dll and does sims4 stuff. 

run sims4-vr/src/sims4-vr/compile.py to compile the mod, requires python 3.7.9 (same version of python as sism4 uses)


