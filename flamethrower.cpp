#include <bits/stdc++.h>
using namespace std;

int main(){
    int maximum=0;
    int n, k;
    cin >> n >> k;
    int trees[n];

    for (int i=0; i<n; i++) cin >> trees[i];
    for (int j=0; j<n-k+1; j++){
        int sum = 0;
        for (int a=0; a<k; a++) sum += trees[j+a];
        maximum = max(maximum,sum);
    }

    cout << maximum;
}