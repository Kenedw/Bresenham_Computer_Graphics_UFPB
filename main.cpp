#include "main.h"


//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	// using namespace std;
	CGDraw CG;
	tuple <int,int,int,int> RGBA1 (255,0,0,255); //vermelho
	tuple <int,int,int,int> RGBA2 (0,255,0,255); //Verde
	tuple <int,int,int,int> RGBA3 (0,0,255,255); //Azul
	
	tuple <int,int> XY1 (106,300);
	tuple <int,int> XY2 (406,300);
	tuple <int,int> XY3 (256,150);
	tuple <int,int> XYsup (IMAGE_WIDTH, 0);
	tuple <int,int> XYinf (0,IMAGE_HEIGHT);
	tuple <int,int> XYini (0,0);
	tuple <int,int> XYfin (IMAGE_WIDTH,IMAGE_HEIGHT);
	

	CG.DrawLine(XYsup,XYinf,RGBA1,RGBA2);
	CG.DrawLine(XYini,XYfin,RGBA2,RGBA1);

	CG.DrawTriangle(XY1,XY2,XY3,RGBA1,RGBA1,RGBA1);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
