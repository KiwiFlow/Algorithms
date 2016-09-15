/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    if(head->next){
        Node * p = Reverse(head->next);
        Node * q=p;
        while(q->next) q=q->next;
        q->next=head;
        head->next=NULL;
        return p;
    }
    return head;
}
