#include<set>
#include<iostream>
#include<string>
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	std::set<std::string> dict;
	std::string word;
	while (std::cin >> word) {
		dict.insert(word);
	}
	for (auto &val : dict) {
		for (int leftsize = 1; leftsize < val.size(); leftsize++) {
			if (dict.count(val.substr(0, leftsize)) && dict.count(val.substr(leftsize, val.size() - leftsize))) {
				std::cout << val << std::endl;
				break;
			}
		}
	}
	return 0;
}
