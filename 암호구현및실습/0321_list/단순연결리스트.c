#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

// phead: 리스트의 헤드 포인터의 포인터
// p: 선행 노드
// new_node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
    if (*phead == NULL) // 공백리스트인 경우
    {
        new_node->link = NULL;
        *phead = new_node;
    }
    else if (p == NULL) // p가 NULL이면 첫번째 노드로 삽입
    {
        new_node->link = *phead;
        *phead = new_node;
    }
    else // p 다음에 삽입
    {
        new_node->link = p->link;
        p->link = new_node;
    }
}

// phead: 헤드 포인터에 대한 포인터
// p: 삭제될 노드의 선행 노드
// removed: 삭제될 노드
void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
    if (p == NULL)
    {
        *phead = (*phead)->link; //(*(*phead)).link
    }
    else
    {
        p->link = removed->link;
    }
    free(removed);
}

//새로운 노드 생성 함수
ListNode *create_node(int Data, ListNode *Link)
{
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    if (new_node == NULL)
    {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    new_node->data = Data;
    new_node->link = Link;
    return new_node;
}

void display(ListNode* lst)
{
   for (int i = 0;; i++)
   {
      if (!lst)
         break;
      printf("%d번째 data는 %d입니다.\n", i, lst->data);
      lst = lst->link;
   }
}

int main()
{
    ListNode *List1 = NULL;
    ListNode *pos;

    insert_node(&List1, NULL, create_node(10, NULL));
    insert_node(&List1, NULL, create_node(20, NULL));
    insert_node(&List1, NULL, create_node(40, NULL));
    remove_node(&List1, NULL, List1);
    display(List1);
    remove_node(&List1, NULL, List1);
    display(List1);
    remove_node(&List1, NULL, List1);
    display(List1);

    return 0;
}

/*
특정 위치에 삽입 또는 삭제할 경우?
insert_node(&List1, ? , create_node(30, Null);  // 20다음에 위치
*/