#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    typedef struct person
    {
        char name[10];
        int age;
        float height;
    } person;

    person a;
    person *pa;

    pa = &a;

    strcpy_s(a.name, "young");
    a.age = 30;
    a.height = 180;

    printf("%s\n", (*pa).name);
    printf("%d\n", (*pa).age);
    printf("%f\n", (*pa).height);
}