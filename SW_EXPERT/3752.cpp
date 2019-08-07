#include <iostream>
#include <cstring>
using namespace std;

int arr[101], dp[10001];

int main() {
	int T, N, sum, cnt;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		cin >> N;
		sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = sum; j >= 0; j--) {
				if (dp[j])
					dp[j + arr[i]] = 1;
			}
		}
		cnt = 0;
		for (int i = 0; i <= sum; i++) {
			if (dp[i])
				cnt++;
		}
		cout << "#" << t << " " << cnt << "\n";
	}
}