#define DOIS_BYTES 0xC0
#define TRES_BYTES 0XE0
#define QUATRO_BYTES 0XF0
#define MASCARA 0x80

int conv32_8 (FILE *arq_entrada, FILE *arq_saida) {

	char utf8;
	char utf32;
	char aux[10];
	int contador_erro = 0;

	while(fscanf(arq_entrada, %c, &utf32)!=NULL) {

		if(utf32 <= 0x007F) { // 0 -> 01111111, dentro dos padrões

			utf8 = utf32;

			fprintf(arq_saida, "%c", utf8);

			contador_erro++;
		}

		if(utf32 >= 0x0080 && utf8 <= 0x07FF) { //10000000 -> 00000111 11111111, fora dos padrões
											   //11000000 10000000 -> 11011111 10111111
			aux[0] = utf32 >> 8;
			aux[0] = aux[0] << 10;
			aux[1] = utf32 << 8;
			aux[1] = aux[1] >> 12;
			aux[2] = aux[1] >> 2;
			aux[2] = aux[1] << 2;
			aux[2] = aux[2] << 6;
			aux[3] = aux[1] << 14;
			aux[3] = aux[1] >> 14;
			aux[3] = aux[3] << 4;
			aux[4] = utf32 << 12;
			aux[4] = aux[4] >> 12;

			utf8 = DOIS_BYTES + aux[0] + aux[2] + aux[3] + aux[4];

			fprintf(arq_saida, "%x", utf8);

			contador_erro++;
		}
	}
}

