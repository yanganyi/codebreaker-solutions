#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0;
    
    int n;
    cin >> n;

    int num;
    for (int i=0; i<n; i++){
        cin >> num;
        sum += num;
    }
    cout << sum;
}