include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<i64> v(n);
    vector<i64> sub(n-1);
    
    for(int i = 0; i < n; i++){
        scanf("%ld", &v[i]);
    }
    
    for(int i = 0; i < n-1; i++){
        sub[i] = v[i+1] - v[i];
    }
    
    i64 sum = v[n-1] - v[0];
    sort(sub.begin(), sub.end(), greater<i64>());
    
    for(int i = 0; i < k-1; i++){
        sum -= sub[i];
    }
    
    printf("%ld", sum);
    
    return 0;
}