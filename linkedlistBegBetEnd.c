#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedlistTraversal(struct Node* ptr){
    while (ptr != NULL){
  
    printf("Element:%d\n", ptr->data);
    ptr = ptr->next;
    }
}
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    ptr ->next= head;
    return ptr;

}


struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next=ptr;
    return head; 
}

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    struct Node * p = head;
    while(p->next!=NULL){
    p = p->next;

    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}


struct Node * insertAtAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    ptr->next = prevNode->next;
    prevNode->next=ptr;
    return head;
}



int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head-> next = second;

    second->data=14;
    second-> next = third;

    third->data=21;
    third-> next = NULL;
    printf("linked list before insertion\n");
    linkedlistTraversal(head);
    //head = insertAtFirst(head, 88);
 //   head = insertAtIndex(head, 88, 1);
  //  head = insertAtEnd(head, 88);
    head = insertAtAfterNode(head, second, 99);
    printf("linked list after insertion\n");
    linkedlistTraversal(head);
    return 0;

}