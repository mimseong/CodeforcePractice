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
    vector <string> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    sort(v.begin(), v.end());
        
    int count = 1;
    int max = 1;
    for(int i = 0; i < n-1; i++){
        if(v[i] == v[i+1])
            count++;
        if(v[i] != v[i+1]){
            if(max < count)
                max = count;
            count = 1;
        }
    }
    if(max < count)
        max = count;
    printf("%d", max);
    
    return 0;
}