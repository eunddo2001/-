#include <stdio.h>

int main(){

int v3 = 0;
int v8[52];
int byte_14002C018[52]={0x58, 0x11, 0x60, 0x11, 0x60, 0x11, 0x55, 0x11, 0x3E, 0x11, 0x8A,
                    0x11, 0x41, 0x11, 0x86, 0x11, 0x3E, 0x11, 0x77, 0x11, 0x41, 0x11,
                    0x86, 0x11, 0x7F, 0x11, 0x75, 0x11, 0x3E, 0x11, 0x72, 0x11, 0x3E,
                    0x11, 0x87, 0x11, 0x72, 0x11, 0x7D, 0x11, 0x7A, 0x11, 0x75, 0x11,
                    0x3E, 0x11, 0x7C, 0x11, 0x43, 0x11, 0x8A, 0x11};

for(int i=0;i<52;i++){
    v8[i] = v3 ^ byte_14002C018[i] - 17;
    printf("%x", v8[i]);
}

}