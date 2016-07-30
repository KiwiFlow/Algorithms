/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode * ans = head;
    struct ListNode dummyEven;
    dummyEven.next = NULL;
    struct ListNode *pEvenTail = &dummyEven;
    
    while(head){
        if(head->next){
            if(head->next->next){
                pEvenTail->next = head->next;
                pEvenTail = pEvenTail->next;
                head->next = head->next->next;
                head = head->next;
                pEvenTail->next = NULL;
            }else{
                pEvenTail->next = head->next;
                pEvenTail = pEvenTail->next;
                pEvenTail->next = NULL;
                head->next = dummyEven.next;
                head = NULL;
            }
        }else{
            head->next = dummyEven.next;
            head = NULL;
        }
    }
    return ans;
}
