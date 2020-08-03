/*

Hard

2345

359

Add to List

Share
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int count,num,n;//From the head we do not need offset; from the tail we need offset
    struct ListNode *prev;
    struct ListNode *shead;
    struct ListNode *p1;
    struct ListNode *p2;
    
    if(head==NULL||k==1) return head;
    
    num=0;
    for(p1=head;p1!=NULL;p1=p1->next){
        num++;
    }
    
    n=num/k;
    if(n==0) return head;
    
    count=1;
    shead=head;
    prev=NULL;
    p1=head;//p1=shead;
    while(p1!=NULL && p1->next!=NULL && n ){   // NOTICE: p1!=NULL is a must and it should be checked before p1->next!=NULL
        p2=p1->next;
        p1->next=p2->next;
        p2->next=shead;
        shead=p2;
        count++;
        if( count == k ){
            if(n==num/k)
                head=shead;
            count=1;
            if(prev!=NULL) prev->next=shead;//in the middle -> it should connect this sub list first and then update the prev as p1 then move p1 to the next sub list
            prev=p1;
            p1=p1->next;
            shead=p1;
            n--;
        }
    }

    return head;
}
