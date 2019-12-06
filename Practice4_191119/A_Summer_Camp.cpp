#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
 
using i64 = long long;
 
int main() {
    int n;
    scanf("%d", &n);
    
    string s = "";
    for(int i = 1; i <= 1000; i++){
        s += to_string(i);
    }
    
    printf("%c", s[n-1]);
    
    return 0;
}