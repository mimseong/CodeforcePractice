#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int front;
    int here;
    int back;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <Node> a(n+1);
    
    vector<int> max(n+1);
    vector<int> min(n+1);
    
    for(int i = 1; i <= n; i++){
        a[i].front = i-1;
        a[i].here = i;
        a[i].back = i+1;
        
        max[i] = i;
        min[i] = i;
    }
    
    
    
    for(int i = 0; i < m; i++){
        int h;
        scanf("%d", &h);
        
        if(a[h].here == 1)
            continue;
        
        int f = a[h].front;
        
        a[h].here--;
        a[f].here++;
        
        a[a[h].back].front = f;
        a[a[f].front].back = h;
        
        a[f].back = a[h].back;
        a[h].front = a[f].front;
        
        a[f].front = h;
        a[h].back = f;
        
        if(a[h].here < min[h])
            min[h] = a[h].here;
        if(a[f].here > max[f])
            max[f] = a[f].here;
    }
    
    for(int i = 1; i <= n; i++){
        cout << min[i] << " " << max[i] << endl;
    }
    
    
    return 0;
}