#include <bits/stdc++.h>
using namespace std;

int exponentiate(int base, int power, int modulo){
    if (power == 1) return base % modulo;
    
    int temp = exponentiate(base, power/2, modulo);
    
    temp = (1LL * temp * temp) % modulo;
    
    if (power%2 == 0) return temp;
    else return (1LL * temp * base) % modulo;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int testcase_count;
    cin >> testcase_count;

    int base, power, modulo;
    for (int i=0; i<testcase_count; i++){
        cin >> base >> power >> modulo;
        cout << exponentiate(base, power, modulo) << "\n";
    }
}