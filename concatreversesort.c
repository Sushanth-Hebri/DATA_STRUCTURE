/*Implement Single Link List with following operations
       a) Sort the linked list.
       b) Reverse the linked list.
       c) Concatenation of two linked lists*/



#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
int data;
struct Node *next;
}node;
node *head=NULL;
node * create(node *curr,int len)
{
int d;
Node *start;
    printf("Enter %d elements\n",len);
for(int i=0;i<len;i++)
{
   scanf("%d",&d);
node *temp=(node*)malloc(sizeof(node));
temp->data=d;
temp->next=NULL;
if(curr==NULL)
{
curr=temp;
start=curr;
}
else
{
curr->next=temp;
curr=temp;
}
}
return start;
}
void merge(node *curr1,node *curr2)
{
if(curr1==NULL || curr2==NULL)
{
printf("Empty Linked List\n");
return ;
}
head=curr1;
while(curr1->next)
{
curr1=curr1->next;
}
curr1->next=curr2;
printf("Merge Operation Successfull");
return ;
}
void print(node *curr)
{
node *temp=curr;
if(temp==NULL)
{
printf("Empty Linked List\n");
return;
}
while(temp)
{
printf("%d\t",temp->data);
temp=temp->next;
}
return;
}
void sort(node *curr)
{
if(curr==NULL)
{
printf("Empty linked list\n\n");
return;
}
node *temp1=curr,*temp2;
while(temp1)
{
temp2=temp1->next;
while(temp2)
{
if(temp2->data<temp1->data)
{
int d=temp1->data;
temp1->data=temp2->data;
temp2->data=d;
}
temp2=temp2->next;
}
temp1=temp1->next;
}
printf("Sorting Successfull");
return;
}
int main()
{
node *start1=NULL,*start2=NULL;
int n1,n2;
printf("enter length of 1st linked list\n");
scanf("%d",&n1);
start1=create(start1,n1);
printf("enter length of 2nd linked list\n");
scanf("%d",&n2);
start2=create(start2,n2);
printf("Two linked list are\n");
print(start1);
printf("\n\n");
print(start2);
while(1)
{
printf("\n\n1. sort 1st linked list\n2. sort 2nd linked list\n3. merge two linked list\n4. display merged linked list\n5.sort merged linked list\n6. Exit\n\n");
int ch;
scanf("%d",&ch);
switch(ch)
{
case 1:sort(start1);
     printf("\n");
      break;
   case 2:sort(start2);
   printf("\n");
      break;
case 3:merge(start1,start2);
      break;
case 4:print(head);printf("\n");
      break;
case 5:sort(head);printf("\n");
      break;
case 6:exit(1);
      break;
default:printf("Invalid input..!!\n\n");          
}
}
}
