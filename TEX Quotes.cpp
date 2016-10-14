#include<cstdio>
int main(){
  int c;
  int isLeft = 1;
  while( (c=getchar()) != EOF){
  	if(c=='"'){
  		printf("%s",isLeft?"``":"''");
  		isLeft = !isLeft;
  	}else{
  		printf("%c",c);
  	}
  }
  return 0;
}
