#include "Render.h"
#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <math.h>
#include <vector>
using namespace std;

#define _USE_MATH_DEFINES
# define M_PI           3.14159265358979323846  /* pi */


void VIPYK()
{
	double C[] = { 0, 0, 0 };
	double D[] = { 9.5, 0, 0 }; 
	double O[3];//середина CD
	double povorot = -180;


	O[0] = (C[0] + D[0]) / 2;
	O[1] = (C[1] + D[1]) / 2;
	O[2] = 0;

	double radius = (sqrt(pow((C[0] - D[0]), 2) + pow((C[1] - D[1]), 2) + pow((C[2] - D[2]), 2))) / 2; // расстояние между двумя точками
	vector <double> x; // вектора для точек на окружности
	vector <double> y;
	

	for (double i = povorot; i <= (180 + povorot + 1); i += 0.1)
	{
		x.push_back(radius * cos(i * M_PI / 180.0) + O[0]); // функция push_back добавляет значение в конец
		y.push_back(radius * sin(i * M_PI / 180.0) + O[1]);
	}

	glColor3d(0.7, 0.4, 0.8);
	glBegin(GL_POLYGON);
	for (int i = 0; i < x.size() - 1; i++)
	{
		glVertex3d(x[i], y[i], 0);
		glVertex3d(x[i + 1], y[i + 1], 0);
	}
	glEnd();


	glBegin(GL_POLYGON);
	for (int i = 0; i < x.size() - 1; i++)
	{
		glVertex3d(x[i], y[i], 2);
		glVertex3d(x[i + 1], y[i + 1], 2);
	}
	glEnd();

	glColor3d(0.1, 0.6, 0.9);
	glBegin(GL_QUADS);
	for (int i = 0; i < x.size() - 1; i++)
	{
		glVertex3d(x[i], y[i], 0);
		glVertex3d(x[i], y[i], 2);
		glVertex3d(x[i + 1], y[i + 1], 2);
		glVertex3d(x[i + 1], y[i + 1], 0);
	}
	glEnd();




}

void TELO_NIZ()
{
	glBegin(GL_TRIANGLES);
	glColor3d(1, 0, 0.2);

	glVertex3d(9.5, 0, 0);
	glVertex3d(2.8, 5.4, 0);
	glVertex3d(0, 0, 0);

	glColor3d(1, 0, 0.2);
	glVertex3d(2.8, 5.4, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(-3, 6.9, 0);

	glColor3d(1, 0.3, 0.7);
	glVertex3d(-3, 6.9, 0);
	glVertex3d(2.8, 5.4, 0);
	glVertex3d(6.6, 10, 0);

	glColor3d(0, 0, 0.7);
	glVertex3d(2.8, 5.4, 0);
	glVertex3d(14.84, 4.8, 0);
	glVertex3d(6.6, 10, 0);

	glColor3d(0.4, 0, 0);
	glVertex3d(14.84, 4.8, 0);
	glVertex3d(6.6, 10, 0);
	glVertex3d(6.78, 13.9, 0);

	glEnd();
}

void TELO_VERH()
{
	glBegin(GL_TRIANGLES);
	glColor3d(1, 0, 0.2);

	glVertex3d(9.5, 0, 2);
	glVertex3d(2.8, 5.4, 2);
	glVertex3d(0, 0, 2);

	glColor3d(1, 0, 0.2);
	glVertex3d(2.8, 5.4, 2);
	glVertex3d(0, 0, 2);
	glVertex3d(-3, 6.9, 2);

	glColor3d(1, 0.3, 0.7);
	glVertex3d(-3, 6.9, 2);
	glVertex3d(2.8, 5.4, 2);
	glVertex3d(6.6, 10, 2);

	glColor3d(0, 0, 0.7);
	glVertex3d(2.8, 5.4, 2);
	glVertex3d(14.84, 4.8, 2);
	glVertex3d(6.6, 10, 2);

	glColor3d(0.2, 1, 1);
	glVertex3d(14.84, 4.8, 2);
	glVertex3d(6.6, 10, 2);
	glVertex3d(6.78, 13.9, 2);

	glEnd();
}

void TYLOVISHE_TELA()
{
	glBegin(GL_QUADS);
	glColor3d(0.2, 0.7, 0.7);
	glVertex3d(9.5, 0, 2);
	glVertex3d(9.5, 0, 0);
	glVertex3d(2.8, 5.4, 0);
	glVertex3d(2.8, 5.4, 2);

	glColor3d(0.2, 0.6, 0.1);
	glVertex3d(2.8, 5.4, 0);
	glVertex3d(2.8, 5.4, 2);
	glVertex3d(14.84, 4.8, 2);
	glVertex3d(14.84, 4.8, 0);

	glColor3d(1, 0.7, 0.2);
	glVertex3d(14.84, 4.8, 2);
	glVertex3d(14.84, 4.8, 0);
	glVertex3d(6.78, 13.9, 0);
	glVertex3d(6.78, 13.9, 2);

	glColor3d(0.2, 1, 0.1);
	glVertex3d(6.78, 13.9, 0);
	glVertex3d(6.78, 13.9, 2);
	glVertex3d(6.6, 10, 2);
	glVertex3d(6.6, 10, 0);

	glColor3d(0.1, 0, 0.9);
	glVertex3d(6.6, 10, 2);
	glVertex3d(6.6, 10, 0);
	glVertex3d(-3, 6.9, 0);
	glVertex3d(-3, 6.9, 2);

	glColor3d(1, 1, 0.7);
	glVertex3d(-3, 6.9, 0);
	glVertex3d(-3, 6.9, 2);
	glVertex3d(0, 0, 2);
	glVertex3d(0, 0, 0);






	glEnd();
}
void Render(double delta_time)
{

	
	TELO_NIZ();
	TELO_VERH();
	TYLOVISHE_TELA();
	VIPYK();




}


