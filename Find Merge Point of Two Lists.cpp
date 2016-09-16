/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int go(Node *headA,Node *headB,int lenA,int lenB){
    if(lenA > lenB){
        headA = headA->next;
        lenA--;
        return go(headA,headB,lenA,lenB);
    }else{
        if(lenA < lenB){
            headB = headB->next;
            lenB--;
            return go(headA,headB,lenA,lenB);
        }else{
            if(headA->data == headB->data)  return headA->data;
            else{
                headA=headA->next;
                headB=headB->next;
                lenA--;
                lenB--;
                return go(headA,headB,lenA,lenB);
            }
        }
    }
}
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    int lenA = 0,lenB = 0;
    for(Node *p=headA;p;p=p->next) lenA++;
    for(Node *p=headB;p;p=p->next) lenB++;
    return go(headA,headB,lenA,lenB);
}
