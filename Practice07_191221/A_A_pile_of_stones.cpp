
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
    //printf("%d", n);
    
    string s;
    cin >> s;
    
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-')
            count--;
        else
            count++;
        count = max(count, 0);
    }
    
    printf("%d", count);
    
    return 0;
}