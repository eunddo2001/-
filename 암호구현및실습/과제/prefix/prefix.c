#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init(StackType *s){
    //s->stack = 0;
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top ==-1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, int item){
    if (is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->stack[++(s->top)] = item;
}

int pop(StackType *s){
    if (is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->stack[(s->top)--];
}



int main ()
{
    FILE *fp = fopen("AVL.in", "r");
    FILE *fout = fopen("AVL.out", "w");


    fclose(fp);
    fclose(fout);

    return 0;
}