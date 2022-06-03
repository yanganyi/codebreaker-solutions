#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        sum += a;
    }

    int extra[n];
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        extra[i] = a;
    }

    sort(extra, extra+n, greater<int>());
    for (int i=1; i<n; i++) {
        sum += i * extra[i];
    }

    cout << sum;
}