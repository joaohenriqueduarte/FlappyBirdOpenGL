//Algoritmo do jogo Flappy C Bird, desenvolvido pela equipe de Joao Henrique, Paulo Bruny e Ezau Tertuliano
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define PI 3.1415926535

static int t=0, a=0, z=1, x=0, count1=0, count2=0, c=0, i=0, y=0;	//inicializa??o das vari?veis
static int score=0; //pontuação
static int flag=0; 
static const int FPS = 60;//Frames por segundo
int m = 8000;
int n1,n2;
int opcaoCenario;


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
			case 10: //Cinza Escuro
					glColor3f (0.41, 0.41, 0.41);
					break;
			case 11: //Ambar
					glColor3f (1.0, 0.75, 0.0);
					break;				
	}	
}

void circulo(int cor, float rx, float ry, float px, float py){
	
	float angle, raio_x, raio_y;
    int i, circle_points = 1000;
	
	cores(cor);
    glPointSize(1.0);
    glBegin(GL_POLYGON);
    raio_x = rx;
    raio_y = ry;
    
    for(i = 0; i < circle_points; i++) {
    	angle = (2*PI*i)/circle_points;
    	glVertex2f(px+raio_x*cos(angle),py+raio_y*sin(angle));
    }
	glEnd();
}

void luasol(int escolha){
     
		switch(escolha) {
		
            case 0: //Sol
            	circulo(11,4.2,3.0,-15.0,5.0);//Cor,Raio X, Raio Y, Posição X, Posição Y
            	circulo(6,3.9,2.8,-15.0,5.0);//Cor,Raio X, Raio Y, Posição X, Posição Y
            	break;
            				
            case 1: //Lua
            	circulo(8,4.1,3.0,-15.0,5.0); //Cor,Raio X, Raio Y, Posição X, Posição Y
            	circulo(10,0.3,0.2,-16.3,3.5);//Cor,Raio X, Raio Y, Posição X, Posição Y
            	circulo(10,0.8,0.6,-14.0,5.5);//Cor,Raio X, Raio Y, Posição X, Posição Y
            	circulo(10,0.6,0.4,-15.0,7.1);//Cor,Raio X, Raio Y, Posição X, Posição Y
            	break;
            case 2: //Lua nova
            				
            	break;
		}
}

void nuvens(){ //Ainda vou terminar
	
	int a=3,b=4,c=2,d=1,e=0;
	cores(2);
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
    
    	glPushMatrix();//inferior
		glTranslatef(9.00,4.4,0.00);
		glScalef(8.5,2.5,0.00);
		glutSolidCube(1.0);
		glPopMatrix();
		circulo(2,1.6,1.25,4.6,4.4);//Cor,Raio X, Raio Y, Posição X, Posição Y
		circulo(2,1.6,1.25,13.4,4.4);//Cor,Raio X, Raio Y, Posição X, Posição Y
	
}

void janelas(int cor){
	
	cores(cor);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
		for(float i = -17.0; i<16.4; i = i+0.20){
			for(float j = -8.15; j<-7.25; j = j+0.20){
				glVertex2f(i,j);
			}
		} 
   glEnd();	
}

void predios(){
	
	float vetorx[28] = {-16.50,-15.25,-14.1,-13.0,-11.5,-10.25,-9.1,-8.0,-6.5,-5.25,-4.1,-3.0,-1.5,-0.25,
						0.9,2.0,3.5,4.75,5.9,7.0,8.5,9.75,10.9,12.0,13.1,14.2,16.0};
	float vetory[28] = {-7.72,-7.58,-7.7,-7.58,-7.72,-7.58,-7.7,-7.58,-7.72,-7.58,-7.7,-7.58,-7.72,-7.58,
						-7.7,-7.58,-7.72,-7.58,-7.7,-7.58,-7.72,-7.58,-7.7,-7.58,-7.72,-7.58,-7.7,-7.58};
	float vetorz[28] = {1.0,1.3,1.05,1.3,1.0,1.3,1.05,1.3,1.0,1.3,1.05,1.3,1.0,1.3,
						1.05,1.3,1.0,1.3,1.05,1.3,1.0,1.3,1.05,1.3,1.0,1.3,1.05,1.3};
	
	cores(9);
    	for(int i=0; i<28; i++){ //Repetição dos predios
					
        	glPushMatrix();
			glTranslatef(vetorx[i],vetory[i],0.00);
			glScalef(1.0,vetorz[i],0.00);
			glutSolidCube(1.0);
			glPopMatrix();	
		}
}

