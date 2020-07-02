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

    vector<int> arr(n+2);

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    
    vector<int> fromL(n+2), fromR(n+2);

    for (int i = 1; i <= n; i++)
        fromL[i] = fromL[i-1] | arr[i];

    for (int i = n; i >= 1; i--)
        fromR[i] = fromR[i+1] | arr[i];

    int total = fromL[n];
    int maxIdx = 1;

    for (int i = 2; i <= n; i++)
    {
        int maxv = total - (from[maxIdx -1] | fromR[maxIdx + 1]);
        int now = total - (fromL[i-1] | fromR[i+1]);

        if (now > maxv)
            maxIdx = i;
    }

    swap(arr[maxIdx], arr[1]);

    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);

    return 0;
}