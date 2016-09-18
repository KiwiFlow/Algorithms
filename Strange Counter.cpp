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
    long long  t;
    cin >> t;
    long long a = (long long)(log(ceil(t/3.0))/log(2));
    long long b = t - 3*(pow(2,a)-1);
    long long res = 3*pow(2,a)-b+1;
    cout<<res;
    return 0;
}
