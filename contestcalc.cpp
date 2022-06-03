#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> results;

    int contestant_count, selected_count;

    cin >> contestant_count;

    string temp_str;
    int temp_int;
    for (int i=0; i<contestant_count; i++){
        cin >> temp_str >> temp_int;
        results[temp_str] = temp_int;
    }

    cin >> selected_count;

    string selected[selected_count];
    for (int j=0; j<selected_count; j++) cin >> selected[j];

    int sum = 0;
    for (string s: selected) sum += results[s];

    cout << sum / selected_count;
}