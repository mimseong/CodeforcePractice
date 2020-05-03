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
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    string v;
    cin >> v;
 
    if (v[a-1] == v[b-1])
        printf("0");
    else
        printf("1");
    
    return 0;
}