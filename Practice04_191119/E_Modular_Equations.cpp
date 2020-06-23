#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
 
using i64 = long long;
 
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a == b){
        printf("infinity");
        return 0;
    }
    
    int n = 0;
    for(int i = 1; i*i <= (a-b); i++){
        if((a-b)%i == 0){
            if((a-b)/i > b && (a-b)/i != i)
                n++;
            if(i > b)
                n++;
        }
    }
    
    printf("%d", n);
    
    return 0;
}