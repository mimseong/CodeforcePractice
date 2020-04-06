#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
 
using namespace std;
using i64 = long long;
 
int main() {
    string s;
    string result = "";
    
    cin >> s;
    
    
    for(int i = 0; i < s.size(); i++){
        if(i == 0){
            if(s[i] == '9'){
                result += s[i];
                continue;
            }
        }
        
        int tmp = s[i] - '0';
        
        if(tmp >= 5)
            result += 9 - tmp + '0';
        else
            result += tmp + '0';
    }
    
    cout << result;
    
    return 0;
}