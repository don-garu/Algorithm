#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_digit(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

stack<char> sc;
stack<int> cal;

string str, tmp;
int len, res;

void postfix() {
	for (int i = 0; i < len; i++) {
		if (is_digit(str[i]))
			tmp += str[i];
		else {
			switch (str[i]) {
			case '+':
				if (sc.empty())
					sc.push(str[i]);
				else {
					while (sc.size()) {
						char tc = sc.top();
						if (tc == '(')
							break;
						sc.pop();
						tmp += tc;
					}
					sc.push(str[i]);
				}
				break;
			case '*':
				if (sc.empty() || sc.top() == '+')
					sc.push(str[i]);
				else {
					while (sc.size()) {
						char tc = sc.top();
						if (tc == '(' || tc == '+')
							break;
						sc.pop();
						tmp += tc;
					}
					sc.push(str[i]);
				}
				break;
			case '(':
				sc.push(str[i]);
				break;
			case ')':
				while (sc.size()) {
					char tc = sc.top();
					sc.pop();
					if (tc == '(')
						break;
					tmp += tc;
				}
				break;
			}
		}
	}
	while (sc.size()) {
		char tc = sc.top();
		sc.pop();
		tmp += tc;
	}
}
void calculate() {
	int op1, op2, tmp_r;
	len = tmp.length();
	for (int i = 0; i < len; i++) {
		if (is_digit(tmp[i]))
			cal.push(tmp[i] - '0');
		else {
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
				break;
			}
		}
	}
	res = cal.top();
	cal.pop();
}

int main() {
	for (int t = 1; t <= 10; t++) {
		tmp.clear();
		str.clear();
		while (sc.size())
			sc.pop();
		while (cal.size())
			cal.pop();

		cin >> len >> str;
		postfix();
		calculate();
		cout << "#" << t << " " << res << "\n";
	}
}