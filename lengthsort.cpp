#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2) return s1.size() > s2.size();

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int num_of_words;
    cin >> num_of_words;
    vector<string> words;

    string word;
    for (int i=0; i<num_of_words; i++){
        cin >> word;
        words.push_back(word);
    }

    stable_sort(words.begin(), words.end(), cmp);

    for (auto it=words.begin(); it!=words.end(); it++) cout << *it << "\n";
}