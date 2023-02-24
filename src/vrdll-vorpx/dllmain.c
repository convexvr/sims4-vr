/* Replace "dll.h" with the name of your header */
/* #include "dll.h" */
#include <stdio.h>
#include <time.h>
#include "vorpAPI.h"
#include <math.h>

typedef struct float4 {float w; float x; float y; float z; } float4;
typedef struct float3x3 {
float a;
float b;
float c;

float d;
float e;
float f;

float g;
float h;
float i;
} float3x3;

//__declspec(dllexport) int init();
//__declspec(dllexport) int update();

int last_s = 0;
int frames = 0;
int VorpXFrame = 0;
vpxfloat3 last_headsetrot;

__declspec(dllexport) int init()
{
	
	FILE *fp;

	fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fputs("init\n", fp);
	}

	
	VPX_RESULT int_ok = vpxInit();
	if(fp){
		fprintf(fp, "vpxInit: %i\n", int_ok);
		fclose(fp);
	}
	
	return 1+2;
}

UINT64 structpos = 4545;
UINT64 structpos2 = 4545;


int vr_active = 0;

int follow_active = 0;

float height_scale = 4545;
float width_scale = 4545;

float position_scale = 1;
float added_rotation = 0;

float offset_x = 0;
float offset_y = 0;
float offset_z = 0;

float origin_x = 0;
float origin_y = 0;
float origin_z = 0;

float last_x = 0;
float last_y = 0;
float last_z = 0;



float games_x_sidevec = 0;
float games_y_sidevec = 0;
float games_z_sidevec = 0;
	
float games_x_upvec = 0;
float games_y_upvec = 0;
float games_z_upvec = 0;
	
float games_x_fwvec = 0;
float games_y_fwvec = 0;
float games_z_fwvec = 0;


float games_x = 0;
float games_y = 0;
float games_z = 0;


__declspec(dllexport) float get_float_value(int val_id){
	if(val_id == 0){
		return games_x;
	}
	if(val_id == 1){
		return games_y;
	}
	if(val_id == 2){
		return games_z;
	}
	if(val_id == 3){
		return games_x_sidevec;
	}
	if(val_id == 4){
		return games_y_sidevec;
	}
	if(val_id == 5){
		return games_z_sidevec;
	}
	if(val_id == 6){
		return games_x_upvec;
	}
	if(val_id == 7){
		return games_y_upvec;
	}
	if(val_id == 8){
		return games_z_upvec;
	}
	if(val_id == 9){
		return games_x_fwvec;
	}
	if(val_id == 10){
		return games_y_fwvec;
	}
	if(val_id == 11){
		return games_z_fwvec;
	}
	
	return 0;
}

__declspec(dllexport) int set_follow(int follow){
	follow_active = follow;
	return follow_active;
}

__declspec(dllexport) int set_offset(float x, float y, float z){
	offset_x = x;
	offset_y = y;
	offset_z = z;
	
	FILE *fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fprintf(fp, "set_offset: %f\n", offset_x);
		fclose(fp);
	}
}

__declspec(dllexport) int set_origin(float x, float y, float z){
	origin_x = x;
	origin_y = y;
	origin_z = z;
	
	FILE *fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fprintf(fp, "set_origin: %f\n", origin_x);
		fclose(fp);
	}
}

__declspec(dllexport) int set_vr_active(int num){
	vr_active = num;
	
	FILE *fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fprintf(fp, "set_vr_active: %i\n", vr_active);
		fclose(fp);
	}
}


__declspec(dllexport) int set_position_scale(float num){
	position_scale = num;
	
	FILE *fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fprintf(fp, "position_scale: %f\n", position_scale);
		fclose(fp);
	}
}

__declspec(dllexport) int set_added_rotation(float num){
	added_rotation = num;
	
	FILE *fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fprintf(fp, "added_rotation: %f\n", added_rotation);
		fclose(fp);
	}
}



__declspec(dllexport) int set_scale(float width, float height){
	height_scale = height;
	width_scale = width;
	FILE *fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fprintf(fp, "set_scale: %f, %f\n", width_scale, height_scale);
		fclose(fp);
	}
}

