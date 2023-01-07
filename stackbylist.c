// stack by linked list

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct NODE
{
    int data;
    struct NODE *link;
};

typedef struct NODE node;
node *R = NULL, *F = NULL;

void Insert();
void Delete();
void Display();

void Insert()
{
    node *new;
    new = (node *)malloc(sizeof(node));
    printf("\nEnter an element\n");
    scanf("%d", &new->data);
    if (R == NULL && F == NULL)
    {
        R = new;
        F = new;
        R->link = NULL;
        return;
    }
    R->link = new;
    R = new;
    R->link = NULL;
}

void Delete()
{

    if (R == NULL && F == NULL)
    {
        printf("\nQ is Empty\n");
        return;
    }
    printf("\nDeleted element is %d\n", F->data);
    F = F->link;

    if(F==NULL){
        F=NULL;
        R=NULL;
    }
}

void Display()
{
    node *temp;
    if (F == NULL && R == NULL)
    {
        printf("\nQ is Empty\n");
        return;
    }
    printf("\nQUEUE Contents\n");
    temp = F;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n1.INSERT\n2.DELETE\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("wrong choice");
            break;
        }
    }
}