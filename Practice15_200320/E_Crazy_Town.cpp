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
 
int main() {
    vector<int> home(2);
    vector<int> univ(2);
    
    scanf("%d %d", &home[0], &home[1]);
    scanf("%d %d", &univ[0], &univ[1]);
    
    int n, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        i64 a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        
        i64 res1 = a*home[0] + b*home[1] + c;
        i64 res2 = a*univ[0] + b*univ[1] + c;
        
        if (res1 < 0ll && 0ll < res2)
            count++;
        else if (res2 < 0ll && 0ll < res1)
            count++;
    }
    printf("%d", count);
    
    return 0;
}