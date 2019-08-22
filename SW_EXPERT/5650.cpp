#include <iostream>
using namespace std;
struct hole {
	int y, x;
};

hole warmhole[11][2];
int N, map[110][110];
int r, c, dir, score, Answer;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void block(int num) {
	// 0 - À§, 1 - ¿À, 2 - ¾Æ, 3 - ¿Þ
	if (num == 1 && (dir == 2 || dir == 3)) {
		if (dir == 2)
			dir = 1;
		else if (dir == 3)
			dir = 0;
	}
	else if (num == 2 && (dir == 0 || dir == 3)) {
		if (dir == 0)
			dir = 1;
		else if (dir == 3)
			dir = 2;
	}
	else if (num == 3 && (dir == 0 || dir == 1)) {
		if (dir == 0)
			dir = 3;
		else if (dir == 1)
			dir = 2;
	}
	else if (num == 4 && (dir == 1 || dir == 2)) {
		if (dir == 1)
			dir = 0;
		else if (dir == 2)
			dir = 3;
	}
	else {
		dir = (dir + 2) % 4;

	}
}

void warf(int num) {
	if (r == warmhole[num][0].y && c == warmhole[num][0].x) {
		r = warmhole[num][1].y;
		c = warmhole[num][1].x;
	}
	else {
		r = warmhole[num][0].y;
		c = warmhole[num][0].x;
	}
}

void simulate(int sr, int sc, int sdir) {
	int holecnt[11] = { 0, };
	r = sr;
	c = sc;
	dir = sdir;
	score = 0;
	while (1) {
		if ((r == sr && c == sc && score > 0) || map[r][c] == -1)
			break;
		if (r < 1 || r > N || c < 1 || c > N) {
			dir = (dir + 2) % 4;
			score++;
		}
		else {
			if (map[r][c] >= 1 && map[r][c] <= 5) {
				block(map[r][c]);
				score++;
			}
			else if (map[r][c] >= 6) {
				if (holecnt[map[r][c]] >= 2)
					break;
				warf(map[r][c]);
				holecnt[map[r][c]]++;
			}
		}
		r = r + dr[dir];
		c = c + dc[dir];
	}
	if (score > Answer)
		Answer = score;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 11; i++) {
			warmhole[i][0].y = 0;
			warmhole[i][0].x = 0;
			warmhole[i][1].y = 0;
			warmhole[i][1].y = 0;
		}
		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6) {
					if (warmhole[map[i][j]][0].y == 0 && warmhole[map[i][j]][0].x == 0) {
						warmhole[map[i][j]][0].y = i;
						warmhole[map[i][j]][0].x = j;
					}
					else {
						warmhole[map[i][j]][1].y = i;
						warmhole[map[i][j]][1].x = j;
					}
				}
			}
		}
		Answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						simulate(i, j, k);
					}
				}
			}
		}
		cout << "#" << t << " " << Answer << "\n";
	}
}