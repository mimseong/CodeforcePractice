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
 
int make(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
            continue;
        sum += s[i] - '0';   
    }
    
    return sum;
}
 
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    vector<int> ans;
    for (int i = 1; i <= 81; i++)
    {
        i64 res = 1;
        for (int j = 0; j < a; j++)
            res *= i;
        res *= b;
        res += c;
        
        if (0 < res && res < MAX)
        {
            if(make(to_string(res)) == i)
                ans.push_back(res);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    
    return 0;
}