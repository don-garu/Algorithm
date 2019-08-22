#include <iostream>
using namespace std;

typedef long long ll;

int arr[1000001];
ll result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, B, C;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		int left = arr[i] - B > 0 ? arr[i] - B : 0;
		result++;
		result += (ll)(left / C) + !(!(left % C));
	}
	cout << result << "\n";
}