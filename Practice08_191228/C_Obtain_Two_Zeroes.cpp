#include <iostream>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    
    for(int i = 0; i < q; i++){
        int n, m;
        scanf("%d %d", &n, &m);
        
        int minNum = min(n, m);
        int maxNum = max(n, m);
        
        if(minNum*2 < maxNum){
            printf("NO\n");
            continue;
        }
        
        if((n+m)% 3 == 0)
            printf("YES\n");
        else
            printf("NO\n"); 
        
    }
    
    return 0;
}