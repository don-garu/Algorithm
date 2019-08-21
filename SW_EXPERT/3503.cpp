#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, res_cnt;
int height[10001], vis[10001];
vector<int> v;

void solve();
int mabs(int n);

bool comp(int a, int b) {
	return a > b;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(height, 0, sizeof(height));
		memset(vis, 0, sizeof(vis));
		v.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> height[i];
		}
		solve();
		cout << "#" << t << " " << res_cnt << "\n";
	}
}

int mabs(int n) {
	return (n > 0) ? n : -n;
}

void solve() {
	sort(height, height + N, &comp);

	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (flag)
			v.push_back(height[i]);
		else
			v.insert(v.begin(), height[i]);
		flag = !flag;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	int diff = 0;
	for (int i = 0; i < v.size(); i++) {
		if (diff < mabs(v[i] - v[(i + 1) % v.size()]))
			diff = mabs(v[i] - v[(i + 1) % v.size()]);
	}
	res_cnt = diff;
}