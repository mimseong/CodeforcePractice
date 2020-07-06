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
 
void solve()
{
    i64 n, k;
    scanf("%lld %lld", &n, &k);
    
    int maxv = 1;
    for (int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            if ((n/i) > maxv && ((n/i) <= k))
            {
                maxv = n/i;
            }
            else if (i > maxv && i <= k)
            {
                maxv = i;
            }
        }
            
    }
    
    printf("%lld\n", n/maxv);
}
 
int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    
    
    return 0;
}