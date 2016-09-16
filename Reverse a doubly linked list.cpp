/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    if(!head)   return NULL;
    if(head->next){
        Node * p = head->next;
        Node * q = Reverse(head->next);
        p->next = head;
        head->prev = p;
        head->next = NULL;
        return q;
    }
    return head;
}
