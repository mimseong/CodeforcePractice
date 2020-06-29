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

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

bool sortbyfirst(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int count_one(int n)
{
    int count = 0;

    for (i64 i = 1; i <= n; i *= 2)
    {
        int res =  n & i;
        if (res == i)
          count++;
    }

    return count;
}


int main() {
    int n;
    scanf("%d", &n);
    
    vector<ii> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i].first);
        v[i].second = count_one(v[i].first);
    }

    sort(v.begin(), v.end(), sortbyfirst);

    
    
    return 0;
}