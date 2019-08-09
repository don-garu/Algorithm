#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> tup;
int x[4] = { -1, 0, 1, 0 }, y[4] = { 0, -1, 0, 1 };
int map[10][10], dp[6][10][10], vis[10][10];
int T, N, K, mx, mx_cnt;

void dfs(pi loc, int cut, int cnt) {
	int dp_loc = dp[cut][loc.first][loc.second];
	if (dp_loc && dp_loc > cnt || vis[loc.first][loc.second])
		return;
	vis[loc.first][loc.second] = 1;
	dp_loc = cnt;
	if (mx_cnt < cnt) {
		mx_cnt = cnt;
	}

	for (int k = 0; k < 4; k++) {
		int nf, ns;
		nf = loc.first + y[k];
		ns = loc.second + x[k];
		if (nf >= 0 && nf < N && ns >= 0 && ns < N) {
			if (cut == 0) {
				for (int i = 1; i <= K; i++) {
					if (map[loc.first][loc.second] > map[nf][ns] - i) {
						map[nf][ns] -= i;
						dfs(make_pair(nf, ns), i, cnt + 1);
						map[nf][ns] += i;
					}
				}
			}
			if (map[loc.first][loc.second] > map[nf][ns]) {
				dfs(make_pair(nf, ns), cut, cnt + 1);
			}
		}
	}
	vis[loc.first][loc.second] = 0;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		mx = 0;
		mx_cnt = 0;
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (mx < map[i][j])
					mx = map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == mx) {
					dfs(make_pair(i, j), 0, 1);
				}
			}
		}
		cout << "#" << t << " " << mx_cnt << "\n";
	}
}