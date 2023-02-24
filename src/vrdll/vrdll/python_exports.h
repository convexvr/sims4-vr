/* Replace "dll.h" with the name of your header */
/* #include "dll.h" */
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <Matrices.h>

typedef struct float4 { float w; float x; float y; float z; } float4;
typedef struct vpxint4 { int x; int y; int z; int w; } vpxint4;
typedef struct vpxfloat3 { float x; float y; float z; } vpxfloat3;
typedef struct vpxfloat4 { float x; float y; float z; float w; } vpxfloat4;
typedef struct vpxmtx4x4 { float m[16]; } vpxmtx4x4;

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
vpxfloat3 last_headsetpos;

UINT64 structpos = 4545;
UINT64 structpos2 = 4545;


Matrix4 m_mat4HMDPose;
Matrix4 m_mat4eyePosLeft;
Matrix4 m_mat4eyePosRight;

Matrix4 m_mat4ProjectionCenter;
Matrix4 m_mat4ProjectionLeft;
Matrix4 m_mat4ProjectionRight;


float m_fNearClip = 0.05;
float m_fFarClip = 500;

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

#define M_PI    3.14159265358979323846264338327950288   /* pi */
vr::HmdVector3d_t QuaternionToEuler(vr::HmdQuaternion_t q)
{
	vr::HmdVector3d_t e;
	double x, y, z, w;
	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
	double test = x * y + z * w;
	if (test > 0.499) {
		e.v[0] = 2 * atan2(x, w);
		e.v[1] = M_PI / 2.0;
		e.v[2] = 0;
		return e;
	}
	if (test < -0.499) {
		e.v[0] = -2 * atan2(x, w);
		e.v[1] = -M_PI / 2;
		e.v[2] = 0;
		return e;
	}
	double sqx = x * x;
	double sqy = y * y;
	double sqz = z * z;
	e.v[0] = atan2(2 * y * w - 2 * x * z, 1 - 2 * sqy - 2 * sqz);
	e.v[1] = asin(2 * test);
	e.v[2] = atan2(2 * x * w - 2 * y * z, 1 - 2 * sqx - 2 * sqz);
	return e;
}

vr::HmdQuaternion_t EulerToQuaternion(vr::HmdVector3d_t e)
{
	vr::HmdQuaternion_t q;
	double c1 = cos(e.v[0] / 2);
	double s1 = sin(e.v[0] / 2);
	double c2 = cos(e.v[1] / 2);
	double s2 = sin(e.v[1] / 2);
	double c3 = cos(e.v[2] / 2);
	double s3 = sin(e.v[2] / 2);
	double c1c2 = c1 * c2;
	double s1s2 = s1 * s2;
	q.w = c1c2 * c3 - s1s2 * s3;
	q.x = c1c2 * s3 + s1s2 * c3;
	q.y = s1 * c2 * c3 + c1 * s2 * s3;
	q.z = c1 * s2 * c3 - s1 * c2 * s3;
	return q;
}


__declspec(dllexport) uint64_t __cdecl get_button_value(int val_id) {
	if (val_id == 0) {
		return(LastRightHandState.ulButtonPressed);
	}
	if (val_id == 1) {
		return(LastLeftHandState.ulButtonPressed);
	}
	return 0;
}

