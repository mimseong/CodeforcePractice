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
    string s;
    cin >> s;
    int m;
    cin >> m;
    
    vector<int> count((s.size()+1)/2, 0);
 
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        count[tmp-1]++;
    }
    
    if (count[0] % 2 == 1)
    {
        char tmp;
        tmp = s[0];
        s[0] = s[s.size()-1];
        s[s.size()-1] = tmp;
    }
    
    for (int j = 1; j < (s.size()+1)/2; j++)
    {
        count[j] += count[j-1];
        if (count[j] % 2 == 1)
        {
            char tmp;
            tmp = s[j];
            s[j] = s[s.size()-1-j];
            s[s.size()-1-j] = tmp;
        }
    }
    
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    
    
    return 0;
}