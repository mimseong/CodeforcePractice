#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n;
    i64 m, sum = 0;
    scanf("%d %lld", &n, &m);
    vector<int> v(n);
    vector<int> ans;
    
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    sort(v.begin(), v.end());
    int index = 0;
    for (int i = 1; i <= 1000000000; i++)
    {
        if(v[index] == i)
        {
            index++;
        }
        else
        {
            if (sum + i <= m)
            {
                sum += i;
                ans.push_back(i);
            }
            else
                break;
        }
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}