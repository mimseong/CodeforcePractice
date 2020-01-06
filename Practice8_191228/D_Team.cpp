#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int min = n-1;
    int max = (n+1)*2;
    
    if(m < min || max < m){
        printf("-1");
        return 0;
    }
    
    int all = m - min;
    
    for(int i = 0; i < 2; i++){
        if(all > 0){
            printf("1");
            all--;
        }
    }
    for(int i = 0; i < n-1; i++){
        printf("01");
        if(all > 0){
            printf("1");
            all--;
        }
    }
    printf("0");
    for(int i = 0; i < 2; i++){
        if(all > 0){
            printf("1");
            all--;
        }
    }
    
    
    return 0;
}