#include <iostream>
using namespace std;
typedef pair<int, int> pi;

int T, Minji, Target;

void solve();
pi get_loc(int num);
int mabs(int num);

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> Minji >> Target;
		cout << "#" << t << " ";
		solve();
	}
}

pi get_loc(int num) {
	int sum = 0, i, j;
	for (i = 1; num - (sum + i) > 0; i++) {
		sum += i;
	}
	j = num - sum;
	return make_pair(i, j);
}

void solve() {
	pi l1, l2;
	l1 = get_loc(Minji);
	l2 = get_loc(Target);
	if (l1.first > l2.first)
		swap(l1, l2);
	int diff_x = l1.second - l2.second;
	int diff_y = l1.first - l2.first;

	if (diff_y * diff_x < 0)
		cout << mabs(diff_y) + mabs(diff_x) << "\n";
	else {
		diff_y = mabs(diff_y);
		diff_x = mabs(diff_x);
		if (diff_y > diff_x)
			cout << diff_y << "\n";
		else
			cout << diff_x << "\n";
	}
}

int mabs(int num) {
	return (num > 0) ? num : -num;
}