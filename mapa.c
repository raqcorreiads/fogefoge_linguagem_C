# include  < stdio.h >
# include  < stdlib.h >
# inclui  " mapa.h "
# inclui  < string.h >

void  lemapa (MAPA* m) {
	ARQUIVO* f;
	f = fopen ( " mapa.txt " , " r " );
	se (f == 0 ) {
		printf ( " Erro na leitura do mapa " );
		saída ( 1 );
	}

	fscanf (f, " %d  %d " , &(m-> linhas ), &(m-> colunas ));
	alocamapa (m);

	for ( int i = 0 ; i < m-> linhas ; i++) {
		fscanf (f, " %s " , m-> matriz [i]);
	}

	fechar (f);
}

void  alocamapa (MAPA* m) {
	m-> matriz = malloc ( sizeof ( char *) * m-> linhas );

	for ( int i = 0 ; i < m-> linhas ; i++) {
		m-> matriz [i] = malloc ( sizeof ( char ) * m-> colunas + 1 );
	}
}

void  copiamapa (MAPA* destino, MAPA* origem) {
	destino-> linhas = origem- > linhas ;
	destino-> vozes = origem- > vozes ;
	alocamapa (destino);
	for ( int i = 0 ; i < origem-> linhas ; i++) {
		strcpy (destino-> matriz [i], origem-> matriz [i]);
	}
}


void  liberamapa (MAPA* m) {
	for ( int i = 0 ; i < m-> linhas ; i++) {
		livre (m-> matriz [i]);
	}

	grátis (m-> matriz );
}


int  encontraapa (MAPA* m, POSICAO* p, char c) {

	for ( int i = 0 ; i < m-> linhas ; i++) {
		for ( int j = 0 ; j < m-> vocais ; j++) {
			if (m-> matriz [i][j] == c) {
				p-> x = i;
				p-> y = j;
				retornar  1 ;
			}
		}
	}

	retorna  0 ;
}

int  podeandar (MAPA* m, char personagem, int x, int y) {
	Retorna
		ehvalida (m, x, y) &&
		! ehparede (m, x, y) &&
		! ehpersonagem (m, personagem, x, y);
}

int  ehvalida (MAPA* m, int x, int y) {
	se (x >= m-> linhas )
		retorna  0 ;
	if (y >= m-> sonoros )
		retorna  0 ;

	retornar  1 ;
}

int  ehpersonagem (MAPA* m, char personagem, int x, int y) {
	Retorna
		m-> matriz [x][y] == personagem;
}

int  ehparede (MAPA* m, int x, int y) {
	Retorna
		m-> matriz [x][y] == PAREDE_VERTICAL ||
		m-> matriz [x][y] == PAREDE_HORIZONTAL;
}


void  andanomapa (MAPA* m, int xorigem, int yorigem,
	int destino, int destino) {

	char personagem = m-> matriz [xorigem][yorigem];
	m-> matriz [xdestino][ydestino] = personagem;
	m-> matriz [xorigem][yorigem] = VAZIO;

}
