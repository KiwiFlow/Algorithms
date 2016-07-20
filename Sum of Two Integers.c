/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.*/
int getSum(int a, int b) {
   int mask=1;
   int c=0;
   int j=0;//进位
   while(mask){
       int a_mask = a&mask;
       int b_mask = b&mask;
       c = c|(a_mask^b_mask^j);
       if(a_mask&b_mask | b_mask&j | a_mask&j){
           j=mask<<1;
       }else{
           j=0;
       }
       mask=mask<<1;
   }
   return c;
}
