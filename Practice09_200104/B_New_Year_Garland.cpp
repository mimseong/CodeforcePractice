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
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        
        if(r-1 > g+b)
            printf("No\n");
        else if(g-1 > r+b)
            printf("No\n");
        else if(b-1 > g+r)
            printf("No\n");
        else
            printf("Yes\n");
    }
    
    
    return 0;
}