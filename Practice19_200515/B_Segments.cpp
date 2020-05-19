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
#include <fstream>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second
#define MOD ((int)(1e9 + 9))
 
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
 
    vector<int> layer;
 
    for (int l = 0; l < n; l++)
    {
        for (int r = 1; r <= n - l; r++)
        {
            bool ok = false;
 
            for (auto& ri : layer)
            {
                if (l >= ri)
                {
                    ri += r;
                    ok = true;
                    break;
                }
            }
 
            if (!ok)
                layer.push_back(l + r);
        }
    }
 
    printf("%d\n", layer.size());
 
    return 0;
}