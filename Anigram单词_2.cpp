#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
int main() {
	int n; cin >> n;
	map<string,set<string> > dict;


	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		char key[15];
        memset(key,0,15);
		memcpy(key, s.c_str(), strlen(s.c_str()));
		sort(key, key + strlen(key));
		string skey(key);
		dict[skey].insert(s);
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
			if(dict[skey].find(q) != dict[skey].end()){
                cout << dict[skey].size() - 1 <<endl;
            }else{
                cout << dict[skey].size() << endl;
            }
			// cout << count << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
