#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  signed char sc = -1;
  unsigned int ui = sc;
  unsigned int ui1 = (unsigned int)((signed int) sc);
  unsigned int ui2 = (unsigned int)((unsigned char) sc);
  printf("sc=%d, ui=%u, ui1=%u, ui2=%u \n", sc, ui,ui1,ui2);
  printf("dump de sc: \n");
  dump(&sc, sizeof(sc));
  printf("dump de ui: \n");
  dump(&ui, sizeof(ui));
  printf("dump de ui1: \n");
  dump(&ui1, sizeof(ui1));
  printf("dump de ui2: \n");
  dump(&ui2, sizeof(ui2));
  return 0;
}

