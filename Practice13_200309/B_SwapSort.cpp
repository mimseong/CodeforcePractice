#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ii = pair<int, int>;

int main() {
    int n;
    scanf("%d", &n);
    
    vector <int> arr(n);
    
    set<ii> index;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        index.emplace(arr[i], i);
    }
    
    vector<ii> res;
    
    for (int i = 0; i < n; i++)
    {
        int small = index.begin()->first;
        index.erase(ii(arr[i], i));
        
        if (small == arr[i])
            continue ;
            
        auto minIdx = *index.begin();
        index.erase(index.begin());
        res.emplace_back(i, minIdx.second);
        swap(arr[i], arr[minIdx.second]);
        index.emplace(arr[i], minIdx.second);
    }
    
    printf("%d\n", res.size());
    for (auto& ri : res)
        printf("%d %d\n", ri.first, ri.second);
    
    return 0;
}