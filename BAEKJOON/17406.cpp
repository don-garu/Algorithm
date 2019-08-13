#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct {
	int r, c, s;
}RCS;

int dir_x[4] = { 1, 0, -1, 0 }, dir_y[4] = { 0, 1, 0, -1 };

int arr[51][51], save[51][51], N, M;
RCS nod[6];

void main_func(int r, int c, int s) {
	int st_i = r - s - 1, st_j = c - s - 1, ed_i = r + s - 1, ed_j = c + s - 1;
	int flag = 0, cur, tmp, cnt = 0;
	for (int k = 0; k < s; k++) {
		flag = 0;
		int i = st_i + k, j = st_j + k + 1;
		cur = save[st_i + k][st_j + k];
		while (i != st_i + k || j != st_j + k) {
			tmp = cur;
			cur = save[i][j];
			save[i][j] = tmp;
			if (!(i + dir_y[flag] >= st_i + k && i + dir_y[flag] <= ed_i - k && j + dir_x[flag] >= st_j + k && j + dir_x[flag] <= ed_j - k))
				flag++;
			i += dir_y[flag];
			j += dir_x[flag];
		}
		save[st_i + k][st_j + k] = cur;
	}
}

int main() {
	int K, R, C, S;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> a;
	for (int k = 0; k < K; k++) {
		cin >> R >> C >> S;
		nod[k].r = R;
		nod[k].c = C;
		nod[k].s = S;
		a.push_back(k);
	}
	int max = 2147483647, sum;
	do {
		memcpy(save, arr, sizeof(arr));
		for (int i = 0; i < a.size(); i++) {
			main_func(nod[a[i]].r, nod[a[i]].c, nod[a[i]].s);
		}
		for (int i = 0; i < N; i++) {
			sum = 0;
			for (int j = 0; j < M; j++) {
				sum += save[i][j];
			}
			if (max > sum)
				max = sum;
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << max << "\n";
}
