/*Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    int count,hnum;
    int n;                              //temporary
    struct ListNode* halfhead;
    struct ListNode *current,*tmp1,*tmp2; //temporary
    
    
    //Count how many nodes O(N)
    count=0;
    for(current=head;current!=NULL;current=current->next)
        count++;
    
    hnum=count/2;
    n=0;
    for(current=head;current!=NULL;current=current->next){
        if(n==hnum){ //FOUND the middle one
            //The total # of list is ODD or EVEN
            //halfhead=(count%2==0)?NULL:current;CANNOT
            halfhead=current;
            //tmp1=current->next; WRONG
            tmp1=(count%2==0)?current:current->next;
            break;
        }
        n++;
    }
    
    while(tmp1!=NULL){
        
        tmp2 = tmp1->next;
        
        if(tmp2==NULL){  //To check if the tmp1 is the last one -> should be the head of the second half list
            tmp1->next = halfhead;
            halfhead = tmp1;
            break;
        }
        else{
            current=tmp2->next;  //No matter it's NULL or not
        }
        tmp2->next=tmp1;
        tmp1->next=halfhead;
        halfhead=tmp2;
        tmp1=current;
    }
    
    for(n=0,tmp1=head,tmp2=halfhead; n!=hnum&&tmp1!=NULL&tmp2!=NULL; n++,tmp1=tmp1->next,tmp2=tmp2->next){
        if(tmp1->val!=tmp2->val)
            return false;
    }
    
    return true; 
}


