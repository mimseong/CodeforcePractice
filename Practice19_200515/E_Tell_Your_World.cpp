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
    int n;
    scanf("%d", &n);
    
    vector<i64> y(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &y[i]);
        
    vector<ii64> d;
    d.emplace_back(1, y[1] - y[0]);
    d.emplace_back(2, y[2] - y[0]);
    d.emplace_back(1, y[2] - y[1]);
    
    for (auto &di : d)
    {
        auto dx = di.xx;
        auto dy = di.yy;
        
        set <i64> coef;
        
        for (int x = 0; x < n; x++)
            coef.insert(dx * y[x] - dy * (x+1));
        
        if (coef.size() == 2)
        {
            printf("Yes");
            return 0;
        }
    }
    
    printf("No");
    
    return 0;
}