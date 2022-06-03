#include <bits/stdc++.h>
using namespace std;


int main(){
    int lunchbox_count, school_count;
    cin >> lunchbox_count >> school_count;

    vector<int> lunchbox_needed;

    int temp;
    for (int i=0; i<school_count; i++){
        cin >> temp;
        lunchbox_needed.push_back(temp);
    }

    sort(lunchbox_needed.begin(), lunchbox_needed.end());

    int sum = 0;
    for (int j=0; j<school_count; j++){
        sum += lunchbox_needed[j];
        if (sum > lunchbox_count){
            cout << j << "\n";
            return 0;
        }
    }

    cout << school_count << "\n";
}