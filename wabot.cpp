#include <climits>
using namespace std;

typedef priority_queue<long long,vector<long long>,greater<long long>> my_pq;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    map<int,my_pq> modules;

    int lvl, time;
    for (int i=0; i<n; i++){
        cin >> lvl >> time;
        if (modules.find(lvl) == modules.end()){
            my_pq pq;
            pq.push(time);
            modules[lvl] = pq;
        }
        else{
            my_pq &pq = modules.at(lvl);
            pq.push(time);
        }
    }

    long long cost = 0;

    for (auto it=modules.begin(); it!=modules.end(); it++){
        int level = it->first;
        my_pq &pq = it->second;

        while (pq.size() > 1){
            long long module_a = pq.top(); pq.pop();
            long long module_b = pq.top(); pq.pop();
            long long new_cost = module_a+module_b;
            cost += new_cost;

            if (modules.find(level+1) == modules.end()){
                my_pq new_pq;
                new_pq.push(new_cost);
                modules[level+1] = new_pq;
            }
            else{
                my_pq &new_pq = modules.at(level+1);
                new_pq.push(new_cost);
            }
        }
    }

    cout<<cost;
}