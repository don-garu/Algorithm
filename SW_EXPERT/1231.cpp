#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef struct {
	int left, right;
	char data;
} nod;

nod node[101];

void search(nod& n_cur) {
	if (n_cur.left != -1)
		search(node[n_cur.left]);
	cout << n_cur.data;
	if (n_cur.right != -1)
		search(node[n_cur.right]);
}


int main() {
	int N;
	string s, token;

	for (int t = 1; t < 11; t++) {
		for (int i = 0; i <= 100; i++) {
			node[i].data = '\n';
			node[i].left = node[i].right = -1;
		}
		cin >> N;
		getline(cin, s);
		for (int i = 1; i <= N; i++) {
			int tcnt = 0;
			getline(cin, s);
			stringstream sst(s);

			while (getline(sst, token, ' ')) {
				tcnt++;
				switch (tcnt) {
				case 2:
					node[i].data = token[0];
					break;
				case 3:
					node[i].left = stoi(token);
					break;
				case 4:
					node[i].right = stoi(token);
				}
			}
		}
		cout << "#" << t << " ";
		search(node[1]);
		cout << "\n";
	}
	cin >> N;
}