#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;

void turn(string& s, int dir) {
	if (dir == 1) {
		s = s.substr(7, 1) + s.substr(0, 7);
	}
	else {
		s = s.substr(1, 7) + s.substr(0, 1);
	}
}

int main() {
	int T, K, n, dir, tmp;
	int vis[5];
	string magnet[5];
	queue<pi> pq;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K;
		for (int i = 1; i < 5; i++) {
			magnet[i] = "";
			for (int j = 0; j < 8; j++) {
				cin >> tmp;
				magnet[i].append(to_string(tmp));
			}
		}
		for (int k = 0; k < K; k++) {
			cin >> n >> dir;
			pq.push(make_pair(n, dir));
			memset(vis, 0, sizeof(int) * 5);
			while (pq.size()) {
				pi tmp = pq.front();
				pq.pop();
				int tmp_n = tmp.first, tmp_dir = tmp.second;
				if (vis[tmp_n] == 1)
					continue;
				vis[tmp_n] = 1;
				// left
				if (tmp_n - 1 > 0 && magnet[tmp_n][6] != magnet[tmp_n - 1][2] && vis[tmp_n - 1] != 1) {
					pq.push(make_pair(tmp_n - 1, tmp_dir * -1));
				}
				// right
				if (tmp_n + 1 < 5 && magnet[tmp_n][2] != magnet[tmp_n + 1][6] && vis[tmp_n + 1] != 1) {
					pq.push(make_pair(tmp_n + 1, tmp_dir * -1));
				}
				turn(magnet[tmp_n], tmp_dir);
			}
		}
		int sum = 0;
		for (int i = 1; i < 5; i++) {
			if (magnet[i][0] == '1')
				sum += pow(2, i - 1);
		}
		cout << "#" << t << " " << sum << "\n";
	}
}