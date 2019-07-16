#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct {
	vector<int> children;
	int parent[15], depth;
} node;

node tree[10001];

int lca(int x, int y);
int depth_setting(int x);
int search(int x);
void reset();

int main() {
	int T, V, E, X, Y, a, b, res_lca, res_children;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		reset();
		cin >> V >> E >> X >> Y;
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			tree[a].children.push_back(b);
			tree[b].parent[0] = a;
		}
		depth_setting(1);
		for (int j = 1; j < 15; j++) {
			for (int i = 1; i <= V; i++) {
				tree[i].parent[j] = tree[tree[i].parent[j - 1]].parent[j - 1];
			}
		}
		res_lca = lca(X, Y);
		res_children = search(res_lca);
		cout << "#" << t << " " << res_lca << " " << res_children << "\n";
	}
}

int search(int x) {
	int tmp = 0;
	if (tree[x].children.empty())
		return 1;
	for (int i = 0; i < tree[x].children.size(); i++) {
		tmp += search(tree[x].children[i]);
	}
	return tmp + 1;
}

int lca(int x, int y) {
	if (tree[x].depth > tree[y].depth) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	int d1 = tree[x].depth, d2 = tree[y].depth;
	for (int i = 14; i >= 0; i--) {
		if (d2 - d1 >= (1 << i)) {
			y = tree[y].parent[i];
			d2 = tree[y].depth;
		}
	}
	if (x == y)
		return x;
	while (x != y) {
		x = tree[x].parent[0];
		y = tree[y].parent[0];
	}
	return x;
}

int depth_setting(int x) {
	tree[x].depth = tree[tree[x].parent[0]].depth + 1;
	for (int i = 0; i < tree[x].children.size(); i++) {
		depth_setting(tree[x].children[i]);
	}
	return 0;
}

void reset() {
	for (int i = 0; i < 10001; i++) {
		tree[i].children.clear();
		tree[i].depth = 0;
		memset(tree[i].parent, 0, sizeof(int) * 15);
	}
}