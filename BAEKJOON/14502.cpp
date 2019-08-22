#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;

void solve();

vector<pi> empty_space, virus;
vector<int> wall;
int map[10][10], tmp[10][10], vis[10][10];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int N, M, result;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				empty_space.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}
	solve();
	cout << result << "\n";
}

void bfs() {
	queue<pi> pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2)
				pq.push(make_pair(i, j));
		}
	}
	while (pq.size()) {
		pi loc = pq.front();
		pq.pop();
		if (vis[loc.first][loc.second] == 1)
			continue;
		vis[loc.first][loc.second] = 1;
		tmp[loc.first][loc.second] = 2;
		for (int k = 0; k < 4; k++) {
			int ny = loc.first + dy[k], nx = loc.second + dx[k];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && tmp[ny][nx] == 0 && vis[ny][nx] == 0)
				pq.push(make_pair(ny, nx));
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0)
				cnt++;
		}
	}
	/*	printf("#########WALL#########\n");
		for (int i = 0; i < 3; i++)
			printf("(%d, %d) ", empty_space[wall[i]].first, empty_space[wall[i]].second);
		printf("\nCNT : %d\n", cnt);*/
	if (result < cnt)
		result = cnt;
}

void diffusion() {
	memset(vis, 0, sizeof(vis));
	memcpy(tmp, map, sizeof(map));
	for (int i = 0; i < wall.size(); i++) {
		tmp[empty_space[wall[i]].first][empty_space[wall[i]].second] = 1;
	}
	bfs();
}

void dfs(int idx) {
	if (wall.size() == 3) {
		diffusion();
		return;
	}
	for (int i = idx + 1; i < empty_space.size(); i++) {
		wall.push_back(i);
		dfs(i);
		wall.pop_back();
	}
}

void solve() {
	for (int i = 0; i < empty_space.size(); i++) {
		wall.push_back(i);
		dfs(i);
		wall.pop_back();
	}
}