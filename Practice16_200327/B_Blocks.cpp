#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    vector<char> cpy(n);
    for(int i = 0; i < n; i++)
    {
        cpy[i] = s[i];
    }
    
    int w = 0, b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'W')
            w++;
        else
            b++;
    }
    int wc = w, bc = b;
    if ((n%2==0) && (w%2==1) && (b%2==1))
    {
        printf("-1");
        return 0;
    }
    
    if ((b==n) || (w==n))
    {
        printf("0");
        return 0;
    }
    
    vector<int> ans;
    //while (w != n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'B')
            {
                ans.push_back(i);
                if (s[i+1] == 'W')
                {
                    s[i] = 'W';
                    s[i+1] = 'B';
                }
                else
                {
                    s[i] = 'W';
                    s[i+1] = 'W';
                    w += 2;
                    b -= 2;
                }
            }
        }
    }
    
    if (w != n)
    {
        vector<int> ans2;
        //while (w != n)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (cpy[i] == 'W')
                {
                    ans2.push_back(i);
                    if (cpy[i+1] == 'B')
                    {
                        cpy[i] = 'B';
                        cpy[i+1] = 'W';
                    }
                    else
                    {
                        cpy[i] = 'B';
                        cpy[i+1] = 'B';
                        wc += 2;
                        bc -= 2;
                    }
                }
            }
        }
    
        cout << ans2.size() << endl;
        for (int i = 0; i < ans2.size(); i++)
        {
            cout << ans2[i] + 1 << " ";
        }
    }
    else
    {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << " ";
        }
    }
    return 0;
}