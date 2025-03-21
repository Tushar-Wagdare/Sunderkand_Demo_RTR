#include<windows.h>

typedef struct 
{
	float x;
	float y;
}Vec2f;

typedef struct  
{
	float x;
	float y;
	float z;
}Vec3f;

Vec3f cross(Vec3f a, Vec3f b)
{
	Vec3f c;
	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);

	return(c);
}

void NormalizeVec3f(Vec3f* inputVector)
{
	float magnitude = sqrt((inputVector->x * inputVector->x) + (inputVector->y * inputVector->y) + (inputVector->z * inputVector->z));

	if (magnitude != 0)
	{
		inputVector->x = inputVector->x / magnitude;
		inputVector->y = inputVector->y / magnitude;
		inputVector->z = inputVector->z / magnitude;
	}
}

typedef struct 
{
	Vec3f position;
	Vec3f front;
	Vec3f up;
	Vec3f right;
	float yaw;
	float roll;
	float pitch;
}Camera;

Camera createCamera(Vec3f initialPosition, Vec3f initialFront, Vec3f initialUp, float initialYaw, float initialRoll, float initialPitch)
{
	Camera camera;

	camera.position = initialPosition;
	camera.front    = initialFront;
	camera.up       = initialUp;
	camera.yaw      = initialYaw;
	camera.roll     = initialRoll;
	camera.pitch    = initialPitch;

	return(camera);
}

