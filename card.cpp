#include <bits/stdc++.h>
using namespace std;

int main(){
    int card_count, target;
    string operations;
    cin >> card_count >> target >> operations;
    deque<int> cards;
    for (int i=0; i<card_count; i++) cards.push_back(i);

	//remove "."
    operations.pop_back();

    for (int j=0; j<operations.size(); j++){
        auto it = cards.begin();
        if (operations[j] == 'B') it++;
        cards.push_back(*it);
        cards.erase(it);
    }

    auto it = cards.begin();
    it += target-1;
	cout << *it << " ";
    it++;
	cout << *it << " ";
    it++;
	cout << *it;
}