__declspec(dllexport) float __cdecl get_float_value(int val_id) {
	if (val_id == 0) {
		return games_x;
	}
	if (val_id == 1) {
		return games_y;
	}
	if (val_id == 2) {
		return games_z;
	}
	if (val_id == 3) {
		return games_x_sidevec;
	}
	if (val_id == 4) {
		return games_y_sidevec;
	}
	if (val_id == 5) {
		return games_z_sidevec;
	}
	if (val_id == 6) {
		return games_x_upvec;
	}
	if (val_id == 7) {
		return games_y_upvec;
	}
	if (val_id == 8) {
		return games_z_upvec;
	}
	if (val_id == 9) {
		return games_x_fwvec;
	}
	if (val_id == 10) {
		return games_y_fwvec;
	}
	if (val_id == 11) {
		return games_z_fwvec;
	}

	if (val_id == 12) {
		return last_headsetrot.x;
	}
	if (val_id == 13) {
		return last_headsetrot.y;
	}
	if (val_id == 14) {
		return last_headsetrot.z;
	}

	if (val_id == 15) {
		return last_headsetpos.x;
	}
	if (val_id == 16) {
		return last_headsetpos.y;
	}
	if (val_id == 17) {
		return last_headsetpos.z;
	}
	if (val_id == 18) {
		return(LastRightHandState.rAxis->x);
	}
	if (val_id == 19) {
		return(LastRightHandState.rAxis->y);
	}
	if (val_id == 20) {
		return(LastLeftHandState.rAxis->x);
	}
	if (val_id == 21) {
		return(LastLeftHandState.rAxis->y);
	}
	

	return 0.0f;
}

__declspec(dllexport) int __cdecl set_follow(int follow) {
	follow_active = follow;
	return follow_active;
}

__declspec(dllexport) int __cdecl set_offset(float x, float y, float z) {
	offset_x = x;
	offset_y = y;
	offset_z = z;

	vireio::deb("set_offset: %f %f %f\n", offset_x, offset_y, offset_z);

	return 0;
}

__declspec(dllexport) int __cdecl set_origin(float x, float y, float z) {
	origin_x = x;
	origin_y = y;
	origin_z = z;

	vireio::deb("set_origin: %f, %f, %f", origin_x, origin_y, origin_z);
	return 0;
}

__declspec(dllexport) int __cdecl set_vr_active(int num) {
	vr_active = num;

	vireio::deb("set_vr_active: %i\n", vr_active);
	return 0;
}


__declspec(dllexport) int __cdecl set_position_scale(float num) {
	position_scale = num;

	vireio::deb("position_scale: %f\n", position_scale);
	return 0;
}

__declspec(dllexport) int __cdecl set_added_rotation(float num) {
	added_rotation = num;

	vireio::deb("added_rotation: %f\n", added_rotation);
	return 0;
}



__declspec(dllexport) int __cdecl set_scale(float width, float height) {
	height_scale = height;
	width_scale = width;
	vireio::deb("set_scale: %f, %f\n", width_scale, height_scale);
	return 0;
}

__declspec(dllexport) int __cdecl set_struct_location(UINT64 location) {

	if (structpos != location) {
		structpos2 = structpos;
	}
	if (location == 4545) {
		structpos2 = location;
	}
	structpos = location;
	vireio::deb("set_struct_location: %llx\n", structpos);
	float* x_pos;
	float* y_pos;
	float* z_pos;

	x_pos = (float*)structpos + (0x60 / 4);
	y_pos = (float*)structpos + (0x64 / 4);
	z_pos = (float*)structpos + (0x68 / 4);
	vireio::deb("gamepos: %f %f %f\n", *x_pos, *y_pos, *z_pos);
	return 0;
}


//required quaternation functions
float4 euler2quat(float ai, float aj, float ak) {
	ai /= 2.0;
	aj /= 2.0;
	ak /= 2.0;
	float ci = cos(ai);
	float si = sin(ai);
	float cj = cos(aj);
	float sj = sin(aj);
	float ck = cos(ak);
	float sk = sin(ak);
	float cc = ci * ck;
	float cs = ci * sk;
	float sc = si * ck;
	float ss = si * sk;

	float4 q = { cj * cc + sj * ss, cj * cs - sj * sc, cj * sc - sj * cs, cj * ss + sj * cc };
	return q;
}

float4 qmult(float4 q1, float4 q2) {
	float w1 = q1.w;
	float x1 = q1.x;
	float y1 = q1.y;
	float z1 = q1.z;

	float w2 = q2.w;
	float x2 = q2.x;
	float y2 = q2.y;
	float z2 = q2.z;

	float w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2;
	float x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2;
	float y = w1 * y2 + y1 * w2 + z1 * x2 - x1 * z2;
	float z = w1 * z2 + z1 * w2 + x1 * y2 - y1 * x2;
	float4 q = { w, x, y, z };
	return q;
}

