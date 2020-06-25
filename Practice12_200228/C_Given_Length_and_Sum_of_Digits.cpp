#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, s;
    int start, end;
    scanf("%d %d", &m, &s);
    vector <int> min_ans(m, 0);
    vector <int> max_ans(m, 0);

    if (m == 1 && s == 0)
    {
        printf("0 0");
        return (0);
    }
    if (s < 1 || m * 9 < s)
    {
        printf("-1 -1");
        return (0);
    }
    //min
    int sum = s - 1;
    for (int i = 0; i < m; i++)
    {
        if (i == 0)
            end = 1;
        else
            end = 0;
        for (int j = 9; j >= end; j--)
        {
            if (j <= sum)
            {
                min_ans[i] = j;
                sum -= j;
                break;
            }
        }
    }
    min_ans[m - 1] += 1;
    
    //max
    sum = s;
    for (int i = 0; i < m; i++)
    {
        if (i == 0)
            end = 1;
        else
            end = 0;
        for (int j = 9; j >= end; j--)
        {
            if (j <= sum)
            {
                max_ans[i] = j;
                sum -= j;
                break;
            }
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        printf("%d", min_ans[i]);
    }
    printf(" ");
    for (int i = 0; i < m; i++)
    {
        printf("%d", max_ans[i]);
    }

    return (0);
}