#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n, m;
    scanf("%d", &n);
    vector <i64> v1(n + 1, 0);
    vector <i64> v2(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &v1[i]);
        v2[i] = v1[i];
    }
    scanf("%d", &m);
    sort(v2.begin(), v2.end());
    for(int i = 1; i <= n; i++)
    {
        v1[i] += v1[i - 1];
        v2[i] += v2[i - 1];
    }
    for(int i = 0; i < m; i++)
    {
        int type, l, r;
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            printf("%lld\n", v1[r] - v1[l-1]);
        else
            printf("%lld\n", v2[r] - v2[l-1]);
    }
    return 0;
}