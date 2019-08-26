// 5644. 무선 충전
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;
struct user {
	int r, c;
	pi usable[10];
};

struct charger {
	int r, c;
	int power, range;
};

int map[12][12];
int move_dir[2][101];
int dr[5] = { 0, -1, 0, 1, 0 }, dc[5] = { 0, 0, 1, 0, -1 };
user person[2];
charger bc[9];
int M, A, Answer;

int m_abs(int x) {
	if (x > 0)
		return x;
	else
		return -x;
}

void move_person(int m) {
	person[0].r += dr[move_dir[0][m]];
	person[0].c += dc[move_dir[0][m]];
	person[1].r += dr[move_dir[1][m]];
	person[1].c += dc[move_dir[1][m]];
}

bool comp(pi p1, pi p2) {
	return p1.first > p2.first;
}

void check_charger() {
	for (int i = 0; i < 2; i++) {
		memset(person[i].usable, 0, sizeof(person[i].usable));
		for (int j = 1; j <= A; j++) {
			int dist = m_abs(person[i].r - bc[j].r) + m_abs(person[i].c - bc[j].c);
			if (dist <= bc[j].range) {
				person[i].usable[j].first = bc[j].power;
				person[i].usable[j].second = j;
			}
		}
		sort(person[i].usable + 1, person[i].usable + A + 1, &comp);
	}
}

void decide_charger() {
	if (person[0].usable[1].second == 0 || person[1].usable[1].second == 0) {
		Answer += person[0].usable[1].first + person[1].usable[1].first;
		return;
	}
	if (person[0].usable[1].second != person[1].usable[1].second) {
		Answer += person[0].usable[1].first + person[1].usable[1].first;
	}
	else {
		int max_1 = person[0].usable[1].first;
		int max_2;
		if (person[0].usable[2].first < person[1].usable[2].first)
			max_2 = person[1].usable[2].first;
		else
			max_2 = person[0].usable[2].first;
		Answer += max_1 + max_2;
	}
}

void solve() {
	Answer = 0;
	person[0].r = 1, person[0].c = 1;
	person[1].r = 10, person[1].c = 10;
	for (int m = 0; m <= M; m++) {
		move_person(m);
		check_charger();
		decide_charger();
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> M >> A;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> move_dir[i][j];
			}
		}
		for (int i = 1; i <= A; i++) {
			cin >> bc[i].c >> bc[i].r >> bc[i].range >> bc[i].power;
		}
		solve();
		cout << "#" << t << " " << Answer << "\n";
	}
}