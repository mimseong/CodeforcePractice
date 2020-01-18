#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
 
int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    
    for(int i = l; i <= r; i++){
        string s = to_string(i);
        
        int s_size = s.size();
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        
        if(s_size == s.size()){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    
    return 0;
}