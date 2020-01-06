#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbyFirst(pair<int,int> &a, pair<int,int> &b){
    return (a.first < b.first);
}

bool isOk(double mid, int n, vector<pair<int, int>> v){
    double val1_left = v[0].first;
    double val1_right = v[0].first + v[0].second*mid;
    
    printf("\nval1 : %lf %lf\n", val1_left, val1_right);
    
    for(int i = 1; i < n; i++){
        double val2_left = max((double)v[0].first, (double)v[i].first - v[i].second*mid);
        double val2_right = min((double)v[n-1].first, (double)v[i].first + v[i].second*mid);
        printf("val2 : %lf %lf\n", val2_left, val2_right);
        
        if(val1_left < val2_left)
            val1_left = val2_left;
        if(val2_right < val1_right)
            val1_right = val2_right;
        
        if((val1_left < val2_left) && (val2_left > val1_right))
            return false;
        if((val1_left > val2_left) && (val1_left > val2_right))
            return false;
    }
    
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v(n);
    
    //position
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i].first);
    //speed
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i].second);
    
    sort(v.begin(), v.end(), sortbyFirst);
    double max_time = 0;
    for(int i = 0; i < n; i++){
        double time_tmp;
        if(v[i].first - v[0].first < v[n-1].first - v[i].first)
            time_tmp = (v[n-1].first - v[i].first)/v[i].second;
        else
            time_tmp = (v[i].first - v[0].first)/v[i].second;
        if(time_tmp > max_time)
            max_time = time_tmp;
    }
    
    double lo = 0, hi = max_time;
    double ans = 0;
    
    for(int i = 0; i < 5; i++){
        double mid = (lo+hi)/2;
        printf("%lf %lf %lf", mid, lo, hi);
        if(isOk(mid, n, v)){
            hi = mid;
            ans = mid;
            printf(" ok\n");
        }
        else{
            lo = mid;
            printf(" no\n");
        }
    }
    
    printf("%lf", ans);
    
    return 0;
}