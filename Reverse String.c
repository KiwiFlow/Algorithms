char* reverseString(char* s) {
    if(s==NULL){
        return NULL;
    }
    for(int i=0,j=strlen(s)-1;i<=j;i++,j--){
        char tmp = s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
    return s;
}
