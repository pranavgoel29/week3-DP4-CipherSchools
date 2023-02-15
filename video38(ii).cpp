//#include <bits/stdc++.h>
//using namespace std;
//
///* BFS algorithm (Queue) --> army example
// * Breadth-first search is a graph traversal algorithm that starts traversing the graph from the root node and explores all the neighboring nodes.
// * Then, it selects the nearest node and explores all the unexplored nodes. While using BFS for traversal, any node in the graph can be considered as the root node.
// */
//
//void bfs_iterative(int cur,unordered_map<int,list<int>> &adj_list,unordered_map<int,bool> &visited){
//    queue<int> nodes;
//    nodes.push(cur);
//    visited[cur] = true;
//
//    while(!nodes.empty()){
//        int node = nodes.front();
//        nodes.pop();
//        cout<<node<< " ";
//        for(int neigh:adj_list[node]){
//            if(!visited[neigh]){
//                nodes.push(neigh);
//                visited[neigh]= true;
//            }
//        }
//    }
//}
//
//
//
//void print(unordered_map<int,list<int>> &adj_list){
//    for(auto kv_pairs : adj_list){
//        cout<<kv_pairs.first<<": {";
//        for(auto v : kv_pairs.second){
//            cout<<v<<", ";
//        }
//        cout<<"}"<<endl;
//    }
//}
//
//int main(){
//    vector<pair<int,int>> edges{
//            {1,3},
//            {1,4},
//            {2,8},
//            {2,4},
//            {3,5},
//            {8,3},
//            {4,9},
//            {4,8},
//            {5,7},
//            {6,7},
//            {6,8},
//    };
//
//    unordered_map<int,list<int>> adj_list;
//    for(auto edge : edges){
//        adj_list[edge.first].push_back(edge.second);
//        adj_list[edge.second].push_back(edge.first);
//    }
//
//    unordered_map<int,bool> visited;
//
//    print(adj_list);
//    bfs_iterative(7,adj_list,visited);          //7 5 6 3 8 1 2 4 9
//
//
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

/* DFS algorithm
 * It is a recursive algorithm to search all the vertices of a tree data structure or a graph.
 * The depth-first search (DFS) algorithm starts with the initial node of graph G and goes deeper until we find the goal node or the node with no children.
 */

void dfs_iterative(int cur,unordered_map<int,list<int>> &adj_list,unordered_map<int,bool> &visited){
    stack<int> nodes;
    nodes.push(cur);

    while(!nodes.empty()){
        int node = nodes.top();
        nodes.pop();
        if(!visited[node]){
            cout<<node<<" ";
            visited[node] = true;
        }
        for(auto neigh:adj_list[node]){
            if(!visited[neigh]){
                nodes.push(neigh);
            }
        }
    }
    cout<<endl;
}


void dfs_recursive(int cur,unordered_map<int,list<int>> &adj_list,unordered_map<int,bool> &visited){
    cout<<cur<<" ";

    visited[cur] = true;
    for(int neigh:adj_list[cur]){
        if(!visited[neigh]){
            dfs_recursive(neigh,adj_list,visited);
        }
    }
}


void print(unordered_map<int,list<int>> &adj_list){
    for(auto kv_pairs : adj_list){
        cout<<kv_pairs.first<<": {";
        for(auto v : kv_pairs.second){
            cout<<v<<", ";
        }
        cout<<"}"<<endl;
    }
}

int main(){
    vector<pair<int,int>> edges{
            {1,3},
            {1,4},
            {2,8},
            {2,4},
            {3,5},
            {3,8},
            {4,9},
            {4,8},
            {5,7},
            {6,7},
            {6,8},
    };

    unordered_map<int,list<int>> adj_list;
    for(auto edge : edges){
        adj_list[edge.first].push_back(edge.second);
        adj_list[edge.second].push_back(edge.first);
    }

    unordered_map<int,bool> visited1;
    unordered_map<int,bool> visited2;

    print(adj_list);
    dfs_iterative(7,adj_list,visited2);
    dfs_recursive(7,adj_list,visited1);            //7 5 3 1 4 2 8 6 9


    return 0;
}