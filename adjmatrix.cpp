#include <bits/stdc++.h>
using namespace std;

int main(){
    int vertex_count, edge_count;
    cin >> vertex_count >> edge_count;

    bool matrix[vertex_count+1][vertex_count+1];
    for (int i=0; i<=vertex_count; i++) for (int j=0; j<=vertex_count; j++) matrix[i][j] = false;

    int nodea, nodeb;
    for (int i=0; i<edge_count; i++){
        cin >> nodea >> nodeb;
        matrix[nodea][nodeb] = true;
        matrix[nodeb][nodea] = true;
    }
    for (int i=1; i<=vertex_count; i++){
        for (int j=1; j<=vertex_count; j++) cout<<matrix[i][j];
        cout<<"\n";
    }
}