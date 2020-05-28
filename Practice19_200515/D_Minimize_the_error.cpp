#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() 
{
    int n, k1, k2;
    scanf("%d %d %d", &n, &k1, &k2);
 
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
 
    priority_queue<i64> sub;
    for (int i = 0; i < n; i++)
        sub.push(abs(a[i] - b[i]));
    
    i64 sum = k1 + k2;
    for (int i = sum; i > 0; i--)
    {
        int top = sub.top();
        sub.pop();
        if (top > 0)
        {
            sub.push(top-1);
        }
        else
        {
            sub.push(top+1);
        }
    }
    
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += sub.top() * sub.top();
        sub.pop();
    }
    cout << ans;
    
    return 0;
}