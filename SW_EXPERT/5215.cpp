#include <iostream>
#include <cstring>
using namespace std;

int dp[21][10001];
int value[21], kal[21];
bool used[21];

int __MAX__(int x, int y) {
	int res = x > y ? x : y;
	return res;
}
int main() {
	int T, N, L;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> L;
		for (int i = 1; i <= N; i++) {
			cin >> value[i] >> kal[i];
		}
		memset(dp, 0, sizeof(dp));
		memset(used, 0, sizeof(used));
		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= L; i++) {
				if (i < kal[j])
					dp[j][i] = dp[j - 1][i];
				else
					dp[j][i] = __MAX__(dp[j - 1][i], dp[j - 1][i - kal[j]] + value[j]);
			}
		}
		cout << "#" << t << " " << dp[N][L] << "\n";
	}
}