#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

//스택 초기화 함수
void init(StackType *s){
    s->top = -1;
}

//공백 상태 검출 