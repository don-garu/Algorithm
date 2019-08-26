// 14503. ·Îº¿ Ã»¼Ò±â
#include <iostream>
using namespace std;

int r, c, dir;
int N, M;
int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };
int map[52][52];
int vis[52][52];
int Answer;

void solve();

int main() {
	cin >> N >> M;
	cin >> r >> c >> dir;
	r++;
	c++;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << Answer << "\n";
}

void solve() {
	bool flag = true;
	int nr, nc, ndir;
	while (1) {
		if (vis[r][c] == 0) {
			vis[r][c] = 1;
			Answer++;
		}
		flag = false;
		for (int k = 0; k < 4; k++) {
			ndir = (dir + 3 + 3 * k) % 4;
			nr = r + dr[ndir];
			nc = c + dc[ndir];
			if (nr < 1 || nr > N || nc < 1 || nc > M)
				continue;
			if (map[nr][nc] == 1 || vis[nr][nc] == 1)
				continue;
			flag = true;
			r = nr;
			c = nc;
			dir = ndir;
			break;
		}
		if (!flag) {
			ndir = (dir + 2) % 4;
			nr = r + dr[ndir];
			nc = c + dc[ndir];
			if (map[nr][nc] == 1)
				break;
			r = nr;
			c = nc;
		}
	}
}