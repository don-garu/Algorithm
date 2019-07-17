#include <iostream>
#include <cstring>
using namespace std;

int map[21][21], N, vis[21][21], check[101], result;
int go_x[4] = { 1, -1, -1, 1 }, go_y[4] = { 1, 1, -1, -1 };
int st, ed;

void go(int x, int y, int dir, int cnt);

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				st = i, ed = j;
				go(i, j, 0, 0);
			}
		}
		if (!result)
			cout << "#" << t << " -1\n";
		else
			cout << "#" << t << " " << result << "\n";
	}
}

void go(int y, int x, int dir, int cnt) {
	if (y == st && x == ed && result < cnt && dir == 3) {
		result = cnt;
		return;
	}
	if (x < 0 || x >= N || y < 0 || y >= N || vis[y][x] == 1 || check[map[x][y]] == 1)
		return;
	vis[y][x] = 1; check[map[x][y]] = 1;

	go(y + go_y[dir], x + go_x[dir], dir, cnt + 1);

	if (dir < 3)
		go(y + go_y[dir + 1], x + go_x[dir + 1], dir + 1, cnt + 1);

	vis[y][x] = 0;; check[map[x][y]] = 0;
}