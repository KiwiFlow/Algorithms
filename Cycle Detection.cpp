/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(!head)   return false;
    Node *fast=head->next,*slow=head;
    while(fast && slow){
        if(slow==fast){
            return true;
        }else{
            slow = slow->next;
            if(fast->next){
                fast = fast->next->next;
            }else{
                fast = NULL;
            }
        }
    }
    return false;
}
