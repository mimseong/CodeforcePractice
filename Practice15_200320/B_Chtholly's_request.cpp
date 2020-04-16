#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
 
using namespace std;
using i64 = long long;
 
int main() {
    i64 k, p;
    cin >> k >> p;
    
    i64 sum = 0;
    for(int i = 1; i <= k; i++)
    {
        string s = to_string(i);
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        s += tmp;
        sum += (stoll(s) % p);
        sum %= p;
    }
    cout << sum << endl;
    
    
    return (0);
}