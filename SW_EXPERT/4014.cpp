#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
int map[21][21], dp[21];

bool go_v(int idx, int N, int X) {
	memset(dp, 0, sizeof(int) * 21);
	queue<pi> pq;
	for (int i = 1; i < N; i++) {
		if (map[idx][i - 1] != map[idx][i]) {
			if (abs(map[idx][i - 1] - map[idx][i]) > 1) // fail
				return false;
			if (map[idx][i - 1] < map[idx][i])
				pq.push(make_pair(i - 1, -1));
			else
				pq.push(make_pair(i, 1));
		}
	}
	while (pq.size()) {
		pi tmp = pq.front();
		pq.pop();

		for (int k = 0; k < X; k++) {
			int dx = tmp.first + k * tmp.second;
			if (dx >= 0 && dx < N && dp[dx] != 1) {
				dp[dx] = 1;
			}
			else {
				return false;
			}
		}
	}
	return true;
}
bool go_h(int idx, int N, int X) {
	memset(dp, 0, sizeof(int) * 21);
	queue<pi> pq;
	for (int i = 1; i < N; i++) {
		if (map[i - 1][idx] != map[i][idx]) {
			if (abs(map[i - 1][idx] - map[i][idx]) > 1) // fail
				return false;
			if (map[i - 1][idx] < map[i][idx])
				pq.push(make_pair(i - 1, -1));
			else
				pq.push(make_pair(i, 1));
		}
	}
	while (pq.size()) {
		pi tmp = pq.front();
		pq.pop();

		for (int k = 0; k < X; k++) {
			int dx = tmp.first + k * tmp.second;
			if (dx >= 0 && dx < N && dp[dx] != 1) {
				dp[dx] = 1;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int T, N, X, sum;
	bool res;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (go_v(i, N, X))
				sum++;
			if (go_h(i, N, X))
				sum++;
		}
		cout << "#" << t << " " << sum << "\n";
	}
}