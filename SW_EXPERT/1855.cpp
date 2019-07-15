#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
	vector<int> children;
	int parent[21], depth;
} node;

node tree[100001];

int lca(int i, int j);
int dist(int i, int j);
void reset() {
	for (int i = 0; i < 100001; i++) {
		tree[i].children.clear();
		tree[i].depth = 0;
		memset(tree[i].parent, 0, sizeof(int) * 21);
	}
}

int main() {
	queue<int> pq;
	int T, N, t_in, curr, prev;
	long long sum;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		while (pq.size())
			pq.pop();
		reset();
		cin >> N;
		for (int i = 2; i <= N; i++) {
			cin >> t_in;
			tree[i].parent[0] = t_in;
			tree[i].depth = tree[t_in].depth + 1;
			tree[t_in].children.push_back(i);
		}
		for (int j = 1; j < 21; j++) {
			for (int i = 1; i <= N; i++) {
				tree[i].parent[j] = tree[tree[i].parent[j - 1]].parent[j - 1];
			}
		}
		curr = 1;
		for (int i = 0; i < tree[1].children.size(); i++) {
			pq.push(tree[1].children[i]);
		}
		sum = 0;
		while (pq.size()) {
			prev = curr;
			curr = pq.front();
			pq.pop();
			sum += dist(curr, prev);
			for (int i = 0; i < tree[curr].children.size(); i++) {
				pq.push(tree[curr].children[i]);
			}
		}
		cout << "#" << t << " " << sum << "\n";
	}
}

int dist(int i, int j) {
	int lca_loc = lca(i, j);
	int dist = tree[i].depth - tree[lca_loc].depth + tree[j].depth - tree[lca_loc].depth;
	return dist;
}

int lca(int i, int j) {
	if (tree[i].depth > tree[j].depth)
		swap(i, j);
	int l1 = tree[i].depth, l2 = tree[j].depth;
	for (int k = 20; k >= 0; k--) {
		if (l2 - l1 >= (1 << k))
			j = tree[j].parent[k];
	}
	if (i == j)
		return i;
	for (int k = 20; k >= 0; k--) {
		if (tree[i].parent[k] != tree[j].parent[k]) {
			i = tree[i].parent[k];
			j = tree[j].parent[k];
		}
	}
	return tree[i].parent[0];
}