#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pi;
struct cmd {
	char move_dir;
	int cnt;
};

struct snake {
	int r, c;
};

vector<snake> body;
cmd cmd_set[101];
int N, K, L, Answer;
int map[102][102];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };
int dir;

void solve();
bool move(int dir, int move_cnt);

int main() {
	int r, c, x;
	char cinp;
	map[1][1] = 2;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		map[r][c] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x >> cinp;
		cmd_set[i].move_dir = cinp;
		cmd_set[i].cnt = x;
	}
	solve();
	cout << Answer << "\n";
}

bool move(int dir, int move_cnt) {
	snake tmpb;
	if (move_cnt < 0)
		move_cnt = 2147483647;
	for (int i = 0; i < move_cnt; i++) {
		tmpb.r = body.front().r + dr[dir];
		tmpb.c = body.front().c + dc[dir];
		body.insert(body.begin(), tmpb);
		Answer++;
		if (body.front().r < 1 || body.front().r > N || body.front().c < 1 || body.front().c > N || (Answer > 0 && map[body.front().r][body.front().c] == 2))
			return false;
		if (map[body.front().r][body.front().c] == 1) {
			map[body.front().r][body.front().c] = 2;
		}
		else {
			map[body.front().r][body.front().c] = 2;
			map[body.back().r][body.back().c] = 0;
			body.pop_back();
		}
	}
	return true;
}

void solve() {
	Answer = 0;
	dir = 1;
	int tmp_cnt = cmd_set[0].cnt;
	snake tmpb;
	tmpb.r = 1, tmpb.c = 1;
	body.push_back(tmpb);
	for (int i = 0; i < L; i++) {
		if (move(dir, tmp_cnt) == false)
			return;
		switch (cmd_set[i].move_dir) {
		case 'L':
			dir = (dir + 3) % 4;
			break;
		case 'D':
			dir = (dir + 1) % 4;
			break;
		}
		tmp_cnt = cmd_set[i + 1].cnt - cmd_set[i].cnt;
	}
	move(dir, tmp_cnt);
}