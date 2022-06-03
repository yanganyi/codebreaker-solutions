#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int mod = 998244353;
    int fibo[n] = {0,1};

    for (int i=2; i<=n; i++) fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
    for (int i=0; i<=n; i++) cout << fibo[i] << "\n";
}