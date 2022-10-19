# sims4-vr
Sims 4 plugin that adds VR functionality to sims 4.
### It allows you to walk around in sims 4 and do all the things that your sims do in person.

Built for oculus quest 2 but should work with other steamvr compatible headsets to.

The plugin works like a bridge betwen sims 4 and VorpX by using the VorpX API. You need to have VorpX for the plugin to work.
The plugin only works on the 64bit windows version of sims 4.
More technical break down here: https://github.com/convexvr/sims4-vr/blob/main/src/README.md

sims4-vr plugin adds full headset tracking and motion controller support to sims 4.



## Install
https://github.com/convexvr/sims4-vr/releases/download/v1.01/convexvr_sims4-vr-bundle.zip

Unzip the **convexvr_sims4-vr-bundle.zip** zip file and place the **convexvr_sims4-vr** folder in the mods folder  **C:\Users\\$USER\Documents\Electronic Arts\The Sims 4\Mods**

For the mod to work properly you need to set the following settings in vorpx and sims 4

## Sims4 settings and VorpX settings
### Vorpx settings
```
Full VR Mode
3D-Strength/Scale: 0.13
3D-FOV Enhancment: 0
Camera Height Modifier: 0
Edge Peak Strength Modifier 0.31
Game hud scale: 1
Game hudscale  horizontal 0.75
Game hud depth: 0.5
Aspect ratio: 1:1
Image zoom: 0.795
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
3. The first time when you are in sims4 configure the sims4 (sims4 settings menu) and the vorpX settings(press delete on keyboard to open VorpX settings).
4. When playing press the B-button on your oculus controller once quickly to initate VR mode

## Controls
### Right hand oculus controller

```
Oculus B-button quick press: Toggle VR mode
Oculus a-button quick press: Lock or unlock camera position to active sim.
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
```
