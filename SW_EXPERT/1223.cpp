#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str, tmp;
stack<char> sc;
stack<int> cal;
int n, res;

void calculate() {
	int op1, op2;
	n = tmp.length();
	for (int i = 0; i < n; i++) {
		if (tmp[i] >= '0' && tmp[i] <= '9')
			cal.push(tmp[i] - '0');
		else
			switch (tmp[i]) {
			case '+':
				op1 = cal.top();
				cal.pop();
				op2 = cal.top();
				cal.pop();
				cal.push(op2 + op1);
				break;
			case '*':
				op1 = cal.top();
				cal.pop();
				op2 = cal.top();
				cal.pop();
				cal.push(op2 * op1);
			}
	}
	res = cal.top();
	cal.pop();
}

void postfix() {
	for (int i = 0; i < n; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			tmp += str[i];
		else
			switch (str[i]) {
			case '+':
				while (sc.size()) {
					tmp += sc.top();
					sc.pop();
				}
				sc.push(str[i]);
				break;
			case '*':
				while (sc.size()) {
					if (sc.top() == '+')
						break;
					tmp += sc.top();
					sc.pop();
				}
				sc.push(str[i]);
				break;
			}
	}
	while (sc.size()) {
		tmp += sc.top();
		sc.pop();
	}
}

int main() {
	for (int t = 1; t <= 10; t++) {
		while (sc.size())
			sc.pop();
		while (cal.size())
			cal.pop();
		tmp.clear();
		str.clear();

		cin >> n;
		cin >> str;
		postfix();
		calculate();
		cout << "#" << t << " " << res << "\n";
	}
}