#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    ll n, hours, min, hrs;
    cin >> n;
    hours = n/60;
    min = n%60;
    hrs = hours%24;
    if (hrs < 10) cout << "0" << hrs;
    else cout << hrs;
    if (min < 10) cout << "0" << min;
    else cout << min << "\n";
}