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
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        i64 n, x;
        scanf("%lld %lld", &n, &x);
        
        vector <ii64> v(n);
        for (int j = 0; j < n; j++)
            scanf("%lld %lld", &v[j].first, &v[j].second);
        
        i64 max_val = v[0].first;
        int max_idx = 0;
        for (int j = 1; j < n; j++)
        {
            if((v[j].first - v[j].second) > (v[max_idx].first - v[max_idx].second))
                max_idx = j;
            if(v[j].first > max_val)
                max_val = v[j].first;
        }
        
        x -= max_val;
        if (x <= 0)
        {
            printf("1\n");
            continue;
        }
        
        if (v[max_idx].first - v[max_idx].second <= 0)
            printf("-1\n");
        else
            printf("%lld\n", (x+v[max_idx].first-v[max_idx].second-1)/(v[max_idx].first-v[max_idx].second)+1);
    }
    
    return 0;
}