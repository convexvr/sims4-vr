# Mod function

The mod is a python script mod that is loaded like any normal sims4 mod. Once the mod is loaded it injects a dll in to the sims 4 that overwrites
the sims4 camera position and rotation with the camera position and rotation that the DLL is getting from VorpX and the VR headset.

## Problems
There are some issues with scaling and projection that causes the world to warp a bit when you tilt your head. If you have those types of issues set your games resolution to what the mod expects. Or Look at the python variables game_camera_scale and game_camera_scalew to fix the warping.
The exact values of those variables that remove the warping depends on your headsets field of view and the resolution of the game, vorpx image zoom and vorpx 3D-Strength.

### Updates to the sims4
The mod makes in memmory patches to the sims 4 executable so when the sims exacutable is updated there is a chance the mod might break. When that happens the new patch locations need to be found and added to the mod. This is something that can be done with CheatEngine.
