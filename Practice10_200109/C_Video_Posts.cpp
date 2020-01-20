#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    vector<int> ans;
    int all_sum = 0;
    for(int i = 0; i<n ; i++){
        scanf("%d", &v[i]);
        all_sum += v[i];
    }
    
    if(all_sum%k != 0){
        printf("No\n");
        return 0;
    }
    
    int count = 0;
    int sum = 0;
    for(int i = 0; i<n ; i++){
        sum += v[i];
        if(sum == all_sum/k){
            ans.push_back(i+1);
            count++;
            sum = 0;
        }
    }
    int before = 0;
    if(k == count){
        printf("Yes\n");
        for(int i = 0; i < ans.size(); i++){
            printf("%d ", ans[i]-before);
            before = ans[i];
        }
    }
    else{
        printf("No\n");
    }
    
    return 0;
}