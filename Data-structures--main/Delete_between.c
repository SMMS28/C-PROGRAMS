#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void Traverse(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("The Element: % d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node *DeleteBetween(struct Node *ptr,int pos)
{
    struct Node * p=ptr;
    int i=0;
    while(i!=pos-1)
    {
        p=p->next;
        i++;
    }
    struct Node *q=p->next;
    p->next=q->next;
    free(q);
    return ptr;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node*)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct Node*));
    fourth=(struct Node*)malloc(sizeof(struct Node*));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;
    
    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    Traverse(head);
    head=DeleteBetween(head,2);
    printf("After deletion of node in btw nodes:\n");
    Traverse(head);
    return(0);
}