float3x3 quat2mat(float4 quat) {
	float w = quat.w;
	float x = quat.x;
	float y = quat.y;
	float z = quat.z;


	float Nq = w * w + x * x + y * y + z * z;
	if (Nq < 2.220446049250313e-16) {
		float3x3 m1 = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
		return m1;
	}
	float s = 2.0 / Nq;
	float X = x * s;
	float Y = y * s;
	float Z = z * s;
	float wX = w * X; float wY = w * Y; float wZ = w * Z;
	float xX = x * X; float xY = x * Y; float xZ = x * Z;
	float yY = y * Y; float yZ = y * Z; float zZ = z * Z;

	float3x3 m = {
		1.0 - (yY + zZ), xY - wZ, xZ + wY,
		xY + wZ, 1.0 - (xX + zZ), yZ - wX,
		xZ - wY, yZ + wX, 1.0 - (xX + yY)
	};
	return m;
}

inline float vpxRadToDeg(const float a) { return a * 57.295795131f; }
inline float vpxDegToRad(float a) { return a * 0.0174532925f; }

float3x3 get_mat(float4 headsetrot, float rotate) {
	float radians = vpxDegToRad(rotate);

	float4 yaw_quat = euler2quat(radians, 0, 0);

	float4 combined_quat = qmult(headsetrot, yaw_quat);

	return(quat2mat(combined_quat));

}

int apply_mat(UINT64 structp, Matrix4 matrix, Matrix4 Scale, Matrix4 eye_pos) {
	float* x_pos;
	float* y_pos;
	float* z_pos;
	float* extra_pos;

	x_pos = (float*)structp + (96 / 4);
	y_pos = (float*)structp + (100 / 4);
	z_pos = (float*)structp + (104 / 4);
	extra_pos = (float*)structp + (108 / 4);

	float* width_scalep;
	float* height_scalep;

	width_scalep = (float*)structp + (112 / 4);
	height_scalep = (float*)structp + (132 / 4);


	float* x_sidevec;
	float* y_sidevec;
	float* z_sidevec;
	float* extra_sidevec;

	float* x_upvec;
	float* y_upvec;
	float* z_upvec;
	float* extra_upvec;

	float* x_fwvec;
	float* y_fwvec;
	float* z_fwvec;
	float* extra_fwvec;

	UINT64 Affine_rotation_direction_matrix_pos = structp + 48;

	UINT64 Scale_matrix_pos = Affine_rotation_direction_matrix_pos + (4*16);

	

	x_sidevec = (float*)structp + (48 / 4);
	y_sidevec = (float*)structp + (52 / 4);
	z_sidevec = (float*)structp + (56 / 4);
	extra_sidevec = (float*)structp + (60 / 4);

	x_upvec = (float*)structp + (64 / 4);
	y_upvec = (float*)structp + (68 / 4);
	z_upvec = (float*)structp + (72 / 4);
	extra_upvec = (float*)structp + (76 / 4);

	x_fwvec = (float*)structp + (80 / 4);
	y_fwvec = (float*)structp + (84 / 4);
	z_fwvec = (float*)structp + (88 / 4);
	extra_fwvec = (float*)structp + (92 / 4);

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


	if (vr_active == 1) {

		if (follow_active == 0) {
			*x_pos = matrix[12] + eye_pos[12];
			*y_pos = matrix[13] + eye_pos[13];
			*z_pos = matrix[14] + eye_pos[14];
			*extra_pos = matrix[15];
		}
		else {
			*x_pos += eye_pos[12];
			*y_pos += eye_pos[13];
			*z_pos += eye_pos[14];
		}

		//last_x = x;
		//last_y = y;
		//last_z = y;

		//Dont transfter the entire scale matrix that does not work, It generates grabage
		memcpy((void*)Scale_matrix_pos, Scale.get(), sizeof(float)*4*4);

		//*height_scalep = Scale[0];
		//*width_scalep = Scale[5];

		/*
		* In sims it normaly looks like this: when in normal viewing mode (not fps)
		*  Scale[0] = 2.288473129
		* Scale[5] = 3.218951225
		* Scale[10] = -1.000099897 //this changes slightly when using scrollwhell to zoom but is always close to -1
		* Scale[11] = 0.4369725883
		* Scale[12] = 0.3106601834
		* The rest is generally zero
		* When in fps the valuse chnage a bit the -1 is always minus one thogh
		* 
		*/

		//2022TEST switch side and upp
		*x_sidevec = matrix[0];
		*y_sidevec = matrix[1];
		*z_sidevec = matrix[2];
		*extra_sidevec = matrix[3];

		*x_upvec = matrix[4];
		*y_upvec = matrix[5];
		*z_upvec = matrix[6];
		*extra_upvec = matrix[7];

		*x_fwvec = matrix[8];
		*y_fwvec = matrix[9];
		*z_fwvec = matrix[10];
		*extra_fwvec = matrix[11];
	}
	return 0;
}
/*
Matrix4 ConvertSteamVRMatrixToMatrix4(const vr::HmdMatrix34_t& matPose)
{
	Matrix4 matrixObj(
		matPose.m[0][0], matPose.m[1][0], matPose.m[2][0], 0.0,
		matPose.m[0][1], matPose.m[1][1], matPose.m[2][1], 0.0,
		matPose.m[0][2], matPose.m[1][2], matPose.m[2][2], 0.0,
		matPose.m[0][3], matPose.m[1][3], matPose.m[2][3], 1.0f
	);
	return matrixObj;
}
*/

