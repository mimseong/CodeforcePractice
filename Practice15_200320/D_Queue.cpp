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
    int n;
    scanf("%d", &n);
    
    vector<int> pre(1000005, -1);
    vector<int> nxt(1000005, -1);
    vector<int> count(1000005, 0);
    
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        nxt[a] = b;
        pre[b] = a;
        count[a]++;
        count[b]++;
    }
    
    vector<int> pseq, nseq;
    
    int now = pre[0];
    while (now > 0)
    {
        pseq.push_back(now);
        now = pre[now];
    }
 
    int end = 0;
    if (n % 2 == 1)
    {
        for (int i = 0; i < count.size(); i++)
        {
            if(count[i] == 1 && nxt[i] != -1)
            {
                end = i;
            }
        }
    }
    now = nxt[end];
    if (n % 2 == 1)
        nseq.push_back(end);
    while (now > 0)
    {
        nseq.push_back(now);
        now = nxt[now];
    }
    
    vector<int> ans(n);
    if (n % 2 == 1)
    {
        for (int i = 0; i < nseq.size(); i++)
            ans[i*2] = nseq[i];
        for (int i = 0; i < pseq.size(); i++)
            ans[(pseq.size()-1-i)*2 + 1] = pseq[i];
    }
    else
    {
        for (int i = 0; i < nseq.size(); i++)
            ans[i*2 + 1] = nseq[i];
        for (int i = 0; i < pseq.size(); i++)
            ans[(pseq.size()-1-i)*2] = pseq[i];
    }
    
    
    
    
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    
    return 0;
}