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
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
 
int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        vector <int> a(x);
        vector <int> b(x);
        string input;
        cin >> input;
        bool is_one = false;
        
        for (int j = 0; j < x; j++)
        {
            if (is_one == false)
            {
                if (input[j] == '2')
                {
                    a[j] = 1;
                    b[j] = 1;
                }
                else if (input[j] == '1')
                {
                    a[j] = 0;
                    b[j] = 1;
                    is_one = true;
                }
                else
                {
                    a[j] = 0;
                    b[j] = 0;
                }
            }
            else
            {
                if (input[j] == '2')
                {
                    a[j] = 2;
                    b[j] = 0;
                }
                else if (input[j] == '1')
                {
                    a[j] = 1;
                    b[j] = 0;
                    is_one = true;
                }
                else
                {
                    a[j] = 0;
                    b[j] = 0;
                }
            }
        }
        
        for (int j = 0; j < x; j++)
            cout << a[j];
        cout << endl;
        for (int j = 0; j < x; j++)
            cout << b[j];
        cout << endl;
    }
    
    return 0;
}