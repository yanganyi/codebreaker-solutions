#include <bits/stdc++.h>
using namespace std;

string upper(string s) {
    string new_str(s);
    for (auto & c: new_str) c = toupper(c);
    return new_str;
}

int main() {
    int l;
    cin >> l;
    int data[l];
    for (int i=0; i<l; i++) cin >> data[i];
    sort(data, data+l);

    int qn;
    cin >> qn;
    for (int i=0; i<qn; i++){
        int q;
        cin >> q;
        int greater = l - (lower_bound(data,data+l,q+1) - data);

        int less = lower_bound(data,data+l,q) - data;
        cout << "Smaller: " << less << ", Greater: " << greater << "\n";
    }
}