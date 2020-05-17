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
using ii = pair<int, int>;
 
int main() {
    int n;
    scanf("%d", &n);
    
    vector <int>v(101);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    
    int sum = 4;
    for (int i = 4; i <= 100; i += 2)
    {
        v[i] = v[i-2] + sum;
        sum += 2;
    }
    sum = 5;
    for (int i = 5; i <= 100; i += 2)
    {
        v[i] = v[i-2] + sum;
        sum += 2;
    }
    
    cout << v[n];
    
    
    return 0;
}