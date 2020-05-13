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
 
bool sortbysecond(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
 
int main() {
    int n, r, avg;
    scanf("%d %d %d", &n, &r, &avg);
    
    i64 sum = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &v[i].first, &v[i].second);
        sum += v[i].first;
        v[i].first = r - v[i].first;
    }
    sort(v.begin(), v.end(), sortbysecond);
    
    i64 count = 0;
    i64 ans = 0;
    i64 calc = n * (i64)avg - sum;
    
    if (calc <= 0)
    {
        cout << "0";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i].first + count < calc)
        {
            count += v[i].first;
            ans += (i64)v[i].second * v[i].first;
        }
        else
        {
            ans += (i64)v[i].second * (calc - count);
            break;
        }
    }
    cout << ans;
    
    return 0;
}