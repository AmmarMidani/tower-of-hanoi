//#include <Windows.h>                              // Header File For Windows
//#include <GL\GL.h>                                // Header File For The OpenGL32 Library
//#include <GL\GLU.h>                               // Header File For The GLu32 Library
//#include <GL\freeglut.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//#include <cmath>
//#include <iostream>
//
//void display(void);
//void keyboard(unsigned char key, int x, int y);
//void DrawDisk();
//
//// Global Vars
//GLfloat angel = 90.0;
//GLfloat cam_zoomin_zoomout = 0.0f;
//GLfloat cam_up_down = 0.0;
//
//// End Global Vars
//
//void initGL(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_SMOOTH);
//
//	/* depth buffer test */
//
//	glClearDepth(1.0);
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LEQUAL);
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//}
//
//void resizeScene(GLsizei width, GLsizei height) {
//	if (height == 0.0)
//		height = 1;
//
//	/* apply viewport transformation  */
//
//	glViewport(0, 0, width, height);
//
//	/* apply projection transformation */
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glLoadIdentity();                                         /* reset MODELVIEW matrix         */
//	//gluLookAt(0.0, 0.0, cam_zoomin_zoomout, cam_right_left, cam_up_down, 0.0, 0.0, 1.0, 0.0);  /* apply viewing transformation   */
//
//	gluLookAt(0.0, 1.0, 3.5 + cam_zoomin_zoomout, 0.0, cam_up_down, 0.0, 0.0, 1.0, 0.0); // calculate view point 
//
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
//	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
//	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
//	glEnd();
//
//	GLUquadricObj *quadratic;
//	quadratic = gluNewQuadric();
//	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
//	gluCylinder(quadratic, 0.1f, 0.1f, 1.0f, 32, 32);
//	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
//	gluCylinder(quadratic, 0.1f, 0.1f, 1.0f, 32, 32);
//	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
//	gluCylinder(quadratic, 0.1f, 0.1f, 1.0f, 32, 32);
//
//	DrawDisk();
//
//	glutSwapBuffers();
//	glutKeyboardFunc(keyboard);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Ammar Midani & Dima Yazji");
//	glColor3f(1.0, 1.0, 1.0);                                 /* draw torus with given color    */
//
//	initGL();
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(resizeScene);
//	glutMainLoop();
//
//	return(0);
//}
//
//void keyboard(unsigned char key, int x, int y) {
//	switch (key)
//	{
//	case 'q':
//	case 'Q':
//	case 27:
//		exit(0);
//		break;
//	case 'f':
//	case 'F':
//	case 'È':
//		glutFullScreen();
//		break;
//	case '+':
//		cam_zoomin_zoomout -= 0.5;
//		break;
//	case '-':
//		cam_zoomin_zoomout += 0.5;
//		break;
//	case'r':
//	case'R':
//	case'Þ':
//		cam_zoomin_zoomout = 0;
//		cam_up_down = 0;
//		break;
//	case 'a':
//	case 'A':
//	case 'Ô':
//		break;
//	case 'd':
//	case 'D':
//	case 'í':
//		break;
//	case 'w':
//	case 'W':
//	case 'Õ':
//		cam_up_down -= 0.5;
//		break;
//	case 's':
//	case 'S':
//	case 'Ó':
//		cam_up_down += 0.5;
//		break;
//	}
//	display();              // Draw The Scene
//}
//
//void DrawDisk()
//{
//	glPushMatrix();
//	glRotatef(angel, 1.0, 0.0, 0.0);                           /* apply modelling transformation */
//	glColor3f(1.0, 1.0, 1.0);                                 /* draw torus with given color    */
//	glutWireTorus(0.3, 0.5, 32, 32);
//	glPopMatrix();
//}

#include <Windows.h>                              // Header File For Windows
#include <GL\GL.h>                                // Header File For The OpenGL32 Library
#include <GL\GLU.h>                               // Header File For The GLu32 Library
#include <GL\freeglut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <iostream>
#include <list>

using namespace std;

// Menu items
enum MENU_TYPE
{
	MENU_HELP,
	MENU_SOLVE,
	MENU_INCREASE_SPEED,
	MENU_DECREASE_SPEED,
	MENU_Exit,
};

class MyPoint {
public:
	double x;
	double y;
	double z;
	MyPoint()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
	MyPoint(double Set_X, double Set_Y, double Set_Z)
	{
		x = Set_X;
		y = Set_Y;
		z = Set_Z;
	}
	MyPoint& operator= (MyPoint const& obj)
	{
		x = obj.x;
		y = obj.y;
		z = obj.z;
		return *this;
	}
	MyPoint operator-(MyPoint const& p1)
	{
		return MyPoint(x - p1.x, y - p1.y, z - p1.z);
	}
};

