#include <iostream>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void pushNode(struct Node** headref, int value)   {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = value;
    temp -> next = (*headref);
    (*headref) = temp;
}

void appendNode(struct Node** headref, int value)   {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headref;
    temp -> data = value;
    temp -> next = NULL;

    if(*headref == NULL){
        *headref = temp;
        return;
    }

    while(last -> next != NULL)  {
        last = last->next;
    }

    last -> next = temp;
    return;
}

void insertAfter(struct Node** headref, int value)  {
}

void traverse(struct Node* node)   {
    while(node != NULL)    {
        std::cout << node -> data << " ";
        node = node -> next;

    }
}

int main()  {

    struct  Node *head = NULL;
    for(int i=2; i<= 100000; i+=i)  {
        appendNode(&head, i);
        pushNode(&head, i-1);
    }
    traverse(head);

}
