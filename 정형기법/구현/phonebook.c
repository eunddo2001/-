#include <stdio.h>

int Name;
int Phone;
int tel[100]={-1};

int phonebook()
{
    for(int Name =1;Name<=100;Name++)
    {
        tel[Name-1]=Phone;
    }
}

int DoFindOp(int Name)
{
    if (tel[Name-1]!=-1)
    {
        printf("%d의 전화번호는 %d입니다.", Name, tel[Name-1]);
    }
    else
    {
        printf("%d의 전화번호가 저장되어 있지 않습니다", Name);
    }
}

int DoAddnameOp(int Name, int Phone)
{
    if(tel[Name-1]==-1)
    {
        tel[Name-1]=Phone;
    }
    else
    {
        printf("이미 저장되어 있는 사람입니다");
    }
}

int DoDeleteOp()
{
    if(tel[Name-1]!=-1)
    {
        tel[Name-1]=-1;
    }
    else
    {
        printf("삭제할 사람의 전화번호가 존재하지 않습니다.");
    }
}

int main()
{
    DoFindOp(name);
}