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
#define all(x) (x).begin(), (x).end()
#define MAX 1e9
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

void solve()
{
    int n;
    scanf("%d", &n);

    i64 sum = 0;
    i64 count = 1;
    for (int i = 3; i <= n; i += 2)
    {
        sum += 4*(i-1)*count++;
    }

    printf("%lld\n", sum);
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        solve();
    
    return 0;
}