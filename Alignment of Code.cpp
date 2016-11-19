#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<stdio.h>
#include<queue>
#include<climits>
#include<vector>
#include<sstream>
#include<map>
using namespace std;
const int LIMIT = 1010;
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	vector<vector<string>> input(LIMIT);
	vector<int> column_size(LIMIT, 0);
	string oneline;
	int row = 0;
	while (getline(cin, oneline))
	{
		stringstream ss(oneline);
		int column = 0;
		string word;
		while (ss >> word){
			column_size[column] = max(column_size[column],(int)word.size());
			input[row].push_back(word);
			column++;
		}
		row++;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < input[i].size(); j++) {
			cout << input[i][j];
			if (j != input[i].size() - 1) {
				for (int k = 0; k <= column_size[j] - input[i][j].size(); k++) {
					cout << " ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
