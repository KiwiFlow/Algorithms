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


int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    
    long r = n%s.size();
    long d_c = 0,r_c = 0;
    for(int i=0;i<s.size();i++){
        if(i<r){
            r_c = r_c + (s[i]=='a'?1:0);
        }
        d_c = d_c + (s[i]=='a'?1:0);
    }
    
    cout<<d_c*(n/s.size()) + r_c;
    
    return 0;
}
