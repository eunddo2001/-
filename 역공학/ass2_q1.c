#include <stdio.h>

int sub_140001300(int *a1, unsigned int a2, int *a3, int a4, char a5, char a6)
{
  int i;

  for ( i = 0; i < a2; ++i ){
    a1[i] = (a6 * i) ^ a5 ^ a3[i];
    printf("%x", a1[i]);
  }

  return 0;
}


int main(){
int Str2[24];
int aJvUlHBvxrEc1d[24] = {0x4A, 0x56, 0x28, 0x75, 0x6C, 0x7D, 0x68, 0x7D,
                          0x62, 0x76, 0x58, 0x72, 0x28, 0x45, 0x43, 0x31, 
                          0x44, 0x5B, 0x40, 0x00};
sub_140001300(Str2, 20, aJvUlHBvxrEc1d, 20, 1, 2);
}