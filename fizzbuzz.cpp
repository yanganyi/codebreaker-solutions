#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	long long n, a, b;
	cin >> n >> a >> b;
	
	for (long long i=1; i<=n; i++){
		bool fizz = (i%a == 0);
		bool buzz = (i%b == 0);
		if (fizz && buzz) cout << "FizzBuzz\n";
		else if (fizz) cout << "Fizz\n";
		else if (buzz) cout << "Buzz\n";
		else cout << i << "\n";
	}
}
