#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> tp;

int map[51][51], dp[51][51];

bool go_up(int x, int y) {
	if ((x == 1 || x == 2 || x == 4 || x == 7) && (y == 1 || y == 2 || y == 5 || y == 6))
		return true;
	else
		return false;
}
bool go_down(int x, int y) {
	if ((x == 1 || x == 2 || x == 5 || x == 6) && (y == 1 || y == 2 || y == 4 || y == 7))
		return true;
	else
		return false;
}
bool go_left(int x, int y) {
	if ((x == 1 || x == 3 || x == 6 || x == 7) && (y == 1 || y == 3 || y == 4 || y == 5))
		return true;
	else
		return false;
}
bool go_right(int x, int y) {
	if ((x == 1 || x == 3 || x == 4 || x == 5) && (y == 1 || y == 3 || y == 6 || y == 7))
		return true;
	else
		return false;
}

int main() {
	int T, N, M, R, C, L, res;
	queue<tp> pq;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		pq.push(make_pair(make_pair(R, C), 1));
		while (pq.size()) {
			pi loc = pq.front().first;
			int cnt = pq.front().second;
			pq.pop();
			if (dp[loc.first][loc.second] != 0 && cnt >= dp[loc.first][loc.second]) {
				continue;
			}
			dp[loc.first][loc.second] = cnt;
			int cur = map[loc.first][loc.second];

			if (loc.first - 1 >= 0 && loc.first - 1 < N && loc.second >= 0 && loc.second < M) {
				// up
				if (go_up(cur, map[loc.first - 1][loc.second]))
					pq.push(make_pair(make_pair(loc.first - 1, loc.second), cnt + 1));
			}
			if (loc.first + 1 >= 0 && loc.first + 1 < N && loc.second >= 0 && loc.second < M) {
				// down
				if (go_down(cur, map[loc.first + 1][loc.second]))
					pq.push(make_pair(make_pair(loc.first + 1, loc.second), cnt + 1));
			}
			if (loc.first >= 0 && loc.first < N && loc.second - 1 >= 0 && loc.second - 1 < M) {
				// left
				if (go_left(cur, map[loc.first][loc.second - 1]))
					pq.push(make_pair(make_pair(loc.first, loc.second - 1), cnt + 1));
			}
			if (loc.first >= 0 && loc.first < N && loc.second + 1 >= 0 && loc.second + 1 < M) {
				// right
				if (go_right(cur, map[loc.first][loc.second + 1]))
					pq.push(make_pair(make_pair(loc.first, loc.second + 1), cnt + 1));
			}
		}
		res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dp[i][j] != 0 && dp[i][j] <= L)
					res++;
			}
		}
		cout << "#" << t << " " << res << "\n";
	}
}