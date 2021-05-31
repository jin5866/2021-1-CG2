#pragma once
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif // !STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<memory>
#include"Objects.h"
//#include "TextureManager.h"
#include <glut.h>
using namespace std;

int						m_Mouse_Coord[2];	// previous mouse coordinates
unsigned char			m_Mouse_Event[3];	// mouse event handler
float					m_Rotate[2];		// x,y
float					m_Zoom;				// view zoom

int timer = 0;
const int tickTime = 20;

GLuint texture1, texture2;

void draw_my_cube(GLfloat size);
void draw_my_Torus(double r, double c, int rSeg, int cSeg);
void Timer(int value);
void Tick(int value);

vector<unique_ptr<MyObject>> objs{};

//The Function for Load Texture File
//GLuint LoadMeshFromFile(const char* texFile)
//{
//	GLuint texture;
//	glGenTextures(1, &texture);
//	FILE* fp = NULL;
//	if (fopen_s(&fp, texFile, "rb")) {
//		printf("ERROR : No %s. \n fail to bind %d\n", texFile, texture);
//		return false;
//	}
//	int width, height, channel;
//	unsigned char* image = stbi_load_from_file(fp, &width, &height, &channel, 4);
//	fclose(fp);
//
//	//bind
//	glBindTexture(GL_TEXTURE_2D, texture);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	stbi_image_free(image);
//
//	return texture;
//}

void Initialize(void)
{
	m_Zoom = 120;
	//depth test
	glEnable(GL_DEPTH_TEST);
	//Background Color Setting
	glClearColor(0.95f, 0.95, 0.95, 1.0f);



	// Loading Texture file example:
	// GLint texture1 = LoadMeshFromFile("texture.png");
	//texture1 = LoadMeshFromFile("Contents/2.png");
	//texture2 = LoadMeshFromFile("Contents/3.png");
	objs.push_back(make_unique<MyCube>(10.0f));


}


void display()
{
	//scene buffer clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //Transformation matrix initialize 

	//according to "translation" and "rotation" adjust the  position and angle
	glTranslatef(0.0, 0.0, -m_Zoom);
	//value m_Rotate changing by mouse (ref: mouse() and motion() function)
	glRotatef(m_Rotate[0], 1.0, 0.0, 0.0);
	glRotatef(m_Rotate[1], 0.0, 1.0, 0.0);

	// *******************do something here!!*******************

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);

	GLfloat light_pos[] = { 10, 10, 0, 0 };
	GLfloat light_amnient[] = { 0.3,0.3,0.3,1.0 };
	GLfloat light_diffuse[] = { 0,0,1,1.0 };
	GLfloat light_specular[] = { 1,1,1,1 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amnient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	////glutSolidTorus(2, 5, 6, 6);
	//glBindTexture(GL_TEXTURE_2D, texture1);
	//glEnable(GL_TEXTURE_2D);
	//draw_my_cube(10);
	//
	//glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, texture2);
	////glEnable(GL_TEXTURE_2D);
	//glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
	//draw_my_cube(10);
	//glPopMatrix();

	for (auto& obj : objs) {
		glPushMatrix();
		glTranslatef(obj->transform.position[0], obj->transform.position[1], obj->transform.position[2]);
		glRotatef(obj->transform.rotation[0], 1, 0, 0);
		glRotatef(obj->transform.rotation[1], 0, 1, 0);
		glRotatef(obj->transform.rotation[2], 0, 0, 1);
		glScalef(obj->transform.scale[0], obj->transform.scale[1], obj->transform.scale[2]);
		obj->Draw();
		glPopMatrix();
	}

	
	//*******************Implemente the lighitng and texturing *******************
	//*******************Drawing your characters*******************	    

	/*glPushMatrix();
	glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();*/

	/*
	glColor3f(0.0, 0.0, 1.0);


	glPushMatrix();
	glTranslatef(0, 5, 0);
	glScalef(4.0, 1.0, 1.0);
	//instead glutWireCube -> draw_my_cube
	//draw_my_cube(3); 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -5, 0);

	//instead glutWireTorus -> draw_my_Torus
	draw_my_Torus(2, 5, 6, 6);
	glPopMatrix();*/

	glutSwapBuffers();
}


void Reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 0.1, 500); // define view frustum
	glViewport(0, 0, w, h);    //w: is width, h: is height 
}


void Mouse(int mouse_event, int state, int x, int y)
{
	//mouse x,y coordinate
	m_Mouse_Coord[0] = x;
	m_Mouse_Coord[1] = y;

	switch (mouse_event)
	{
	case GLUT_LEFT_BUTTON:
		m_Mouse_Event[0] = ((GLUT_DOWN == state) ? 1 : 0);
		break;
	case GLUT_MIDDLE_BUTTON:
		m_Mouse_Event[1] = ((GLUT_DOWN == state) ? 1 : 0);
		break;
	case GLUT_RIGHT_BUTTON:
		m_Mouse_Event[2] = ((GLUT_DOWN == state) ? 1 : 0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


void MouseMotion(int x, int y)
{
	//difference of mouse' previous coordinate and current coordinate
	int diffx = x - m_Mouse_Coord[0];
	int diffy = y - m_Mouse_Coord[1];

	m_Mouse_Coord[0] = x;
	m_Mouse_Coord[1] = y;

	if (m_Mouse_Event[0])
	{
		m_Rotate[0] += (float)0.1 * diffy;
		m_Rotate[1] += (float)0.1 * diffx;
	}
	else if (m_Mouse_Event[2]) //right button for zoom in/zoom out
	{
		m_Zoom += (float)0.1 * diffy;
	}

	glutPostRedisplay();
}


void Keyboard(unsigned char key, int x, int y)
{
	//press"q" for exit program
	switch (key)
	{
	case 'q':
		exit(0);
		break;
		// *******************do something here!!*******************
		// According to the keyboard to control the characters

	}
	glutPostRedisplay();
}



void draw_my_cube(GLfloat size) {
	//Vertices Position. Size for Scaling the cube
	GLfloat v[8][3] = {
		{0.500000 * size, -0.500000 * size, 0.500000 * size},
		{-0.500000 * size, -0.500000 * size, 0.500000 * size},
		{-0.500000 * size, 0.500000 * size, 0.500000 * size},
		{0.500000 * size, 0.500000 * size, 0.500000 * size},
		{0.500000 * size, -0.500000 * size, -0.500000 * size},
		{-0.500000 * size, -0.500000 * size, -0.500000 * size},
		{-0.500000 * size, 0.500000 * size, -0.500000 * size},
		{0.500000 * size, 0.500000 * size, -0.500000 * size}
	};
	// Face Normal
	GLfloat n[6][3] = {

		{0.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, -1.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, -1.0f, 0.0f},
		{1.0f, 0.0f, 0.0f},
		{-1.0f, 0.0f, 0.0f}
	};
	// Face Element index
	GLint faces[6][4] = {
		{0,1,2,3},
		{7,6,5,4},
		{3,2,6,7},
		{1,0,4,5},
		{0,4,7,3},
		{2,6,5,1}
	};
	//Drawing Cube
	for (int i = 0; i < 6; i++) {
		// One Cube has 6 quads
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]); //face normal
		glTexCoord2f(1.0f, 1.0f); //uv coordinate
		glVertex3fv(&v[faces[i][0]][0]);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3fv(&v[faces[i][1]][0]);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3fv(&v[faces[i][2]][0]);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
}


void draw_my_Torus(double r, double c, int rSeg, int cSeg) {
	// r: inner radius, c:outer radius
	// rSeg and cSeg: number of side and ring's segment
	const double PI = 3.1415926;
	const double TAU = 2 * PI;
	vector<float*> torus_v;		//torus's vertex
	vector<float*> torus_v_n;	//torus's vertex  normal
	vector<int*> torus_f;		//torus's face  
	vector<float*> torus_n;		//torus's face normal
	vector<float*> uv;			//torus's uv coordinate 

	// Calculte Torus Postion
	for (int i = 0; i < rSeg; i++) {
		for (int j = 0; j <= cSeg; j++) {
			for (int k = 0; k <= 1; k++) {
				float s = (i + k) % rSeg + 0.5;
				float t = j % (cSeg + 1);
				float x = (c + r * cos(s * TAU / rSeg)) * cos(t * TAU / cSeg);
				float y = (c + r * cos(s * TAU / rSeg)) * sin(t * TAU / cSeg);
				float z = r * sin(s * TAU / rSeg);
				float* new_ver = new float[3];
				new_ver[0] = (float)x, new_ver[1] = (float)y, new_ver[2] = (float)z;
				torus_v.push_back(new_ver); //save vertex position

				float u = (i + k) / (float)rSeg;
				float v = j / (float)cSeg;
				float* uv_coord = new float[2];
				uv_coord[0] = u, uv_coord[1] = v;
				uv.push_back(uv_coord);  //save uv coordinate 
			}
		}
	}

	// save the face information(vertices index)
	for (int i = 0; i < torus_v.size() - 3; i += 2)
	{
		int* new_ver = new int[4];
		new_ver[0] = i, new_ver[1] = i + 1, new_ver[2] = i + 2, new_ver[3] = i + 3;
		torus_f.push_back(new_ver);
	}

	// *******************do something here!!******************* 
	// calculate face normal
	for (int i = 0; i < torus_v.size() - 3; i += 2)
	{
		float* normal = new float[3];

		//three position in one face
		float p1[3] = { torus_v[i][0],torus_v[i][1],torus_v[i][2] };
		float p2[3] = { torus_v[i + 1][0],torus_v[i + 1][1],torus_v[i + 1][2] };
		float p3[3] = { torus_v[i + 2][0],torus_v[i + 2][1],torus_v[i + 2][2] };

		//*************calculate the face normal in there************* 
		//hint: using the cross product   

		//calcute the normal value(normal[0]:x,normal[1]:y,normal[2]:z) 
		normal[0] = 0, normal[1] = 0, normal[2] = 0;
		//save the face normal
		torus_n.push_back(normal);
	}

	// initialize the size of vertex normal(torus_v_n), the size same as vertex
	for (int i = 0; i < torus_v.size(); i++)
	{
		float* new_ver = new float[3];
		new_ver[0] = (float)0, new_ver[1] = (float)0, new_ver[2] = (float)0;
		torus_v_n.push_back(new_ver);
	}

	//*************calculate the vertex normal in there*************
	//Hint 1: The vertex normal can be calculated using the average of the adjacent face normals
	//Hint 2: In there one vertex(same id) has two adjacent faces   
	//Hint 3: Also need finding the adjacent faces of vertex which in the same position but has a different Id 


	// Drawing Torus
	for (int i = 0; i < torus_f.size(); i++)
	{
		glBegin(GL_QUAD_STRIP);
		//face normal 
		glNormal3f(-1 * torus_n[i][0], -1 * torus_n[i][1], -1 * torus_n[i][2]);
		for (int j = 0; j < 4; j++)
		{
			//uv coordinate
			glTexCoord2d(uv[torus_f[i][j]][0], uv[torus_f[i][j]][1]);
			//Vertex normal  
			//glNormal3f(-1 * torus_v_n[torus_f[i][j]][0], -1 * torus_v_n[torus_f[i][j]][1], -1 * torus_v_n[torus_f[i][j]][2]);   
			glVertex3f(torus_v[torus_f[i][j]][0], torus_v[torus_f[i][j]][1], torus_v[torus_f[i][j]][2]);
		}
		glEnd();
	}
}


int main(int argc, char* argv[]) {

	//Window generation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(400, 100); //Window position
	glutInitWindowSize(1024, 576); //Window size
	glutCreateWindow("OpenGL"); //Window name 
	//Initialize function
	Initialize();
	//callback function 
	glutDisplayFunc(display);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMotion);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(1, Timer,1);
	glutTimerFunc(tickTime, Tick, tickTime);
	glutMainLoop();
	return 0;
}

void Timer(int value) {
	timer += 1;
	glutTimerFunc(value, Timer, value);
}

void Tick(int value) {
	glutTimerFunc(tickTime, Tick, tickTime);
	for (auto& obj : objs) {
		obj->Tick(0.001 * tickTime);
	}
	glutPostRedisplay();
}

