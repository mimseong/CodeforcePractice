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
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v(n+1);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    
    int group = 0;
    int start_idx = 1;
    int max = v[1].second;
    bool find = false;
    
    for (int i = 1; i <= n; i++)
    {
        if (v[i].second == start_idx && !find)
                find = true;
        if (v[i].second > max)
                max = v[i].second;
        if (find && i == max)
        {
            group++;
            find = false;
            start_idx = i+1;
            max = v[i+1].second;
        }
    }
    cout << group;
    
    return 0;
}