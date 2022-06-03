#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int rows,columns;
    cin >> rows >> columns;
    vector<vector<int>> wall;
    vector<vector<int>> maximum;

    for (int i=0; i<rows; i++){
        wall.push_back({});
        maximum.push_back({});
    }

    int temp;
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            cin >> temp;
            wall[i].push_back(temp);
            if (i == 0) maximum[i].push_back(temp);
            else maximum[i].push_back(0);
        }
    }

    for (int i=1; i<rows; i++){
        for (int j=0; j<columns; j++){
            maximum[i][j] = maximum[i-1][j];
            if (j > 0) maximum[i][j] = max(maximum[i][j], maximum[i-1][j-1]);
            if (j = columns-1) maximum[i][j] = max(maximum[i][j], maximum[i-1][j+1]);
            maximum[i][j] += wall[i][j];
        }
    }

    int max_flies = 0;
    for (int j=0; j<columns; j++) max_flies=max(max_flies, maximum[rows-1][j]);

    cout<<max_flies;
}
