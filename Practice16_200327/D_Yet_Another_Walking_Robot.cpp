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
 
using namespace std;
using i64 = long long;
 
int main() 
{
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        int n;
        string s;
        cin >> n >> s;
        
        map<pair<int, int>, int> idx;
        int x = 0, y = 0;
        int l = n, r = n, len = n + 1;
        bool ischange = true;
        idx[{0, 0}] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (s[j-1] == 'L')
                x--;
            else if (s[j-1] == 'R')
                x++;
            else if (s[j-1] == 'D')
                y--;
            else if (s[j-1] == 'U')
                y++;
 
            //없는 경우
            if (idx.find({x, y}) == idx.end())
            {
                idx[{x, y}] = j;
            }
            //있는 경우
            else
            {
                if (len > (j - idx[{x, y}]))
                {
                    len = j - idx[{x, y}];
                    l = idx[{x, y}] + 1;
                    r = j;
                    ischange = false;
                }
                idx[{x, y}] = j;
            }
            //cout << x << " " << y << endl;
        }
        
        if (ischange)
            printf("-1\n");
        else
            printf("%d %d\n", l, r);
    }
    
    return 0;
}