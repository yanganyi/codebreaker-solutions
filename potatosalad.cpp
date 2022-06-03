#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, t;
    cin >> n >> t;
    int nums[n];
    for (int i=0; i<n; i++) cin >> nums[i];
    sort(nums, nums+n, greater<int>());
    int sum = 0;
    for (int i=0; i<t; i++) sum += nums[i];
    cout << sum;
}