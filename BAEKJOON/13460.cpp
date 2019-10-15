#include <iostream>

using namespace std;

struct ball {
	int r, c;
};

char map[11][11];
int N, M, Answer;
ball red, blue;

int dr[4] = { 0, 0, -1, 1 }, dc[4] = { -1, 1, 0, 0 };

void real_move(ball balls[], int dir) {
	// 0 : left, 1 : right, 2 : up, 3 : down
	int rr = balls[0].r, rc = balls[0].c;
	int br = balls[1].r, bc = balls[1].c;
	while ((rr + dr[dir] >= 1 && rr + dr[dir] <= N) && (rc + dc[dir] >= 1 && rc + dc[dir] <= M) && map[rr + dr[dir]][rc + dc[dir]] != '#') {
		rr += dr[dir];
		rc += dc[dir];
		if (map[rr][rc] == 'O')
			break;
	}
	while ((br + dr[dir] >= 1 && br + dr[dir] <= N) && (bc + dc[dir] >= 1 && bc + dc[dir] <= M) && map[br + dr[dir]][bc + dc[dir]] != '#') {
		br += dr[dir];
		bc += dc[dir];
		if (map[br][bc] == 'O')
			break;
	}
	if (map[rr][rc] != 'O' && rr == br && rc == bc) {
		if (dir == 0 && balls[0].c < balls[1].c)
			bc++;
		else if (dir == 0)
			rc++;
		if (dir == 1 && balls[0].c > balls[1].c)
			bc--;
		else if (dir == 1)
			rc--;
		if (dir == 2 && balls[0].r < balls[1].r)
			br++;
		else if (dir == 2)
			rr++;
		if (dir == 3 && balls[0].r < balls[1].r)
			rr--;
		else if (dir == 3)
			br--;
	}
	balls[0].r = rr, balls[0].c = rc;
	balls[1].r = br, balls[1].c = bc;
}

void move(ball rb, ball bb, int dir, int cnt) {
	if (cnt > 10 || (Answer != -1 && Answer <= cnt)) {
		return;
	}
	// 0 : left, 1 : right, 2 : up, 3 : down
	ball balls[2] = { rb, bb };
	real_move(balls, dir);
	rb = balls[0], bb = balls[1];
	/*
	for (int i = 1; i < cnt; i++)
	cout << " ";
	printf("[%d] DIR %d // RED (%d, %d) BLUE (%d, %d)\n", cnt, dir, rb.r, rb.c, bb.r, bb.c);
	*/
	bool f_red = false, f_blue = false;
	if (map[rb.r][rb.c] == 'O')
		f_red = true;
	if (map[bb.r][bb.c] == 'O')
		f_blue = true;

	if (f_blue)
		return;

	if (f_red) {
		if (Answer == -1)
			Answer = cnt;
		else
			Answer = Answer < cnt ? Answer : cnt;
		return;
	}

	for (int k = 0; k < 4; k++) {
		if (k != dir)
			move(rb, bb, k, cnt + 1);
	}
}

void solve() {
	Answer = -1;
	for (int k = 0; k < 4; k++) {
		move(red, blue, k, 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				map[i][j] = '.';
				blue = { i, j };
			}
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				red = { i, j };
			}
		}
	}

	solve();
	cout << Answer << "\n";
}