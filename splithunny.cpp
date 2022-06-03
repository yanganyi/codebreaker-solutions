#include <bits/stdc++.h>
using namespace std;

const int row_delta[4] = {-1,0,1,0};
const int col_delta[4] = {0,1,0,-1};

void dfs(vector<vector<int>> &hunny, int row_count, int col_count, int i, int j){

    // out of bound
    if (i<0 || i>=row_count || j<0 || j>=col_count) return;

    // empty or visited
    if (hunny[i][j]=='.' || hunny[i][j]=='V') return;

    // unvisited -> mark as visited
    hunny[i][j] = 'V';

    // visit in each direction
    for (int k=0; k<4; k++) {
        int r = i + row_delta[k];
        int c = j + col_delta[k];
        dfs(hunny, row_count, col_count, r, c);
    }
}

int dfs_on_2d_matrix(vector<vector<int>> &hunny){
    int cc = 0;
    int row_count = hunny.size();
    int col_count = hunny[0].size();
    for (int i=0; i<row_count; i++){
        for (int j=0; j<col_count; j++){
            if (hunny[i][j]=='.' || hunny[i][j]=='V') continue;
            cc++;
            dfs(hunny, row_count, col_count, i, j);
        }
    }
    return cc;
}

int main(){

    int rows, columns;
    cin >> rows >> columns;

    vector<vector<int>> hunny;

    char temp;
    for (int i=0; i<rows; i++) {
        vector<int> row;
        for (int j=0; j<columns; j++) {
            cin >> temp;
            row.push_back(temp);
        }
        hunny.push_back(row);
    }


    int groups = dfs_on_2d_matrix(hunny);

    cout << "Oh, bother. There are " << groups << " pools of hunny.";
}