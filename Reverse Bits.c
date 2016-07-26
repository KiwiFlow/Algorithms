uint32_t reverseBits(uint32_t n) {
   char record[16]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
   uint32_t ans=0;
   for(int i=0;i<8;i++){
       uint32_t mask = 0x0000000F;
       uint32_t chunk = n&mask;
       uint32_t reverseChunk = record[chunk];
       ans = ans | reverseChunk;
       if(i<7){
        ans = ans<<4;
        n = n>>4;
       }
   }
   return ans;
}
