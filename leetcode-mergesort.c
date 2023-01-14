/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL&&list2==NULL)
    return NULL;
    if(list1==NULL)
    return list2;
    if(list2==NULL)
    return list1;
    struct ListNode* last, *third;
    if(list1->val<list2->val)
    {
        third=list1;
        last=list1;
        list1=list1->next;
        last->next=NULL;
    }
    else
    {
        third=list2;
        last=list2;
        list2=list2->next;
        last->next=NULL;
    }
    while(list1!=NULL&&list2!=NULL)
    {
        if(list1->val<list2->val)
        {
        last->next=list1;
        last=list1;
        list1=list1->next;
        last->next=NULL;
        }
        else
        {
            last->next=list2;
            last=list2;
            list2=list2->next;
            last->next=NULL;
        }
    }
    while(list1!=NULL)
    {
        last->next=list1;
        last=list1;
        list1=list1->next;
        last->next=NULL;
    }
    while(list2!=NULL)
    {
        last->next=list2;
        last=list2;
        list2=list2->next;
        last->next=NULL;
    }
    return third;


}