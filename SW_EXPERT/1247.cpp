#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

typedef pair<int, int> pi;

pi map[11], p_s, p_e;
int T, N, x, y, res, vis[11];

int calDist(pi& x, pi& y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

void dfs(int i, int sum, int cnt) {
	if (cnt == N) {
		sum += calDist(map[i], p_e);
		if (res > sum)
			res = sum;
		return;
	}
	vis[i] = 1;
	for (int k = 0; k < N; k++) {
		if (vis[k] != 1) {
			dfs(k, sum + calDist(map[i], map[k]), cnt + 1);
		}
	}
	vis[i] = 0;
}

int main() {
	int sum;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(vis, 0, sizeof(vis));
		cin >> N;
		cin >> x >> y;
		p_s = make_pair(x, y);
		cin >> x >> y;
		p_e = make_pair(x, y);
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			map[i] = make_pair(x, y);
		}
		res = 2147483647;
		for (int i = 0; i < N; i++) {
			sum = calDist(p_s, map[i]);
			dfs(i, sum, 1);
		}
		cout << "#" << t << " " << res << "\n";
	}
}