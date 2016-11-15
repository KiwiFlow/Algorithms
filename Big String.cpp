#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<string.h>


const int LIMIT = 1e6;
const int BLOCK = 4000;

char data[LIMIT];

void init(std::list<std::vector<char> > &ds, char data[]) {
	int slen = strlen(data);
	while (slen > 0) {
		if (slen / BLOCK) {
			ds.push_back(std::vector<char>(data + ds.size()*BLOCK, data + ds.size()*BLOCK + BLOCK));
		}
		else {
			ds.push_back(std::vector<char>(data + ds.size()*BLOCK, data + ds.size()*BLOCK + slen));
		}
		slen -= BLOCK;
	}
}

void insert(std::list<std::vector<char> > &ds, char c, int pos) {
	/*Insert a character ch before the p-th character of the current string. If p is larger than the length of the string, the character is appended to the end of the string.*/
	//printf("insert %c %d\n",c,pos);
	for (std::list<std::vector<char> >::iterator it = ds.begin(); it != ds.end(); it++) {
		std::list<std::vector<char> >::iterator iter = ++it;
		it--;
		if (iter != ds.end() && pos > (*it).size()) {
			pos -= (*it).size();
		}
		else {
			if ((*it).size() >= pos) {
				(*it).insert((*it).begin() + pos - 1, c);
			}
			else {
				(*it).push_back(c);
			}
			if ((*it).size() > 2 * BLOCK) {
				std::list<std::vector<char> >::iterator insert_iter = ++it;
				it--;
				ds.insert(insert_iter, std::vector<char>((*it).begin() + BLOCK, (*it).end()));
				(*it).erase((*it).begin() + BLOCK, (*it).end());
			}
			return;
		}
	}
}
char query(std::list<std::vector<char> > &ds, int pos) {
	/*The input ensures that the p-th character exists.*/
	//printf("query %d \n",pos);
	for (std::list<std::vector<char> >::iterator it = ds.begin(); it != ds.end(); it++) {
		if (pos > (*it).size()) {
			pos -= (*it).size();
		}
		else {
			return (*it)[pos - 1];
		}
	}
	return -1;
}

int main() {
	//freopen("d://in.txt", "r", stdin);
	std::list<std::vector<char> > ds;
	scanf("%s", data);
	init(ds, data);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char type[2];
		scanf("%s", type);
		//printf("%s",type);
		if (type[0] == 'I') {
			char c[2];
			int pos;
			scanf("%s%d", c, &pos);
			insert(ds, c[0], pos);
		}
		else {
			//puts("?");
			int pos;
			scanf("%d", &pos);
			printf("%c\n", query(ds, pos));
		}
	}
	return 0;
}







