#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Mapping
{
public :
    void init(const vector<int>& raw, int base = 0)
    {
        start = base;
        arr = raw;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
    }

    int get_idx(int k)
    {
        return start + (lower_bound(all(arr), k) - arr.begin());
    }

    int get_value(int idx)
    {
        return arr[idx - start];
    }

    int size()
    {
        return arr.size();
    }

private:
    int start;
    vector<int> arr;
};

int color[6][6];

int main()
{
    vector<int> x(6), y(6);

    for (int i = 0; i < 6; i++)
        scanf("%d %d", &x[i], &y[i]);

    Mapping xmap, ymap;
    xmap.init(x);
    ymap.init(y);

    for (int i = 0; i < 6; i++)
    {
        x[i] = xmap.get_idx(x[i]);
        y[i] = ymap.get_idx(y[i]);
    }

    for (int i = 2; i < 6; i += 2)
        for (int sx = x[i]; sx < x[i + 1]; sx++)
            for (int sy = y[i]; sy < y[i + 1]; sy++)
                color[sx][sy] = 1;

    for (int sx = x[0]; sx < x[1]; sx++)
    {
        for (int sy = y[0]; sy < y[1]; sy++)
        {
            if (color[sx][sy] == 0)
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return (0);
}