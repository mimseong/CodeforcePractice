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
    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &v[i]);
        sum |= v[i];
    }

    i64 max = 0;
    i64 max_idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum - (sum - v[i]) > max)
        {
            max = sum - (sum - v[i]);
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