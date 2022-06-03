#include <bits/stdc++.h>
using namespace std;


void print2dVector(vector<vector<int>> &v){
    int rows, cols;

    // size of each dimension
    rows = v.size();
    if (!v.empty()) cols = v[0].size();
    else cols = 0;

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++) cout << v[i][j] << " ";
        cout << '\n';
    }
}

// INT32_MAX : solution space not yet explored
// -1        : solution space explored, but no solution
// any value between [0,INT_MAX) are valid answers
int search_recursively(vector<vector<int>> &dp, vector<int> coins, int i, int remaining_value){

    if (i<0 || remaining_value<0) return -1;

    if (dp[i][remaining_value] < INT32_MAX) return dp[i][remaining_value];

    // 0 coins needed if remaining value is 0
    if (remaining_value == 0) return 0;

    // search for local optimum, two possibilities

    int local_optimum = INT32_MAX;

    // possibility 1: not using the ith coin
    int outcome1 = search_recursively(dp, coins, i-1, remaining_value);
    if (outcome1 > -1) local_optimum = min(local_optimum, outcome1);

    // possibility 2: using the ith coin
    int outcome2 = search_recursively(dp, coins, i, remaining_value-coins[i]);
    if (outcome2 > -1) local_optimum = min(local_optimum, 1+outcome2);

    // both possibilities are not valid
    if (local_optimum == INT32_MAX) local_optimum = -1;
    dp[i][remaining_value] = local_optimum;
    return local_optimum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int n, value;
    cin >> n >> value;

    vector<int> coins;
    coins.push_back(0);
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        coins.push_back(a);
    }

    vector<vector<int>> dp;
    for (int i=0; i<=n; i++){
        vector<int> row;
        int init_value;
        if (i == 0) init_value = -1;
        else init_value = INT32_MAX;
        for (int j=0; j<=value; j++) row.push_back(init_value);
        dp.push_back(row);
    }

    int a = search_recursively(dp, coins, n, value);
    cout << a;
}
