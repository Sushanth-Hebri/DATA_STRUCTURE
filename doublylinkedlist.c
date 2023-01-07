//doubly linked list operation

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void create();
void display();
void insert_beg();
void delete_ele();
struct Node{
    struct Node *llink;
    int data;
    struct Node *rlink;
};
typedef struct Node node;
 node *curr,*new,*start,*temp;




int main(){
    int ch;
    int ele;
    while(1){
   
   printf("\n1.create\n 2.insert left side\n3.delete element\n4.display\n5.exit\n");
   printf("\nEeter your choice:");
   scanf("%d",&ch);
   switch(ch){
       case 1:create();
       break;
       case 2:insert_beg();
       break;
       case 3:delete_ele();
       break;
       case 4:display();
       break;
       case 5:exit(0);
       break;
       default:printf("\nwrong choice\n");
       break;
   }
   
}
}

//inserting

void create(){
   
    int choice;
    start=(node *)malloc(sizeof(node));
    printf("\nEnter elment to insert:");
    scanf("%d",&start->data);
    start->llink=NULL;
    curr=start;
    while(1){
        printf("\nDo yo want to insert another item?\n(1.yes 2.no)");
        scanf("%d",&choice);
       if(choice==1){
           new=(node *)malloc(sizeof(node));
           printf("\nenter element to insert:");
           scanf("%d",&new->data);
           curr->rlink=new;
           new->llink=curr;
           curr=new;
       }
       else{
           curr->rlink=NULL;
           return;
       }
       
    }
   
}



void insert_beg(){
    new =(node *)malloc(sizeof(node));
    printf("\nenter a new element:");
    scanf("%d",&new->data);
    if(start==NULL){
        new->llink=NULL;
        new->rlink=NULL;
        start=new;
        return;
    }
   
   
    else{
        new->rlink=start;
        start->llink=new;
        new->llink=NULL;
        start=new;
    }
   
}



void delete_ele(){
    int ele;
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    printf("enter the element to  delete\n");
    scanf("%d",&ele);
   
   
   
    if(start->data==ele){
        temp=start;
        start=start->rlink;
        start->llink=NULL;
        free(temp);
        return;
    }
   
   
    temp=start;
    while(temp!=NULL && temp->data!=ele){
        temp=temp->rlink;
    }
   if(temp==NULL){
        printf("invalid item!!!");
       return;
   }
     if(temp->data==ele ){
        temp->llink->rlink=temp->rlink;
    }
   
    if(temp->rlink!=NULL)
    temp->rlink->llink=temp->llink;
        free(temp);

    return;
}

//display
void display(){
   
    if(start==NULL){
        printf("no elements to display!\n");
        return;
    }
    temp=start;
   
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->rlink;
    }
}
