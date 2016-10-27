#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
	std::list<char> mylist;
	std::list<char>::iterator it;
	it = mylist.begin();
	int c;
	while ((c=getchar()) != EOF) {
		switch (c) {
		case '[': {
			it = mylist.begin();
			break;
		}
		case ']': {
			it = mylist.end();
			break;
		}
		case '\n': {
			for (it = mylist.begin(); it != mylist.end(); ++it)
				std::cout << *it;
			std::cout << '\n';
			mylist.clear();
			it = mylist.begin();
			break;
		}
		default: {
			it = mylist.insert(it, (char)c);
			it++;
		}
		}
	}
	return 0;
}
