#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, max = 0, size = 0;
	vector<int> v;
	vector<int>::iterator it;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(arr, 0, sizeof(arr));
		v.clear();
		size = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		v.push_back(arr[0]);
		size++;
		for (int i = 1; i < n; i++) {
			if (v.back() < arr[i]) {
				v.push_back(arr[i]);
			}
			else {
				it = lower_bound(v.begin(), v.end(), arr[i]);
				(*it) = arr[i];
			}
		}
		max = v.size();
		cout << "#" << t << " " << max << "\n";
	}
}