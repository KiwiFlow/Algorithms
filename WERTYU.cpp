#include<cstdio>
#include<algorithm>
using namespace std;
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
	int c;
	while((c=getchar())!=EOF){
		char * i = find(s,s+sizeof(s),c);
        if(i==s+sizeof(s)){
            putchar(c);
        }else{
            putchar(*(i-1));
        }
	}
    return 0;
}