//-----------------------------------------------------------------------------
// Purpose: Gets a Matrix Projection Eye with respect to nEye.
//-----------------------------------------------------------------------------
Matrix4 GetHMDMatrixProjectionEye(vr::Hmd_Eye nEye)
{
	if (!forwarder)
		return Matrix4();

	vr::HmdMatrix44_t mat = forwarder->m_pHMD->GetProjectionMatrix(nEye, m_fNearClip, m_fFarClip);

	return Matrix4(
		mat.m[0][0], mat.m[1][0], mat.m[2][0], mat.m[3][0],
		mat.m[0][1], mat.m[1][1], mat.m[2][1], mat.m[3][1],
		mat.m[0][2], mat.m[1][2], mat.m[2][2], mat.m[3][2],
		mat.m[0][3], mat.m[1][3], mat.m[2][3], mat.m[3][3]
	);
}
//-----------------------------------------------------------------------------
// Purpose: Gets an HMDMatrixPoseEye with respect to nEye.
//-----------------------------------------------------------------------------
Matrix4 GetHMDMatrixPoseEye(vr::Hmd_Eye nEye)
{
	if (!forwarder)
		return Matrix4();

	vr::HmdMatrix34_t matEyeRight = forwarder->m_pHMD->GetEyeToHeadTransform(nEye);
	Matrix4 matrixObj(
		matEyeRight.m[0][0], matEyeRight.m[1][0], matEyeRight.m[2][0], 0.0,
		matEyeRight.m[0][1], matEyeRight.m[1][1], matEyeRight.m[2][1], 0.0,
		matEyeRight.m[0][2], matEyeRight.m[1][2], matEyeRight.m[2][2], 0.0,
		matEyeRight.m[0][3], matEyeRight.m[1][3], matEyeRight.m[2][3], 1.0f
	);

	return matrixObj.invert();
}

//-----------------------------------------------------------------------------
// Purpose: Gets a Current View Projection Matrix with respect to nEye,
//          which may be an Eye_Left or an Eye_Right.
//-----------------------------------------------------------------------------
Matrix4 GetCurrentViewProjectionMatrix(vr::Hmd_Eye nEye)
{
	Matrix4 matMVP;
	if (nEye == vr::Eye_Left)
	{
		matMVP = m_mat4ProjectionLeft * m_mat4eyePosLeft * m_mat4HMDPose;
	}
	else if (nEye == vr::Eye_Right)
	{
		matMVP = m_mat4ProjectionRight * m_mat4eyePosRight * m_mat4HMDPose;
	}

	return matMVP;
}

