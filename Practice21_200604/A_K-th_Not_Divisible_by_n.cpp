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
        i64 n, k;
        scanf("%lld %lld", &n, &k);
        
        i64 ans = k/(n-1)*n + k%(n-1);
        if (k%(n-1) == 0)
            ans--;
        printf("%lld\n", ans);
    }
    
    return 0;
}