__declspec(dllexport) int set_struct_location(UINT64 location){
	
	if(structpos != location){
		structpos2 = structpos;
	}
	if(location == 4545){
		structpos2 = location;
	}
	structpos = location;
	FILE *fp = fopen("C:\\s4\\debug_c.txt", "a");
	if(fp){
		fprintf(fp, "set_struct_location: %llx\n", structpos);
	}
	float *x_pos;
	float *y_pos;
	float *z_pos;
	
	x_pos = (float*)structpos+(0x60/4);
	y_pos = (float*)structpos+(0x64/4);
	z_pos = (float*)structpos+(0x68/4);
	if(fp){
		fprintf(fp, "set_struct_location: %llx\n", x_pos);
		fprintf(fp, "gamepos: %f %f %f\n", *x_pos, *y_pos, *z_pos);
		fclose(fp);
	}
}


//required quaternation functions
float4 euler2quat(float ai, float aj, float ak){
	ai /= 2.0;
    aj /= 2.0;
    ak /= 2.0;
    float ci = cos(ai);
    float si = sin(ai);
    float cj = cos(aj);
    float sj = sin(aj);
    float ck = cos(ak);
    float sk = sin(ak);
    float cc = ci*ck;
    float cs = ci*sk;
    float sc = si*ck;
    float ss = si*sk;

    float4 q = {cj*cc + sj*ss, cj*cs - sj*sc, cj*sc - sj*cs, cj*ss + sj*cc};
	return q;
}

float4 qmult(float4 q1, float4 q2){
	float w1 = q1.w;
	float x1 = q1.x;
	float y1 = q1.y;
	float z1 = q1.z;
    
    float w2 = q2.w;
	float x2 = q2.x;
	float y2 = q2.y;
	float z2 = q2.z;
    
    float w = w1*w2 - x1*x2 - y1*y2 - z1*z2;
    float x = w1*x2 + x1*w2 + y1*z2 - z1*y2;
    float y = w1*y2 + y1*w2 + z1*x2 - x1*z2;
    float z = w1*z2 + z1*w2 + x1*y2 - y1*x2;
    float4 q = {w, x, y, z};
	return q;
}

float3x3 quat2mat(float4 quat){
	float w = quat.w;
	float x = quat.x;
	float y = quat.y;
	float z = quat.z;
	
	
    float Nq = w*w + x*x + y*y + z*z;
    if(Nq < 2.220446049250313e-16){
    	float3x3 m1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    	return m1;
	}
    float s = 2.0/Nq;
    float X = x*s;
    float Y = y*s;
    float Z = z*s;
    float wX = w*X; float wY = w*Y; float wZ = w*Z;
    float xX = x*X; float xY = x*Y; float xZ = x*Z;
    float yY = y*Y; float yZ = y*Z; float zZ = z*Z;
    
    float3x3 m = {
		1.0-(yY+zZ), xY-wZ, xZ+wY,
		xY+wZ, 1.0-(xX+zZ), yZ-wX,
		xZ-wY, yZ+wX, 1.0-(xX+yY)
		};
    return m;	
}

