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
        int n;
        scanf("%d", &n);
        vector<i64> v(n);
        for(int i = 0; i < n; i++)
            scanf("%lld", &v[i]);
        sort(v.begin(), v.end());
        
        
        i64 count = v[0];
        int s = 0, e = 0;
        while(s < n){
            if(count > 2048){
                count -= v[s];
                s++;
            }
            else if(count < 2048){
                e++;
                count += v[e];
            }
            else{
                break;
            }
        }
        if(count == 2048)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}