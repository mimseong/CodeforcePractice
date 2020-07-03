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
    int p, q, l, r;
    scanf("%d %d %d %d", &p, &q, &l, &r);

    vector<ii> a(p);
    vector<ii> c(q);

    for (int i = 0; i < p; i++)
        scanf("%d %d", &a[i].xx, &a[i].yy);
    for (int i = 0; i < q; i++)
        scanf("%d %d", &c[i].xx, &c[i].yy);

    int count = 0;
    for (int i = l; i <= r; i++)
    {
        bool is_find = false;
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < q; k++)
            {
                if (max(a[j].xx, (c[k].xx + i)) <= min(a[j].yy, (c[k].yy + i)))
                {
                    is_find = true;
                    break;
                }
            }
            if (is_find)
            {
                count++;
                break;
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}
