#include <bits/stdc++.h>
using namespace std;

void process(deque<char> &seq, string str, char b, int c){
    if (str == "ADD_BACK") seq.push_back(b);
    else if (str == "ADD_FRONT") seq.push_front(b);
    else if (str == "SNIP_BACK"){
        int num = seq.size()-c-1;
        for (int j=0; j<num; j++) seq.pop_back();

    }
    else if (str == "SNIP_FRONT"){
        int num = c+1;
        for (int j=0; j<num; j++) seq.pop_front();
    }
    else if (str == "QUERY") cout << seq[c] << "\n";
}

int main(){
    deque<char> seq;

    int operation_count;
    cin >> operation_count;

    string ops[operation_count];
    char nucl[operation_count];
    int numbers[operation_count];

    for (int i=0; i<operation_count; i++){
        cin >> ops[i];
        if (ops[i] == "ADD_BACK"  ||  ops[i] == "ADD_FRONT") cin >> nucl[i];
        else cin >> numbers[i];
    }
    for (int i=0; i<operation_count; i++){
        if (ops[i] == "ADD_BACK"  ||  ops[i] == "ADD_FRONT") process(seq, ops[i], nucl[i], -1);
        else process(seq,ops[i], '_', numbers[i]);
    }
}