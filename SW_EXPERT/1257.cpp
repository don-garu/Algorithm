#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void push(vector<string>& v, string s) {
	int len = v.size();
	bool flag = true;
	for (int i = 0; i < len; i++) {
		if (v[i].compare(s) == 0)
			flag = false;
	}
	if (flag)
		v.push_back(s);
}

int main() {
	int T, K, len, size;
	bool flag;
	string s, res;
	vector<string> sv[26];

	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 26; i++)
			sv[i].clear();
		cin >> K;
		cin >> s;
		len = s.length();
		for (int i = 0; i < s.length(); i++) {
			for (int j = 1; j <= len - i; j++) {
				push(sv[s[i] - 'a'], s.substr(i, j));
			}
		}
		size = 0;
		for (int i = 0; i < 26; i++) {
			size += sv[i].size();
			sort(sv[i].begin(), sv[i].end());
		}
		flag = false;
		for (int i = 0; i < 26; i++) {
			if (sv[i].size() < K)
				K -= sv[i].size();
			else {
				flag = true;
				res = sv[i][K - 1];
				break;
			}
		}
		cout << "#" << t << " ";
		if (flag)
			cout << res << "\n";
		else
			cout << "none\n";
	}
}