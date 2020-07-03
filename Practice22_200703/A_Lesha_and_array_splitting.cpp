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

    vector<int> v(n);
    int sum = 0;
    bool is_zero = true;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
        if (v[i] != 0)
            is_zero = false;
    }

    if (is_zero)
    {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    if (sum != 0)
    {
        printf("1\n");
        printf("1 %d", n);
        return 0;
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            index = i;
            break;
        }
    }
    printf("2\n");
    printf("1 %d\n", index + 1);
    printf("%d %d", index + 2, n);
    
    return 0;
}
