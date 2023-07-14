#include "mygl.h"
#include "definitions.h"
#include <iostream>

static void PutPixel(tPonto Ponto) {
	// ponto.y * image_width calcula o número de linhas
	// ponto.x * 4           calcula o número de colunas 
	
	int offset = Ponto.y * 4 * IMAGE_WIDTH + Ponto.x * 4;

	FBptr[offset + 0] = Ponto.cor.r;
	FBptr[offset + 1] = Ponto.cor.g;
	FBptr[offset + 2] = Ponto.cor.b;
	FBptr[offset + 3] = Ponto.cor.a;
}

static void DrawLine(tPonto pInicial, tPonto pFinal) {
	// Vaviáveis que serão utilizadas para desenhar
	tPonto Pixel, aux;
	tColor colorVariation;
	int passoY = 1;
	int dx, dy, incL, incNE, d, y, m;

	// A rasterização sempre será feito da esquerda para direita
	// Portanto verifica se o primeiro ponto é menor que o segundo
	// Caso contrário o ajusta as posições
	if (pInicial.x > pFinal.x) {
		aux.cor = pInicial.cor;
		pInicial.cor = pFinal.cor;
		pFinal.cor = aux.cor;
		DrawLine(pFinal, pInicial);
		return;
	}

	// Calcula componentes da reta
	dx = pFinal.x - pInicial.x;
	dy = pFinal.y - pInicial.y;
	m = dy / (dx + 1);
	incL = 2 * dy;
	incNE = 2 * dy - 2 * dx;
	d = 2 * dy - dx;
	y = pInicial.y;

	// Reta Decrescente
	if (pInicial.y > pFinal.y) {
		dy = -dy;
		incL = 2 * dy;
		incNE = 2 * dy - 2 * dx;
		d = 2 * dy - dx;
		passoY = -1;
	}

	// Reta Vertical
	if (pInicial.x == pFinal.x) {
		if (pInicial.y > pFinal.y) {
			aux.y = pInicial.y;
			pInicial.y = pFinal.y;
			pFinal.y = aux.y;

			aux.cor = pInicial.cor;
			pInicial.cor = pFinal.cor;
			pFinal.cor = aux.cor;
		}

		for (int y = pInicial.y; y < pFinal.y; y++) {
			Pixel.x = pInicial.x;
			Pixel.y = y;
			Pixel.cor = pInicial.cor;

			PutPixel(Pixel);
		}
		return;
	}

	// Rasterização da linha
	for (int x = pInicial.x; x <= pFinal.x; x++) {
		Pixel.x = x;
		Pixel.y = y;
		Pixel.cor = pInicial.cor;
		PutPixel(Pixel);
		if (d <= 0) {
			d += incL;
		}
		else {
			d += incNE;
			y += passoY;
		}
	}

}


static void DrawTriangle(tTriangle triangle) {
	DrawLine(triangle.ponto1, triangle.ponto2);
	DrawLine(triangle.ponto2, triangle.ponto3);
	DrawLine(triangle.ponto3, triangle.ponto1);
}




//Parametros para entradas e testes das funções
static tColor cor1 = { cor1.r = 255, cor1.g = 0, cor1.b = 0, cor1.a = 255};
static tColor cor2 = { cor2.r = 0, cor2.g = 255, cor2.b = 0, cor2.a = 255 };
static tColor cor3 = { cor3.r = 0, cor3.g = 0, cor3.b = 255, cor3.a = 255 };
static tColor cor4 = { cor4.r = 255, cor4.g = 255, cor4.b = 255, cor4.a = 255 };

static tPonto ponto1 = { ponto1.x = 256, ponto1.y = 256, ponto1.cor = cor1 };
static tPonto ponto2 = { ponto2.x = 256, ponto2.y = 500, ponto2.cor = cor2 };
static tPonto ponto3 = { ponto3.x = 500, ponto3.y = 500, ponto3.cor = cor3 };
static tPonto ponto4 = { ponto4.x = 500, ponto4.y = 256, ponto4.cor = cor3 };
static tPonto ponto5 = { ponto5.x = 500, ponto5.y = 12, ponto5.cor = cor2 };
static tPonto ponto6 = { ponto6.x = 256, ponto6.y = 12, ponto6.cor = cor3 };
static tPonto ponto7 = { ponto7.x = 12, ponto7.y = 12, ponto7.cor = cor3 };
static tPonto ponto8 = { ponto8.x = 12, ponto8.y = 256, ponto8.cor = cor3 };
static tPonto ponto9 = { ponto9.x = 12, ponto9.y = 500, ponto9.cor = cor3 };

static tTriangle triangle = { triangle.ponto1 = ponto1,
							  triangle.ponto2 = ponto5,
							  triangle.ponto3 = ponto6 };


void MyGlDraw(void)
{
	DrawTriangle(triangle);
		
}