class MyDisk {
public:
	MyDisk()
	{
		normal = MyPoint(0.0, 0.0, 1.0);
	}
	MyPoint position; //
	MyPoint normal;   //orientation
};

struct ActiveDisc {    //Active Disc to be moved [later in motion]
	int disc_index;
	MyPoint start_pos, dest_pos;
	double u;		    // u E [0, 1]
	double step_u;
	bool is_in_motion;
	int direction;     // +1 for Left to Right & -1 for Right to left, 0 = stationary
};

// Axis and Discs Globals - Can be changed for different levels
const size_t NUM_DISCS = 5;
const double AXIS_HEIGHT = 3.0;

struct Axis {
	MyPoint positions[NUM_DISCS];
	int occupancy_val[NUM_DISCS];
};

struct GameBoard {
	double x_min, y_min, x_max, y_max; //Base in XY-Plane
	double axis_base_rad;               //Axis's base radius
	Axis axis[3];
};

struct solution_pair {
	size_t f, t;         //f = from, t = to
};

//Game Settings
MyDisk discs[NUM_DISCS];
GameBoard t_board;
ActiveDisc active_disc;
list<solution_pair> sol;
bool to_solve = false;
MENU_TYPE show = MENU_HELP;

//Globals for window, time, FPS
size_t FPS = 60;
size_t prev_time = 0;
size_t window_width = 600, window_height = 600;

void initialize();
void initialize_game();
void display_handler();
void reshape_handler(int w, int h);
void keyboard_handler(unsigned char key, int x, int y);
void anim_handler();
void move_disc(int from_axis, int to_axis);
MyPoint get_inerpolated_coordinate(MyPoint v1, MyPoint v2, double u);
void move_stack(int n, int f, int t); // Hanoi Algorithem
void menu(int); // Menu handling function declaration

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(500, 10);
	glutCreateWindow("Towers of Hanoi");

	initialize();
	cout << "Solving Towers of Hanoi" << endl;
	cout << "Press H for Help" << endl;
	cout << "-----------------------------" << endl;
	cout << "Powered By: Ammar Midnai - Ammar_67532" << endl;
	cout << "Powered By: Dima Yazji - Dima_66877" << endl;
	cout << "-----------------------------" << endl;


	// Create a menu
	glutCreateMenu(menu);

	// Add menu items
	glutAddMenuEntry("Help (H)", MENU_HELP);
	glutAddMenuEntry("Solve (S)", MENU_SOLVE);
	glutAddMenuEntry("Increase Speed (+)", MENU_INCREASE_SPEED);
	glutAddMenuEntry("Decrease Speed (-)", MENU_DECREASE_SPEED);
	glutAddMenuEntry("Exit (Q, Esc)", MENU_Exit);

	// Associate a mouse button with menu
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//Callbacks
	glutDisplayFunc(display_handler);
	glutReshapeFunc(reshape_handler);
	glutKeyboardFunc(keyboard_handler);
	glutIdleFunc(anim_handler);

	glutMainLoop();
	return 0;
}

void initialize()
{
	glClearColor(0.1, 0.1, 0.1, 5.0); //Background Color
	glShadeModel(GL_SMOOTH);		  //SMOOTH Shading
	glEnable(GL_DEPTH_TEST);		  //Enabling Depth Test

									  //Setting Light0 parameters
	GLfloat light0_pos[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // A positional light
	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);

	glEnable(GL_LIGHTING);			  //Enabling Lighting
	glEnable(GL_LIGHT0);		      //Enabling Light0	

									  //Globals initializations
	prev_time = glutGet(GLUT_ELAPSED_TIME);

	//Initializing Game State
	initialize_game();
}

