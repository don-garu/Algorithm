#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pi;

struct comp {
	bool operator()(pi &a, pi &b) {
		return a.first > b.first;
	}
};
vector<pi> adj[1001];
int connected[1001], sum;
priority_queue<pi, vector<pi>, comp> pq;

int main() {
	int N, M, a, b, x;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> x;
		adj[a].push_back(make_pair(x, b));
		adj[b].push_back(make_pair(x, a));
	}
	pq.push(make_pair(0, 1));
	while (pq.size()) {
		int tmp_val = pq.top().first, cur = pq.top().second;
		pq.pop();
		if (connected[cur] == 1)
			continue;
		connected[cur] = 1;
		sum += tmp_val;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next_val = adj[cur][i].first;
			int next = adj[cur][i].second;
			if (connected[next] == 0) {
				pq.push(make_pair(next_val, next));
			}
		}
	}
	cout << sum << "\n";
}