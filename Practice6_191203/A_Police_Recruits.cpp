#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
 
using namespace std;
using i64 = long long;
 
 
int main() {
    int n;
    scanf("%d", &n);
    
    int now = 0;
    int count = 0;
    for(int i = 0; i< n; i++){
        int input;
        scanf("%d", &input);
        
        if(input == -1){
            now--;
            if(now < 0)
                count++;
        }
        else {
            if(now < 0)
                now = 0;
            now += input;    
        }
    }
    
    printf("%d", count);
    
    return 0;
}