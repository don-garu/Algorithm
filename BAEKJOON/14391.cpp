#include <iostream>
#include <string>
using namespace std;

int map[10][10];
int N, M;
int gb_sum;

void solve();
void calculate(int mask);

int main() {
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	solve();
	cout << gb_sum << "\n";
}

void solve() {
	for (int i = 0; i < (1 << (N*M)); i++) {
		calculate(i);
	}
}

void calculate(int mask) {
	int lc_sum = 0;
	int s = 0;
	for (int i = 0; i < N; i++) {
		s = 0;
		for (int j = 0; j < M; j++) {
			int k = i * M + j; // mask indexing
			if ((mask & (1 << k)) == 0) {
				s = s * 10 + map[i][j];
			}
			else {
				lc_sum += s;
				s = 0;
			}
		}
		lc_sum += s;
	}
	for (int j = 0; j < M; j++) {
		s = 0;
		for (int i = 0; i < N; i++) {
			int k = i * M + j;
			if ((mask & (1 << k)) != 0) {
				s = s * 10 + map[i][j];
			}
			else {
				lc_sum += s;
				s = 0;
			}
		}
		lc_sum += s;
	}
	if (gb_sum < lc_sum) {
		gb_sum = lc_sum;
	}
}