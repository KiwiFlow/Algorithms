class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        stack<ListNode *> s;
        ListNode * cur=head;
        while(cur){
            s.push(cur);
            cur=cur->next;
        }
        cur=head;
        while(!s.empty()){
            ListNode * t = s.top();
            if(t->val!=cur->val){
                return false;
            }else{
                s.pop();
                cur=cur->next;
            }
        }
        return true;
    }
};