void initialize_game()
{
	//Initializing 1)GameBoard t_board 2) Discs discs  3) ActiveDisc active_disc
	// State

	//1) Initializing GameBoard
	t_board.axis_base_rad = 1.0;
	t_board.x_min = 0.0;
	t_board.x_max = 6.6 * t_board.axis_base_rad;
	t_board.y_min = 0.0;
	t_board.y_max = 2.2 * t_board.axis_base_rad;

	double x_center = (t_board.x_max - t_board.x_min) / 2.0;
	double y_center = (t_board.y_max - t_board.y_min) / 2.0;

	double dx = (t_board.x_max - t_board.x_min) / 3.0; //Since 3 Axis
	double r = t_board.axis_base_rad;

	//Initializing axis Occupancy value		
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t h = 0; h < NUM_DISCS; h++)
		{
			if (i == 0)
			{
				t_board.axis[i].occupancy_val[h] = NUM_DISCS - 1 - h;
			}
			else t_board.axis[i].occupancy_val[h] = -1;
		}
	}


	//Initializing Axis positions
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t h = 0; h < NUM_DISCS; h++)
		{
			double x = x_center + ((int)i - 1) * dx;
			double y = y_center;
			double z = (h + 1) * 0.3;
			MyPoint& pos_to_set = t_board.axis[i].positions[h];
			pos_to_set.x = x;
			pos_to_set.y = y;
			pos_to_set.z = z;
		}
	}

	//2) Initializing Discs
	for (size_t i = 0; i < NUM_DISCS; i++)
	{
		discs[i].position = t_board.axis[0].positions[NUM_DISCS - i - 1];
	}

	//3) Initializing Active Disc
	active_disc.disc_index = -1;
	active_disc.is_in_motion = false;
	active_disc.step_u = 0.02;         //Verify
	active_disc.u = 0.0;
	active_disc.direction = 0;
}

//Draw function for drawing a cylinder given position and radius and height
void DrawAxe(double x, double y, double r, double h)
{
	GLUquadric* q = gluNewQuadric();
	GLint slices = 50;
	GLint stacks = 10;
	glPushMatrix();
	glTranslatef(x, y, 0.0f);
	gluCylinder(q, r, r, h, slices, stacks);
	glTranslatef(0, 0, h);
	gluDisk(q, 0, r, slices, stacks);
	glPopMatrix();
	gluDeleteQuadric(q);
}

//Draw function for drawing axis on a given game board i.e. base
void DrawBoardAndAxis(GameBoard const& board)
{
	//Materials, 
	GLfloat mat_white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_yellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };

	glPushMatrix();
	//Drawing the Base Rectangle [where the axis are placed]
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_white);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex2f(board.x_min, board.y_min);
	glVertex2f(board.x_min, board.y_max);
	glVertex2f(board.x_max, board.y_max);
	glVertex2f(board.x_max, board.y_min);
	glEnd();

	//Drawing axis and Pedestals
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_yellow);

	double r = board.axis_base_rad;
	for (size_t i = 0; i < 3; i++)
	{
		MyPoint const& p = board.axis[i].positions[0];
		DrawAxe(p.x, p.y, r * 0.1, AXIS_HEIGHT - 0.1);
		DrawAxe(p.x, p.y, r, 0.1);
	}

	glPopMatrix();
}

