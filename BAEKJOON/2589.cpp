#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <cstring>
using namespace std;

typedef tuple<int, int, int> tp;

struct comp {
	bool operator()(tp &a, tp &b) {
		return get<2>(a) > get<2>(b);
	}
};

char map[51][51];
int vis[51][51];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int N, M, max_cnt;

void dump();
void bfs(int y, int x);

int main() {
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				memset(vis, 0xffffffff, sizeof(vis));
				bfs(i, j);
			}
		}
	}
	cout << max_cnt << "\n";
}

void bfs(int y, int x) {
	priority_queue<tp, vector<tp>, comp> pq;
	pq.push(make_tuple(y, x, 0));
	while (pq.size()) {
		int lc_y = get<0>(pq.top()), lc_x = get<1>(pq.top()), lc_cnt = get<2>(pq.top());
		pq.pop();
		if (vis[lc_y][lc_x] != -1 && lc_cnt >= vis[lc_y][lc_x])
			continue;
		vis[lc_y][lc_x] = lc_cnt;
		if (max_cnt < lc_cnt)
			max_cnt = lc_cnt;
		for (int k = 0; k < 4; k++) {
			int ny = lc_y + dy[k], nx = lc_x + dx[k];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 'L') {
				if (vis[ny][nx] == -1 || (vis[ny][nx] != -1 && lc_cnt + 1 < vis[ny][nx]))
					pq.push(make_tuple(ny, nx, lc_cnt + 1));
			}
		}
	}
}

void dump() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
}