#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int T, N;
int *vis;
pi *nut;

vector<pi> rev, tmp;

void solve();
void dfs();

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		tmp.clear();
		rev.clear();
		nut = (pi *)calloc(sizeof(pi), N);
		for (int i = 0; i < N; i++) {
			cin >> nut[i].first >> nut[i].second;
		}
		vis = (int *)calloc(sizeof(int), N);
		solve();
		free(nut);
		free(vis);
		cout << "#" << t << " ";
		for (int i = 0; i < rev.size(); i++) {
			cout << rev[i].first << " " << rev[i].second << " ";
		}
		cout << "\n";
	}
}

void dfs() {
	pi cur = tmp.back();
	if (rev.size() < tmp.size()) {
		rev = tmp;
	}
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (vis[i] == 0 && cur.second == nut[i].first) {
			vis[i] = 1;
			tmp.push_back(nut[i]);
			dfs();
			tmp.pop_back();
			vis[i] = 0;
			flag = true;
		}
	}
	if (!flag)
		return;
}

void solve() {
	for (int i = 0; i < N; i++) {
		tmp.push_back(nut[i]);
		vis[i] = 1;
		dfs();
		vis[i] = 0;
		tmp.pop_back();
	}
}