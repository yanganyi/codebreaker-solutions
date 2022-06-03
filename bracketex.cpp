#include <bits/stdc++.h>
using namespace std;

bool is_a_pair(char a, char b){
    bool round = 	a=='(' && b==')';
    bool square =	a=='[' && b==']';
    bool curly =	a=='{' && b=='}';

    if (round || square || curly) return true;
    else return false;
}

void bracket_validator(int len, string sequence){

    string close="}])";
    string v="Valid";
    string inv="Invalid";
    stack<char> seq;


    if (len%2 == 1){
        cout << inv;
		// must use "return" not "return 0" since func is void
        return;
    }

    for (int i=0; i<len; i++){
        char obj = sequence[i];
        int index = close.find(obj);


        if (index == string::npos) seq.push(sequence[i]);

        else{
            if (seq.size()==0){
                cout << inv;
                return;
            }
            else if (!is_a_pair(seq.top(),obj)){
                cout << inv;
                return;
            }
            else seq.pop();
        }
    }

    if (seq.size()==0) cout<<v;
    else cout<<inv;
}


int main(){
    int n;
    string sequence;
    cin >> n;
    cin >> sequence;
    bracket_validator(n, sequence);
}