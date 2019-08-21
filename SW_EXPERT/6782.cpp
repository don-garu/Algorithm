#include <iostream>
#include <cmath>
using namespace std;

int T;
long long N;

void solve();

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << "#" << t << " ";
		solve();
	}
}

void solve() {
	long long cnt = 0;
	long long tmp;
	while (N != 2) {
		if (N == 1) {
			cnt++;
			break;
		}
		tmp = (long long)sqrt(N);
		if (N - tmp * tmp == 0) {
			N = tmp;
			cnt++;
		}
		else {
			cnt += (tmp + 1) * (tmp + 1) - N + 1;
			N = tmp + 1;
		}
	}
	cout << cnt << "\n";
}