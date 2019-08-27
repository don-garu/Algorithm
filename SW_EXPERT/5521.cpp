#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[501];
int vis[501];
int T, N, M, a, b;
int Answer;

void solve();
void dfs(int idx, int cnt);

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 501; i++) {
			adj[i].clear();
			vis[i] = 0;
		}
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		solve();
		cout << "#" << t << " " << Answer << "\n";
	}
}

void dfs(int idx, int cnt) {
	if (cnt == 2)
		return;
	int sz = adj[idx].size();
	for (int i = 0; i < sz; i++) {
		vis[adj[idx][i]] = 1;
		dfs(adj[idx][i], cnt + 1);
	}
}

void solve() {
	Answer = 0;
	vis[1] = 1;
	dfs(1, 0);
	for (int i = 2; i <= N; i++) {
		if (vis[i])
			Answer++;
	}
}