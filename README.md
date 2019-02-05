# Computer-Graphics-UFPB
---

## Menu

* [Introdução](#introdução)
* [Framework](#framework)
* [Funções Propostas](#funções-propostas)
	* [Rasterização de ponto](#rasterização-de-ponto)
* [Digital Differential Analyzer](#digital-differential-analyzer)
* [Bresenham Algorithm](#bresenham-algorithm)
* [Drawing Triangles](#drawing-triangles)
* [Conclusion](#conclusion)
* [References](#references)
* [Build Instructions](#build-instructions)

---

### Introdução
Este artigo é destinado ao primeiro trabalho da disciplina de Introdução a Computação Grafica, ministrada pelo professor Christian Azambuja Pagot, o qual desenvolvel a framework em uso.

---

### Framework
O framework usado, foi desenvolvido pelo professor Christian, ao qual simula o acesso a memoria, através de um ponteiro FBptr, já que os sistemas operacionais não permitem este acesso.

---

#### Funções Propostas
Foi proposto a implementação de tres funções neste trabalho, usando o algorítimo de rasterização de [Bresenham](https://pt.wikipedia.org/wiki/Algoritmo_de_Bresenham), em que faz o desenho de linhas em sistemas matriciais, que nos permiti determinar quais os pontos devem ser coloridos; mas para isto devemos primeiramente saber desenhar um ponto, um pixel.
Isto nos leva a primeira função, "PutPixel"

#### PutPixel
Para se desenhar um pixel, primeiro devemos entender o que é um pixel. Pixel é o menor elemento em um dispositivo de exibição (como por exemplo o monitor), em que podemos designar uma cor, como em uma imagem digital, ele é o menor ponto que forma uma imagem.

<p align="center">
	<br>
	<img src="./prints/pixel.jpg"/ width=600px height=400px>
	<h5 align="center">Figure 1 - pixel</h5>
	<br>
</p>

No nosso caso, cada pixel recebe 4 bytes como informações de cor, uma para o vermelho, uma para o azul , uma para o verde e o alfa, que controla a transparência do nosso pixel. Os pixel são endereçados na memoria, como pontos de coordenadas (x,y), levando em conta que a o número de pixels na tela é dado pela multiplicação de número de linhas pelo número de colunas, a memória deve ter esta mesma quantidade de posições para representar a tela, só que de forma linear.

Agora que sabemos o que é um pixel e como ele é endereçado, veremos como desenha-lo em C++, utilizando a framework já citada. 

```C++
void  MyGlDraw(void)
{
	// ***********************************************************
	// Chame aqui as funções do mygl.h
	// ***********************************************************
	CGDraw CG;
	tuple <int,int,int,int>  RGBA1 (255,0,0,255); //vermelho
	tuple <int,int>  XY1 (100,100); //Posição

	CG.PutPixel(XY1,RGBA1);
}
```

```C++
void  CGDraw::PutPixel(tuple<int, int> XY, tuple<int, int, int, int> RGBA)
{
	int R, G, B, A;
	int x, y;

	tie(R, G, B, A) = RGBA;
	tie(x, y) = XY;
	if (x > IMAGE_WIDTH || x <  0  || y > IMAGE_HEIGHT || y <  0)//verifica se ta desenhando fora
		return;
	
	FBptr[(4  * x) + (4  * y * IMAGE_HEIGHT) +  0] = R; // componente R
	FBptr[(4  * x) + (4  * y * IMAGE_HEIGHT) +  1] = G; // componente G
	FBptr[(4  * x) + (4  * y * IMAGE_HEIGHT) +  2] = B; // componente B
	FBptr[(4  * x) + (4  * y * IMAGE_HEIGHT) +  3] = A; // componente A
}
```
A função a cima recebe:
1. XY é a posição a ser desenhada na tela.
2. RGBA informações de cor.

<p align="center">
	<br>
	<img src="./prints/putPixel.jpg"/ width=510px height=540px>
	<h5 align="center">Figure 2 - Pixel vermelho desenhado na tela</h5>
	<br>
</p>

---