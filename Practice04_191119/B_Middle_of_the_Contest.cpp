#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
 
using i64 = long long;
 
int main() {
    int h1, m1;
    int h2, m2;
    char tmp;
    
    scanf("%d%c%d", &h1, &tmp, &m1);
    scanf("%d%c%d", &h2, &tmp, &m2);
    
    int sum = (h2*60 + m2 + h1*60 + m1)/2;
    
    printf("%02d:%02d", sum/60, sum%60);
    
    return 0;
}