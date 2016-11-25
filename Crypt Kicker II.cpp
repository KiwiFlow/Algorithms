#include<set>
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

bool isMatch(string &d, string &s, unordered_map<char, char> &dict) {
	dict[' '] = ' ';
	if (d.size() != s.size()) return false;
	unordered_set<char> used;
	used.insert(' ');
	for (int i = 0; i < d.size(); i++) {
		if (!dict.count(d[i])) {
			if (used.count(s[i])) {
				return false;
			}
			else {
				dict[d[i]] = s[i];
			}
		}
		else {
			if (s[i] != dict[d[i]]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	string s = "the quick brown fox jumps over the lazy dog";
	int t;
	cin >> t;
	getchar();
	getchar();
	while (t--) {
		vector<string> crypt;
		string oneline;
		while (getline(cin, oneline) && oneline!="") {
			crypt.push_back(oneline);
		}
		unordered_map<char, char> dict;
		dict.clear();
		for (auto &val : crypt) {
			if (isMatch(val, s,dict)) {
				break;
			}
			else {
				dict.clear();
			}
		}
		if (dict.empty()) {
			cout << "No solution." << endl;
		}
		else {
			//decrypt
			for (auto &val : crypt) {
				for (auto &c : val) {
					putchar(dict[c]);
				}
				if(t) putchar('\n');
			}
		}
                if(t) cout << endl;
	}
	return 0;
}
