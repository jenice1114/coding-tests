// https://www.acmicpc.net/problem/1969
// C11

#include <stdio.h>

#define MAX_LEN 1001

int main() {
  int N,M;
  scanf("%d %d", &N, &M);
  
  char dna[N][MAX_LEN];
  for (int i=0; i<N; i++) {
    scanf("%s", dna[i]);
  }
  
  char result[M+1];
  int hd = 0;
  for (int i=0; i<M; i++) {
    int cnt[4] ={0,}; // A, C, G, T
    for (int j=0; j<N; j++) {
      if (dna[j][i] == 'A') cnt[0]++;
      else if (dna[j][i] == 'C') cnt[1]++;
      else if (dna[j][i] == 'G') cnt[2]++;
      else if (dna[j][i] == 'T') cnt[3]++;
    }
    
    int max_count = cnt[0];
    char max_char = 'A';
    if (cnt[1] > max_count || (cnt[1] == max_count && max_char > 'C')) {
      max_count = cnt[1];
      max_char = 'C';
    }
    if (cnt[2] > max_count || (cnt[2] == max_count && max_char > 'G')) {
      max_count = cnt[2];
      max_char = 'G';
    }
    if (cnt[3] > max_count || (cnt[3] == max_count && max_char > 'T')) {
      max_count = cnt[3];
      max_char = 'T';
    }

    result[i] = max_char;
    hd += N - max_count;
  }
  result[M] = '\0';
  
  printf("%s\n%d", result, hd);
  
  return 0;
}
