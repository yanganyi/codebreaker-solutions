#include <stdc++.h>
using namespace std;

int main(){
    set<int> sleeping;

    int cat_count, event_count;
    cin >> cat_count >> event_count;
    
    string command;
    int cat_x, cat_y;
    for (int i=0; i<event_count; i++){
        cin >> command;
        cin >> cat_x;
        if (command == "SLEEP") sleeping.insert(cat_x);
        else if (command == "WAKE") sleeping.erase(sleeping.find(cat_x));
        else{
            cin>>cat_y;
            // not found or no sleeping cats within range
            if (sleeping.lower_bound(cat_x)==sleeping.end() || *sleeping.lower_bound(cat_x)>cat_y) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}