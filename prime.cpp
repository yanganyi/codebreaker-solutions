#include <bits/stdc++.h>
using namespace std;

bool isprime(long n) {
    if (n < 2) return false;
    if (n==2 || n==3) return true;
    if (n%2 == 0) return false;
    for (int i=3; i<sqrt(n)+1; i+=2) if (n%i==0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a;
    cin >> a;
    if (isprime(a)) cout << "Prime";
    else cout << "Not Prime";
}