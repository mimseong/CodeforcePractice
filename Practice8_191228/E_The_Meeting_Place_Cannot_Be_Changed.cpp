#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long int;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<i64, i64>> v(n);
    
    for(int i = 0; i < n; i++)
        scanf("%lld", &v[i].first);
    for(int i = 0; i < n; i++)
        scanf("%lld", &v[i].second);
    
    double lo = 0, hi = 1e9;
    
    for(int i = 0; i < 100; i++){
        double mid = (lo + hi) * 0.5;
        
        vector<double> starts, ends;
        for(int j = 0; j < n; j++){
            starts.push_back(v[j].first - v[j].second * min((double)v[j].first / v[j].second, mid));
            ends.push_back(v[j].first + v[j].second * min((1e9 - v[j].first) / v[j].second, mid));
        }
        
        if(*max_element(starts.begin(), starts.end()) > *min_element(ends.begin(), ends.end()))
            lo = mid;
        else
            hi = mid;
    }
    
    printf("%.10lf", lo);
    
    
    return 0;
}