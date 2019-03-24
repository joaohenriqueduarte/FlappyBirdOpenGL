//Algoritmo do jogo Flappy C Bird, desenvolvido pela equipe de Joao Henrique, Paulo Bruny e Ezau Tertuliano
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

static int t=0, a=0, z=1, x=0, count1=0, count2=0, c=0, i=0, y=0;	//inicializa��o das vari�veis
static int score=0;
static int flag=0;
static const int FPS = 60;//Frames por segundo
int m = 8000;
int n1,n2;


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
			case 8: //Cinza Medio
					glColor3f (0.86, 0.86, 0.86);
					break;
			case 9: //Cinza Escuro
					glColor3f (0.66, 0.66, 0.66);
					break;
					
	}
	
}

void cenario(int escolha){

	float x=-16.50,y=-7.72,z=1.0;
	int x1=0,x2=0,x3=0;
	int a=3,b=4,c=2,d=1,e=0;
	
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
    				
    			for(int i=0; i<28; i++){ //Repeti��es dos predios
    				
    				switch(x1) { //Estrutura de escolha da coordenada x do predio
		
            				case 0: //X do Predio 0
            						x = -16.50;
            						break;
            				case 1: //X do Predio 1
            						x = -15.25;
            						break;
            				case 2: //X do Predio 2
            						x = -14.1;
            						break;
            				case 4: //X do Predio 3
            						x = -13.0;
            						break;
            				case 5: //X do Predio 4
            						x = -11.5;
            						break;
            				case 6: //X do Predio 5
            						x = -10.25;
            						break;
            				case 7: //X do Predio 6
            						x = -9.1;
            						break;
            				case 8: //X do Predio 7
            						x = -8.0;
            						break;
            				case 9: //X do Predio 8
            						x = -6.5;
            						break;
            				case 10: //X do Predio 9
            						x = -5.25;
            						break;
            				case 11: //X do Predio 10
            						x = -4.1;
            						break;
            				case 12: //X do Predio 11
            						x = -3.0;
            						break;
            				case 13: //X do Predio 12
            						x = -1.5;
            						break;
            				case 14: //X do Predio 13
            						x = -0.25;
            						break;
            				case 15: //X do Predio 14
            						x = 0.9;
            						break;
            				case 16: //X do Predio 15
            						x = 2.0;
            						break;
            				case 17: //X do Predio 16
            						x = 3.5;
            						break;
            				case 18: //X do Predio 17
            						x = 4.75;
            						break;
            				case 19: //X do Predio 18
            						x = 5.9;
            						break;
            				case 20: //X do Predio 19
            						x = 7.0;
            						break;
            				case 21: //X do Predio 20
            						x = 8.5;
            						break;
            				case 22: //X do Predio 21
            						x = 9.75;
            						break;
            				case 23: //X do Predio 22
            						x = 10.9;
            						break;
            				case 24: //X do Predio 23
            						x = 12.0;
            						break;
            				case 25: //X do Predio 24
            						x = 13.1;
            						break;
            				case 26: //X do Predio 25
            						x = 14.2;
            						break;
            				case 27: ////X do Predio 26
            						x = 16.0;
            						break;
            		}
            		
            		switch(x2) { //Estrutura de escolha da coordenada y do predio
		
            				case 0: //Y do prédio
            						y = -7.72;
            						break;
            				case 1: //Y do prédio
            						y = -7.58;
            						break;
            				case 2: //Y do prédio
            						y = -7.7;
            						break;
            				case 3: //Y do prédio
            						y = -7.58;
            						break;
            		}
            		switch(x3) { //Estrutura de escolha da escala z do predio
		
            				case 0: //Z do prédio
            						z = 1.0;
            						break;
            				case 1: //Z do prédio
            						z = 1.3;
            						break;
            				case 2: //Z do prédio
            						z = 1.05;
            						break;
            				case 3: //Z do prédio
            						z = 1.3;
            						break;
					
						//Predios		
            			cores(9); //Cor dos prédios
            			glPushMatrix();
						glTranslatef(x,y,0.00);
						glScalef(1.0,z,0.00);
						glutSolidCube(1.0);
						glPopMatrix();
						
						x1++;
						x2++;
						x3++;
						if(x2 == 3){
							x2=0;
						}
						if(x3 == 3){
							x3=0;
						}		
			}
					
					//Janelas
					cores(8);
    				glPointSize(2.0f);
    				glBegin(GL_POINTS);
		
					for(float i = -20.0; i<16.4; i){
						for(float j = -8.15; j<-7.25; j){
							glVertex2f(i,j);
							j = j+0.20;
						}
						i = i+0.20;
					}    
    					glEnd();
	
	switch(escolha) {
		
            case 0: //Dia
            		glClearColor (0.53, 0.81, 0.98, 1.0); //Fundo Dia
            		
			cores(2);//Nuvem 1
    				glBegin(GL_POLYGON);
        			glVertex2f(-a,-c); 
        			glVertex2f(-b,-d); 
        			glVertex2f(-b, e); 
        			glVertex2f(-b, d);
        			glVertex2f(-a, c); 
        			glVertex2f( a, c); 
        			glVertex2f( b, d);  
        			glVertex2f( b, e);  
        			glVertex2f( b,-d);  
        			glVertex2f( a,-c); 
    				glEnd();//Fim da nuvem
			
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
    				//Janelas
    				cores(6);
    				glPointSize(2.0f);
    				glBegin(GL_POINTS);
    				for(float i = -20.0; i<16.4; i){
						for(float j = -8.15; j<-7.25; j){
							glVertex2f(i,j);
							j = j+0.20;
						}
						i = i+0.20;
					}    
    				glEnd();
    				
				break;
		}
		glutPostRedisplay();
		glShadeModel (GL_FLAT);
	
	}
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
	
	//cano 1
	glPushMatrix();//inferior
	glTranslatef(-12.00,-4.4,0.00);
	glScalef(1.25,8.0,0.00);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();//superior
	glTranslatef(-12.00,5.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();


	//cano 2
	glPushMatrix();//Inferior
	glTranslatef(-7.00,-3.45,0.00);
	glScalef(1.25,9.90,0.00);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();//Superior
	glTranslatef(-7.00,7.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

    //cano 3
	glPushMatrix();//Inferior
	glTranslatef(-2.00,-5.95,0.00);
	glScalef(1.25,4.9,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//Superior
	glTranslatef(-2.00,3.10,0.00);
	glScalef(1.25,11.40,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	//cano 4
	glPushMatrix();//Inferior
	glTranslatef(3.00,-3.90,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//Superior
	glTranslatef(3.00,6.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();


	//cano5
	glPushMatrix();//Inferior
	glTranslatef(8.00,-1.95,0.00);
	glScalef(1.25,12.90,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//Superior
	glTranslatef(8.00,10.00,0.00);
	glScalef(1.25,9.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	//cano 6, chegada
	glPushMatrix();//Inferior
	glTranslatef(15.00,-4.3,0.00);
	glScalef(1.25,8.25,0.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();//Superior
	glTranslatef(15.00,5.2,0.00);
	glScalef(1.25,10.00,0.00);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
}

void display(){ // Melhorar
	
	glClear (GL_COLOR_BUFFER_BIT);
	
	cenario(0); //Chamada do cenario (0 Dia e 1 Noite)

	passaro(); //Chamada do passaro
	
	canos(); //Chama os Canos
	
	glFlush();
	glutSwapBuffers();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){  //Alterar tamanho da janela
	//GLsizei largura, altura;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D (-20.0f, 20.0f, -8.5f, 8.5f);
	
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


	// Condi��o de colis�es
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
			MessageBox(0,"You Win õ/","Win",MB_OK|MB_ICONINFORMATION);
			exit(0);
		}
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}

	
}

void keyboard (unsigned char key, int x, int y){	//Adcionar mais fun��es


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

void MenuPrincipal(int op){ //Menu Principal n�o terminado
	
}

void MenuInformacaoes(int op){ //Informa��es do Menu
	
   switch(op) { //Sele��o do menu
   	
            case 0:
                    MessageBox(0,"Em desenvolvimento","Cores",MB_OK|MB_ICONINFORMATION);
                    break;
            case 1:
                    MessageBox(0,"W,S,A,D para movimentar o passaro e ESC para sair","Teclas",MB_OK|MB_ICONINFORMATION);
                    break;
            case 2:
                    MessageBox(0,"Chegar at� o final sem bater nos canos","Regras",MB_OK|MB_ICONINFORMATION);
                    break;
    }
} 

void MenuMouse(){ //Menu do Mouse

int menu,submenuFundo,submenuInfo,submenuJanela;

    submenuFundo = glutCreateMenu(cenario);
	glutAddMenuEntry("Dia",0);
	glutAddMenuEntry("Noite",1);
	
	submenuInfo = glutCreateMenu(MenuInformacaoes);
	glutAddMenuEntry("Cores",0);
	glutAddMenuEntry("Teclas",1);
	glutAddMenuEntry("Regras",2);

   	menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Informa��es",submenuInfo);
    glutAddSubMenu("Mapa",submenuFundo);
    
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void GerenciaMouse(int button, int state, int x, int y){ //Gerenciamento do Mouse
	
	
    if (state == GLUT_DOWN) {
        MenuMouse(); //Chamada da fun��o menu mouse
	}
	
    if (button == GLUT_LEFT_BUTTON){ //Bot�o Esquerdo Muda Cor
    
	}
	
    glutPostRedisplay();
}

int main(){
	
	printf("Desenvolvido por Joao Henrique, Paulo Bruni e Ezau Tertuliano \n");
	
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); //OpenGL
	glutInitWindowSize (800, 600); //Resolu��o
	glutInitWindowPosition (600, 250); //Posi��o Inicial
	glutCreateWindow("Flappy C Bird"); //Nome da janela
	glutReshapeFunc(AlteraTamanhoJanela);//Maximiza��o
	glutDisplayFunc(display);//Display
	glutMouseFunc(GerenciaMouse);//Gerenciador de Mouse
	glutKeyboardFunc(keyboard); //Gerenciamento de teclado
	
	glutMainLoop();//Loop
	return 0;
}//Fim Main
//Fim
