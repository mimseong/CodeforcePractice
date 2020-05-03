#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
 
i64 combination(int n, int k)
{
    if(n == k || k == 0)
        return 1;
    return (combination(n-1, k-1) + combination(n-1, k));
}
 
int main() {
    string send;
    string recv;
    cin >> send;
    cin >> recv;
    
    //cout << s << " " << send;
    
    int pos = 0;
    for (int i = 0; i < send.size(); i++)
    {
        if (send[i] == '+')
            pos++;
        else
            pos--;
    }
    //cout << pos << endl;
   
    int r_pos = 0, q_num = 0;
    for (int i = 0; i < recv.size(); i++)
    {
        if (recv[i] == '+')
            r_pos++;
        else if (recv[i] == '-')
            r_pos--;
        else
            q_num++;
    }
    if (q_num == 0)
    {
        if (r_pos == pos)
            cout << "1.0";
        else
            cout << "0.0";
        return (0);
    }
    
    vector<i64> res;
    int start = q_num;
    for (int i = 0; i <= q_num; i++, start -= 2)
    {
        i64 comb = combination(q_num, i);
        for (i64 i = 0; i < comb; i++)
        {
            res.push_back(start);
        }
    }

    double d = 0;
    for (int i = 0; i < res.size(); i++)
    {
        //cout << res[i] << " ";
        res[i] += r_pos;
        //cout << res[i] << endl;;
        if (pos == res[i])
            d++;
    }
    //cout << endl;
    printf("%.10lf", d/(double)res.size());
    
    return 0;
}