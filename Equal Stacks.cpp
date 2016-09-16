#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void remove(int &s1,int &s2,int &s3,int &i,int &j,int &k,vector<int> &h1,vector<int> &h2,vector<int> &h3){
    if(s1>=s2 && s1>=s3){
        s1-=h1[i];
        i++;
    }else{
        if(s2>=s1 && s2>=s3){
            s2-=h2[j];
            j++;
        }else{
            s3-=h3[k];
            k++;
        }
    }
}
int main(){
    int n1;
    int n2;
    int n3;
    int s1=0,s2=0,s3=0;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
        s1+=h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
         s2+=h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
         s3+=h3[h3_i];
    }
    if(!n1 || !n2 || !n3){
        cout<<0;
        return 0;
    }
    
    int i=0,j=0,k=0;
    while(s1!=s2 || s1!=s3 || s2!=s3){
        remove(s1,s2,s3,i,j,k,h1,h2,h3);
    }
    cout<<s1;
    return 0;
}
