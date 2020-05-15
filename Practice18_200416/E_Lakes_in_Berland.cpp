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
 
bool visited[55][55];
char map[55][55];
 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
 
int n, m;
 
bool    sort_by_size(const vector<ii> &a, const vector<ii> &b)
{
    return (a.size() < b.size());
}
 
void    dfs(int x, int y, vector<ii> &v)
{
    if (visited[x][y])
        return ;
 
    if (map[x][y] == '*')
        return ;
 
    visited[x][y] = true;
    v.emplace_back(x, y);
 
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < m && x + dx[i] < n)
            dfs(x + dx[i], y + dy[i], v);
    }
}
 
void    print_map(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
 
bool    check_river(vector<ii> &element)
{
    for (int i = 0; i < element.size(); i++)
    {
        if (element[i].first == 0 || element[i].first == n-1)
            return false;
        if (element[i].second == 0 || element[i].second == m-1)
            return false;
    }
    return true;
}
 
int     main()
{
    int k;
    scanf("%d %d %d", &n, &m, &k);
 
    char tmp;
    scanf("%c", &tmp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &map[i][j]);
        }
        scanf("%c", &tmp);
    }
    
    vector<ii> ans[2500];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '.' && !visited[i][j])
            {
                vector<ii> element;
                dfs(i, j, element);
                if (check_river(element))
                    ans[count++] = element;
            }
        }
    }
    
    sort(&ans[0], &ans[count], sort_by_size);
 
    // for (int i = 0; i < count; i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j].first << ", " << ans[i][j].second << endl;
    //     }
    //     cout << endl;
    // }
    
    int min_num = 0;
    for (int i = 0; i < count - k; i++)
    {
        min_num += ans[i].size();
        //cout << min_num << endl;
    }
    //cout << count << endl;
    cout << min_num << endl;
    for (int i = 0; i < count - k; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            map[ans[i][j].first][ans[i][j].second] = '*';
        }
    }
    
    print_map(n, m);
    
    return 0;
}