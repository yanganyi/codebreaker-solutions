#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int hill_count, frog_count, mosquito_count;
    cin >> hill_count >> frog_count >> mosquito_count;

    vector<int> frog_jump_length;
    vector<int> hills_with_mosquito;

    int temp;

    for (int i=0; i<frog_count; i++){
        cin >> temp;
        frog_jump_length.push_back(temp);
    }

    for (int i=0; i<mosquito_count; i++){
        cin >> temp;
        hills_with_mosquito.push_back(temp);
    }

    vector<int> frog_index;
    int min_mosquito_squashed = INT32_MAX;
    int mosquito_squashed = 0;
    for (int i=0; i<frog_count; i++){
        for (auto it=hills_with_mosquito.begin(); it!=hills_with_mosquito.end(); it++){
            if (*it%frog_jump_length[i] == 0) mosquito_squashed++;
        }
        if (mosquito_squashed == min_mosquito_squashed) frog_index.push_back(i+1);
        if (mosquito_squashed < min_mosquito_squashed){
            frog_index.clear();
            min_mosquito_squashed = mosquito_squashed;
            frog_index.push_back(i+1);
        }

        mosquito_squashed = 0;
    }

    int len = frog_index.size();

    cout << len << "\n";
    for (int i=0; i<len; i++) cout << frog_index[i] << " ";
}