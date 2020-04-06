#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#define MOD ((i64)1e9 + 7)
using namespace std;
using i64 = long long;
 
int main() {
    string s;
    cin >> s;
    i64 count = 0, b = 0;
    int state = 0;
    
    for(int i = s.size()-1; i>= 0; i--){
        if(state == 0){
            if(s[i]=='b'){
                state = 1;
                b++;
            }
        }
        else if(state == 1){
            if(s[i] == 'a'){
                count += b;
                b *= 2;
            }
            else {
                b++;
            }
        }
        
        b %= MOD;
        count %= MOD;
    }
    
    cout << count;
    
    return 0;
}