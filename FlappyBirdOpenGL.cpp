#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>


static int t=0, a=0, z=1, x=0, count1=0, count2=0, c=0, i=0, y=0;	//initialize the values required
static int score=0;
static int flag=0;
static const int FPS = 60;//Ftames per Second
int m = 8000;

void fundo(){ // Adicionar nuvens
	glClearColor (1.0, 1.0, 1.0, 1.0); // Cor do fundo
	glShadeModel (GL_FLAT);

}

void passaro(){
	
	glColor3f (0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-15.0+(GLfloat)a,(GLfloat)y,0.0);
	glScalef(0.1,0.08,0.08);
	glutSolidCube(1.0);
	glPopMatrix();
	
}

void canos(){
	
	//canos 1 b
	glPushMatrix();
	glTranslatef(-12.00,-5.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-12.00,5.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();


	//canos 2
	glPushMatrix();
	glTranslatef(-7.00,-3.0,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.00,7.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-2.00,-8.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.00,2.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(3.00,-4.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.00,6.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(8.00,0.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.00,10.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();
	
}

void display(void){ // Melhorar
	
	glClear (GL_COLOR_BUFFER_BIT);

	passaro();

	//Plataforma de chegada
	glColor3f (1.0, 0.0, 0.2);
	glPushMatrix();
	glScalef(1.00,0.3,0.3);
	glTranslatef(15.0,0.0,0.0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	canos();
	
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h)	{ //Alterar tamanho da janela

	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 0.2, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
}

void timer(int value){ //Estudar

	//Incrementation
	//X translation...Continous.
	if(z==1)
	{
		a=a+1;
		glutPostRedisplay();
		glutTimerFunc(m/FPS,timer,value);
	}
	//Back to Pavalion..
	else if(z==2)
	{
		a=0;y=0;
		glutPostRedisplay();
	}

	//w..move up
	else if(z==3)
	{
		y=(y+1)%9;
		glutPostRedisplay();
		z=1;
		glutTimerFunc(m/FPS,timer,value);
	}
	//s..move down
	else if(z==4)
	{
		y=(y-1)%9;
		glutPostRedisplay();
		z=1;
		glutTimerFunc(m/FPS,timer,value);
	}

		//printf("\t%d\t%d\n",a,y);


	// Collision Conditions
	if(a==3)
	{
		flag=1;
		if(y==0)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==8&&flag==1)
	{
		flag=2;
		if(y==2||y<=-8)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==13&&flag==2)
	{
		flag=3;
		if(y==-3||y>=7)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==18&&flag==3)
	{
		flag=4;
		if(y==1)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==23&&flag==4)
	{
		flag=5;
		if(y==5||y<=-5)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==30&&flag==5)
	{
		if(y==0)
		{
			printf("\n\n*************************************\n\t-----------\n\t| YOU WON |\n\t-----------\n*************************************\n\n");
			exit(0);
		}
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}

	
}

void keyboard (unsigned char key, int x, int y){	//Estudar


	switch (key){

		case 'w':
			z=3;
		break;

		case 's':
			z=4;
		break;

		case 'a':
			z=2;
		break;

		case 'd':

			z=1;
			glutTimerFunc(100,timer,0);
		break;

	}
}

int main(int argc, char** argv){
	

	glutInit(&argc, argv);

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize (800, 600);

	glutInitWindowPosition (100, 100);
	
	glutCreateWindow (argv[0]);
	fundo();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}

