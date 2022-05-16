#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 200

typedef struct
{
    int stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s)
{
    memset(s->stack, 0, sizeof(int) * MAX_STACK_SIZE);
    s->top = -1;
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, char item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->stack[++(s->top)] = item;
}

char pop(StackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->stack[(s->top)--];
}

int is_operator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int calculate(char op, int a, int b)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else
        return a / b;
}

void prefix(StackType *s, char token)
{
    push(s, token);
    while (!is_operator(s->stack[s->top]) && !is_operator(s->stack[(s->top) - 1]) && is_operator(s->stack[(s->top) - 2]))
    {
        int b = pop(s);
        int a = pop(s);
        int op = pop(s);
        int value = calculate(op, a - '0', b - '0');
        push(s, value + '0');
    }
}

int main(void)
{
    StackType *s = (StackType*)malloc(sizeof(StackType));
    int n = 0;
    char token;

    FILE *fp = fopen("prefix.in", "r");
    FILE *fout = fopen("prefix.out", "w");

    fscanf(fp, "%d", &n);
    fprintf(fout, "%d\n", n);
    fgetc(fp);

    for (int i = 0; i < n; i++)
    {
        init(s);
        while (fscanf(fp, "%c", &token) != EOF)
        {
            prefix(s, token);
            if (fgetc(fp) == '\n')
                break;
        }
        fprintf(fout, "%c\n", s->stack[s->top]);
    }

    fclose(fp);
    fclose(fout);

    return 0;
}