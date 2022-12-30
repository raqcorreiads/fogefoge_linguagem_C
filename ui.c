# include  < stdio.h >
# inclui  " mapa.h "

char desenhoparede[ 4 ][ 7 ] = {
	{ " ...... " },
	{ " ...... " },
	{ " ...... " },
	{ " ...... " }
};

char desenhofantasma[ 4 ][ 7 ] = {
	{ " .-.   " },
	{ " | OO| " },
	{ " | | " },
	{ " '^^^' " }
};

char desenhoheroi[ 4 ][ 7 ] = {
	{ " .--. "   },
	{ " / _.-' "   },
	{ " \\   '-. " },
	{ " '--' "   }
};

char desenhopilula[ 4 ][ 7 ] = {
	{ "       " },
	{ " .-.   " },
	{ " '-'   " },
	{ "       " }
};

char desenhovazio[ 4 ][ 7 ] = {
	{ "       " },
	{ "       " },
	{ "       " },
	{ "       " }
};

void  imprimeparte ( char desenho[ 4 ][ 7 ], int parte) {
	printf ( " %s " , desenho[parte]);
}

void  imprimemapa (MAPA* m) {
	for ( int i = 0 ; i < m-> linhas ; i++) {

		for ( int parte = 0 ; parte < 4 ; parte++) {
			for ( int j = 0 ; j < m-> vocais ; j++) {

				switch (m-> matriz [i][j]) {
					caso FANTASMA:
						imprimeparte (desenhofantasma, parte);
						quebrar ;
					Caso HERÓI:
						imprimeparte (desenhoheroi, parte);
						quebrar ;
					caso PILULA:
						imprimeparte (desenhopilula, parte);
						quebrar ;
					caso PAREDE_VERTICAL:
					caso PAREDE_HORIZONTAL:
						imprimeparte (desenhoparede, parte);
						quebrar ;
					caso VAZIO:
						imprimeparte (desenhovazio, parte);
						quebrar ;
				}

			}
			printf ( " \n " );
		}

	}
}
