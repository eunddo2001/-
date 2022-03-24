#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
}DlistNode;

// 삽입연산
// 노드 new_node를 노드 before의 오른쪽에 삽입