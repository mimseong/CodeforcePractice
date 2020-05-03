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
 
int main() {
    int n;
    scanf("%d", &n);
    
    i64 sum = 0;
    for (int i = 3; i <= n; i++)
    {
        sum += (i-1) * i;
    }
    cout << sum;
    
    return 0;
}