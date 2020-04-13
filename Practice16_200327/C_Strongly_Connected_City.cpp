#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
 
using namespace std;
using i64 = long long;
 
class Graph {
public:
    int N;
    vector<vector <int>> adj;
    vector<bool> visited;
    
    Graph() : N(0) {}
    Graph(int n) : N(n) {
        adj.resize(N);
        visited.resize(N);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void sortList() {
        for (int i = 0; i < N; i++)
        {
            for (int i = 0; i < N; i++)
                sort(adj[i].begin(), adj[i].end());
        }
    }
    
    int dfsAll(int start)
    {
        int components = 0;
        fill(visited.begin(), visited.end(), false);
        
        for (int i = 0; i < N; i++)
        {
            if (start >= N)
                start = 0;
            if (!visited[start])
            {
                //cout << "new DFS begin" << endl;
                dfs(start++);
                components++;
            }
        }
        
        return components;
    }
    
    void dfs()
    {
        fill(visited.begin(), visited.end(), false);
        dfs(0);
    }
private:
    void dfs(int curr)
    {
        visited[curr] = true;
        //cout << "node " << curr << " visited " << endl;
        for (int next: adj[curr])
            if (!visited[next]) dfs(next);
    }
};
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    string row, col;
    cin >> row >> col;
    
    // G.sortList();
    // G.dfsAll();
    
    Graph G(n*m);
    
    //<><>부터 edge 연결
    for (int j = 0; j < n; j++)
    {
        if (row[j] == '>')
        {
            for (int i = 0; i < m-1; i++)
            {
                G.addEdge((m*j) + i, (m*j) + i+1);
            }
        }
        else
        {
            for (int i = m-1; i > 0; i--)
            {
                G.addEdge((m*j) + i, (m*j) + i-1);
            }
        }
    }
    
    
    for (int j = 0; j < m; j++)
    {
        if (col[j] == 'v')
        {
            for (int i = 0; i < n-1; i++)
            {
                G.addEdge(j + m*i, j + m*(i+1));
            }
        }
        else
        {
            for (int i = n-1; i > 0; i--)
            {
                G.addEdge(j + m*i, j + m*(i-1));
            }
        }
    }
    
    G.sortList();
    
    for (int i = 0; i < n*m; i++)
    {
        int result = G.dfsAll(i);
        if (result != 1)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}