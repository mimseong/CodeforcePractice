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
 
int main() {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    
    vector<int> check(n, 0);
    vector<i64> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &v[i]);
        
        if (v[i] > l)
        {
            check[i] = 1;
        }
    }
    
    int group = 0;
    bool is_one = false;
    
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 1 && !is_one)
        {
            group++;
            is_one = true;
        }
        else if (check[i] == 0 && is_one)
        {
            is_one = false;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        
        if (t == 0)
        {
            printf("%d\n", group);
            continue;
        }
        
        int p;
        i64 d;
        scanf("%d %lld", &p, &d);
        
        v[--p] += d;
        
        if (v[p] <= l)
            continue;
        
        if (check[p] == 1)
            continue;
            
        check[p] = 1;
        bool left = false, right = false;
        
        if (p-1 >= 0)
            if (check[p-1] == 1)
                left = true;
        if (p+1 < n)
            if (check[p+1] == 1)
                right = true;
        
        if (!left && !right)
            group++;
        else if (left && right)
            group--;
        
    }
    
    return 0;
}