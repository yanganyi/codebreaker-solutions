#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc, x, y, x1, y1;
	cin >> tc;
	for (int i=0; i<tc; i++){
		cin >> x >> y >> x1 >> y1;
		if (x==x1 && y==y1) cout << 0 << "\n";
		else if (x==x1) cout << abs(y1-y) << "\n";
		else if (y==y1) cout << abs(x1-x) << "\n";
		else cout << abs(x1-x) + abs(y1-y) + 2 << "\n";
	}
}