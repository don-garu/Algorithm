#include <iostream>
#include <vector>
#define MXSIZE 4000
using namespace std;

struct atom {
	int r, c, energy;
	int dir;
};

int dr[4] = { 1, -1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
vector<atom> atoms;
int map[MXSIZE + 1][MXSIZE + 1];
int N, T;
int Answer;

void solve() {
	Answer = 0;
	int sz;
	while (atoms.size()) {
		sz = atoms.size();
		for (int i = 0; i < sz; i++) {
			map[atoms[i].r][atoms[i].c] = 0;
			int dir = atoms[i].dir;
			int nr = atoms[i].r + dr[dir];
			int nc = atoms[i].c + dc[dir];
			if (nr < 0 || nr > MXSIZE || nc < 0 || nc > MXSIZE) {
				atoms[i].energy = 0;
				continue;
			}
			atoms[i].r = nr;
			atoms[i].c = nc;
			map[nr][nc] += atoms[i].energy;
		}
		for (int i = 0; i < sz; i++) {
			if (atoms[i].energy == 0)
				continue;
			int cr = atoms[i].r, cc = atoms[i].c;
			if (map[cr][cc] != atoms[i].energy) {
				//printf("LOC (%d, %d) Boom %d\n", cr, cc, map[cr][cc]);
				Answer += map[cr][cc];
				map[cr][cc] = 0;
				atoms[i].energy = 0;
			}
		}
		for (vector<atom>::iterator it = atoms.begin(); it != atoms.end(); ) {
			if ((*it).energy == 0)
				it = atoms.erase(it);
			else
				it++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, d, K;
	atom tmp;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> d >> K;
			y = (y + 1000) * 2;
			x = (x + 1000) * 2;
			tmp.r = y;
			tmp.c = x;
			tmp.dir = d;
			tmp.energy = K;
			atoms.push_back(tmp);
		}
		solve();
		cout << "#" << t << " " << Answer << "\n";
	}
}