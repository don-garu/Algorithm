#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> sel;
bool map[21][21], check[21];
int N, M, T, a, b;
int result;

void solve();
void dfs(int idx);
bool chk(int target);

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		sel.clear();

		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			map[a][b] = true;
			map[b][a] = true;
		}
		solve();
		cout << "#" << t << " " << result << "\n";
	}
}

bool chk(int target) {
	int sz = sel.size();
	for (int i = 0; i < sz; i++) {
		if (map[sel[i]][target] == true)
			return false;
	}
	return true;
}

void dfs(int idx) {
	if (sel.size() <= N) {
		result++;
		for (int i = idx; i <= N; i++) {
			if (chk(i) && !check[i]) {
				check[i] = 1;
				sel.push_back(i);
				dfs(i + 1);
				sel.pop_back();
				check[i] = 0;
			}
		}
	}
}

void solve() {
	result = 0;
	dfs(1);
}