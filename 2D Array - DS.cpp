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

int hourglasses(vector<vector<int>> &arr,int i,int j){
    return arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+
        arr[i][j]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
}
int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int res = INT_MIN;
    for(int arr_i = 1;arr_i <= 4;arr_i++){
       for(int arr_j = 1;arr_j <= 4;arr_j++){
          res = max(res,hourglasses(arr,arr_i,arr_j));
       }
    }
    cout<<res;
    return 0;
}
