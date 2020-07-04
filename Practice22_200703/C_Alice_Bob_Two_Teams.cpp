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
        
    string s;
    cin >> s;
    
    i64 sum_b = 0;
    vector<i64> point(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            sum_b += v[i];
            point[i] = v[i] * -1;
        }
        else
            point[i] = v[i];
    }
    
    vector<i64> left(n);
    left[0] = point[0];
    for (int i = 1; i < n; i++)
        left[i] = point[i] + left[i-1];
     
    vector<i64> right(n);
    right[n-1] = point[n-1];
    for (int i = n-2; i >= 0; i--)
        right[i] = point[i] + right[i+1];
    
    i64 max1 = *max_element(left.begin(), left.end());
    i64 max2 = *max_element(right.begin(), right.end());
    
    cout << max(max(max1, max2) + sum_b, sum_b);
    
    return 0;
}