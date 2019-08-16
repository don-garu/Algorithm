#include <iostream>
#include <string>

using namespace std;

int y[4] = { -1, 0, 1, 0 }, x[4] = { 0, 1, 0, -1 }; // 0À§ 1¿À 2¾Æ 3¿Þ
int nd[2][4] = { {1, 0, 3, 2}, {3, 2, 1, 0} };
int map[600][600], mmax, mdir;
char result[4] = { 'U', 'R', 'D', 'L' };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, PR, PC;
	string s;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			switch (s[j - 1]) {
			case ('.'):
				map[i][j] = 1;
				break;
			case ('/'):
				map[i][j] = 2;
				break;
			case ('\\'):
				map[i][j] = 3;
				break;
			}
		}
	}
	cin >> PR >> PC;
	for (int i = 0; i < 4; i++) {
		int ci = PR, cj = PC, cnt = 1, direction = i;
		while (1) {
			if (map[ci + y[direction]][cj + x[direction]] == 0)
				break;
			ci += y[direction];
			cj += x[direction];
			if (map[ci][cj] > 1)
				direction = nd[map[ci][cj] - 2][direction];
			cnt++;
			if (ci == PR && cj == PC && direction == i) {
				cout << result[i] << "\nVoyager\n";
				return 0;
			}
		}
		if (mmax < cnt) {
			mmax = cnt;
			mdir = i;
		}
	}
	cout << result[mdir] << "\n" << mmax << "\n";
}