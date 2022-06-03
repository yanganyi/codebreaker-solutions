#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
  ll n, p;
  cin >> n >> p;
  ll m = 0;
  ll a[n];
  for(ll i=0; i<n; i++) cin >> a[i];
  for(ll i=0; i<n; i++){
    ll sum=0, no=0;
    while(sum<=p && i+no<n){
      sum += a[i+no];
	  no++;
    }
    m = max(no,m);
  }
  cout << m-1;
}