float3x3 get_mat(float4 headsetrot, float rotate){
	float radians = vpxDegToRad(rotate);
	
	float4 yaw_quat = euler2quat(radians, 0, 0);
	
	float4 combined_quat = qmult(headsetrot, yaw_quat);
	
	return(quat2mat(combined_quat));

}
int apply_mat(UINT64 structp, float x, float y, float z, float3x3 mat){
	float *x_pos;
	float *y_pos;
	float *z_pos;
	
	x_pos = (float*)structp+(0x60/4);
	y_pos = (float*)structp+(0x64/4);
	z_pos = (float*)structp+(0x68/4);
	
	float *width_scalep;
	float *height_scalep;
	
	width_scalep = (float*)structp+(0x70/4);
	height_scalep = (float*)structp+(0x84/4);
	
	
	float *x_sidevec;
	float *y_sidevec;
	float *z_sidevec;
	
	float *x_upvec;
	float *y_upvec;
	float *z_upvec;
	
	float *x_fwvec;
	float *y_fwvec;
	float *z_fwvec;
	
	x_sidevec = (float*)structp+(48/4);
	y_sidevec = (float*)structp+(52/4);
	z_sidevec = (float*)structp+(56/4);
	
	x_upvec = (float*)structp+(64/4);
	y_upvec = (float*)structp+(68/4);
	z_upvec = (float*)structp+(72/4);
	
	x_fwvec = (float*)structp+(80/4);
	y_fwvec = (float*)structp+(84/4);
	z_fwvec = (float*)structp+(88/4);
	
	games_x = *x_pos;
	games_y = *y_pos;
	games_z = *z_pos;
		
	games_x_sidevec = *x_sidevec;
	games_y_sidevec = *y_sidevec;
	games_z_sidevec = *z_sidevec;
	
	games_x_upvec = *x_upvec;
	games_y_upvec = *y_upvec;
	games_z_upvec = *z_upvec;
	
	games_x_fwvec = *x_fwvec;
	games_y_fwvec = *y_fwvec;
	games_z_fwvec = *z_fwvec;
	
	
	if(vr_active == 1){
		
		if(follow_active == 0){
			*x_pos = x;
			*y_pos = y;
			*z_pos = z;
		}
		
		last_x = x;
		last_y = y;
		last_z = y;
		
		*height_scalep = height_scale;
		*width_scalep = width_scale;
		
		*x_sidevec = mat.a;
		*y_sidevec = mat.b;
		*z_sidevec = mat.c;
		
		*x_upvec = mat.d;
		*y_upvec = mat.e;
		*z_upvec = mat.f;
		
		*x_fwvec = mat.g;
		*y_fwvec = mat.h;
		*z_fwvec = mat.i;
	}
}

__declspec(dllexport) int update()
{
	FILE *fp;

	int curVorpXFrame = vpxGetCurrentVorpFrame();
	
	if(VorpXFrame != curVorpXFrame){
		//vpxfloat3 headsetrot = vpxGetHeadsetRotationEuler();
		vpxfloat3 delta_rot;
		delta_rot.x = 0;//headsetrot.x - last_headsetrot.x;
		delta_rot.y = 0;//headsetrot.y - last_headsetrot.y;
		delta_rot.z = 0;//headsetrot.z - last_headsetrot.z;
		//vpxSetGameCamRotationDeltaEuler(delta_rot);//What does vpxSetGameCamRotationDeltaEuler acctually do...?
		
		VorpXFrame = curVorpXFrame;
		//last_headsetrot = headsetrot;
	}

	vpxfloat3 headsetpos = vpxGetHeadsetPosition();
	vpxfloat4 headsetrot =  vpxGetHeadsetRotationQuaternion();
	
	headsetpos.x -= offset_x;
	headsetpos.y -= offset_y;
	headsetpos.z -= offset_z;
	
	vpxfloat3 corected_headsetpos = vpxYawCorrection(headsetpos, added_rotation);
	
	float new_cam_x = origin_x + (position_scale*corected_headsetpos.x);
	float new_cam_y = origin_y + (position_scale*corected_headsetpos.y);
	float new_cam_z = origin_z - (position_scale*corected_headsetpos.z);
	
	if (structpos == 4545){
		return 0;
	}
	
	float4 own_quat = {-headsetrot.w, headsetrot.x, headsetrot.y, headsetrot.z};
	float3x3 mat = get_mat(own_quat, added_rotation);
	

	
	
	apply_mat(structpos, new_cam_x, new_cam_y, new_cam_z, mat);
	if(structpos2 != 4545){
		apply_mat(structpos2, new_cam_x, new_cam_y, new_cam_z, mat);
	}
	
	fp = fopen("C:\\s4\\debug_c.txt", "a");
	
		
	
	time_t rawtime;
    struct tm * timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    int current_s = timeinfo->tm_sec;
    frames += 1;
    if(last_s != current_s){
    	//fprintf(fp, "headsetpos: %f %f %f\n", headsetpos.x, headsetpos.y, headsetpos.z);
    	//fprintf(fp, "gamepos: %f %f %f\n", *x_pos, *y_pos, *z_pos);
    	
    	//fprintf(fp, "headsetrot: %f %f %f %f\n", headsetrot.w, headsetrot.x, headsetpos.y, headsetpos.z);
    	if(fp){
    		fprintf(fp, "fps: %i VorpXframe:  %i\n", frames, VorpXFrame);
		}
    	
    	
    	frames = 0;
    	last_s = current_s;
	}
	
	if(fp){
		fclose(fp);
	}
	return 1+3;
}
