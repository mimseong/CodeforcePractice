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
 
int main() {
    int h1, h2, a, b;
    scanf("%d %d %d %d", &h1, &h2, &a, &b);
    
    // cout << h1 << h2 << a << b;
    
    int h = h2 - h1;
    if (a*8 >= h)
    {
        printf("0");
        return 0;
    }
    
    if (a <= b)
    {
        printf("-1");
        return 0;
    }
    
    cout << (h - 8*a + 12*(a-b) -1) / (12 * (a-b));
    
    return 0;
}