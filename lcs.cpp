#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int ans = 0;

    string first, second;
    cin >> first >> second;
    int f = first.length();
    int s = second.length();

    // lcs[i][j] stores the longest common subsequence
    // between the first i characters in the first string
    // and the first j characters in the second string
    vector<vector<int>> lcs;

    for (int i=0; i<=f; i++){
        lcs.push_back({});
        for (int j=0; j<=s; j++){
            lcs[i].push_back(0);
        }
    }

    for (int i=1; i<=f; i++){
        for (int j=1; j<=s; j++){
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            if (first[i-1] == second[j-1]){
                lcs[i][j] = max(lcs[i][j], lcs[i-1][j-1]+1);
            }
        }
    }

    for (int i=1; i<=f; i++) for (int j=1; j<=s; j++) ans=max(ans,lcs[i][j]);

    cout<<ans;
}