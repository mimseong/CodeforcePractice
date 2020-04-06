#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long int;

string RGB = "RGB";

int main(){
    int q;
    scanf("%d", &q);
    
    for(int i = 0; i < q; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        string s;
        cin >> s;
        int min = s.size();
        
        for(int j = 0; j < 3; j++){
            int l = 0, r = 0;
            int c = j;
            int count = 0;
            
            for(int i = 0; i < k; c++,i++){
                if(s[i] == RGB[c%3])
                    count++;
            }
            if(k-count < min)
                min = k-count;
            
            for(int r = k; r < n; r++, c++){
                if(s[r] == RGB[c%3])
                    count++;
                if(s[r-k] == RGB[(c-k)%3])
                    count--;
                if(k-count < min)
                    min = k-count;
            }
        }
        cout << min << endl;
    }
    
    return 0;
}