#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

struct compare {
	bool operator()(pi& a, pi& b) {
		return a.first > b.first;
	}
};
int vis[100001], cnt = 0;

int dir[2] = { -1, 1 };
int main() {
	int n, k, res;
	cin >> n >> k;
	priority_queue<pi, vector<pi>, compare> pq;
	pq.push(make_pair(0, n));
	while (pq.size()) {
		int tmp_sc = pq.top().first, tmp_loc = pq.top().second;
		pq.pop();
		if (tmp_sc > vis[tmp_loc])
			continue;
		if (tmp_loc == k) {
			if (vis[tmp_loc] == 0) {
				cnt = 0;
			}
			else if (tmp_sc > vis[tmp_loc]) {
				break;
			}
		}
		vis[tmp_loc] = 1;
		if (tmp_loc * 2 >= 0 && tmp_loc * 2 < 100001 && vis[tmp_loc * 2] != 1) {
			pq.push(make_pair(tmp_sc, tmp_loc * 2));
		}
		for (int k = 0; k < 2; k++) {
			int next = tmp_loc + dir[k];
			if (next >= 0 && next < 100001 && vis[next] != 1) {
				pq.push(make_pair(tmp_sc + 1, next));
			}
		}
	}
	cout << res << "\n";
}