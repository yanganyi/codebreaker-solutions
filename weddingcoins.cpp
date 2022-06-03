#include <bits/stdc++.h>
using namespace std;

int main(){
    
    long long n;
    cin >> n;
    long long count = 0;
    int coins[13] = {1000000, 500000, 100000, 50000, 10000, 5000, 1000, 500, 100, 50, 10, 5, 1};

    for (int i=0; i<13; i++){
        if (n >= coins[i]){
            long long how_many = n/coins[i];
            count += how_many;
            n -= coins[i]*how_many;
        }
        if (n==0) break;
    }
    cout << count;
}
