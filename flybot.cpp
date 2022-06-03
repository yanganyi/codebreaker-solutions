#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int rows, columns;
    cin >> rows >> columns;

    vector<vector<char>> wall;
    vector<vector<int>> routes;

    for (int i=0; i<rows; i++){
        wall.push_back({});
        routes.push_back({});
        for (int j=0; j<columns; j++){
            wall[i].push_back(0);
            routes[i].push_back(0);
        }
    }

    char temp;
    for (int i=0; i<rows; i++) for (int j=0; j<columns; j++) cin >> wall[i][j];

    routes[0][0]=1;

    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            if (i==0 && j==0) continue;
            if (wall[i][j] == "X") continue;

            if (i == 0){
                routes[i][j] = routes[i][j-1];
                continue;
            }
            if (j == 0){
                routes[i][j] = routes[i-1][j];
                continue;
            }

            routes[i][j]   =   (routes[i-1][j] + routes[i][j-1])  %  MOD;
        }
    }

    int output = routes[rows-1][columns-1];
    cout << output;
}