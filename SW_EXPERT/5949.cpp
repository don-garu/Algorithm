#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;
string ss, st;
long long res;

void solve();
int mabs(int num);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> ss >> st;
		solve();
		cout << "#" << t << " " << res << "\n";
	}
}

int mabs(int num) {
	return num > 0 ? num : -num;
}

void solve() {
	vector<int> sv, tv;
	res = 0;
	int len = ss.length(), tmp;
	for (int i = 0; i < len; i++) {
		if (ss[i] == 'a')
			sv.push_back(i);
		if (st[i] == 'a')
			tv.push_back(i);
	}
	len = sv.size();
	for (int i = 0; i < len; i++) {
		res += mabs(sv[i] - tv[i]);
	}
}