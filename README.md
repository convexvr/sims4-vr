# sims4-vr
Sims 4 plugin that adds VR functionality to sims 4.

Built for oculus quest 2 but should work with other steamvr compatible headsets to.

The plugin works like a bridge betwen sims 4 and VorpX by using the VorpX API. You need to have VorpX for the plugin to work.
The plugin only works on the 64bit windows version of sims 4.

sims4-vr plugin adds full headset tracking and motion controller support to sims 4.


## Install
https://github.com/convexvr/sims4-vr/raw/main/convexvr_sims4-vr-bundle.zip

Unzip the **convexvr_sims4-vr-bundle.zip** zip file and place the **convexvr_sims4-vr** folder in the mods folder  **C:\Users\\$USER\Documents\Electronic Arts\The Sims 4\Mods**

## Sims4 settings and VorpX settings
### Vorpx settings
```
Full VR Mode
3D-Strength/Scale: 0.14
3D-FOV Enhancment: 0
Camera Height Modifier: 0
Edge Peak Strength Modifier 0.31
Game hud scale: 1
Game hudscale  horizontal 0.75
Game hud depth: 0.5
Aspect ratio: 1:1
Image zoom: 1.073
Right controller triger button mapped to: left click
```
### Sims 4 settings:
```
Resolution:  1024x768
Display type: Fullscreen
Refresh rate: 75
```

## Usage
1. Start VorpX
2. Start Sims4 
3. When you are in sims4 configure the sims4 (sims4 settings menu) and the vorpX settings(press delete on keyboard to open VorpX settings).
4. When playing press the B-button on your oculus controller once quickly to initate VR mode

## Controls
### Right hand oculus controller

```
Oculus B-button quick press: Toggle VR mode
Oculus a-button quick press: Reset camera position to active sim
Oculus A-button long press: Toggle HUD

Oculus Trigger button: mouse press
Oculus Grab button: Enable Screen Mode (VorpX Edge peek)
```
#### When screen mode is active 
```
Oculus joystick: Moves the mouse pointer
```
#### When VR mode is active
```
Oculus joystick: Moves the camera
```

## Stuff that needs improvment
```
Move camera and mouse by pointing and shooting with controller.
Need to record a small video to show how it looks.
Need to imporve memmory patching of the binary so that the active sim can be tracked in realtime.
Increase framerate somehow.
Make the scaling and tracking better somehow.
```
