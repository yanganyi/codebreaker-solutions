#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int fence = 0;
    string op;
    for (int i=0; i<m; i++) {
        cin >> op;
        if (op == "LAND") 		fence += 1;
        if (op == "LEAVE") 		fence -= 1;
        if (op == "EVACUATE") 	fence = 0;
        if (fence<0 || fence>n) {
            cout << "PLAN REJECTED\n";
            return 0;
        }
    }
    cout << "PLAN ACCEPTED\n";
}