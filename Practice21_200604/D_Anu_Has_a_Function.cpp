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
 
int main()
{
    int n;
    scanf("%d", &n);
    
    vector<i64> v(n);
    i64 all = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &v[i]);
        all |= v[i];
    }
 
    vector<i64> left(n, 0);
    for (int i = 1; i < n; i++)
        left[i] = left[i-1] | v[i-1];

    vector<i64> right(n, 0);
    for (int i = n-1; i > 0; i--)
        right[i-1] = right[i] | v[i];
 
    int max_idx = 0;
    i64 max = all - (left[0] | right[0]);
    for (int i = 1; i < n; i++)
    {
        if (all - (left[i] | right[i]) > max)
        {
            max = all - (left[i] | right[i]);
            max_idx = i;
        }
    }

    printf("%d ", v[max_idx]);
    for (int i = 0; i < n; i++)
    {
        if (i != max_idx)
            printf("%d ", v[i]);
    }
    
    return 0;
}