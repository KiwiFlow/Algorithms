/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(0==l1)	return l2;
    	if(0==l2)	return l1;
    	ListNode *iter1=l1,*iter2=l2;
    	ListNode *dummy=new ListNode(-1);
    	ListNode *ptail=dummy;
    	int carry=0;
    	while(iter1 || iter2)
    	{
    		ListNode *pNode=new ListNode(0);
                                         
            int val1 = 0 , val2 = 0;
            
            if(iter1){
                val1 = iter1->val;
                iter1 = iter1->next;
            }
            
            if(iter2){
                val2 = iter2->val;
                iter2 = iter2->next;
            }
            
			
			pNode->val=(val1+val2+carry)%10;
			carry=(val1+val2+carry)/10;
                                         
			ptail->next=pNode;
    		ptail=pNode;
			
    	}
                                         
    	if(carry)
    	{
    		ListNode *tmp=new ListNode(carry);
    		ptail->next=tmp;
    		ptail=tmp;
    	}
                                         
    	ptail->next=0;
        return dummy->next;
    }
};
