#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<string.h>
#include<map>
#include<iostream>
#include<string>

struct Trie {
	struct node {
		bool flag; //是否为一个单词的结尾
		node * child[2];
		node() {
			flag = false;
			child[0] = NULL;
			child[1] = NULL;
		}
	};
	node *root;
	Trie() {
		root = new node;
	}
	bool insert(const char *str) {
		node * p = root;
		bool has_new = false;//是否进行过new操作
		while (*str) {
			if (p->flag == true) {
				return false;
			}
			else {
				if (*str == '0') {
					if (!p->child[0]) {
						p->child[0] = new node;
						has_new = true;
					}
					p = p->child[0];
				}
				else {
					if (!p->child[1]) {
						p->child[1] = new node;
						has_new = true;
					}
					p = p->child[1];
				}
			}
			str++;
		}
		p->flag = true;
		return has_new ? true : false;
	}
};

int main() {
	//freopen("d://in.txt", "r", stdin);
	//freopen("d://out.txt", "w", stdout);
	int counter = 1;
	std::string str;
	Trie *trie = new Trie;
	bool ans = true;
	while (std::cin >> str) {
		if (str[0] == '9') {
			if (ans) {
				printf("Set %d is immediately decodable\n", counter);
			}
			else {
				printf("Set %d is not immediately decodable\n", counter);
			}
			counter++;
			trie = new Trie;
			ans = true;
		}
		else {
			ans &= trie->insert(str.c_str());
		}
	}
	return 0;
}
