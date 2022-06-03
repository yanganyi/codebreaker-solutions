#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    int data[n];
    for (int i=0; i<n; i++) cin >> data[i];
    long long global_optimum = 0, local_optimum = 0;
    priority_queue<int> pq;

    int i = 0;
    while (pq.size() < k){
        if (i >= n) break;
        else pq.push(data[i++]);
    }

    while (true){
        while (!pq.empty() && pq.top()>=0){
            int t = pq.top();
            local_optimum += t;
            pq.pop();
            if (i<n) pq.push(data[i++]);
        }
		global_optimum = max(global_optimum, local_optimum);

        if (!pq.empty()) {
            int t = pq.top();
            local_optimum += t;
            pq.pop();
        }
        if (i >= n) break;
        else pq.push(data[i++]);
    }

    cout << global_optimum << '\n';
}