// Draw function for drawing discs
void draw_discs()
{
	int slices = 100;
	int stacks = 10;

	double rad;

	GLfloat r, g, b;
	GLfloat emission[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat no_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat material[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	for (size_t i = 0; i < NUM_DISCS; i++)
	{
		switch (i)
		{
		case 0: r = 1.0f; g = 0.0f; b = 0.0f;
			break;
		case 1: r = 0.0f; g = 1.0f; b = 0.0f;
			break;
		case 2: r = 0.0f, g = 0.0f; b = 1.0f;
			break;
		case 3: r = 1.0f, g = 1.0f; b = 0.0f;
			break;
		case 4: r = 0.0f, g = 1.0f; b = 1.0f;
			break;
		case 5: r = 1.0f, g = 0.0f; b = 1.0f;
			break;
		default: r = g = b = 1.0f;
			break;
		};

		material[0] = r;
		material[1] = g;
		material[2] = b;
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material);

		GLfloat u = 0.0f;

		if (i == active_disc.disc_index) {
			glMaterialfv(GL_FRONT, GL_EMISSION, emission);
			u = active_disc.u;
		}

		GLfloat factor = 1.6f;
		switch (i) {
		case 0: factor = 0.2;
			break;
		case 1: factor = 0.4;
			break;
		case 2: factor = 0.6;
			break;
		case 3: factor = 0.8;
			break;
		case 4: factor = 1.0;
			break;
		case 5: factor = 1.2;
			break;
		case 6: factor = 1.4;
			break;
		default: break;
		};
		rad = factor * t_board.axis_base_rad;
		int d = active_disc.direction;

		glPushMatrix();
		glTranslatef(discs[i].position.x, discs[i].position.y, discs[i].position.z);
		double theta = acos(discs[i].normal.z);
		theta *= 180.0f / M_PI;
		glRotatef(d * theta, 0.0f, 1.0f, 0.0f);
		glutSolidTorus(0.2 * t_board.axis_base_rad, rad, stacks, slices);
		glPopMatrix();

		glMaterialfv(GL_FRONT, GL_EMISSION, no_emission);
	}
}

void display_handler()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	double x_center = (t_board.x_max - t_board.x_min) / 2.0;
	double y_center = (t_board.y_max - t_board.y_min) / 2.0;
	double r = t_board.axis_base_rad;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // M
	gluLookAt(x_center, y_center - 10.0, 3.0 * r,
		x_center, y_center, 3.0,
		0.0, 0.0, 1.0);

	glPushMatrix();
	DrawBoardAndAxis(t_board);
	draw_discs();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void reshape_handler(int w, int h)
{
	window_width = w;
	window_height = h;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void move_stack(int n, int f, int t)
{
	if (n == 1) {
		solution_pair s;
		s.f = f;
		s.t = t;
		sol.push_back(s);         //pushing the (from, to) pair of solution to a list [so that it can be animated later]
		cout << "From Axis " << f << " to Axis " << t << endl;
		return;
	}
	move_stack(n - 1, f, 3 - t - f);
	move_stack(1, f, t);
	move_stack(n - 1, 3 - t - f, t);
}

void solve()
{
	move_stack(NUM_DISCS, 0, 2);
}

void keyboard_handler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
	case 'q':
	case 'Q':
	case 'Ö':
		exit(0);
		break;
	case 'h':
	case 'H':
	case 'Ç':
		cout << "ESC: Quit" << endl;
		cout << "S: Solve" << endl;
		cout << "H: Help" << endl;
		cout << "+/-: increase/decrease Speed" << endl;
		cout << "-----------------------------" << endl;
		cout << "Powered By: Ammar Midnai - Ammar_67532" << endl;
		cout << "Powered By: Dima Yazji - Dima_66877" << endl;
		cout << "-----------------------------" << endl;
		break;
	case 's':
	case 'S':
	case 'Ó':
		if (t_board.axis[0].occupancy_val[NUM_DISCS - 1] < 0)
			break;
		solve();
		to_solve = true;
		break;
	case '+':
		if (FPS > 490) FPS = 500;
		else FPS += 10;
		cout << "(+) Speed: " << FPS / 5.0 << "%" << endl;
		break;
	case '-':
		if (FPS <= 10)FPS = 10;
		else FPS -= 10;
		cout << "(-) Speed: " << FPS / 5.0 << "%" << endl;
		break;
	default:
		break;
	};
}

void move_disc(int from_axis, int to_axis)
{

	int d = to_axis - from_axis;
	if (d > 0) active_disc.direction = 1;
	else if (d < 0) active_disc.direction = -1;

	if ((from_axis == to_axis) || (from_axis < 0) || (to_axis < 0) || (from_axis > 2) || (to_axis > 2))
		return;

	size_t i;
	for (i = NUM_DISCS - 1; i >= 0 && t_board.axis[from_axis].occupancy_val[i] < 0; i--);
	if ((i < 0) || (i == 0 && t_board.axis[from_axis].occupancy_val[i] < 0))
		return; //Either the index < 0 or index at 0 and occupancy < 0 => it's an empty Axis

	active_disc.start_pos = t_board.axis[from_axis].positions[i];

	active_disc.disc_index = t_board.axis[from_axis].occupancy_val[i];
	active_disc.is_in_motion = true;
	active_disc.u = 0.0;


	size_t j;
	for (j = 0; j < NUM_DISCS - 1 && t_board.axis[to_axis].occupancy_val[j] >= 0; j++);
	active_disc.dest_pos = t_board.axis[to_axis].positions[j];

	t_board.axis[from_axis].occupancy_val[i] = -1;
	t_board.axis[to_axis].occupancy_val[j] = active_disc.disc_index;
}

MyPoint get_inerpolated_coordinate(MyPoint sp, MyPoint tp, double u)
{
	//4 Control points
	MyPoint p;
	double x_center = (t_board.x_max - t_board.x_min) / 2.0;
	double y_center = (t_board.y_max - t_board.y_min) / 2.0;

	double u3 = u * u * u;
	double u2 = u * u;

	MyPoint cps[4]; //P1, P2, dP1, dP2


					//Hermite Interpolation [Check Reference for equation of spline]
	{
		//P1
		cps[0].x = sp.x;
		cps[0].y = y_center;
		cps[0].z = AXIS_HEIGHT + 0.2 * (t_board.axis_base_rad);

		//P2
		cps[1].x = tp.x;
		cps[1].y = y_center;
		cps[1].z = AXIS_HEIGHT + 0.2 * (t_board.axis_base_rad);

		//dP1
		cps[2].x = (sp.x + tp.x) / 2.0 - sp.x;
		cps[2].y = y_center;
		cps[2].z = 2 * cps[1].z; //change 2 * ..

								 //dP2
		cps[3].x = tp.x - (tp.x + sp.x) / 2.0;
		cps[3].y = y_center;
		cps[3].z = -cps[2].z; //- cps[2].z;


		double h0 = 2 * u3 - 3 * u2 + 1;
		double h1 = -2 * u3 + 3 * u2;
		double h2 = u3 - 2 * u2 + u;
		double h3 = u3 - u2;

		p.x = h0 * cps[0].x + h1 * cps[1].x + h2 * cps[2].x + h3 * cps[3].x;
		p.y = h0 * cps[0].y + h1 * cps[1].y + h2 * cps[2].y + h3 * cps[3].y;
		p.z = h0 * cps[0].z + h1 * cps[1].z + h2 * cps[2].z + h3 * cps[3].z;

	}

	return p;
}

