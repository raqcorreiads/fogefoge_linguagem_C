# include  < stdio.h >
# include  < stdlib.h >
# inclui  " tempo.h "
# inclui  " fogefoge.h "
# inclui  " mapa.h "
# inclui  " ui.h "

MAPA m;
POSICAO heroi;
int templo = 0 ;

int  acabou () {
	POSI��O pos;

	int perdeu = ! encontraapa (&m, &pos, HEROI);
	int ganho = ! encontraapa (&m, &pos, FANTASMA);

	retorno ganho || perdeu;

}

int  ehdire��o ( char dire��o) {
	Retorna
		dire��o == ESQUERDA ||
		dire��o == CIMA ||
		dire��o == BAIXO ||
		dire��o == DIREITA;
}

void  move ( char direcao) {

	int proximox = heroi. x ;
	int proximidade = heroi. y ;

	switch (dire��o) {
		caso ESQUERDA:
			proximidade--;
			quebrar ;
		caso CIMA:
			proximox--;
			quebrar ;
		caso BAIXO:
			proximox++;
			quebrar ;
		caso DIREITA:
			pr�ximo++;
			quebrar ;
	}

	if (! podeandar (&m, HEROI, proximox, proximoy))
		retorno ;

	if ( ehpersonagem (&m, PILULA, proximox, proximoy)) {
		tempilula = 1 ;
	}

	andanomapa (&m, heroi. x , heroi. y , proximox, proximoy);
	heroi. x = pr�ximox;
	heroi. y = proximidade;
}

int  praondefantasmavai ( int xatual, int yatual,
	int * xdestino, int * ydestino) {

	int opera��es[ 4 ][ 2 ] = {
		{ xatual , yatual+ 1 },
		{ xatual+ 1 , yatual },
		{ xatual , yatual- 1 },
		{ xatual- 1 , yatual }
	};

	srand ( tempo ( 0 ));
	for ( int i = 0 ; i < 10 ; i++) {
		int posi��o = rand () % 4 ;

		if ( podeandar (&m, FANTASMA, opcoes[posicao][ 0 ], opcoes[posicao][ 1 ])) {
			*xdestino = opcoes[posicao][ 0 ];
			*ydestino = opcoes[posicao][ 1 ];
			retornar  1 ;
		}
	}

	retorna  0 ;
}

 fantasmas vazios () {
	c�pia MAPA;

	copiamapa (&copia, &m);

	for ( int i = 0 ; i < copia. linhas ; i++) {
		for ( int j = 0 ; j < copia. colunas ; j++) {
			if (copia. matriz [i][j] == FANTASMA) {

				int xdestino;
				int ydestino;

				int encontrou = praondefantasmavai (i, j, &xdestino, &ydestino);

				if (encontro) {
					andanomapa (&m, i, j, xdestino, ydestino);
				}
			}
		}
	}

	liberamapa (&copia);
}

void  explodepilula2 ( int x, int y, int somax, int somay, int qtd) {

	if (qtd == 0 ) return ;

	int novox = x+somax;
	int novoy = y+somay;

	if (! ehvalida (&m, novox, novoy)) return ;
	if ( ehparede (&m, novox, novoy)) return ;

	m. matriz [novox][novoy] = VAZIO;
	explodepilula2 (novox, novoy, somax, somay, qtd- 1 );
}

void  explodepilula () {
	if (!tempilula) return ;

	explodepilula2 (heroi. x , heroi. y , 0 , 1 , 3 );
	explodepilula2 (heroi. x , heroi. y , 0 , - 1 , 3 );
	explodepilula2 (heroi. x , heroi. y , 1 , 0 , 3 );
	explodepilula2 (heroi. x , heroi. y , - 1 , 0 , 3 );

	temp�lula = 0 ;
}

int  principal () {

	lemapa (&m);
	encontraapa (&m, &heroi, HEROI);

	fazer {
		printf ( " P�lula: %s \n " , (tempilula ? " SIM " : " N�O " ));
		imprimemapa (&m);

		char comando;
		scanf ( "  %c " , &comando);

		if ( ehdirecao (comando)) move (comando);
		if (comando == BOMBA) explodepilula ();

		fantasmas ();

	} while (! acabou ());

	liberamapa (&m);
}
