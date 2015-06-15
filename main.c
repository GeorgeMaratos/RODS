#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int L = 0, *P = NULL;

int read_problem(FILE *f) {
  int i;
  char buf[40] = {0}, *tok = NULL;
  fgets(buf,10,f);
  tok = strtok(buf," \n");
  L = atoi(tok);
  P = malloc(sizeof(int) * L);
  fgets(buf,40,f);
  tok = strtok(buf, " \n");
  for(i=0;i<L;i++) {
    P[i] = atoi(tok);
    tok = strtok(NULL, " \n");
  }
  return 0;
}

int max(int a, int b) { return (a>b) ? a:b; }

int cut_rod(int *price, int len) {
  int q = INT_MIN, i;
  if(len == 0) 
    return 0;
  for(i=1;i<=len;i++) {
    q = max(q,price[i - 1] + cut_rod(price,len-i));
  }
  return q;
}

int solve_problem(void) {
  int q = 0;
  q = cut_rod(P,L);
  printf("Maximum: %d\n",q);
  return 0;
}

int main(int argc, char **argv) {
  FILE *f = NULL;
  if(argc != 2)
    return 1;
  f = fopen(argv[1], "r");
  if(read_problem(f)) 
    return 1;
  if(solve_problem())
    return 1;
  free(P);
  return 0;
}
