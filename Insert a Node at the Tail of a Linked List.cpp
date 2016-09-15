/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    if(!head){
        head = new Node();
        head->data = data;
    }else{
        Node *p=head;
        while(p->next) p=p->next;
        p->next = new Node();
        p->next->data = data;
    }
    return head;
}