//-----------------------------------------------------------------------------
// Purpose: Converts a SteamVR matrix to our local matrix class
//-----------------------------------------------------------------------------
Matrix4 ConvertSteamVRMatrixToMatrix4(const vr::HmdMatrix34_t& matPose)
{
	Matrix4 matrixObj(
		matPose.m[0][0], matPose.m[1][0], matPose.m[2][0], 0.0,
		matPose.m[0][1], matPose.m[1][1], matPose.m[2][1], 0.0,
		matPose.m[0][2], matPose.m[1][2], matPose.m[2][2], 0.0,
		matPose.m[0][3], matPose.m[1][3], matPose.m[2][3], 1.0f
	);
	return matrixObj;
}

void SetupHMDMatrixes(){
	m_mat4ProjectionLeft = GetHMDMatrixProjectionEye(vr::Eye_Left);
	m_mat4ProjectionRight = GetHMDMatrixProjectionEye(vr::Eye_Right);
	m_mat4eyePosLeft = GetHMDMatrixPoseEye(vr::Eye_Left);
	m_mat4eyePosRight = GetHMDMatrixPoseEye(vr::Eye_Right);
	//
}

vpxfloat4 GetRotation(vr::HmdMatrix34_t matrix) {
	vpxfloat4 q;

	q.w = sqrt(fmax(0, 1 + matrix.m[0][0] + matrix.m[1][1] + matrix.m[2][2])) / 2;
	q.x = sqrt(fmax(0, 1 + matrix.m[0][0] - matrix.m[1][1] - matrix.m[2][2])) / 2;
	q.y = sqrt(fmax(0, 1 - matrix.m[0][0] + matrix.m[1][1] - matrix.m[2][2])) / 2;
	q.z = sqrt(fmax(0, 1 - matrix.m[0][0] - matrix.m[1][1] + matrix.m[2][2])) / 2;
	q.x = copysign(q.x, matrix.m[2][1] - matrix.m[1][2]);
	q.y = copysign(q.y, matrix.m[0][2] - matrix.m[2][0]);
	q.z = copysign(q.z, matrix.m[1][0] - matrix.m[0][1]);
	return q;
}

