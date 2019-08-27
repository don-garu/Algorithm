#include <iostream>
using namespace std;

int oprnd[15], opcnt[4];
char optor[15], oplist[4] = { '+', '-', '*', '/' };

int T, N;
int a_max, a_min, Answer;

void solve();
void insert_optor(int idx);
void calc();

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int k = 0; k < 4; k++) {
			cin >> opcnt[k];
		}
		for (int i = 0; i < N; i++) {
			cin >> oprnd[i];
		}
		solve();
		cout << "#" << t << " " << Answer << "\n";
	}
}

void calc() {
	int lc_res = oprnd[0];
	for (int i = 0; i < N - 1; i++) {
		switch (optor[i]) {
		case '+':
			lc_res = lc_res + oprnd[i + 1];
			break;
		case '-':
			lc_res = lc_res - oprnd[i + 1];
			break;
		case '*':
			lc_res = lc_res * oprnd[i + 1];
			break;
		case '/':
			lc_res = lc_res / oprnd[i + 1];
			break;
		}
	}
	if (a_max < lc_res)
		a_max = lc_res;
	if (a_min > lc_res)
		a_min = lc_res;
}

void insert_optor(int idx) {
	if (idx == N - 1) {
		calc();
		return;
	}
	for (int k = 0; k < 4; k++) {
		if (opcnt[k]) {
			opcnt[k]--;
			optor[idx] = oplist[k];
			insert_optor(idx + 1);
			opcnt[k]++;
		}
	}
}

void solve() {
	Answer = 0;
	a_max = -100000000;
	a_min = 1000000000;
	insert_optor(0);
	Answer = a_max - a_min;
}