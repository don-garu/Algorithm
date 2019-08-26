// 5658. 보물상자 비밀번호
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int T, N, K, M;
string str;

vector<LL> v;
vector<string> sv;

void solve();
void split();
void m_xtoi();

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		cin >> str;
		M = N / 4;
		solve();
		cout << "#" << t << " " << v[K - 1] << "\n";
	}
}

void __xtoi__(string s) {
	LL num = 0, tmp;
	int sz = M;
	for (int i = 0; i < sz; i++) {
		if (s[i] >= 'A' && s[i] <= 'F')
			tmp = s[i] - 'A' + 10;
		else
			tmp = s[i] - '0';
		num <<= 4;
		num += tmp;
	}
	v.push_back(num);
}

bool comp(const LL a, const LL b) {
	return a > b;
}

void m_xtoi() {
	for (int i = 0; i < sv.size(); i++) {
		__xtoi__(sv[i]);
	}
}

void split() {
	for (int m = 0; m < 4; m++) {
		sv.push_back(str.substr(m * M, M));
	}
}

void solve() {
	v.clear();
	sv.clear();
	for (int m = 0; m < M; m++) {
		split();
		str.insert(str.begin(), str.back());
		str.pop_back();
	}
	sort(sv.begin(), sv.end());
	sv.erase(unique(sv.begin(), sv.end()), sv.end());
	m_xtoi();
	sort(v.begin(), v.end(), &comp);
}