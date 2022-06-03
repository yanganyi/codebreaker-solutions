#include <bits/stdc++.h>
using namespace std;

struct node{

    // children
    node *l_node, *r_node;

    // range of node
    int l, r;

    // value of node
    int val = 0;

    // constructor
    node(int range_start, int range_end){
        l = range_start; r = range_end;
        if (l == r) l_node = r_node = NULL;
        else{
            int m = (l+r) / 2;
            l_node = new node(l, m);
            r_node = new node(m+1, r);
        }
    }

    // propagate value down to the leaf & update value of current node
    void update_for_min(int ind, int new_val){
        if (l == r) {val = new_val; return;}
        int m = (l+r) / 2;
        if (ind <= m) 	l_node -> update_for_min(ind, new_val);
        else 			r_node -> update_for_min(ind, new_val);

        // apply min
        val = min(l_node->val, r_node->val);
    }

    void update_for_sum(int ind, int new_val){
        if (l == r) {val = new_val; return;}

        int m = (l+r) / 2;
		if (ind <= m) 	l_node -> update_for_sum(ind, new_val);
        else 			r_node -> update_for_sum(ind, new_val);

        // apply sum
        val = l_node->val + r_node->val;
    }

    int query_min(int range_start, int range_end){
        // if range is fully covered by [l,r]
        if (range_start<=l && r<=range_end) return val;

        int ans_left=INT_MAX;
        int ans_right=INT_MAX;

        int m = (l+r) / 2;
        if (range_start <= m) 	ans_left = l_node->query_min(range_start, range_end);
        if (m < range_end) 		ans_right = r_node->query_min(range_start, range_end);

        // apply min
        return min(ans_left,ans_right);
    }
    
    int query_sum(int range_start,int range_end){
        // if range is fully covered by [l,r]
        if (range_start<=l && r<=range_end) return val;

        int ans_left=0;
        int ans_right=0;

        int m = (l+r) / 2;
        if (range_start <= m) 	ans_left = l_node -> query_min(range_start, range_end);
        if (m < range_end) 		ans_right = r_node -> query_min(range_start, range_end);

        //apply sum func
        return ans_left+ans_right;
    }
    
}*root;

void init(int n){root=new node(0,n);}

void update(int ind, int val){root -> update_for_min(ind, val);}

int query(int left, int right){return root -> query_min(left, right);}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,q;
    cin >> n >> q;
    init(n);

    int op, a, b;
    for (int i=0; i<q; i++){
        cin >> op >> a >> b;
        if (op == 1) update(a, b);
        else cout << query(a, b) << "\n";
    }
}
// this comment is literally just here for 100 lines