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

void    calc()
{
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    set<pair<ii, ii>> visited;
    int ans = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        int nx = x, ny = y;
        
        if (s[i] == 'N')
            ny++;
        if (s[i] == 'S')
            ny--;
        if (s[i] == 'E')
            nx++;
        if (s[i] == 'W')
            nx--;
            
        if (visited.find(pair<ii, ii>(ii(x, y), ii(nx, ny))) != visited.end())
            ans++;
        else
            ans += 5;
        
        visited.insert(pair<ii, ii>(ii(x,y), ii(nx,ny)));
        visited.insert(pair<ii, ii>(ii(nx,ny), ii(x,y)));
        
        x = nx;
        y = ny;
    }
    
    cout << ans << '\n';
}

int     main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        calc();
    
    return 0;
}