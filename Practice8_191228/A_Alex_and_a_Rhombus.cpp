#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n;
    scanf("%d", &n);
 
    printf("%d", n*n + (n-1)*(n-1));
    
    return 0;
}