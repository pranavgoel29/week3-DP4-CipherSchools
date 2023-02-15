#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 Sequential representation (Adjacency matrix)
In sequential representation, there is a use of an adjacency matrix to represent the mapping between vertices and edges of the graph.
We can use an adjacency matrix to represent the undirected graph, directed graph, weighted directed graph, and weighted undirected graph.
    adj[i][j] = 1 {if there is a path exists from Vi to Vj}
    adj[i][j] = 0 {Otherwise}
    If adj[i][j] = w, it means that there is an edge exists from vertex i to vertex j with weight w.
 */

//Linked list representation (list)
//        An adjacency list is used in the linked representation to store the Graph in the computer's memory. It is efficient in terms of storage as we only have to store the values for edges.

void print(vector<vector<bool>> &adj_max){
    for(int i=0;i<adj_max.size();i++){
        for(int j=0;j<adj_max[0].size();j++){
            cout<<adj_max[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print(map<int,list<int>> &adj_list){
    for(auto kv_pair: adj_list){
        cout<<kv_pair.first<<": {";
        for(auto v: kv_pair.second){
            cout<<v<<",";
        }
        cout<<"}"<<endl;
    }
}

int main() {
    vector<vector<int>> edges = {
            {0,1},
            {1,2},
            {1,3},
            {3,4}
    };

    vector<vector<bool>> adj_max(5,vector<bool>(5,false));
    map<int,list<int>> adj_list;

    for(auto edge:edges){
        adj_max[edge[0]][edge[1]] = true;
        adj_max[edge[1]][edge[0]] = true;
    }

    for(auto edge : edges){
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }

    print(adj_max);
    cout<<endl;

    print(adj_list);

    return 0;
}
