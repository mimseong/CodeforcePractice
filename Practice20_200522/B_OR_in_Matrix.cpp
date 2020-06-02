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
using ii64 = pair<i64, i64>;
 
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    vector<vector<int>> vb(m, vector<int>(n, 0));
    vector<int> rowa(m, 1);
    vector<int> cola(n, 1);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   
        {
            scanf("%d", &vb[i][j]);
            if (vb[i][j] == 0)
            {
                rowa[i] = 0;
                cola[j] = 0;
            }
        }
    }
    
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   
        {
            if (vb[i][j] == 1 && (rowa[i] == 0 && cola[j] == 0))
            {
                printf("NO");
                return 0;
            }
            if (rowa[i] == 1 && cola[j] == 1)
                ans[i][j] = 1;
        }
    }
    
    vector<vector<int>> calc(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   
        {
            if (ans[i][j] == 1)
            {
                for (int k = 0; k < m; k++)
                    calc[k][j] = 1;
                for (int k = 0; k < n; k++)
                    calc[i][k] = 1;
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   
        {
            if (calc[i][j] != vb[i][j])
            {
                printf("NO");
                return 0;
            }
        }
    }
    
    printf("YES\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}