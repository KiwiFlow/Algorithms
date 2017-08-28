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
    ListNode * get_mid(ListNode *head){
        ListNode *iter = head;
        int len = 0;
        while(iter){
            len++;
            iter = iter->next;
        }
        
        iter = head;
        
        for(int i = 0;i < len/2 - 1;i++){
            iter = iter->next;
        }
        
        ListNode * ans = iter->next;
        iter->next = NULL;
        
        return ans;
    }
    
    ListNode* reverseList(ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    
    if(head->next==NULL){
        return head;
    }
    
    ListNode * ret=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return ret;
}
    
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        if(!head->next) return true;
        ListNode * rhs = reverseList(get_mid(head));
        while(head && rhs){
            if(head->val != rhs->val){
                return false;
            }
            head = head->next;
            rhs = rhs->next;
        }
        return true;
    }
};
