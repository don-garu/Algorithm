#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pi;
int arr[101][101], N, cnt;

int check(int i, int j) {
	for (int k = i; k < N; k++) {
		if (arr[k][j] == 2) {
			for (int l = k - 1; l > i; l--) {
				arr[l][j] = 0;
			}
			return k;
		}
	}
	return -1;
}

int main() {
	queue<pi> pq;
	for (int t = 1; t < 11; t++) {
		cin >> N;
		while (pq.size())
			pq.pop();
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					pq.push(make_pair(i, j));
			}
		}
		cnt = 0;
		while (pq.size()) {
			pi tmp = pq.front();
			pq.pop();
			if (arr[tmp.first][tmp.second] != 1)
				continue;
			int tt = check(tmp.first, tmp.second);
			if (tt != -1) {
				cnt++;
			}
		}
		cout << "#" << t << " " << cnt << "\n";
	}
}