void cenario(int escolha){
					
	opcaoCenario = escolha;
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
	
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
    			
				predios();
				janelas(8);
	
	switch(escolha) {
		
            case 0: //Dia
            		glClearColor (0.53, 0.81, 0.98, 1.0); //Fundo Dia
            		luasol(0);
    				nuvens();
			  		break;
					
			case 1: //noite
					glClearColor (0.0, 0.0, 0.5, 0.0); //Fundo Noite
					luasol(1);
					
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
    				janelas(6);	
					break;
		}
	glutPostRedisplay();
	glShadeModel (GL_FLAT);
}

void passaro(){
	//Define o quadrado que eh a base do passaro
	cores(6); //Cor do passaro
	glPushMatrix();
	glTranslatef(-15.0+(GLfloat)a,(GLfloat)y,0.0);
	glScalef(0.1,0.08,0.08);
	glutSolidCube(6.0);
	
	//define a asa do passaro
	cores(1);
	glRotatef(45.0f,0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
               glVertex2f(-2.0f, -2.0f);
               glVertex2f(0.0f, 7.0f);
               glVertex2f(2.0f, -2.0f);              
    glEnd();
    
    //define o bico do passaro
    cores(0);
	glRotatef(230.0f,0.0f, 0.0f, 1.0f);
	glTranslatef(1.0f, 4.0f, 0.0f);
    glBegin(GL_TRIANGLES);
               glVertex2f(-1.0f, -1.0f);
               glVertex2f(0.0f, 2.0f);
               glVertex2f(1.0f, -1.0f);              
    glEnd();
	glPopMatrix();
	
}

void canos(){
	
	float vx[12] = {-12.0,-12.0,-7.0,-7.0,-2.0,-2.0,3.0,3.0,8.0,8.0,15.0,15.0};
	float vy[12] = {-4.4,5.0,-3.45,7.0,-5.95,3.10,-3.90,6.0,-1.95,10.0,-4.3,5.2};
	float vz[12] = {8.0,9.0,9.90,9.0,4.9,11.4,9.0,9.0,12.90,9.0,8.25,10.0};
	
	cores(1);//Cor do cano
	for(int i = 0; i<12; i++){
		
		glPushMatrix();
		glTranslatef(vx[i],vy[i],0.00);
		glScalef(1.25,vz[i],0.00);
		glutSolidCube(1.0);
		glPopMatrix();
		
	}	
}

void display(){ // Melhorar
	
	glClear (GL_COLOR_BUFFER_BIT);
	cenario(opcaoCenario); //Chamada do cenario (0 Dia e 1 Noite)
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

void timer(int value){
	//Continua a incrementar o X do movimento
	if(z==1){
		a=a+1;
		glutPostRedisplay();
		glutTimerFunc(m/FPS,timer,value);
	}
	
	else if(z==2){
		a=0;y=0;
		glutPostRedisplay();
	}

	//w - move para cima
	else if(z==3){
		
		y=(y+1)%9;
		glutPostRedisplay();
		z=1;
		glutTimerFunc(m/FPS,timer,value);
	}
	//s - move para baixo
	else if(z==4){
		
		y=(y-1)%9;
		glutPostRedisplay();
		z=1;
		glutTimerFunc(m/FPS,timer,value);
	}

	// Condi??o de colis?es
	if(a==3){
		
		flag=1;
		if(y==0)
			score++;
		else{
			printf("\n\nSCORE : %d\n",score);
			MessageBox(0,"You Lose :(","Lose",MB_OK|MB_ICONINFORMATION);
			exit(0);
		}
	}
	else if(a==8&&flag==1){
		flag=2;
		if(y==2||y<=-8)
			score++;
		else{
			printf("\n\nSCORE : %d\n",score);
			MessageBox(0,"You Lose :(","Lose",MB_OK|MB_ICONINFORMATION);
			exit(0);
		}
	}
	else if(a==13&&flag==2){
		flag=3;
		if(y==-3||y>=7)
			score++;
		else{
			printf("\n\nSCORE : %d\n",score);
			MessageBox(0,"You Lose :(","Lose",MB_OK|MB_ICONINFORMATION);
			exit(0);
		}
	}
	else if(a==18&&flag==3){
		flag=4;
		if(y==1)
			score++;
		else{
			printf("\n\nSCORE : %d\n",score);
			MessageBox(0,"You Lose :(","Lose",MB_OK|MB_ICONINFORMATION);
			exit(0);
		}
	}
	else if(a==23&&flag==4){
		flag=5;
		if(y==5||y<=-5)
			score++;
		else{
			printf("\n\nSCORE : %d\n",score);
			MessageBox(0,"You Lose :(","Lose",MB_OK|MB_ICONINFORMATION);
			exit(0);
		}
	}
	else if(a==30&&flag==5){
		if(y==0){
			MessageBox(0,"You Win õ/","Win",MB_OK|MB_ICONINFORMATION);
			exit(0);
		}
		else{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}	
}

void keyboard (unsigned char key, int x, int y){	//Adcionar mais fun??es

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

void TrocaDificuldade(int opcao){
	m = opcao;
}

void MenuPrincipal(int op){ //Menu Principal n?o terminado	
}

void MenuInformacaoes(int op){ //Informa??es do Menu
	
   switch(op) { //Sele??o do menu
   	
            case 0:
                    MessageBox(0,"W,S,A,D para movimentar o passaro e ESC para sair","Teclas",MB_OK|MB_ICONINFORMATION);
                    break;
            case 1:
                    MessageBox(0,"Chegar ate o final sem bater nos canos","Regras",MB_OK|MB_ICONINFORMATION);
                    break;
    }
} 

void MenuMouse(){ //Menu do Mouse

int menu,submenuFundo,submenuInfo,submenuJanela, submenuDificuldade;

    submenuFundo = glutCreateMenu(cenario); //Esta funcao nao esta mudando o cenario, o cenario esta sendo gerado estaticamente la funcao display, precisamos resolver
	glutAddMenuEntry("Dia",0);
	glutAddMenuEntry("Noite",1);
	
	submenuInfo = glutCreateMenu(MenuInformacaoes);
	glutAddMenuEntry("Teclas",0);
	glutAddMenuEntry("Regras",1);
	
	submenuDificuldade = glutCreateMenu(TrocaDificuldade);
	glutAddMenuEntry("Mel na chupeta", 8000);
	glutAddMenuEntry("Fica ligado", 6500);
	glutAddMenuEntry("Num vai dar nao", 4000);

   	menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Informacoes",submenuInfo);
    glutAddSubMenu("Mapa",submenuFundo);
    glutAddSubMenu("Dificuldade",submenuDificuldade);
    
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void GerenciaMouse(int button, int state, int x, int y){ //Gerenciamento do Mouse
	
    if (state == GLUT_DOWN) {
        MenuMouse(); //Chamada da funcao menu mouse
	}
	
    if (button == GLUT_LEFT_BUTTON){ //Botao Esquerdo Muda Cor
    
	}
    glutPostRedisplay();
}

int main(){
	
	printf("Desenvolvido por Joao Henrique, Paulo Bruny e Ezau Tertuliano \n");
	
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); //OpenGL
	glutInitWindowSize (800, 600); //Resolucao
	glutInitWindowPosition (0, 0); //Posicao Inicial definido para o canto superior de qualquer tela
	glutCreateWindow("Flappy C Bird"); //Nome da janela
	glutReshapeFunc(AlteraTamanhoJanela);//Maximiza??o e redimensionamento da janela
	glutDisplayFunc(display);//Display
	glutMouseFunc(GerenciaMouse);//Gerenciador de Mouse
	glutKeyboardFunc(keyboard); //Gerenciamento de teclado
	
	glutMainLoop();//Loop
	return 0;
}//Fim Main
//Fim
