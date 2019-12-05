#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
 
using namespace std;
using i64 = long long;
 
//printf("%d", );
//scanf("%d", &);
//printf("\n");
 
int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    
    int sum;
    for(int i = 0; i < n; i++){
        int h, m;
        scanf("%d %d", &h, &m);
        
        if(i == 0){
            if(s+1 <= 60*h + m){
                printf("0 0");
                return 0;
            }
            sum = 60*h + m;
        }
        int after = 60*h + m;
        if(after - sum >= s*2 + 2){
            printf("%d %d", (sum+s+1)/60, (sum+s+1)%60);
            return 0;
        }
        
        sum = after;
    }
    printf("%d %d", (sum+s+1)/60, (sum+s+1)%60);
    
    return 0;
}