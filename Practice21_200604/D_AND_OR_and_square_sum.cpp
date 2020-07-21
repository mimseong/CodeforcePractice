#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second
#define MOD ((i64)1e10)

using namespace std;

template<typename T, typename Pr = less<T>>
using pq = priority_queue<T, vector<T>, Pr>;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    vector<int> count(22, 0);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (v[i] & (1<<j))
                count[j]++;
        }
    }
    
    i64 ans = 0;
    vector<int> zero(22, 0);
    while (count != zero)
    {
        i64 num = 0;
        for (int j = 0; j < 21; j++)
        {
            if (count[j] > 0)
            {
                count[j]--;
                num = num + (1 << j);
            }
        }
        ans += num * num;
    }

    printf("%lld", ans);

    return 0;
}