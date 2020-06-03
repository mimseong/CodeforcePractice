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
#define xx first
#define yy second
#define mod 1000000009
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    int s, x1, x2, t1, t2, p, d;
    scanf("%d %d %d %d %d %d %d", &s, &x1, &x2, &t1, &t2, &p, &d);
    
    // printf("%d %d %d %d %d %d %d", s, x1, x2, t1, t2, p, d);
    
    int walk_time = 0;
    int tram_time = 0;
    
    walk_time = abs(x2-x1)*t2;
    
    if (x1 < p && d == 1)
    {
        tram_time += (s-p)*t1 + (s-x1)*t1;
        d = -1;
    }
    else if (x1 <= p && d == -1)
    {
        tram_time += (p-x1)*t1;
        d = -1;
    }
    else if (p <= x1 && d == 1)
    {
        tram_time += (x1 - p) * t1;
        d = 1;
    }
    else if (p < x1 && d == -1)
    {
        tram_time += p*t1 + x1*t1;
        d = 1;
    }
    
    if (x1 < x2 && d == 1)
        tram_time += (x2-x1)*t1;
    else if (x1 < x2 && d == -1)
        tram_time += x1*t1 + x2*t1;
    else if (x2 < x1 && d == 1)
        tram_time += (s-x1)*t1 + (s-x2)*t1;
    else if (x2<x1 && d == -1)
        tram_time += (x1-x2)*t1;
        
    cout << min(walk_time, tram_time);
    
    return 0;
}