#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(101, 0);

    for (int i = 1; i <= 100; i++)
    {
        int k, f;
        scanf("%d %d", &k, &f);
        arr[k] = f;
    }
    // for (int i = 1; i <= 100; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    
    int ans_step = -1;#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> arr(101, 0);

    for (int i = 0; i < m; i++)
    {
        int k, f;
        scanf("%d %d", &k, &f);
        arr[k] = f;
    }
    
    int ans = 0;
    for (int step = 1; step < 101; )
    {
        bool is_ok = true;
        for (int i = 1; i <= 100; i++)
        {
            if (arr[i] != 0 && arr[i] != (i + step - 1)/step)
            {
                is_ok = false;
                break ;
            }
        }
        if (is_ok)
        {
            if (ans == 0)
                ans = (n + step - 1)/step;
            else
            {
                if (ans != (n + step - 1)/step)
                {
                    printf("-1");
                    return 0;
                }
            }
        }
        if (step == 50)
            step = 100;
        else
            step++;
    }
    if (ans == 0)
        printf("-1");
    else
        printf("%d", ans);
    
    return (0);
}
    for (int step = 1; step < 101; )
    {
        bool is_ok = true;
        for (int i = 1; i <= 100; i++)
        {
            if (arr[i] != 0 && arr[i] != (i + step - 1)/step)
            {
                is_ok = false;
                break ;
            }
        }
        if (is_ok)
        {
            if (ans_step == -1)
                ans_step = step;
            else
            {
                printf("-1");
                return 0;
            }
        }
        if (step == 50)
            step = 100;
        else
            step++;
    }
    if (ans_step == -1)
        printf("-1");
    else
        printf("%d", (n + ans_step - 1)/ans_step);
    
    return (0);
}