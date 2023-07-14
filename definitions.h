#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define IMAGE_WIDTH  512 // número de colunas da imagem.
#define IMAGE_HEIGHT 512 // número de linhas da imagem.

__declspec(selectany) unsigned char* FBptr; //'selectany' Escolhe definição para uso por todas as referências externas e descartar o restante
											//Para o uso do definitions.h em mais de um arquivo

#endif // _DEFINITIONS_H_
