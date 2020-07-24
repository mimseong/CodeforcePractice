#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
bool sortbyfirst(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.first < b.first); 
}
 
int main() {
    
    vector<ii> v;
    
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        v.emplace_back(s.size()-2, i);
    }
    
    sort(v.begin(), v.end(), sortbyfirst);
    
    int great = 0;
    int idx = -1;
    if (v[0].xx*2 <= v[1].xx)
    {
        great++;
        idx = v[0].yy;
    }
    if (v[2].xx*2 <= v[3].xx)
    {
        great++;
        idx = v[3].yy;
    }
    
    if (great == 1)
        printf("%c", idx + 'A');
    else
        cout << "C";
    
    return 0;
}