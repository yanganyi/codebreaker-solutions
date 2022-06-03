#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int> lis;

    int n;
    cin >> n;

    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;

        if (i == 0) lis.push_back(temp);
        else if (temp < lis[0]) lis[0] = temp;
        else if (temp > lis.back()) lis.push_back(temp);
        else{
            auto it = upper_bound(lis.begin(), lis.end(), temp);
            *it = temp;
        }
    }

    cout << lis.size();
}