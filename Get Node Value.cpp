/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    int len = 0;
    for(Node *p=head;p;p=p->next)    len++;
    int pos = len-1-positionFromTail;
    for(int i=0;i<pos;i++) head=head->next;
    return head->data;
}
