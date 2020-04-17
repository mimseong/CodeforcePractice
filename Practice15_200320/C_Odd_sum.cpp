#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
i64 ft_abs(i64 num)
{
    if (num < 0)
        return -1 * num;
    return num;
}
 
int main() {
    i64 n;
    i64 sum = 0;
    scanf("%lld", &n);
    vector<i64> v(n);
    
    i64 min_odd_idx = -1;
    for (i64 i = 0; i < n; i++)
    {
        scanf("%lld", &v[i]);
        
        if (v[i] > 0)
            sum += v[i];
        if (ft_abs(v[i]) % 2 == 1 && min_odd_idx == -1)
            min_odd_idx = i;
    }
    if (sum % 2 == 1)
    {
        printf("%lld", sum);
        return 0;
    }
    
    for (i64 i = 0; i < n; i++)
    {
        if (ft_abs(v[i]) % 2 == 1 && ft_abs(v[i]) < ft_abs(v[min_odd_idx]))
        {
            min_odd_idx = i;
        }
    }
    if (v[min_odd_idx] > 0)
        sum -= v[min_odd_idx];
    else
        sum += v[min_odd_idx];
                
    printf("%lld", sum);
    
    return 0;
}