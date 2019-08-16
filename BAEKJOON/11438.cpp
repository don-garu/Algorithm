#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	vector<int> child;
	int par[18], depth;
}node;

node tree[100001];
vector<int> adj[100001];
int vis[100001];

void dfs(int num, int dep) {
	tree[num].depth = dep;
	for (int i = 0; i < adj[num].size(); i++) {
		if (vis[adj[num][i]] == 0) {
			tree[num].child.push_back(adj[num][i]);
			tree[adj[num][i]].par[0] = num;
			vis[adj[num][i]] = 1;
			dfs(adj[num][i], dep + 1);
		}
	}
}

void lca(int x, int y) {
	if (tree[x].depth > tree[y].depth)
		swap(x, y);
	int d1 = tree[x].depth, d2 = tree[y].depth;
	for (int k = 17; k >= 0; k--) {
		if (d2 - d1 >= (1 << k)) {
			y = tree[y].par[k];
			d2 = tree[y].depth;
		}
	}
	if (x == y) {
		cout << x << "\n";
		return;
	}
	for (int k = 17; k >= 0; k--) {
		if (tree[x].par[k] != tree[y].par[k]) {
			x = tree[x].par[k];
			y = tree[y].par[k];
		}
	}
	cout << tree[x].par[0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x, y;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vis[1] = 1;
	dfs(1, 1);
	for (int k = 1; k <= 17; k++) {
		for (int i = 1; i <= N; i++) {
			tree[i].par[k] = tree[tree[i].par[k - 1]].par[k - 1];
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		lca(x, y);
	}
}