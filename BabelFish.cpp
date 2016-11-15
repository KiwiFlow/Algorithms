#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<string.h>
#include<map>
#include<iostream>
#include<string>
const int BLOCK = 20;
unsigned long long hash(const char *s) {
	unsigned long long ans = 0;
	while (*s) {
		ans = ans * 26 + (*s - 'a' + 1);
		s++;
	}
	return ans;
}

int main() {
	//freopen("d://in.txt", "r", stdin);
	//freopen("d://out.txt", "w", stdout);
	char eng[BLOCK],fore[BLOCK];
	std::map<unsigned long long, char *> dict;
	char t;
	int i;
	while (1)
	{
		t = getchar();
		if (t == '\n')               //要处理好换行和空格。如果此时是换行则说明字典已输完
			break;
		else
		{
			eng[0] = t;
			i = 1;
			while (1)
			{
				t = getchar();
				if (t == ' ')              //如果此时是空格说明英语已经输完，接下来应该输外语
					break;
				eng[i++] = t;
			}
			eng[i] = '\0';
		}
		scanf("%s", fore);
		getchar();
		char * unit = new char[BLOCK];
		memcpy(unit, eng, BLOCK);
		dict[hash(fore)] = unit;
	}

	std::string s;
	while (std::cin >> s) {
		if (dict.count(hash(s.c_str()))) {
			printf("%s\n", dict[hash(s.c_str())]);
		}
		else {
			printf("eh\n");
		}
	}
	return 0;
}








