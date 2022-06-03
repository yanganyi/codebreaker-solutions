#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int> gifts;
    int receiver;
    for (int i=1; i<=n; i++){
        cin >> receiver;
        gifts[receiver] = i;
    }
    for (int i=1; i<=n; i++) cout << gifts[i] << "\n";
}