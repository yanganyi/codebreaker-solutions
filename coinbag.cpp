#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int num, size;
    cin >> num >> size;

    int weights[num+1]; weights[0]=0;
    int values[num+1];  values[0]=0;

    // dp[i][j] stores max value considering first i items with total weight j
    vector<vector<int>> dp;
    for (int i=0; i<=num; i++){
        dp.push_back({});
        for (int j=0; j<=size; j++) dp[i].push_back(0);
    }

    int tempa, tempb;
    for (int i=1; i<=num; i++){
        cin >> tempa >> tempb;
        weights[i] = tempa;
        values[i]  = tempb;
    }

    for (int i=1; i<=num;i ++){
        // weight of object might be 0, so we start j from 0
        for (int j=0; j<=size; j++){
            dp[i][j] = dp[i-1][j];
            bool outofbounds1  =  j-weights[i] < 0;
            bool outofbounds2  =  j-1          < 0;
            if (!outofbounds1) dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i]]+values[i]);
            if (!outofbounds2) dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    cout << dp[num][size];
}