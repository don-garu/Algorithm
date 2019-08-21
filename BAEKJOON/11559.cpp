#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;

char map[13][7];
int chain;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int vis[13][7];

queue<pi> pq;
stack<pi> sp;

void cnt();
void set();
void move();
void solve();
void dump();

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << chain << "\n";
}

void dump() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void move() {
	int loc = 11;
	for (int j = 0; j < 6; j++) {
		loc = 11;
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] != '.') {
				swap(map[loc--][j], map[i][j]);
			}
		}
	}
}

void set() {
	while (sp.size()) {
		int cy = sp.top().first, cx = sp.top().second;
		sp.pop();
		map[cy][cx] = '.';
	}
}

void cnt() {
	char comp = map[pq.front().first][pq.front().second];
	while (pq.size()) {
		int cy = pq.front().first, cx = pq.front().second;
		pq.pop();
		if (vis[cy][cx] == 1)
			continue;
		vis[cy][cx] = 1;
		sp.push(make_pair(cy, cx));
		for (int k = 0; k < 4; k++) {
			int ny = cy + dy[k], nx = cx + dx[k];
			if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6 && map[ny][nx] == comp && vis[ny][nx] == 0) {
				pq.push(make_pair(ny, nx));
			}
		}
	}
}

void solve() {
	bool flag = false;
	while (1) {
		flag = false;
		memset(vis, 0, sizeof(vis));
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					pq.push(make_pair(i, j));
					cnt();
					if (sp.size() >= 4) {
						flag = true;
						set();
					}
					while (sp.size())
						sp.pop();
				}
			}
		}
		if (!flag)
			break;
		chain++;
		move();
	}
}