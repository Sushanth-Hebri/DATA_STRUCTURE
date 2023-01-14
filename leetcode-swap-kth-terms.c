
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k){

          struct ListNode* first=head,*second=head,*temp=head,*ptr=head,*prev=head;;
       int n;
       while(first)
       {
           n++;
           first=first->next;
       }
       for(int i=0;i<k-1;i++)
       {
           temp=temp->next;
       }
       int val1=temp->val;
       for(int i=0;i<n-k;i++)
       {
           second=second->next;
       }
       int val2=second->val;
       while(ptr)
       {
           if(ptr==temp)
           {
               ptr->val=val2;
           }
           if(ptr==second)
           {
               ptr->val=val1;
           }
           ptr=ptr->next;
       }
       return head;
}