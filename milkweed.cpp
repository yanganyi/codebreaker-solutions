#include <bits/stdc++.h>
using namespace std;

bool out_of_boundary(int rows, int cols, int r, int c){
    if (r<0 || r>=rows || c<0 || c>=cols) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int cols, rows;
    cin >> cols >> rows;
    int a, b;
    cin >> a >> b;

    vector<vector<char>> grid;
    int grass_count = 0;
    vector<pair<int,int>> toscan;

    for (int i=0; i<rows; i++){
        vector<char> row;
        string temp_s;
        cin >> temp_s;
        for (int j=0; j<cols; j++){
            row.push_back(temp_s[j]);
            if (temp_s[j] == '.') grass_count++;
        }
        grid.push_back(row);
    }
    toscan.push_back(make_pair(rows-b, a-1));

    int day = 0;

    while (grass_count > 0){
        vector<pair<int,int>> new_toscan;
        for (int i=0; i<toscan.size(); i++){
            auto p = toscan[i];
            int r = p.first;
            int c = p.second;

            if (out_of_boundary(rows, cols, r, c)) continue;
            if (grid[r][c] == '*') continue;
            if (grid[r][c] == 'M') continue;


            grid[r][c] = 'M';
            grass_count--;

            new_toscan.push_back(make_pair(r-1, c));
            new_toscan.push_back(make_pair(r-1, c-1));
            new_toscan.push_back(make_pair(r-1, c+1));

            new_toscan.push_back(make_pair(r,   c-1));
            new_toscan.push_back(make_pair(r,   c+1));

            new_toscan.push_back(make_pair(r+1, c-1));
            new_toscan.push_back(make_pair(r+1, c));
            new_toscan.push_back(make_pair(r+1, c+1));
        }
        if (new_toscan.size()>0 && grass_count>0){
            toscan = new_toscan;
            day++;
        }
        else break;
    }
    cout << day;
}