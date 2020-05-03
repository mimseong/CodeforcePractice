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

vector<int> v[2005];

void    print()
{
    vector<int> result;

    for (int i = 1; i <= 2000; i++)
    {
        for (auto vi : v[i])
            printf("%d ", vi);
    }
    printf("\n");
}
 
int     main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        int diff;
        scanf("%d", &diff);
        v[diff].push_back(i);
    }
    
    int three_index = 0;
    vector<int> two_index;

    for (int i = 1; i <= 2000; i++)
    {
        if (v[i].size() >= 3)
        {
            three_index = i;
            break ;
        }
        if (v[i].size() == 2)
        {
            two_index.push_back(i);
        }
    }
    
    if (three_index == 0 && two_index.size() < 2)
    {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    print();

    if (two_index.size() >= 2)
    {
        swap(v[two_index[0]][0], v[two_index[0]][1]);
        print();
        swap(v[two_index[1]][0], v[two_index[1]][1]);
        print();
    }
    else
    {
        swap(v[three_index][0], v[three_index][1]);
        print();
        swap(v[three_index][0], v[three_index][2]);
        print();
    }
    
    return 0;
}