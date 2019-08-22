#include <iostream>
#include <queue>
#include <stack>
#include <tuple>

#define MMAX 2147483647
using namespace std;
typedef tuple<int, int, int, int> tp;
typedef pair<int, int> pi;

char move_cmd[5] = { 'U', 'D', 'L', 'R', 'T' };

void move(tp loc, char cmd);
void solve();
void get_loc();
void bfs();

struct comp {
	bool operator()(tp &a, tp &b) {
		return get<3>(a) > get<3>(b);
	}
};

char map[51][51];
int N, vis[2][51][51];
int dir_y[2][3] = { {0, 1, 2}, {0, 0, 0} }, dir_x[2][3] = { {0, 0, 0}, {0, 1, 2} };
int result;
priority_queue<tp, vector<tp>, comp> pq;
tp st_loc, ed_loc; // i, j, dir, cnt

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	if (result == MMAX)
		cout << "0\n";
	else
		cout << result - 1 << "\n";
}

bool chk_end(tp loc) {
	if ((get<0>(loc) != get<0>(ed_loc)) || (get<1>(loc) != get<1>(ed_loc)) || (get<2>(loc) != get<2>(ed_loc)))
		return false;
	return true;
}

void move(tp loc, char cmd) {
	pi cur_loc[3];
	int y = get<0>(loc), x = get<1>(loc);
	int dir = get<2>(loc), cnt = get<3>(loc);
	for (int i = 0; i < 3; i++) {
		cur_loc[i] = make_pair(y + dir_y[dir][i], x + dir_x[dir][i]);
	}
	switch (cmd) {
	case 'U':
		for (int i = 0; i < 3; i++) {
			int ny = cur_loc[i].first - 1, nx = cur_loc[i].second;
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx] == '1')
				return;
		}
		y = cur_loc[0].first - 1, x = cur_loc[0].second;
		break;
	case 'D':
		for (int i = 0; i < 3; i++) {
			int ny = cur_loc[i].first + 1, nx = cur_loc[i].second;
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx] == '1')
				return;
		}
		y = cur_loc[0].first + 1, x = cur_loc[0].second;
		break;
	case 'L':
		for (int i = 0; i < 3; i++) {
			int ny = cur_loc[i].first, nx = cur_loc[i].second - 1;
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx] == '1')
				return;
		}
		y = cur_loc[0].first, x = cur_loc[0].second - 1;
		break;
	case 'R':
		for (int i = 0; i < 3; i++) {
			int ny = cur_loc[i].first, nx = cur_loc[i].second + 1;
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx] == '1')
				return;
		}
		y = cur_loc[0].first, x = cur_loc[0].second + 1;
		break;
	case 'T':
		bool flag = true;
		int st_i, st_j;
		if (dir == 1) {
			// 가로
			st_i = cur_loc[0].first - 1, st_j = cur_loc[0].second;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int ni = i + st_i, nj = j + st_j;
					if (ni < 0 || ni >= N || nj < 0 || nj >= N || map[ni][nj] == '1')
						return;
				}
			}
			if (!flag)
				break;
			y = cur_loc[0].first - 1, x = cur_loc[0].second + 1;
			dir = 0;
		}
		else {
			// 세로
			st_i = cur_loc[0].first, st_j = cur_loc[0].second - 1;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int ni = i + st_i, nj = j + st_j;
					if (ni < 0 || ni >= N || nj < 0 || nj >= N || map[ni][nj] == '1')
						return;
				}
			}
			if (!flag)
				break;
			y = cur_loc[0].first + 1, x = cur_loc[0].second - 1;
			dir = 1;
		}
		break;
	}
	if (vis[dir][y][x] && vis[dir][y][x] <= cnt + 1)
		return;
	pq.push(make_tuple(y, x, dir, cnt + 1));
}

void bfs() {
	while (pq.size()) {
		tp tmp = pq.top();
		pq.pop();
		if (chk_end(tmp)) {
			result = result > get<3>(tmp) ? get<3>(tmp) : result;
			continue;
		}
		int i = get<0>(tmp);
		int j = get<1>(tmp);
		int dir = get<2>(tmp);
		int cnt = get<3>(tmp);
		if (vis[dir][i][j] && cnt >= vis[dir][i][j])
			continue;
		vis[dir][i][j] = cnt;
		for (int k = 0; k < 5; k++) {
			move(tmp, move_cmd[k]);
		}
	}
}

void solve() {
	get_loc();
	result = MMAX;
	pq.push(st_loc);
	bfs();
}

void get_loc() {
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'B') {
				if (flag) {
					if (i + 1 < N && map[i + 1][j] == 'B') {
						st_loc = make_tuple(i, j, 0, 1);
					}
					else if (j + 1 < N && map[i][j + 1] == 'B') {
						st_loc = make_tuple(i, j, 1, 1);
					}
					flag = false;
				}
				map[i][j] = '0';
			}
		}
	}
	flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'E') {
				if (flag) {
					if (i + 1 < N && map[i + 1][j] == 'E') {
						ed_loc = make_tuple(i, j, 0, 1);
					}
					else if (j + 1 < N && map[i][j + 1] == 'E') {
						ed_loc = make_tuple(i, j, 1, 1);
					}
					flag = false;
				}
				map[i][j] = '0';
			}
		}
	}
}