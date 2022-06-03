#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int lis[n];
    int ans = 1;
    for (int i=0; i<n; i++) cin>>arr[i];
    for (int i=0; i<n; i++){
        lis[i]=1;
        for (int j=0;j<i;j++){
            if (arr[j] < arr[i]) lis[i] = max(lis[i], 1+lis[j]);
            ans = max(ans, lis[i]);
        }
    }
    cout<<ans;
}