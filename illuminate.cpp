#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int r, c;
    cin >> r >> c;

    long long dot_count = 0;
    char grid[r+2][c+2];
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            cin >> grid[i][j];
            if (grid[i][j] == '.') dot_count++;
        }
    }

    for (int i=0; i<=c+1; i++){
        grid[0][i] = '#';
        grid[r+1][i] = '#';
    }
	
    for (int i=0; i<=r+1; i++){
        grid[i][0]   = '#';
        grid[i][c+1] = '#';
    }

    long long total = 0;

    for (int i=1; i<=r; i++){
        int group_size = 0;
        for (int j=0; j<=c+1; j++){
            if (grid[i][j] == '#'){
                long long add  =  1LL * group_size * group_size;
                if (group_size > 0) total += add;
                group_size = 0;
            }
			else group_size++;
        }
    }
    for (int i=1; i<=c; i++){
        int group_size = 0;
        for (int j=0; j<=r+1; j++){
            if (grid[j][i] == '#'){
                long long add = 1LL*group_size*group_size;
                if (group_size > 0) total += add;
                group_size = 0;
            }
			else group_size++;

        }
    }
    cout << total - dot_count;
}