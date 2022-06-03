#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int kaix, kaiy, pavex, pavey, cellx, celly;
    cin >> kaix >> kaiy;
	cin >> pavex >> pavey;
	cin >> cellx >> celly;

    bool bottom_left = pavex<kaix && pavey<kaiy && cellx<kaix && celly<kaiy;
    bool bottom_right = pavex>kaix && pavey<kaiy && cellx>kaix && celly<kaiy;
    bool top_left = pavex<kaix && pavey>kaiy && cellx<kaix && celly>kaiy;
    bool top_right = pavex>kaix && pavey>kaiy && cellx>kaix && celly>kaiy;

    if (top_left || top_right || bottom_left || bottom_right) cout<<"YES";
    else cout<<"NO";
}