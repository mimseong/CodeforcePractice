#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int q;
    scanf("%d", &q);
    
    for(int i = 0; i < q; i++){
        i64 n, a, b;
        scanf("%lld %lld %lld", &n, &a, &b);
        
        if(2*a < b){
            printf("%lld\n", n*a);
        }
        else {
            printf("%lld\n", n/2*b + n%2*a);
        }
    }
    
    
    return 0;
}