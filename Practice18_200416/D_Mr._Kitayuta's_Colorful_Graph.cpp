#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
 
vector<int> edge[101][10005];
bool visited[101][10005];
 
bool    dfs(int x, int y, int c)
{
    if (x == y)
        return true;
    
    if (visited[c][x])
        return false;
    
    visited[c][x] = true;
    
    for (auto& nxt : edge[c][x])
    {
        if (dfs(nxt, y, c))
            return true;
    }
    
    return false;
}
 
void    reset(int c)
{
    for (int i = 0; i < 10005; i++)
    {
        visited[c][i] = false;
    }
}
 
int     main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[c][a].push_back(b);
        edge[c][b].push_back(a);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        int count = 0;
        for (int j = 1; j <= 100; j++)
        {
            reset(j);
            if(dfs(u, v, j))
                count++;
        }
        cout << count << endl;
    }
    
    return 0;
}