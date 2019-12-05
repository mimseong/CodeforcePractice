
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
 
using namespace std;
using i64 = long long;
 
//printf("%d", );
//scanf("%d", &);
//printf("\n");
 
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    sort(v.begin(), v.end());
    
    // for(int i = 0; i < n; i++){
    //     printf("%d ", v[i]);
    // }
    
    
    
    int count = 0;
    for(int i = 1; i < n-1; i++){
        if(v[0] < v[i] && v[i] < v[n-1])
            count++;
    }
    
    printf("%d", count);
    
    return 0;
}