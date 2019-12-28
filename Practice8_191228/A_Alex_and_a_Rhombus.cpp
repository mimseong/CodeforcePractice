#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n;
    scanf("%d", &n);
 
    int count = 1;
    for(int i = 1; i < n; i++){
        count += i*4;
    }
    printf("%d", count);
    
    return 0;
}