#include<stdio.h>

#include<stdlib.h>
void insert();
void delete();
void display();
int f=-1,r=-1,size=4,q[4],choice,item,del,i;
//main function

void main()
{
    printf("Enter the size of queue:");
    scanf("%d",&size);
    while(1)
    {
        printf("\noperations on circular queue\n");
        printf("\n1.insert 2.delete 3.display 4.exit\n");
        printf("\nEnter you choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:printf("wrong choice");
        }
       
    }
}
    void insert()
    {
        //check whether queue is full or not
        if(f==0 && r==(size-1) || f==r+1)
        {
       
        printf("queue is full");
        return;
        }
        //else update pointers
      else  if(f==-1 && r==-1)
        {
            f=0;
            r=0;
        }
      else r=((r+1)%size);
      //insert element
      printf("enter the element to insert:");
      scanf("%d",&item);
      q[r]=item;
     
    }
   
    void delete()
    {
        //check for empty queue
   
        if(f==-1 && r==-1)
        {
            printf("queue is empty!");
            return;
        }
        else{
        del=q[f];
        printf("deleted element:%d",del);}
        //update pointers
        if(f==r)
        {
          f=-1;
          r=-1;
        }
        else
        f=((f+1)%size);
   
    }
    void display()
    {
        //check for empty queue
        if(f==-1 && r==-1)
        {
            printf("queue is empty!!");
            return;
           
        }
           
           
           
            printf("elements of queue are\n");
            if(f<=r)
            {
                for(int i=f;i<=r;i++)
                {
                   
                    printf("%d\t",q[i]);
                }
            }
                else
                {
                for(int j=f;j<(size);j++)
                {
                  printf("%d\t",q[j]);  
                }
                for(int k=0;k<=r;k++)
                {
                   
                  printf("%d\t",q[k]);
                }
               
                }
       
       
    }