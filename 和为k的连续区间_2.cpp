#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    map<int,vector<int> > dict;
    bool flag = false;
    int a = 0;
    vector<int> prefix_sum(n+1,0);
    for(int i=1;i<=n;i++){
        // scanf("%d",&a[i]);
        
        cin >> a;
        prefix_sum[i] = prefix_sum[i-1] + a;
        if(dict.count(prefix_sum[i])){
            dict[prefix_sum[i]].push_back(i);
        }else{
            vector<int> unit(1,i);
            dict[prefix_sum[i]] = unit;
        }
    }
    
    for(int i = 1 ;i <= n; i++){
        if(dict.count(prefix_sum[i]+k)){
            int j = n;
            for(auto x : dict[prefix_sum[i]+k]){
                if(x > i){
                    flag = true;
                    j = min(x,j);
                }
            }
            if(flag){
                cout << i + 1 << " " << j << endl;
                break;
            }
        }
        
    }

    if(!flag) cout<<"No Solution";
    return 0;
}


// #include<cstdio>
// #include<iostream>
// int a[10005];
// using namespace std;
// int main(){
//     int n,k;
//     cin>>n>>k;
//     for(int i=1;i<=n;i++){
//         scanf("%d",&a[i]);
//     }
//     int i=1,j=2;
//     bool flag = false;
//     for(int i=1;i<=n;i++){
//         int sum = 0;
//         for(int j=i;j<=n;j++){
//             sum+=a[j];
//             if(sum==k){
//                 cout<<i<<" "<<j;
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag) break;
//     }
//     if(!flag) cout<<"No Solution";
//     return 0;
// }
