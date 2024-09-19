#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


struct node* InsertAtBeg(struct node* head, int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = head;
    newNode->data = val; // corrected here
    return newNode;
}

struct node* InsertAtIndex(struct node* head,int data , int index){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;       
    }
    newnode->data=data;
    newnode->next=p->next;
    p->next=newnode;
    return head;

}

struct node*InsertAtEnd(struct node*head , int data){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    int i=0;
    while(p->next!=NULL){
        p=p->next;
    }
    newNode->data=data;
    newNode->next=NULL;
    p->next=newNode;
    return head;    
}

struct node*InsertAfterNode(struct node*head,int data,struct node*prev_node){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=prev_node->next;
    prev_node->next=newNode;
    return head;

}



void traverse(struct node* ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next; // corrected here
    }
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    // link first and second nodes
    head->data = 7;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 6;
    third->next = NULL;
    //traverse(head);
    head = InsertAfterNode(head, 56,head);
    traverse(head);
    return 0;
}