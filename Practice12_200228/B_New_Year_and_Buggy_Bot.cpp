#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    int s_i, s_j;
    cin >> n >> m;
    vector<string> arr(n);
    string mv;
    string udlr = "0123";
    int ans = 0;

    //input
    sort(udlr.begin(), udlr.end());
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'S')
            {
                s_i = i;
                s_j = j;
            }
        }
    }
    cin >> mv;
    
    //main code
    do 
    {
        int now_i = s_i, now_j = s_j;
        for (int i = 0; i < mv.size(); i++)
        {
            if (mv[i] == udlr[0])
                now_i--;
            if (mv[i] == udlr[1])
                now_i++;
            if (mv[i] == udlr[2])
                now_j--;
            if (mv[i] == udlr[3])
                now_j++;
            if (now_i < 0 || n <= now_i || now_j < 0 || m <= now_j)
                break;
            if (arr[now_i][now_j] == '#')
                break;
            if (arr[now_i][now_j] == 'E')
            {
                ans++;
                break;
            }
        }
    } while (next_permutation(udlr.begin(), udlr.end()));
    
    printf("%d", ans);
}