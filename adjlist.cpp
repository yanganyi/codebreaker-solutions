#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;
    vector<int> g[n+1];
    int a, b;
    
    for (int i=0; i<e; i++){
        cin >> a >> b;
        g[a-1].push_back(b);
        g[b-1].push_back(a);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<g[i].size(); j++){
            if (j==0)	cout << g[i][j];
            else 		cout << " " << g[i][j];
        }
        cout << "\n";
    }
}