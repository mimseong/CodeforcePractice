#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isOk(string s, int mid){
    vector<int> v(26, 0);
    vector<int> check(26, 0);
    vector<int> zero(26, 0);
    
    for(int i = 0; i < mid; i++){
        v[s[i]-'a']++;
        check[s[i]-'a'] = 1;
    }
    
    for(int i = 1; i <= s.length() - mid ; i++){
        v[s[i-1]-'a']--;
        v[s[i+mid-1]-'a']++;
        
        if(v[s[i-1]-'a'] <= 0)
            check[s[i-1]-'a'] = 0;
    }    
    
    if(zero == check)
        return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    
    int lo = 1;
    int hi = s.length();
    
    //이거 다시 확인해야함
    int ans = -999;
    
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        
        if(isOk(s, mid)){
            hi = mid - 1;
            ans = mid;
        }
        else
            lo = mid + 1;
    }
    printf("%d", ans);
}