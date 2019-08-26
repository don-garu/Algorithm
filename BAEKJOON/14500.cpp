// 14500 테트로미노
#include <iostream>
#define BLOCKS 19

using namespace std;

int Block_x[20][4] = {
	{0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, 0, 1}
	, {0, 0, 0, 1}, {0, 1, 2, 2}, {0, 1, 1, 1}, {0, 1, 2, 0}
	, {0, 1, 1, 1}, {0, 1, 2, 2}, {0, 1, 0, 0}, {0, 0, 1, 2}
	, {0, 0, 1, 1}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}
	, {0, 1, 2, 1}, {0, 0, 1, 0}, {0, 1, 1, 2}, {0, 1, 1, 1}
};
int Block_y[20][4] = {
	{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 0, 1, 1}
	, {0, 1, 2, 2}, {0, 0, 0, -1}, {0, 0, 1, 2}, {0, 0, 0, 1}
	, {0, 0, -1, -2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 1, 1, 1}
	, {0, 1, 1, 2}, {0, 0, -1, -1}, {0, -1, -1, -2}, {0, 0, 1, 1}
	, {0, 0, 0, 1}, {0, 1, 1, 2}, {0, -1, 0, 0}, {0, -1, 0, 1}
};

bool chk(int y, int x, int k);
int block_sum(int y, int x, int k);

int N, M;
int map[501][501];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int max = 0, tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < BLOCKS; k++) {
				if (chk(i, j, k)) {
					tmp = block_sum(i, j, k);
					if (tmp > max)
						max = tmp;
				}
			}
		}
	}
	cout << max << "\n";
}

int block_sum(int y, int x, int k) {
	int lc_sum = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + Block_y[k][i];
		int nx = x + Block_x[k][i];
		lc_sum += map[ny][nx];
	}
	return lc_sum;
}

bool chk(int y, int x, int k) {
	for (int i = 0; i < 4; i++) {
		int ny = y + Block_y[k][i];
		int nx = x + Block_x[k][i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			return false;
	}
	return true;
}