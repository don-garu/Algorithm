#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> pp;

int map[16][16], ans, N;
int x[3] = { 1, 1, 0 }, y[3] = { 0, 1, 1 }; // 가로, 세로, 대각선

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	queue<pp> pq;
	pq.push(make_pair(make_pair(0, 1), 0));
	while (pq.size()) {
		pi loc = pq.front().first;
		int cur = pq.front().second;
		pq.pop();
		//cout << "(" << loc.first << ", " << loc.second << ") : " << cur << "\n";
		if (loc.first == N - 1 && loc.second == N - 1) {
			ans++;
			continue;
		}
		pi next;
		if (cur == 0) {
			next = make_pair(loc.first + y[0], loc.second + x[0]);
			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N
				&& map[next.first][next.second] == 0) {
				pq.push(make_pair(next, 0));
			}
			next = make_pair(loc.first + y[1], loc.second + x[1]);
			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N
				&& map[loc.first + 1][loc.second] == 0 && map[loc.first + 1][loc.second + 1] == 0 && map[loc.first][loc.second + 1] == 0) {
				pq.push(make_pair(next, 1));
			}
		}
		else if (cur == 1) {
			next = make_pair(loc.first + y[0], loc.second + x[0]);
			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N
				&& map[next.first][next.second] == 0) {
				pq.push(make_pair(next, 0));
			}
			next = make_pair(loc.first + y[1], loc.second + x[1]);
			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N
				&& map[loc.first + 1][loc.second] == 0 && map[loc.first + 1][loc.second + 1] == 0 && map[loc.first][loc.second + 1] == 0) {
				pq.push(make_pair(next, 1));
			}
			next = make_pair(loc.first + y[2], loc.second + x[2]);
			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N
				&& map[next.first][next.second] == 0) {
				pq.push(make_pair(next, 2));
			}
		}
		else if (cur == 2) {
			next = make_pair(loc.first + y[1], loc.second + x[1]);
			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N
				&& map[loc.first + 1][loc.second] == 0 && map[loc.first + 1][loc.second + 1] == 0 && map[loc.first][loc.second + 1] == 0) {
				pq.push(make_pair(next, 1));
			}
			next = make_pair(loc.first + y[2], loc.second + x[2]);
			if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N
				&& map[next.first][next.second] == 0) {
				pq.push(make_pair(next, 2));
			}
		}
	}
	cout << ans << "\n";
}