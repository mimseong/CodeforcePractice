#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int n, m;

void print_vec(vector<vector<int>> &v)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> shift_row(vector<vector<int>> &v, int p)
{
    v[p][0] = v[p][m];
    
    for (int i = m; i > 0; i--)
    {
        v[p][i] = v[p][i-1];
    }
    
    return v;
}

vector<vector<int>> shift_col(vector<vector<int>> &v, int p)
{
    v[0][p] = v[n][p];
    
    for (int i = n; i > 0; i--)
    {
        v[i][p] = v[i-1][p];
    }
    
    return v;
}

int main() {
    int q;
    scanf("%d %d %d", &n, &m, &q);
    
    vector<vector<int>> ans(n+1, vector<int>(m+1, 0));
    
    vector<int> v[q];
    
    for (int i = 0; i < q; i++)
    {
        int in;
        scanf("%d", &in);
        v[i].push_back(in);
        
        int max_num;
        if (in == 1 || in == 2)
            max_num = 1;
        else
            max_num = 3;
        
        for (int j = 1; j <= max_num; j++)
        {
            scanf("%d", &in);
            v[i].push_back(in);
        }
    }
    
    for (int i = q-1; i >= 0; i--)
    {
        if (v[i][0] == 1)
        {
            shift_row(ans, v[i][1]);
        }
        else if (v[i][0] == 2)
        {
            shift_col(ans, v[i][1]);
        }
        else
        {
            int r = v[i][1], c = v[i][2], x = v[i][3];
            ans[r][c] = x;
        }
    }
    
    print_vec(ans);
    
    return 0;
}