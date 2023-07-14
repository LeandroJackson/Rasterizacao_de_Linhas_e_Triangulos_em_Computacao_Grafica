#ifndef _MYGL_H_
#define _MYGL_H_

void MyGlDraw(void);

//*****************************************************************************
typedef struct {
	int r;
	int g;
	int b;
	int a;
} tColor;

typedef struct {
	int x;
	int y;
	tColor cor;
} tPonto;

typedef struct {
	tPonto ponto1;
	tPonto ponto2;
	tPonto ponto3;
} tTriangle;

static void PutPixel(tPonto Ponto);
static void DrawLine(tPonto pInicial, tPonto pFinal);
static void DrawTriangle(tTriangle triangle);
//*****************************************************************************

#endif // _MYGL_H_
