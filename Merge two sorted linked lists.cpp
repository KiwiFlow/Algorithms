/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(!headA && !headB) return NULL;
    if(headA && !headB) return headA;
    if(!headA && headB) return headB;
    if(headA && headB){
        Node * p=NULL;
        if(headA->data < headB->data){
            p = headA;
            headA = headA->next;
        }else{
            p = headB;
            headB = headB->next;
        }
        p->next = MergeLists(headA,headB);
        return p;
    }
    return NULL;
}
