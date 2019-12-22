#include <iostream>
#include <vector>
 
using namespace std;
using i64 = long long;
 
int main() {
    i64 n; char c;
    scanf("%lld%c", &n, &c);
    
    vector<int> alpha = {4, 5, 6, 3, 2, 1};
    
    i64 q = (n + 3) / 4 - 1;
    i64 r = n % 2;
    
    i64 result = q*16 + alpha[c-'a'];
    if (r == 0)
        result += 7;
    
    printf("%lld", result);
}