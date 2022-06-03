#include <bits/stdc++.h>
using namespace std;

int main(){

    const int LIMIT=2e9+5;

    int vertex_count, edge_count, query_count;
    cin >> vertex_count >> edge_count >> query_count;

    int matrix[vertex_count][vertex_count];

    // initialisation
    for (int i=0; i<vertex_count; i++){
        for (int j=0; j<vertex_count; j++){
            if (i == j) matrix[i][j] = 0;
            else matrix[i][j] = LIMIT;
        }
    }

    // fill in edges
    int vertex_a, vertex_b, weight_ab;
    for (int i=0; i<edge_count; i++){
        cin >> vertex_a >> vertex_b >> weight_ab;
        matrix[vertex_a][vertex_b] = weight_ab;
        matrix[vertex_b][vertex_a] = weight_ab;
    }

    // implementing Floyd-Warshall
    // basically, is the route from vertex i to vertex j through vertex k the shortest?
    for (int k=0; k<vertex_count; k++){
        for (int i=0; i<vertex_count; i++){
            for (int j=0; j<vertex_count; j++){
                if (matrix[i][k]!=LIMIT || matrix[k][j]!=LIMIT){
					matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
				}
            }
        }
    }

    int query_a, query_b;
    for (int i=0; i<query_count; i++){
        cin >> query_a >> query_b;
        int output = matrix[query_a][query_b];
        if (output == LIMIT) cout << "-1\n";
        else cout << output << "\n";
    }
}