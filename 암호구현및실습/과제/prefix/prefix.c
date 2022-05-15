#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 200

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

int is_operator(char op){
    return op=='+'||op=='-'||op=='*'||op=='/';
}

int calculate(char op, int a , int b){
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a-b;
    else if (op == '*')
        return a*b;
    else
        return a/b;   
}

void prefix(FILE *stream, StackType *s, char token){
    if (!is_operator(token)){
        if (!is_operator(s->top)){
            if(is_operator(s->stack[--(s->top)])){
                pop(s);
                pop(s);
                int value = calculate(s->stack[--(s->top)], s->top, token);
                push(s, value);
            }
        }
    }
    else
        push(s, token);   
}

int main ()
{   
    StackType *s;
    int n=0;
    char token;

    FILE *fp = fopen("prefix.in", "r");
    FILE *fout = fopen("prefix.out", "w");

    fscanf(fp, "%d", &n);
    fprintf(fout, "%d\n", n);
    fgetc(fp);

    for(int i=0;i<n;i++){
        while(token = fgetc(fp)!='\n')
        {   
            prefix(fp, s, token);
            printf("hi");
        }
        fprintf(fout, "%d\n", s->top);
    }
    printf("hi");

    fclose(fp);
    fclose(fout);

    return 0;
}