#include <iostream>

using namespace std;

int main() {
    int n, d, h;
    scanf("%d %d %d", &n, &d, &h);
    
    
    
    if(d > 2*h){
        printf("-1");
        return 0;
    }
    
    int count = 2;
    
    for(int i = 0; i < h; i++){
        printf("%d %d\n", count -1, count);
        count++;
    }
    
    for(int i = 0; i < d-h; i++){
        if(i == 0)
            printf("1 %d\n", count);
        else
            printf("%d %d\n", count-1, count);
        count++;
    }
    
    int max = count;
    
    for(int i = 0; i <= n-max; i++){
        printf("1 %d\n", count);
        count++;
    }
    
    return 0;
}