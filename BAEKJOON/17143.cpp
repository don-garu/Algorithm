#include <iostream>
#include <cstring>
using namespace std;
typedef struct {
	int y, x, al;
	int speed, dir, size;
}shark_info;
// 위, 아래, 오른, 왼
int x[5] = { 0, 0, 0, 1, -1 };
int y[5] = { 0, -1, 1, 0, 0 };
int R, C, M;
shark_info sinfo[10001];
int map[101][101], tmp[101][101];

void dump() {
	cout << "================================\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "================================\n";
}

int main() {
	int r, c, s, d, z;
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		cin >> sinfo[i].y;
		cin >> sinfo[i].x;
		cin >> sinfo[i].speed;
		cin >> sinfo[i].dir;
		cin >> sinfo[i].size;
		map[sinfo[i].y][sinfo[i].x] = i;
		sinfo[i].al = 1;
	}
	int sum = 0;
	for (int j = 1; j <= C; j++) { // 낚시왕 이동
		//cout << "loc : " << j << "\n";
		//dump();
		// 잡기
		for (int i = 1; i <= R; i++) {
			if (map[i][j] != 0) {
				sum += sinfo[map[i][j]].size;
				sinfo[map[i][j]].al = 0;
				map[i][j] = 0;
				break;
			}
		}
		// 상어 이동
		memset(tmp, 0, sizeof(tmp));
		int ni, nj, ci, cj, mod;
		for (int k = 1; k <= M; k++) {
			if (sinfo[k].al) {
				ci = sinfo[k].y;
				cj = sinfo[k].x;
				if (sinfo[k].dir > 2)
					mod = 2 * (C - 1);
				else
					mod = 2 * (R - 1);
				//printf("[%d] : (%d, %d)\n", k, ci, cj);
				for (int cnt = sinfo[k].speed % mod; cnt > 0; cnt--) {
					ni = ci + y[sinfo[k].dir];
					nj = cj + x[sinfo[k].dir];
					if (!(ni > 0 && ni <= R && nj > 0 && nj <= C)) {
						if (sinfo[k].dir % 2 == 1)
							sinfo[k].dir++;
						else
							sinfo[k].dir--;
						ni = ci + y[sinfo[k].dir];
						nj = cj + x[sinfo[k].dir];
					}
					ci = ni;
					cj = nj;
					//printf("[%d] : (%d, %d)\n", k, ci, cj);
				}
				sinfo[k].y = ci;
				sinfo[k].x = cj;
				if (tmp[ci][cj] == 0)
					tmp[ci][cj] = k;
				else if (sinfo[tmp[ci][cj]].size < sinfo[k].size) {
					sinfo[tmp[ci][cj]].al = 0;
					tmp[ci][cj] = k;
				}
				else
					sinfo[k].al = 0;
			}
		}
		memcpy(map, tmp, sizeof(map));
	}
	cout << sum << "\n";
}