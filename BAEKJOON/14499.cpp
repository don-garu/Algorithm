// 14499 주사위 굴리기
#include <iostream>
using namespace std;

int dice[7];
int N, M, x, y, K;
int map[21][21];
int dy[5] = { 0, 0, 0, -1, 1 }, dx[5] = { 0, 1, -1, 0, 0 };

void roll(int cmd) {
	switch (cmd) {
	case 1:
		dice[0] = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = dice[0];
		break;
	case 2:
		dice[0] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = dice[0];
		break;
	case 3:
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = dice[0];
		break;
	case 4:
		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[0];
		break;
	}
}

int main() {
	int cd;
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int k = 0; k < K; k++) {
		cin >> cd;
		if (x + dx[cd] >= M || x + dx[cd] < 0 || y + dy[cd] >= N || y + dy[cd] < 0)
			continue;

		roll(cd);

		y += dy[cd];
		x += dx[cd];

		if (map[y][x] == 0) {
			map[y][x] = dice[6];
		}
		else {
			dice[6] = map[y][x];
			map[y][x] = 0;
		}
		cout << dice[1] << "\n";

		/*cout << "  " << dice[2] << "\n";
		cout << dice[4] << " " << dice[1] << " " << dice[3] << "\n";
		cout << "  " << dice[5] << "\n";
		cout << "  " << dice[6] << "\n";
		cout << "\n\n";*/
	}
}