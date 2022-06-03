#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    int reg = 0;

    string ops[n];
    int operand[n];

    for (int i=0; i<n; i++) {
        cin >> ops[i];
        if (ops[i]=="PUSH" || ops[i]=="IFZERO") cin >> operand[i];
    }

    int i = 0;
    while (true) {
        if (ops[i] == "PUSH") s.push(operand[i]);
        else if (ops[i] == "LOAD") s.push(reg);

        else if (ops[i] == "STORE"){
            reg = s.top();
            s.pop();
        }

        else if (ops[i] == "PLUS"){
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(a + b);
        }
        else if (ops[i] == "TIMES"){
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(a * b);
        }

        else if (ops[i] == "IFZERO") {
            int a = s.top(); s.pop();
            if (a != 0) i++;
            else i = operand[i];
            continue;
        }
        else if (ops[i]=="DONE") break;

        i++;
    }

    cout << s.top();
}