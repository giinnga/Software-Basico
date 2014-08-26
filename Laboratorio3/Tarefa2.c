#include <stdio.h>

int isPrio(unsigned int pacote){ //0000 0000 0000 0000 0001 0000 0000 0000 -> 0000 0000 0000 0000 0000 0000 0000 0001
	pacote = pacote >> 12;
	pacote = pacote&0x0001;

	return pacote;
}

int getSeq(unsigned int pacote){
	pacote = pacote << 1;
	pacote = pacote >> 28;
	return pacote;
}

unsigned int incrSeq(unsigned int pacote){
	unsigned int sequencia = getSeq(pacote); //1111
	unsigned int um = 0x0001;
	um = um << 27;
	pacote += um;
	if(sequencia&15){
		um = um << 4;
		pacote -= um;
		return pacote;
	}
	else
		return pacote;
}

unsigned int setParity(unsigned int pacote) {
	unsigned int i,n=0;
	unsigned int pacaux = pacote = pacote << 1;
	pacote = pacote >> 1;
	for(i=32;i>0;i--){
		if(pacaux & 1)
			n++;
		pacaux = pacaux >> 1;
	}
	if(n&1){
		 printf("Impar\n"); return pacote + 0x80000000;}
	printf("Par\n");
	return pacote;
		
}
	

int main() {

	unsigned int pacote1 = 0x7801E3A2; // 0[111 1]000 0000 0001 1110 0011 1010 0010
	unsigned int pacote2 = 0x0801FBA2; // 0[000 1]000 0000 0001 1111 1011 1010 0010

	printf("prio pac1 = %s\n", isPrio(pacote1) ? "S" : "N");
	printf("prio pac2 = %s\n", isPrio(pacote2) ? "S" : "N");

	printf("seq pac1 = %x\n", getSeq(pacote1));
	printf("seq pac2 = %d\n", getSeq(pacote2));

	printf("inc pac1 = %x\n", incrSeq(pacote1));
	printf("inc pac2 = %x\n", incrSeq(pacote2));

	printf("Parity pac1 = %x\n", setParity(pacote1));
	printf("Parity pac2 = %x\n", setParity(pacote2));

	return 0;
}
