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

class Mapping
{
  public:
    void init(const vector<i64>& raw, int base = 0)
    {
        start = base;
        arr = raw;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
    }

    int get_idx(int k)
    {
        return start + lower_bound(all(arr), k) - arr.begin();
    }

    int get_value(int idx)
    {
        return arr[idx - start];
    }

    int size()
    {
        return arr.size();
    }

  private:
    int start;
    vector<i64> arr;
};

int main() {
    int n;
    scanf("%d", &n);
    
    vector<i64> v(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    
    Mapping m;
    m.init(v);

    for (int i = 0; i < n; i++)
        v[i] = m.get_idx(v[i]);

    vector<int> calcL(n, 0);
    int minL = n;
    
    for (int i = 0; i < n; i++)
    {
        vector<int> calcR(n, 0);
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