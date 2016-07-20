/*Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode dummy;
    dummy.next = head;
    dummy.val = head->val;
    for(struct ListNode * i=&dummy;i!=NULL && i->next!=NULL;){
        if(i->next->val == val){
            struct ListNode * tmp = i->next;
            i->next = i->next->next;
            free(tmp);
        }else{
            i=i->next;
        }
    }
    return dummy.next;
}
