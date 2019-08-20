#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	vector<string> a, b;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (binary_search(a.begin(), a.end(), s))
			b.push_back(s);
	}
	sort(b.begin(), b.end());
	cout << b.size() << "\n";
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << "\n";
	}
}