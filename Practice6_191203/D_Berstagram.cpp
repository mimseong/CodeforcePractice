#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
 
using namespace std;
using i64 = long long;

int main() {
    int n, m;
    scanf("%d%c", &n, &m);
    vector<int> change(n+1);
    vector<int> max(n+1);
    vector<int> min(n+1);
    
    for(int i = 1; i <= n; i++){
        change[i] = i;
        max[i] = i;
        min[i] = i;
    }
    
    for(int i = 0; i < m; i++){
        int input;
        scanf("%d", &input);
        
        if(change[input] == 1)
            continue;
        
        change[input]--;
        
        int j;
        for(j = 1; j <= n; j++){
            if(change[j] == change[input]){
                change[j]++;
            }
        }
        
        if(change[input] < min[input])
            min[input] = change[input];
        if(change[j] > max[j])
            max[j] = change[j];
    }
    
    for(int i = 1; i <= n; i++){
        printf("%d %d\n", min[i], max[i]);
    }
    
    return 0;
}