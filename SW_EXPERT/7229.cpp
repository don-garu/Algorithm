#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<double, int>> v;
double res_dif;
int T, N, M;

void solve();
void cut(int idx, vector<double, int> vec, int cnt);

int main() {
	double dd;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		res_dif = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> dd;
			v.push_back(make_pair(dd, 1));
		}
		cin >> M;
		solve();
		cout << "#" << t << " " << res_dif << "\n";
	}
}

void cut(int idx, vector<pair<double, int>> vec, int cnt) {
	// dfs 처럼.
	// 모든 경우를 다 확인
}

void solve() {
	cut(0, v, M);
}