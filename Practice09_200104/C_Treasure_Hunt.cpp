#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int x, y;
    scanf("%d %d", &x, &y);
    
    if(((x2-x1)/x + (y2-y1)/y) % 2 != 0)
        printf("NO\n");
    else if((x2-x1)%x != 0)
        printf("NO\n");
    else if((y2-y1)%y != 0)
        printf("NO\n");
    else
        printf("YES\n");
    
    return 0;
}