#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <functional>
 
using namespace std;
using i64 = long long;
 
 
int main() {
    int n;
    string s;
    vector<int> v(4, 0);
    
    scanf("%d", &n);
    cin >> s;
    
    if(n % 4 != 0){
        printf("===");
        return 0;
    }
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A')
            v[0]++;
        else if(s[i] == 'C')
            v[1]++;
        else if(s[i] == 'G')
            v[2]++;
        else if(s[i] == 'T')
            v[3]++;
    }
    
    
    for(int i = 0; i < 4; i++){
        if(v[i] > n/4){
            printf("===");
            return 0;
        }
    }
    
    stack <char> st;
    for(int i = 0; i < 4; i++){
        v[i] = n/4 - v[i];
        for(int j = 0; j < v[i]; j++){
            if(i == 0)
                st.push('A');
            else if(i == 1)
                st.push('C');
            else if(i == 2)
                st.push('G');
            else if(i == 3)
                st.push('T');
        }
    }
   
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '?'){
            cout << st.top();
            st.pop();
        }
        else{
            cout << s[i];
        }
    }
    
    return 0;
}