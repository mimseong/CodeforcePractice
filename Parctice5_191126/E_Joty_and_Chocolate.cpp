#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
 
using namespace std;
using i64 = long long;
 
i64 GCD(i64 a, i64 b){
    if(b == 0)
        return a;
    return GCD(b, a%b);
}
 
i64 LCM(i64 a, i64 b){
    return a/GCD(a, b)*b;
}
 
 
int main() {
    i64 n, a, b, p, q;
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &p, &q);
    
    i64 choco = 0;
    
    i64 lcm = LCM(a, b);
    
    if(p > q)
        choco += n/lcm*p;
    else
        choco += n/lcm*q;
        
    choco += (n/a-n/lcm)*p;
    choco += (n/b-n/lcm)*q;
        
    printf("%lld", choco);
    
    return 0;
}