#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef struct {
	char kind;
	int time, stis;
}pinfo;

int T, N, M, airport;
int dist[36][36], vis[36];
pinfo info[36];

vector<int> max_v, path;
int max_satis;

void solve();
void dfs(int sum_time, int sum_satis, int day);

int main() {
	int in_dist;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		max_v.clear();
		path.clear();
		max_satis = 0;
		memset(dist, 0, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		memset(info, 0, sizeof(info));

		cin >> N >> M;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				cin >> in_dist;
				dist[i][j] = dist[j][i] = in_dist;
			}
		}
		for (int i = 0; i < N; i++) {
			cin >> info[i].kind;
			if (info[i].kind == 'P') {
				cin >> info[i].time >> info[i].stis;
			}
			else if (info[i].kind == 'A') {
				airport = i;
			}
		}
		solve();
		cout << "#" << t << " " << max_satis << " ";
		for (int i = 1; i < max_v.size(); i++) {
			cout << max_v[i] + 1 << " ";
		}
		cout << "\n";
	}
}

void dfs(int sum_time, int sum_satis, int day) {
	int loc = path.back();
	int next_time;
	if (day == M && loc == airport && sum_satis) {
		if (max_satis < sum_satis) {
			max_satis = sum_satis;
			max_v = path;
		}
		return;
	}
	bool found = false;
	// 찾으면 그곳을 가고, 못찾으면 공항 혹은 호텔로
	for (int i = 0; i < N; i++) {
		if (info[i].kind == 'A' || info[i].kind == 'H' || vis[i] == 1)
			continue;
		if ((next_time = sum_time + dist[loc][i] + info[i].time) > 540)
			continue;
		found = true;
		path.push_back(i);
		vis[i] = 1;
		dfs(next_time, sum_satis + info[i].stis, day);
		vis[i] = 0;
		path.pop_back();
	}
	if (!found) {
		if (day == M) {
			if ((next_time = sum_time + dist[loc][airport]) > 540)
				return;
			path.push_back(airport);
			vis[airport] = 1;
			dfs(next_time, sum_satis, day);
			path.pop_back();
			vis[airport] = 0;
			return;
		}
		else {
			for (int i = 0; i < N; i++) {
				if (info[i].kind == 'H') {
					if ((next_time = sum_time + dist[loc][i]) > 540)
						continue;
					path.push_back(i);
					vis[i] = 1;
					dfs(0, sum_satis, day + 1);
					vis[i] = 0;
					path.pop_back();
				}
			}
		}
	}
}

void solve() {
	path.push_back(airport);
	dfs(0, 0, 1);
}