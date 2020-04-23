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
#include <cmath>
 
using namespace std;
using i64 = long long;
 
int main() 
{
    int n;
    scanf("%d", &n);
    vector<i64> v(n);
    
    int s_num = 0, ns_num = 0, zero = 0;
    vector<int> ns_idx;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &v[i]);
        int tmp = (int)sqrt(v[i]);
        if (tmp * tmp == v[i])
            s_num++;
        else
        {
            ns_num++;
            ns_idx.push_back(i);
        }
        
        if (v[i] == 0)
            zero++;
    }
    //cout << s_num << " " << ns_num << endl;
    if (s_num == ns_num)
    {
        printf("0");
        return (0);
    }
    if (s_num > ns_num)
    {
        i64 sum = 0;
        sum += (s_num - n/2);
        
        if (s_num - zero < s_num - n/2)
            sum += (s_num - n/2) - (s_num - zero);
        
        printf("%lld", sum);
        return (0);
    }
    vector<int> ans;
    for (int i = 0; i < ns_idx.size(); i++)
    {
        // cout << v[ns_idx[i]] << endl;
        i64 x = (i64)sqrt(v[ns_idx[i]]);
        
        i64 diff1 = v[ns_idx[i]] - x*x;
        i64 diff2 = (x+1)*(x+1) - v[ns_idx[i]];
        // cout << diff1 << " " << diff2 << endl;
        
        ans.push_back(min(diff1, diff2));
    }
    sort(ans.begin(), ans.end());
    // cout << endl << "ans" << endl;
    
    i64 sum = 0;
    for (int i = 0; i < ns_num - n/2; i++)
    {
        sum += ans[i];
    }
    printf("%lld", sum);
    
    return 0;
}