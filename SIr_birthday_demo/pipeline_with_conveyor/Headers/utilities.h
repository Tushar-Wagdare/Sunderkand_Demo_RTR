#include<windows.h>

#define PI 3.1436

//---- DEMO VARIABLES -----//
int gCount          = 0;
GLint pss_slice     = 2;
GLint pss_stacks    = 2;
int fpp_scene_count = 0;
//*** Structure Declaration For Circle ***//
struct Vertex {
	float x;
	float y;
	float z;
};
struct Color {
	float r;
	float g;
	float b;
};
struct Size {
	float point_size;
	float line_width;
};
struct Center
{
	float xCoordinate;
	float yCoordinate;
};
struct Radious
{
	float xAxis;
	float yAxis;
};
struct Angle
{
	int from;
	int to;
};
struct Circle
{
	struct Color color;
	struct Center center;
	struct Radious radious;
	struct Angle angle;
	struct Size size;
};
//Framebuffer Animation Variables
GLint tw_count_for_color    = 0;
GLfloat tw_fbPointTranslate = 1.0f;
GLfloat tw_fbPointPlace     = 0.0f;
GLfloat tw_red              = 0.0f;
GLfloat tw_green            = 0.0f;
GLfloat tw_blue             = 0.0f;
GLfloat tw_swapBuffers      = 0.0f;
BOOL tw_bFBfull             = FALSE;
GLfloat tw_xPipeTranslate   = 0.0f;
//Time Variable
GLfloat hour                = 210.0f;
GLfloat minut               = 270.0f;
GLdouble second             = 270.0f;
double elapsedTime          = 0.0;//Elapsed time between two frames
double frameCount           = 0.0;//number of frame since the last FPS update
double fps                  = 0.0;//current FPS value
char titleBuffer[32];
//Sir View Scene Variable
GLfloat tw_xScaleSir        = 0.01f;
GLfloat tw_yScaleSir        = 0.01f;
GLfloat tw_zScaleSir        = 0.0f;
GLfloat tw_xTransSir        = -0.2f;
GLfloat tw_yTransSir        = 0.001f;
GLfloat tw_zTransSir        = -0.1f;
//Screen VAriable
GLfloat tw_rot              = 90.0f;
float tw_red1               = 0.0f;
float tw_green1             = 0.0f;
float tw_blue1              = 0.0f;
//Camera Variable
Camera camera;
Vec2f mouse, canvas, lastMouse, delta;
//Scene Variable
GLint tw_scene              = 0;
GLfloat x_translate_vf      = 0.001;
GLfloat x_translate         = 0.001, y_translate = 0.0, z_translate = 0.0;
GLfloat X_circle0_translate = 0.0, X_circle1_translate = 0.0, y_line_translate = 0.0;
int beltMotion              = 0;
int scene                   = 1;
int test_count;
int scene_count             = 1;
int condition               = 1, countref, line_state = 1;
int start1;
//Time
//GLfloat hour              = 210.0f;
//GLfloat minut             = 270.0f;
//GLdouble second           = 270.0f;
GLfloat rotateCeilingFan    = 0.0f;
GLfloat cloud_X_scale       = 60.25f;
GLfloat cloud_Y_scale       = 60.1f;
// For PlaySound()
//PLAYSOUND BOOLS (Chaupai-1)
BOOL sir_sound_1            = TRUE;
GLUquadric* quadric         = NULL;
// global variable declarations
FILE* gpFILE                = NULL;
//global variable declaration
HWND ghwnd                  = NULL;
BOOL gbActive               = FALSE;
DWORD dwStyle               = 0;
WINDOWPLACEMENT wpPrev      = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen           = FALSE;
// OpenGL releted global variables
HDC ghdc                    = NULL;
HGLRC ghrc                  = NULL;
GLfloat vb_x_move      = 0.3f;
GLfloat vb_z_tranlsate = -3.0f;


//Texture variable (object)

GLuint texture_astro = 0;
GLuint texture_ortho = 0;
GLuint texture_techused = 0;
GLuint texture_gmem = 0;
GLuint texture_gl = 0;
GLuint texture_sir = 0;
GLuint texture_madam = 0;

Vec2f canvas;

//Function
float toRadians(float degree)
{
	return(degree * (PI / 180.0f));
}
