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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *ptail = &dummy;
        while(l1 || l2){
            if(l1 && l2){
                if(l1->val < l2->val){
                    ptail->next = l1;
                    l1 = l1->next;
                    ptail = ptail->next;
                }else{
                    ptail->next = l2;
                    l2 = l2->next;
                    ptail = ptail->next;
                }
            }
            
            if(l1 && !l2){
                ptail->next = l1;
                l1 = NULL;
                ptail = ptail->next;
            }
            
            if(!l1 && l2){
                ptail->next = l2;
                l2 = NULL;
                ptail = ptail->next;
            }
            
        }
        return dummy.next;
    }
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        if(l1==NULL){
//            return l2;
//        }
//        if(l2==NULL){
//            return l1;
//        }
//        ListNode *t1,*t2;
//        ListNode *start1,*end1;
//        ListNode *start2,*end2;
//        ListNode *result;
//        result=t1=l1->val<l2->val?l1:l2;
//        t2=l1->val<l2->val?l2:l1;
//        ListNode *pre;
//        while(t1!=NULL && t2!=NULL)
//        {
//            pre=t1;
//            while(t1!=NULL && t1->val<=t2->val)
//            {
//                pre=t1;
//                t1=t1->next;
//            }
          
//            if(t1==NULL) break;
//            start1=pre;
//            end1=t2;
//            pre=t2;
           
//            while(t2!=NULL && t1->val > t2->val )
//            {
//                pre=t2;
//                //cout<<t2->val<<endl;
//                t2=t2->next;
//            }
//            start2=pre;
//            end2=t1;
//            start1->next=end1;
//            start2->next=end2;
//            //cout<<t1->val<<endl;
//            //cout<<t2->val<<endl;
//        }
//        if(t2!=NULL) 
//        {
//            pre->next=t2;
//        }
//        return result;
//     }
// };
