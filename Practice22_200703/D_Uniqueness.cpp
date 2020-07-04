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
#define MAX 1e9
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    int n;
    scanf("%d", &n);
    
    vector<i64> v(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    
    map<int, int> calcL;
    int minL = n;
    
    for (int i = 0; i < n; i++)
    {
        map<int, int> calcR;
        int len = i;
        
        for (int j = n-1; j >= i; j--)
        {
            calcR[v[j]]++;
            
            if (calcR[v[j]] > 1 || calcL[v[j]] >= 1)
                break;
            len++;
        }
        
        if (n-len < minL)
            minL = n-len;

        calcL[v[i]]++;
        
        if (calcL[v[i]] > 1)
            break;
    }
    
    printf("%d\n", minL);
    
    return 0;
}