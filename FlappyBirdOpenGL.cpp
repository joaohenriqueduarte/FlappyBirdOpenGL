#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


static int t=0, a=0, z=1, x=0, count1=0, count2=0, c=0, i=0, y=0;	//initialize the values required
static int score=0;
static int flag=0;
static const int FPS = 60;//Ftames per Second
int m = 8000;
int n1,n2;

//Funções
void cores(int escolha){
	
	switch(escolha) {
   	
            case 0: //Preto
            		glColor3f (0.0, 0.0, 0.0);
					break;
					
			case 1: //Verde Lima
					glColor3f (0.13, 0.55, 0.13);
					break;
					
			case 2: //Branco
					glColor3f (1.0, 1.0, 1.0);
					break;
						
			case 3: //Marrom
					glColor3f (0.59, 0.29, 0.0);
					break;
						
			case 4: //Azul céu claro
					glColor3f (0.53, 0.81, 0.98);
					break;
			
			case 5: //Azul céu claro
					glColor3f (0.53, 0.81, 0.98);
					break;
					
			case 6: //Amarelo
					glColor3f (1.0, 1.0, 0.0);
					break;	
							
			case 7: //Verde Grama
					glColor3f (0.49, 0.99, 0.0);
					break;
					
	}
	
}

void cenario(int escolha){
	
					//Grama
					cores(7);
    				glLineWidth(7.0f);  // aumenta a espessura das linhas
    				glBegin(GL_LINES);
        			glVertex2f(-20,-8.3);
        			glVertex2f( 20,-8.3);   
    				glEnd();
    
    				//Terra
    				cores(3);
    				glLineWidth(5.0f);  // aumenta a espessura das linhas
    				glBegin(GL_LINES);
    				glVertex2f(-20,-8.45);
        			glVertex2f( 20,-8.45);
        			glVertex2f(-20,-8.5);
        			glVertex2f( 20,-8.5);
					glVertex2f(-20,-8.6);
        			glVertex2f( 20,-8.6); 
    				glEnd();
	
	switch(escolha) {
		
            case 0: //Dia
            		glClearColor (0.53, 0.81, 0.98, 1.0); //Fundo Dia
            
            		//Adicionar Nuvens e montanhas ao fundo
					break;
					
			case 1: //noite
					glClearColor (0.0, 0.0, 0.5, 0.0); //Fundo Noite
					//Adicionar montanhas ao fundo
					//Estrelas, ta bugado mais ta massa =D
    				cores(2);
    				glPointSize(2.0f);
    				glBegin(GL_POINTS);
		
					for(int i = -20; i<20; i++){

							glVertex2f(n1,n2);
							n1 = rand();
							n1 = n1%20;
							n2 = rand();
							n2 = n2%10;
							glVertex2f(-n1,n2);
					}    
    				glEnd();
					break;
		}
		glutPostRedisplay();
		glShadeModel (GL_FLAT);
	
}

void passaro(){
	
	cores(0); //Cor do passaro
	glPushMatrix();
	glTranslatef(-15.0+(GLfloat)a,(GLfloat)y,0.0);
	glScalef(0.1,0.08,0.08);
	glutSolidCube(1.0);
	glPopMatrix();
	
}

void canos(){
	
	cores(1); //Cor dos canos
	
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
	
	cenario(1);

	passaro();

	//Plataforma de chegada, alterar pra um cano
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
		
		case 27:
			exit(1); //ESC PARA SAIR
			break;
	

	}
}

void MenuPrincipal(int op){ //Menu Principal não terminado
	
}

void MenuInformacaoes(int op){ //Informações do Menu
	
   switch(op) { //Seleção do menu
   	
            case 0:
                    MessageBox(0,"Em desenvolvimento","Cores",MB_OK|MB_ICONINFORMATION);
                    break;
            case 1:
                    MessageBox(0,"W,S,A,D para movimentar o passaro e ESC para sair","Teclas",MB_OK|MB_ICONINFORMATION);
                    break;
            case 2:
                    MessageBox(0,"Chegar até o final sem bater nos canos","Regras",MB_OK|MB_ICONINFORMATION);
                    break;
    }
} 

void MenuMouse(){ //Menu do Mouse

int menu,submenuFundo,submenuInfo;

    submenuFundo = glutCreateMenu(cenario);
	glutAddMenuEntry("Dia",0);
	glutAddMenuEntry("Noite",1);
	
	submenuInfo = glutCreateMenu(MenuInformacaoes);
	glutAddMenuEntry("Cores",0);
	glutAddMenuEntry("Teclas",1);
	glutAddMenuEntry("Regras",2);

   	menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Informações",submenuInfo);
    glutAddSubMenu("Mapa",submenuFundo);
    
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void GerenciaMouse(int button, int state, int x, int y){ //Gerenciamento do Mouse
	
	
    if (state == GLUT_DOWN) {
        MenuMouse(); //Chamada da função menu mouse
	}
	
    if (button == GLUT_LEFT_BUTTON){ //Botão Esquerdo Muda Cor
    
	}
	
    glutPostRedisplay();
}

int main(){
	
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); //OpenGL
	glutInitWindowSize (800, 600); //Resolução
	glutInitWindowPosition (100, 100); //Posição Inicial
	glutCreateWindow("Flappy Bird Zuado"); //Nome da janela

	glutReshapeFunc(reshape);//Maximização
	glutDisplayFunc(display);//Display
	glutMouseFunc(GerenciaMouse);//Gerenciador de Mouse
	glutKeyboardFunc(keyboard); //Gerenciamento de teclado

	glutMainLoop();//Loop
	return 0;
}//Fim Main
//Fim
