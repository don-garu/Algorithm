#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

vector<pair<double, int>> v;
double res_dif = 100000;
int T, N, M;

void solve();
void cut(int idx, vector<pair<double, int>> vec, int cnt);

int main() {
	double dd;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		res_dif = 100000;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> dd;
			v.push_back(make_pair(dd, 1));
		}
		cin >> M;
		solve();
		cout << setprecision(10) << "#" << t << " " << res_dif << "\n";
	}
}

void cut(int idx, vector<pair<double, int>> vec, int cnt) {
	// dfs 처럼.
	// 모든 경우를 다 확인
	if (cnt == 0 || idx > N - 1) {
		int length = vec.size();
		double sz = 0, max_sz = 0, min_sz = 100000;
		for (int i = 0; i < length; i++) {
			sz = vec[i].first / vec[i].second;
			if (max_sz < sz)
				max_sz = sz;
			if (min_sz > sz)
				min_sz = sz;
		}
		double diff = max_sz - min_sz;
		if (res_dif > diff)
			res_dif = diff;
	}
	else {
		for (int i = 1; i <= cnt + 1; i++) {
			vec[idx].second = i;
			cut(idx + 1, vec, cnt - i + 1);
		}
	}
}

void solve() {
	cut(0, v, M);
}