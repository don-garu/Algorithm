#include <iostream>
#include <cstring>
using namespace std;

int map[51][51], tmap[51][51];
int x[4] = { -1, 0, 1, 0 }, y[4] = { 0, 1, 0, -1 }, dir_y[4] = { -1, 0, 1, 0 }, dir_x[4] = { 0, 1, 0, -1 };
int R, C, T, uidx = -1, didx = -1;

void solve();
void dump();

int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (uidx == -1)
					uidx = i;
				else
					didx = i;
			}
		}
	}
	for (int t = 0; t < T; t++) {
		memset(tmap, 0, sizeof(tmap));
		solve();
		memcpy(map, tmap, sizeof(map));
	}
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0)
				sum += map[i][j];
		}
	}
	cout << sum << "\n";
}

void solve() {
	// 1 second
	// diffusion
	int dif_cnt;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				dif_cnt = 0;
				for (int k = 0; k < 4; k++) {
					int dy = i + y[k], dx = j + x[k];
					if (dy >= 0 && dy < R && dx >= 0 && dx < C && map[dy][dx] != -1) {
						dif_cnt++;
						tmap[dy][dx] += map[i][j] / 5;
					}
				}
				tmap[i][j] += map[i][j] - ((int)(map[i][j] / 5) * dif_cnt);
			}
		}
	}
	// move first
	int lc_y, lc_x, dir = 0;
	lc_y = uidx - 1;
	lc_x = 0;
	while (1) {
		if (lc_x == 0 && lc_y == uidx)
			break;
		if (lc_y + dir_y[dir] < 0 || lc_y + dir_y[dir] >= R || lc_x + dir_x[dir] < 0 || lc_x + dir_x[dir] >= C || (dir == 2 && lc_y == uidx)) {
			dir++;
		}
		tmap[lc_y][lc_x] = tmap[lc_y + dir_y[dir]][lc_x + dir_x[dir]];
		lc_y += dir_y[dir];
		lc_x += dir_x[dir];
	}
	// move second
	dir = 0;
	lc_y = didx + 1;
	lc_x = 0;
	while (1) {
		if (lc_x == 0 && lc_y == didx)
			break;
		if (lc_y - dir_y[dir] < 0 || lc_y - dir_y[dir] >= R || lc_x + dir_x[dir] < 0 || lc_x + dir_x[dir] >= C || (dir == 2 && lc_y == didx)) {
			dir++;
		}
		tmap[lc_y][lc_x] = tmap[lc_y - dir_y[dir]][lc_x + dir_x[dir]];
		lc_y -= dir_y[dir];
		lc_x += dir_x[dir];
	}
	tmap[uidx][0] = -1;
	tmap[didx][0] = -1;
}

void dump() {
	cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}