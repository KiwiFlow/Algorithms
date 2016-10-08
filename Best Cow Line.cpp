#include<stdio.h>
char a[2005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c",&a[i]);
	}
	int left = 0;
	int right = n-1;
	
	
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(a[left]!=a[right]){
			putchar(( (a[left]<a[right])?a[left++]:a[right--]));
		}else{
			int s = 0;
			while(left+s <= right-s && a[left+s]==a[right-s]){
				s++;
			}
			if(left+s > right-s){
				putchar(a[left]);
				left++;
			}else{
				putchar(( (a[left+s]<a[right-s])?a[left++]:a[right--]));
			}
		}
		cnt++;
		if(cnt%80==0) putchar('\n');
	}
	return 0;
}
