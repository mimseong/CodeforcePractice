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
 
int setSNWE(int n, char t)
{
    if (t == 'W')
    {
        if (n%100/10 == 0)
            n += 10;
    }
    else if (t == 'E')
    {
        if (n%10 == 0)
            n += 1;
    }
    else if (t == 'S')
    {
        if (n/1000 == 0)
            n += 1000;
    }
    else if (t == 'N')
    {
        if (n%1000/100 == 0)
            n += 100;
    }
    return n;
}
 
int main() 
{
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        
        map<pair<int, int>, int> idx;
        int x = 0, y = 0;
        int count = 0;
        
        idx[{0, 0}] = 0;
        for (int j = 1; j <= s.size(); j++)
        {
            //cout << s[j-1] << endl;
            int bfr_x = x, bfr_y = y;
            if (s[j-1] == 'W')
                x--;
            else if (s[j-1] == 'E')
                x++;
            else if (s[j-1] == 'S')
                y--;
            else if (s[j-1] == 'N')
                y++;
            
            idx[{bfr_x, bfr_y}] = setSNWE(idx[{bfr_x, bfr_y}], s[j-1]);
            //cout << bfr_x << " " << bfr_y << " " << idx[{bfr_x, bfr_y}] << endl;
            
            //없는 경우
            if (idx.find({x, y}) == idx.end())
            {
                if (s[j-1] == 'W')
                    idx[{x, y}] = setSNWE(idx[{x, y}], 'E');
                else if (s[j-1] == 'E')
                    idx[{x, y}] = setSNWE(idx[{x, y}], 'W');
                else if (s[j-1] == 'S')
                    idx[{x, y}] = setSNWE(idx[{x, y}], 'N');
                else if (s[j-1] == 'N')
                    idx[{x, y}] = setSNWE(idx[{x, y}], 'S');
                count += 5;
                //cout << "없어용" << endl;
            }
            //있는 경우
            else
            {
                bool is_true = false;
            
                if (s[j-1] == 'W')
                {
                    if (idx[{x, y}] == setSNWE(idx[{x, y}], 'E'))
                    {
                        count += 1;
                        is_true = true;
                    }
                }
                else if (s[j-1] == 'E')
                {
                    if (idx[{x, y}] == setSNWE(idx[{x, y}], 'W'))
                    {
                        count += 1;
                        is_true = true;
                    }
                }
                else if (s[j-1] == 'S')
                {
                    if (idx[{x, y}] == setSNWE(idx[{x, y}], 'N'))
                    {
                        count += 1;
                        is_true = true;
                    }
                }
                else if (s[j-1] == 'N')
                {
                    if (idx[{x, y}] == setSNWE(idx[{x, y}], 'S'))
                    {
                        count += 1;
                        is_true = true;
                    }
                }
                if (is_true == false)
                {
                    if (s[j-1] == 'W')
                        idx[{x, y}] = setSNWE(idx[{x, y}], 'E');
                    else if (s[j-1] == 'E')
                        idx[{x, y}] = setSNWE(idx[{x, y}], 'W');
                    else if (s[j-1] == 'S')
                        idx[{x, y}] = setSNWE(idx[{x, y}], 'N');
                    else if (s[j-1] == 'N')
                        idx[{x, y}] = setSNWE(idx[{x, y}], 'S');
                    count += 5;
                }
            }
            //cout << x << " " << y << endl;
            //cout << x << " " << y << " " << idx[{x, y}] << endl;
        }
        
        cout << count << endl;
    }
    
    return 0;
}