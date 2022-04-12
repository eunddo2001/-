// phead: 리스트의 헤드 포인터의 포인터
// node: 삽입될 노드
void insert_first(ListNode **phead, ListNode *node)
{
    if (*phead == NULL)
    {
        *phead = node;
        node->link = node;
    }
    else
    {
        node->link = (*phead)->link;
        (*phead)->link = node;
    }
}

void insert_last(ListNode **phead, ListNode *node)
{
    if (*phead == NULL)
    {
        *phead = node;
        node->link = node;
    }
    else
    {
        node->link = (*phead)->link;
        (*phead)->link = node;
        *phead = node;
    }
}