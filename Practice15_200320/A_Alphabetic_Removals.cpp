#include <iostream>
#include <queue>
 
using namespace std;
 
queue<int> q[26];
bool removed[400005];
 
int main() {
    int n, k;
    string s;
    
    cin >> n >> k >> s;
    
    for (int i = 0; i < s.size(); i++)
        q[s[i] - 'a'].push(i);
    
    for (int i = 0; i < k ; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (q[c].empty())
                continue ;
            
            removed[q[c].front()] = true;
            q[c].pop();
            break ;
        }
    }
    
    for (int i = 0; i < s.size(); i++)
    {
        if (removed[i])
            continue ;
        
        cout << s[i];
    }
    
    return (0);
}