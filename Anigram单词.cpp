#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int main() {
	int n; cin >> n;
	map<string,vector<string> > dict;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		char key[15];
        memset(key,0,15);
		memcpy(key, s.c_str(), strlen(s.c_str()));
		sort(key, key + strlen(key));
		string skey(key);
        //cout<<key<<" : "<<s<<endl;
		dict[skey].push_back(s);
	}
	int m; cin >> m;
	for (int j = 0; j < m; j++) {
		string q; cin >> q;
		char key[15];
        memset(key,0,15);
		memcpy(key, q.c_str(), strlen(q.c_str()));
		sort(key, key + strlen(key));
		string skey(key);
		int count = 0;
		if (dict.count(skey)) {
			for (auto it = dict[skey].begin(); it != dict[skey].end(); it++) {
                if (*it != q) {
                    //cout<<q<<endl;
                    //cout<<*it<<endl;
                    count++;
                }
			}
			cout << count << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
