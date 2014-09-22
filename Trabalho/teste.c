int conv8_32 (FILE *arq_entrada, FILE *arq_saida, char ordem) {

	unsigned int utf32;
	unsigned int utf8;
	unsigned int aux;
	int contador_erro = 0;

	while(fscanf(arq_entrada, %x, &utf8)!=NULL) {

		if(utf8 <= 0x007F) { // 0 -> 01111111, dentro dos padrões

			aux = utf8;
			utf8 = utf8 + 0x000000;  //0000000 00000000 00000000 01111111, adiciona 1 byte
			utf8 = utf8 << 24;
			utf8 = ~utf8;
			utf32 = utf8 & aux;
			fprintf(arq_saida, %x, utf32);
			contador_erro++;
		}

		if(utf8 >= 0x0080 && utf8 <= 0x07FF) { //10000000 -> 00000111 11111111, fora dos padrões
											   //11000000 10000000 -> 11011111 10111111

			aux = 0xDFBF;
			utf8 = utf8 + 0x000000;  //adiciona 2 bytes
			utf8 = utf8 << 24;
			utf8 = ~utf8;
			utf32 = utf8 & aux;
			fprintf(arq_saida, %x, utf32);
			contador_erro++;
		}
	}
}