__declspec(dllexport) int __cdecl update()
{

	int curVorpXFrame = 0;

	if (VorpXFrame != curVorpXFrame) {
		//vpxfloat3 headsetrot = vpxGetHeadsetRotationEuler();
		vpxfloat3 delta_rot;
		delta_rot.x = 0;//headsetrot.x - last_headsetrot.x;
		delta_rot.y = 0;//headsetrot.y - last_headsetrot.y;
		delta_rot.z = 0;//headsetrot.z - last_headsetrot.z;
		//vpxSetGameCamRotationDeltaEuler(delta_rot);//What does vpxSetGameCamRotationDeltaEuler acctually do...?

		VorpXFrame = curVorpXFrame;
		//last_headsetrot = headsetrot;
	}

	if (!forwarder) {
		return 0;
	}

	//vr::HmdMatrix44_t Right_Projection_matrix = forwarder->m_pHMD->GetProjectionMatrix(vr::EVREye::Eye_Right, m_fNearClip, m_fFarClip);


	// for somebody asking for the default figure out the time from now to photons.
	float fSecondsSinceLastVsync;
	forwarder->m_pHMD->GetTimeSinceLastVsync(&fSecondsSinceLastVsync, NULL);

	float fDisplayFrequency = forwarder->m_pHMD->GetFloatTrackedDeviceProperty(vr::k_unTrackedDeviceIndex_Hmd, vr::Prop_DisplayFrequency_Float);
	float fFrameDuration = 1.f / fDisplayFrequency;
	float fVsyncToPhotons = forwarder->m_pHMD->GetFloatTrackedDeviceProperty(vr::k_unTrackedDeviceIndex_Hmd, vr::Prop_SecondsFromVsyncToPhotons_Float);

	float fPredictedSecondsFromNow = fFrameDuration - fSecondsSinceLastVsync + fVsyncToPhotons;

	forwarder->m_pHMD->GetDeviceToAbsoluteTrackingPose(vr::TrackingUniverseOrigin::TrackingUniverseStanding, fPredictedSecondsFromNow, forwarder->m_rTrackedDevicePose, vr::k_unMaxTrackedDeviceCount);
	

	
	
	vr::TrackedDevicePose_t  Pose = forwarder->m_rTrackedDevicePose[vr::k_unTrackedDeviceIndex_Hmd];
	vr::HmdMatrix34_t matPose = Pose.mDeviceToAbsoluteTracking;
	
	
	m_mat4HMDPose = ConvertSteamVRMatrixToMatrix4(matPose);

	Matrix4 HMDMatRotation = ConvertSteamVRMatrixToMatrix4(matPose);
	HMDMatRotation[12] = 0.0f;
	HMDMatRotation[13] = 0.0f;
	HMDMatRotation[14] = 0.0f;



	

	vpxfloat3 headsetpos = vpxfloat3{ matPose.m[0][3], matPose.m[1][3], matPose.m[2][3] };
		
	
	vpxfloat4 headsetrot = GetRotation(matPose);


	//This version of things turns on the x axel
	vr::HmdVector3d_t rot = QuaternionToEuler(vr::HmdQuaternion_t{ -headsetrot.w,headsetrot.x, headsetrot.y,headsetrot.z });

	

	last_headsetrot.x = vpxRadToDeg(rot.v[2]);
	last_headsetrot.y = vpxRadToDeg(rot.v[0]);
	last_headsetrot.z = vpxRadToDeg(rot.v[1]);

	last_headsetpos.x = matPose.m[0][3];
	last_headsetpos.y = matPose.m[1][3];
	last_headsetpos.z = matPose.m[2][3];

	

	//TODO ADD real yaw correction
	//vpxfloat3 corected_headsetpos = headsetpos;// vpxYawCorrection(headsetpos, added_rotation);
	//Matrix4  = ConvertSteamVRMatrixToMatrix4(matPose);
	


	//TODO: Add rotation to eye position cos or sin
	float EyeCorection_x = m_mat4eyePosLeft[12];
	float EyeCorection_y = m_mat4eyePosLeft[13];
	float EyeCorection_z = m_mat4eyePosLeft[14];

	if (LastRequestedFrameType == 1) {
		EyeCorection_x = m_mat4eyePosRight[12];
		EyeCorection_y = m_mat4eyePosRight[13];
		EyeCorection_z = m_mat4eyePosRight[14];
	}

	Matrix4 eye_pos;
	eye_pos[12] = EyeCorection_x;
	eye_pos[13] = EyeCorection_y;
	eye_pos[14] = EyeCorection_z;

	eye_pos = HMDMatRotation * eye_pos;
	eye_pos.rotateY(-added_rotation);
	//eye_pos.rotateY(-added_rotation);

	Matrix4 heaset_pos;
	heaset_pos[12] = matPose.m[0][3];
	heaset_pos[13] = matPose.m[1][3];
	heaset_pos[14] = matPose.m[2][3];



	heaset_pos.rotateY(-added_rotation);

	//headsetpos.x -= offset_x;
	//headsetpos.y -= offset_y;
	//headsetpos.z -= offset_z;

	vpxfloat3 corected_headsetpos = vpxfloat3{ heaset_pos[12]-offset_x, heaset_pos[13]-offset_y, heaset_pos[14]-offset_z };

	float new_cam_x = origin_x + (position_scale * corected_headsetpos.x);
	float new_cam_y = origin_y + (position_scale * corected_headsetpos.y);
	float new_cam_z = origin_z + (position_scale * corected_headsetpos.z);

	if (structpos == 4545) {
		return 0;
	}

	float4 own_quat = { -headsetrot.w, headsetrot.x, headsetrot.y, headsetrot.z };
	float3x3 mat = get_mat(own_quat, added_rotation);

	//This seams to work to i guess...
	/*
	float3x3 mat = float3x3{
		matPose.m[0][0], matPose.m[1][0], matPose.m[2][0],
		matPose.m[0][1], matPose.m[1][1], matPose.m[2][1],
		matPose.m[0][2], matPose.m[1][2], matPose.m[2][2],
	};
	*/

	
	//matPose.m[0][3] += origin_x;
	//matPose.m[1][3] += origin_y;
	//matPose.m[2][3] += origin_z;

	if (LastRequestedFrameType == 3) {//enable stero
		LastRequestedFrameType = 1;
	}
	


	

	Matrix4 CameraPosMatrix(
		mat.a, mat.b, mat.c, 0.0,
		mat.d, mat.e, mat.f, 0.0,
		mat.g, mat.h, mat.i, 0.0,
		new_cam_x, new_cam_y, new_cam_z, 1.0f
	);
	

	
	m_mat4HMDPose.invert();
	//m_mat4HMDPose.translate(origin_x, origin_y, origin_z);
	//Matrix4 Right_Projection_matrix = GetCurrentViewProjectionMatrix(vr::Eye_Right);
	Matrix4 GameOFfset;
	GameOFfset.translate(Vector3{ origin_x, origin_y, origin_z });

	//Matrix4 Right_Projection_matrix = m_mat4ProjectionRight * m_mat4eyePosRight * m_mat4HMDPose * GameOFfset;

	//CameraPosMatrix.invert();
	//Tyvär ser det ut som att jag inte kan multiplcera in m_mat4ProjectionRight då sims lägger till sin egen projections matrix i efterhand
	//det jag stoppar in är ett affine matrix som bestämmer riktning och position
	Matrix4 Right_Projection_matrix = CameraPosMatrix;

	//Right_Projection_matrix[12] = new_cam_x;
	//Right_Projection_matrix[13] = new_cam_y;
	//Right_Projection_matrix[14] = new_cam_z;

	Matrix4 IdentM;

	Matrix4 ScaleM;
		
	//lets try using the headset matrix now (NO, it is just black)
	//ScaleM = IdentM;
	//Right_Projection_matrix = m_mat4ProjectionRight * m_mat4eyePosRight * m_mat4HMDPose * GameOFfset;
	

	//Using CameraPosMatrix and m_mat4ProjectionRight generates blury stuff but the perspective is right
	if (LastRequestedFrameType == 0) {
		ScaleM = m_mat4ProjectionLeft;
		//LastRequestedFrameType = 1;//this is done at rendering
	}
	else {
		ScaleM = m_mat4ProjectionRight;
		//LastRequestedFrameType = 0;
	}
	



	apply_mat(structpos, Right_Projection_matrix, ScaleM, eye_pos);
	if (structpos2 != 4545) {
		apply_mat(structpos2, Right_Projection_matrix, ScaleM, eye_pos);
	}



	time_t rawtime;
	struct tm timeinfo;

	
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);



	int current_s = timeinfo.tm_sec;
	frames += 1;
	if (last_s != current_s) {


		//fprintf(fp, "headsetpos: %f %f %f\n", headsetpos.x, headsetpos.y, headsetpos.z);
		vireio::deb("origin: %f %f %f gamepos: %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n", origin_x, origin_y, origin_z, games_x, games_y, games_z,
			Right_Projection_matrix[0], Right_Projection_matrix[1], Right_Projection_matrix[2], Right_Projection_matrix[3],
			Right_Projection_matrix[4], Right_Projection_matrix[5], Right_Projection_matrix[6], Right_Projection_matrix[7],
			Right_Projection_matrix[8], Right_Projection_matrix[9], Right_Projection_matrix[10], Right_Projection_matrix[11],
			Right_Projection_matrix[12], Right_Projection_matrix[13], Right_Projection_matrix[14], Right_Projection_matrix[15]
			);

		vireio::deb("rfps: %i VorpXframe:  %i\n", frames, VorpXFrame);


		vireio::deb("headsetrot: %f %f %f\n", last_headsetrot.x, last_headsetrot.y, last_headsetrot.z);
		vireio::deb("fps: %i VorpXframe:  %i\n", frames, VorpXFrame);


		frames = 0;
		last_s = current_s;
	}
	

	return 1 + 3;
}
