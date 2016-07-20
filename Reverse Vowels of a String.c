bool isVowel(char i){
    return i=='a'|i=='e'|i=='i'|i=='o'|i=='u'|
    i=='A'|i=='E'|i=='I'|i=='O'|i=='U';
}
char* reverseVowels(char* s) {
    if(s==NULL){
        return NULL;
    }
    int i=0,j=strlen(s)-1;
    while(true){
        for(;i<strlen(s);i++){
            if(isVowel(s[i])){
                break;
            }
        }
        for(;j>=0;j--){
            if(isVowel(s[j])){
                break;
            }
        }
        if(i<j){
            char tmp=s[i];
            s[i]=s[j];
            s[j]=tmp;
            i++;
            j--;
        }else{
            return s;
        }
    }
}
