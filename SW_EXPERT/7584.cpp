// 7584. 자가 복제 문자열
#include <iostream>
using namespace std;

int solve(long long num) {
	if (num == 1 || num == 2)
		return 0;
	else if (num == 3)
		return 1;
	long long i = 1;
	for (i = 1; num >= (1LL << i++); );
	long long tmp = num - (1LL << (i - 2));
	if (tmp == 0)
		return 0;
	else
		return !solve((1LL << (i - 2)) - tmp);
}

int main() {
	int T;
	long long K;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K;
		cout << "#" << t << " " << solve(K) << "\n";
	}
}