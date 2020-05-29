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
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    int n;
    scanf("%d", &n);
    
    map <string, set<int>> m;
    vector <string> v;
    for (int k = 0; k < n; k++)
    {
        string s;
        cin >> s;
        
        v.push_back(s);
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j <= s.size()-i; j++)
            {
                m[s.substr(j, i)].insert(k);
            }
        }
    }
    
    int q;
    scanf("%d", &q);
    
    for (int k = 0; k < q; k++)
    {
        string s;
        cin >> s;
        
        cout << m[s].size() << " ";
        
        if (m[s].size() == 0)
        {
            cout << "-\n";
            continue;
        }

        cout << v[*m[s].begin()] << " ";
        cout << endl;
    }
    
    return 0;
}