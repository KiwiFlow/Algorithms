#include<set>
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		queue<int*> print_queue;
		priority_queue<int> decision;
		int *goal = nullptr;
		for (int i = 0; i < n; i++) {
			int * x = new int;
			cin >> (*x);
			if (i == m) {
				goal = x;
			}
			print_queue.push(x);
			decision.push(*x);
		}
		int timer = 0;
		while (!print_queue.empty()) {
			int * head = print_queue.front();
			print_queue.pop();
			if (*head == decision.top()) {
				timer++; // print
				decision.pop();
				if (head == goal) {
					cout << timer << endl;
					break;
				}
			}
			else {
				print_queue.push(head);
			}
		}
	}
	return 0;
}
