#include <bits/stdc++.h>
using namespace std;

int main(){
    int brick_count;
    cin >> brick_count;

    stack<int> brick_stack;

    int brick_num;
    for (int i=0; i<brick_count; i++){
        cin >> brick_num;
        while (!brick_stack.empty() && brick_stack.top()<=brick_num) brick_stack.pop();
        brick_stack.push(brick_num);
    }

    while (brick_stack.size() != 0){
        cout<<brick_stack.top() << "\n";
        brick_stack.pop();
    }
}