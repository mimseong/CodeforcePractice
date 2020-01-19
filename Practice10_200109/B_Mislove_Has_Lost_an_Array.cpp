#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int max_num(int n){
    int tmp = 1;
    for(int i = 0; i < n-1; i++){
        tmp *= 2;
    }
    return tmp;
}
 
int main() {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    
    int min_sum = 0;
    int tmp = max_num(l);
    for(int i = 0; i < n; i++){
        min_sum += tmp;
        if(tmp != 1)
            tmp /= 2;
    }
    cout << min_sum;
    
    int max_sum = 0;
    int max_t = max_num(r);
    tmp = 1;
    for(int i = 0; i < n; i++){
        max_sum += tmp;
        if(tmp != max_t)
            tmp *= 2;
    }
    cout << " " << max_sum;
    
    
    return 0;
}