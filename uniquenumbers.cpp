#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	unordered_set<string> numbers;
	int n;
	cin >> n;
	string temp;
	for (int i=0; i<n; i++){
		cin >> temp;
		numbers.insert(temp);
	}
	cout << numbers.size();
}