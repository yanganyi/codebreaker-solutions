#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    // prime number theorem says that there are approximately n / log(n) primes less than n
    // k = n/log(n), but our estimated k must have at least 50% buffer
    int upper = 2*k+1;    // arbitrary starting point, cater for case where k=1
    while (true){
        int k_with_buffer = upper / log(upper);
        if (k_with_buffer < k*1.5) upper+=k;
        else break;
    }

    int nums[upper];

    bool prime[upper];
    for (int i=0; i<upper; i++) prime[i] = true;
    prime[0] = false; prime[1] = false;

    for (int i=2; i<=sqrt(upper)+1; i++) {
        // only need to mark from i^2
        for (int j=i*i; j<upper; j+=i) prime[j] = false;
    }

    int count = 0;
    for (int i=2; i<upper; i++) {
        if (prime[i] == true) count++;
        if (count == k){
            cout << i;
            break;
        }
    }
}