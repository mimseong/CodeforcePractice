#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;

i64 fastMul(i64 m, i64 b){
    if(m == 1){
        return b;
    }
    i64 ans = fastMul(m/2, b) %1000000007;
    if(m%2==1){
        return  ans * ans %1000000007 * b ;
    }
    return ans * ans %1000000007;
}
 
int main() {
    i64 n, m;
    scanf("%lld %lld", &n, &m);
    
    i64 ans = fastMul(m, 2);
    ans -= 1;
    
    printf("%lld", fastMul(n, ans)%1000000007);
    
    return 0;
}