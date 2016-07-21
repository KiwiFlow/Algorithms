/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    int val=node->next->val;
    struct ListNode * tmp = node->next;
    node->next=node->next->next;
    node->val=val;
    free(tmp);
}
