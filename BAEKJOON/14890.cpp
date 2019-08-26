#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, L;
int r, c, dir, Answer;
int map[101][101], vis[101][101];

bool set_load_v();
bool set_load_h();
void go_h(int idx);
void go_v(int idx);
void solve();

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << Answer << "\n";
}

int m_abs(int x) {
	return (x > 0) ? x : -x;
}

bool set_load_v() {
	int lr, lc;
	for (int l = 0; l < L; l++) {
		lr = r;
		lc = c + l * dir;
		if (map[lr][lc] != map[r][c] || vis[lr][lc] == 1)
			return false;
		vis[lr][lc] = 1;
	}
	return true;
}

bool set_load_h() {
	int lr, lc;
	for (int l = 0; l < L; l++) {
		lr = r + l * dir;
		lc = c;
		if (map[lr][lc] != map[r][c] || vis[lr][lc] == 1)
			return false;
		vis[lr][lc] = 1;
	}
	return true;
}

void go_h(int idx) {
	for (int i = 0; i < N - 1; i++) {
		if (map[i][idx] != map[i + 1][idx]) {
			if (m_abs(map[i][idx] - map[i + 1][idx]) > 1)
				return;
			else {
				c = idx;
				if (map[i][idx] < map[i + 1][idx]) {
					r = i;
					dir = -1;
				}
				else {
					r = i + 1;
					dir = 1;
				}
				if (!set_load_h())
					return;
			}
		}
	}
	Answer++;
}

void go_v(int idx) {
	for (int j = 0; j < N - 1; j++) {
		if (map[idx][j] != map[idx][j + 1]) {
			if (m_abs(map[idx][j] - map[idx][j + 1]) > 1)
				return;
			else {
				r = idx;
				if (map[idx][j] < map[idx][j + 1]) {
					dir = -1;
					c = j;
				}
				else {
					c = j + 1;
					dir = 1;
				}
				if (!set_load_v())
					return;
			}
		}
	}
	Answer++;
}

void solve() {
	Answer = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; i++) {
		go_v(i);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; i++) {
		go_h(i);
	}
}