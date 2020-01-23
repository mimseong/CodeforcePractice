#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector<int> parent(n);
    vector<int> child[n];
    
    for(int i = 2; i <= n; i++){
        scanf("%d", &parent[i]);
        child[parent[i]].push_back(i);
    }
    
    
}