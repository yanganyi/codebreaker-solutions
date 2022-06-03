#include <bits/stdc++.h>
using namespace std;

int main(){
	int mark;
	cin >> mark;
	if		(mark >= 91)	cout<<"A*";
	else if (mark >= 75)	cout<<"A";
	else if (mark >= 60)	cout<<"B";
	else if (mark >= 50)	cout<<"C";
	else if (mark >= 35) 	cout<<"D";
	else if (mark >= 20)	cout<<"E";
	else 					cout<<"U";
	
}