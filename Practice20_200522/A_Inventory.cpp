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
using ii64 = pair<i64, i64>;
 
int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> v(n + 1, 0);
    vector<int> count(100005, 0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
        count[v[i]]++;
    }
    
    // for (int i = 1; i <= n; i++)
    //     cout << count[i] << " ";
    
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if(count[i] == 0)
            q.push(i);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (count[v[i]] != 1 || n < v[i])
        {
            cout << q.front() << " ";
            count[v[i]]--;
            q.pop();
        }
        else
            cout << v[i] << " ";
    }
    
    return 0;
}