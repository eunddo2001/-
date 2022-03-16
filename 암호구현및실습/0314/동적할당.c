#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;     //동적 할당된 블록을 가리킬 포인터
    int n, i;

    printf("몇 개의 정수를 입력하고 싶으십니까?");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));

    printf("%d개의 정수를 입력해 주세요.: ", n);
    for(i=0;i<n;++i){
        scanf("%d", &p[i]);
    }
    printf("당신이 입력한 정수를 역순으로 출력합니다: ");
    for(i=n-1;i>=0;--i){
        printf("%d ", p[i]);
    }
    printf("\n");
    free(p);
    return 0;
}