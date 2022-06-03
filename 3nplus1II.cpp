#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, t;
    cin >> n >> t;

    for (int i=1; i<t; i++) {
        if (n == 1){
            n = -1;
            break;
        }
        if (n%2 == 0) n/=2;
        else n = 3*n+1;
    }
    cout << n << "\n";
}