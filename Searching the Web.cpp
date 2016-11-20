#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<stdio.h>
#include<queue>
#include<climits>
#include<vector>
#include<sstream>
#include<iostream>
#include<map>
#include<set>
#include<ctype.h>
#include <iterator>
using namespace std;
const int LIMIT = 100+10;
const int LINE_LIMIT = 1500 + 10;

/*struct comparer {
	bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
		if (lhs.first == rhs.first) {
			return lhs.second < rhs.second;
		}
		else {
			return lhs.first < lhs.first;
		}
	}
};*/

void get_unoin(set<pair<int, int>> &lhs, set<pair<int, int>> &rhs) {
	return;
}

void get_inter(set<pair<int, int>> &lhs, set<pair<int, int>> &rhs) {
	return;
}

void print_ans(const vector<vector<string>> &docs,const set<pair<int, int>> &ans) {
	if (ans.empty()) {
		cout << "Sorry, I found nothing." << endl;
	}
	else {
		int pre_doc = (ans.begin())->first;
		for (auto it = ans.begin(); it != ans.end(); it++) {
			if (it->first != pre_doc) {
				cout << "----------" << endl;
			}
			cout << docs[it->first][it->second] << endl;
			pre_doc = it->first;
		}
	}
	cout << "==========" << endl;
}

int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	string oneline;
	int N; cin >> N;
	getchar(); // 空行
	vector<vector<string>> docs(LIMIT);
	map<string, set<pair<int, int>>> indexs;
	
	int row = 0;
	int doc = 0;
	while (getline(cin, oneline))
	{
		if (oneline == "**********") {
			row = 0;
			doc++;
			if (doc == N) break;
		}
		else {
			/*process rowth line*/
			docs[doc].push_back(oneline);
			pair<int, int> p(doc, row);
			int i = 0;
			while (i < oneline.size()) {
				if (isalpha(oneline[i])) {
					string key;
					while (i < oneline.size() && isalpha(oneline[i])) {
						key += tolower(oneline[i]);
						i++;
					}

					if (!indexs.count(key)) {
						indexs[key] = set<pair<int, int>>();
					}
					indexs[key].insert(p);
				}
				else {
					i++;
				}
			}
			row++;
		}
	}

	int m; cin >> m;
	getchar(); // 空行
	while (getline(cin, oneline)) {
		string query[3];
		stringstream ss(oneline);
		int k = 0;
		while (ss >> query[k]) {
			k++;
		}
		if (query[0] == "NOT") {
			vector<int> docdoc(N, 0);
			for (auto & val : indexs[query[1]]) {
				docdoc[val.first] = 1;
			}
			vector<int> ans_for_this;
			for (auto i = 0; i < N; i++) {
				if (docdoc[i] == 0) {
					ans_for_this.push_back(i);
				}
			}

			if (ans_for_this.empty()) {
				cout << "Sorry, I found nothing." << endl;
			}
			else {
				for (auto i = 0; i < ans_for_this.size(); i++) {
					for (int j = 0; j < docs[ans_for_this[i]].size(); j++) {
						cout << docs[ans_for_this[i]][j] << endl;
					}
					if (i != ans_for_this.size() - 1) {
						cout << "----------" << endl;
					}
				}

			}
			cout << "==========" << endl;
		}
		else {
			if (query[1] == "AND" || query[1] == "OR") {
				
				if (query[1] == "AND") {
					//set_intersection(indexs[query[0]].begin(), indexs[query[0]].end(),
						//indexs[query[3]].begin(), indexs[query[3]].end(), back_inserter(ans), comparer());
					set<pair<int, int>> ans;
					for (auto &val : indexs[query[2]]) {
						auto left = indexs[query[0]].lower_bound(make_pair(val.first, 0));
						auto right = indexs[query[0]].upper_bound(make_pair(val.first, INT_MAX));
						for (auto it = left; it != right; it++) {
							ans.insert(val);
							ans.insert(*it);
						}
					}
					print_ans(docs, ans);
				}
				else {
					//set_union(indexs[query[0]].begin(), indexs[query[0]].end(),
						//indexs[query[3]].begin(), indexs[query[3]].end(), back_inserter(ans), comparer());
					set<pair<int, int>> ans(indexs[query[0]]);
					for (auto &val : indexs[query[2]]) {
						ans.insert(val);
					}
					print_ans(docs, ans);
				}
			}
			else {
				print_ans(docs, indexs[query[0]]);
			}
		}
	}
	return 0;
}