void normalize(MyPoint& v)
{
	double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (length == 0.0) return;
	v.x /= length;
	v.y /= length;
	v.z /= length;
}

void anim_handler()
{
	int curr_time = glutGet(GLUT_ELAPSED_TIME);
	int elapsed = curr_time - prev_time; // in ms
	if (elapsed < 1000 / FPS) return;

	prev_time = curr_time;

	if (to_solve && active_disc.is_in_motion == false) {
		solution_pair s = sol.front();

		cout << "From : " << s.f << " To -> " << s.t << endl;

		sol.pop_front();
		int i;
		for (i = NUM_DISCS; i >= 0 && t_board.axis[s.f].occupancy_val[i] < 0; i--);
		int ind = t_board.axis[s.f].occupancy_val[i];

		if (ind >= 0)
			active_disc.disc_index = ind;

		move_disc(s.f, s.t);
		if (sol.size() == 0)
			to_solve = false;
	}

	if (active_disc.is_in_motion)
	{
		int ind = active_disc.disc_index;
		ActiveDisc& ad = active_disc;

		if (ad.u == 0.0 && (discs[ind].position.z < AXIS_HEIGHT + 0.2 * (t_board.axis_base_rad)))
		{
			discs[ind].position.z += 0.05;
			glutPostRedisplay();
			return;
		}

		static bool done = false;
		if (ad.u == 1.0 && discs[ind].position.z > ad.dest_pos.z)
		{
			done = true;
			discs[ind].normal = MyPoint(0, 0, 1);
			discs[ind].position.z -= 0.05;
			glutPostRedisplay();
			return;
		}

		ad.u += ad.step_u;
		if (ad.u > 1.0) {
			ad.u = 1.0;
		}

		if (!done) {
			MyPoint prev_p = discs[ind].position;
			MyPoint p = get_inerpolated_coordinate(ad.start_pos, ad.dest_pos, ad.u);
			discs[ind].position = p;
			discs[ind].normal.x = (p - prev_p).x;
			discs[ind].normal.y = (p - prev_p).y;
			discs[ind].normal.z = (p - prev_p).z;
			normalize(discs[ind].normal);
		}

		if (ad.u >= 1.0 && discs[ind].position.z <= ad.dest_pos.z) {
			discs[ind].position.z = ad.dest_pos.z;
			ad.is_in_motion = false;
			done = false;
			ad.u = 0.0;
			discs[ad.disc_index].normal = MyPoint(0, 0, 1);
			ad.disc_index = -1;
		}
		glutPostRedisplay();
	}
}

// Menu handling function definition
void menu(int item)
{
	switch (item)
	{
	case MENU_HELP:
		cout << "ESC: Quit" << endl;
		cout << "S: Solve" << endl;
		cout << "H: Help" << endl;
		cout << "+/-: increase/decrease Speed" << endl;
		cout << "-----------------------------" << endl;
		cout << "Powered By: Ammar Midnai - Ammar_67532" << endl;
		cout << "Powered By: Dima Yazji - Dima_66877" << endl;
		cout << "-----------------------------" << endl;
		break;
	case MENU_SOLVE:
		if (t_board.axis[0].occupancy_val[NUM_DISCS - 1] < 0)
			break;
		solve();
		to_solve = true;
		break;
	case MENU_INCREASE_SPEED:
		if (FPS > 490) FPS = 500;
		else FPS += 10;
		cout << "(+) Speed: " << FPS / 5.0 << "%" << endl;
		break;
	case MENU_DECREASE_SPEED:
		if (FPS <= 10)FPS = 10;
		else FPS -= 10;
		cout << "(-) Speed: " << FPS / 5.0 << "%" << endl;
		break;
	case MENU_Exit:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
	return;
}