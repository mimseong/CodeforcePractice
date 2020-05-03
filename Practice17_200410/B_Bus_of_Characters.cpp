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
 
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.first < b.first); 
} 
 
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    
    sort(v.begin(), v.end(), sortbysec);
    
    queue<int> introvert;
    stack<int> extrovert;
    
    for (int i = 0; i < n; i++)
    {
        introvert.push(v[i].second + 1);
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << introvert.front() << " ";
    //     introvert.pop();
    // }
    
    for (int i = 0; i < 2*n; i++)
    {
        int tmp;
        scanf("%1d", &tmp);
        if (tmp == 0)
        {
            cout << introvert.front() << " ";
            extrovert.push(introvert.front());
            introvert.pop();
        }
        else
        {
            cout << extrovert.top() << " ";
            extrovert.pop();
        }
    }
    
    return 0;
}