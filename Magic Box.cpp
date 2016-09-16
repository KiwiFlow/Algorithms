#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int res=0;
    int Cr=0,Cy=0,Cb=0;
    string seq;
    cin>>seq;
    for(int i=0;i<seq.size();i++){
    	switch(seq[i]){
    		case 'R':{Cr++; break;}
    		case 'Y':{Cy++; break;}
    		case 'B':{Cb++; break;}
    	}
        res = max(res,Cr+Cy+Cb);
        //cout<<Cr<<" "<<Cy<<" "<<Cb<<endl;
        if(abs(Cr-Cy)==x && abs(Cy-Cb)==y && abs(Cb-Cr)==z
        || abs(Cr-Cy)==x && abs(Cy-Cb)==z && abs(Cb-Cr)==y
        || abs(Cr-Cy)==y && abs(Cy-Cb)==x && abs(Cb-Cr)==z
        || abs(Cr-Cy)==y && abs(Cy-Cb)==z && abs(Cb-Cr)==x
        || abs(Cr-Cy)==z && abs(Cy-Cb)==x && abs(Cb-Cr)==y
        || abs(Cr-Cy)==z && abs(Cy-Cb)==y && abs(Cb-Cr)==x){
            Cr=Cy=Cb=0;
        }
    }
    cout<<res;
    return 0;
}
