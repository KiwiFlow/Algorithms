#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
    	/*input*/
        int n,m;
        cin>>n>>m;
        map<int,set<int> > graph;
        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            graph[a].insert(b);
            graph[b].insert(a);
        }
        int s;
        cin>>s;
        /*bfs*/
        vector<int> res(n+1,-1);
        vector<int> unv(n+1,0);
        queue<pair<int,int> > q;
        q.push(make_pair(s,0));
        unv[s] = 1;
        while(!q.empty()){
        	pair<int,int> node =  q.front();
        	q.pop();
        	res[node.first] = node.second*6;
        	for(set<int>::iterator index=graph[node.first].begin();index!=graph[node.first].end();index++){
                if(unv[*index]==0){
                    q.push(make_pair(*index,node.second+1));
                    unv[*index] = 1;
                }
            }
        }
        /*output*/
        for(int pr = 1;pr<res.size();pr++){
            if(pr!=s){
                cout<<res[pr]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
Consider an undirected graph consisting of  nodes where each node is labeled from  to  and the edge between any two nodes is always of length . We define node  to be the starting position for a BFS.

Given  queries in the form of a graph and some starting node, , perform each query by calculating the shortest distance from starting node  to all the other nodes in the graph. Then print a single line of space-separated integers listing node 's shortest distance to each of the  other nodes (ordered sequentially by node number); if  is disconnected from a node, print  as the distance to that node.

Input Format

The first line contains an integer, , denoting the number of queries. The subsequent lines describe each query in the following format:

The first line contains two space-separated integers describing the respective values of  (the number of nodes) and  (the number of edges) in the graph.
Each line  of the  subsequent lines contains two space-separated integers,  and , describing an edge connecting node  to node .
The last line contains a single integer, , denoting the index of the starting node.
Constraints

Output Format

For each of the  queries, print a single line of  space-separated integers denoting the shortest distances to each of the  other nodes from starting position . These distances should be listed sequentially by node number (i.e., ), but should not include node . If some node is unreachable from , print  as the distance to that node.

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output

6 6 -1
-1 6*/
