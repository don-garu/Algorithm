#include <iostream>
#include <cstring>
using namespace std;

struct hole {
	int r, c;
};

hole warmhole[11][2];
int T, N, r, c, dir;
int map[110][110];
int score, Answer;

int Block[6][4] = { {0, }, {2, 3, 1, 0}, {1, 3, 0, 2}, {3, 2, 0, 1}, {2, 0, 3, 1}, {2, 3, 0, 1} };
int dir_x[4] = { 0, 1, 0, -1 }, dir_y[4] = { -1, 0, 1, 0 };
int holecnt[11];

void solve();
void move(int sr, int sc, int sdir);

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		memset(holecnt, 0, sizeof(holecnt));
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6) {
					warmhole[map[i][j]][holecnt[map[i][j]]].r = i;
					warmhole[map[i][j]][holecnt[map[i][j]]].c = j;
					holecnt[map[i][j]]++;
				}
			}
		}
		solve();
		cout << "#" << t << " " << Answer << "\n";
	}
}

void warf(int num) {
	if (warmhole[num][0].r == r && warmhole[num][0].c == c) {
		r = warmhole[num][1].r;
		c = warmhole[num][1].c;
	}
	else {
		r = warmhole[num][0].r;
		c = warmhole[num][0].c;
	}
}

void move(int sr, int sc, int sdir) {
	score = 0;
	r = sr, c = sc, dir = sdir;
	memset(holecnt, 0, sizeof(holecnt));
	while (1) {
		if ((score > 0 && r == sr && c == sc) || map[r][c] == -1)
			break;
		if (r < 1 || r > N || c < 1 || c > N) {
			dir = (dir + 2) % 4;
			score++;
		}
		else {
			if (map[r][c] >= 6) {
				if (holecnt[map[r][c]] >= 2)
					break;
				warf(map[r][c]);
				holecnt[map[r][c]]++;
			}
			else if (map[r][c] >= 1 && map[r][c] <= 5) {
				dir = Block[map[r][c]][dir];
				score++;
			}
		}
		r = r + dir_y[dir];
		c = c + dir_x[dir];
	}
	if (Answer < score)
		Answer = score;
}

void solve() {
	Answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					move(i, j, k);
				}
			}
		}
	}
}