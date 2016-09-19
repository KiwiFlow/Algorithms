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
    int n;
    cin >> n;
    vector<int> A(n);
    map<int,int> r;
    int res = INT_MAX;
    bool hasA = false;
    for(int i = 0;i < n;i++){
        cin >> A[i];
        if(r.find(A[i])!=r.end()){
            res = min(res,abs(i-r[A[i]]));
            hasA = true;
        }
        r[A[i]] = i;
    }
    cout<<(hasA?res:-1)<<endl;
    return 0;
}
