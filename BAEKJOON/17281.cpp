#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int info[10][51]; // 선수별 이닝 정보
int base[4]; // 현재 진출 정보
int mx_score, N;
vector<int> v;

void solve();
void move(int attack);
void game();

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> info[j][i];
		}
	}
	for (int i = 1; i <= 9; i++)
		v.push_back(i);
	solve();
	cout << mx_score << "\n";
}

void move(int attack) {
	for (int i = 3; i > 0; i--) {
		if (base[i]) {
			if (i + attack > 3)
				base[0]++;
			else
				base[i + attack] = 1;
			base[i] = 0;
		}
	}
	base[attack % 4]++;
}

void game() {
	int out_cnt = 0, player = 0, lc_score = 0;
	for (int i = 1; i <= N; i++) {
		out_cnt = 0;
		for (int i = 0; i < 4; i++)
			base[i] = 0;
		while (1) {
			if (out_cnt == 3)
				break;

			if (info[v[player]][i] == 0) {
				out_cnt++;
			}
			else {
				move(info[v[player]][i]);
				lc_score += base[0];
				base[0] = 0;
			}
			// testing
			//printf("Player %d : %d\n", v[player], info[v[player]][i]);
			// testing end
			player = (player + 1) % 9;
		}
	}
	if (lc_score > mx_score) {
		mx_score = lc_score;
	}
}

void solve() {
	do {
		if (v[3] == 1)
			game();
	} while (next_permutation(v.begin(), v.end()));
}