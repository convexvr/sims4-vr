# Mod function

The mod is a python script mod that is loaded like any normal sims4 mod. Once the mod is loaded it injects a dll in to the sims 4 that overwrites
the sims4 camera position and rotation with the camera position and rotation that the DLL is getting from VorpX and the VR headset.

## Problems
There are some issues with scaling and projection that causes the world to warp a bit when you tilt your head. Look at the python variable game_camera_scale
and game_camera_scalew to fix. The exact values that remove the warping depends on your headsets field of view and the resolution of the game.

### Updates to the sims4
When the sims exacutable is updated the mod needs to be updated to match the new exacutable. The python variable code_injection_base_address
contains the address to the place where the game needs to be patched. I have used cheatengine in the past to locate the correct place in the executable.
