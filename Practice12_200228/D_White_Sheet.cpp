#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> x(7);
    vector<int> y(7);

    for (int i = 1; i < 7; i++)
    	scanf("%d %d", &x[i], &y[i]);
    if (x[3] <= x[1] && y[3] <= y[1] && x[2] <= x[4] && y[2] <= y[4])
    {
    	printf("NO");
    	return (0);
    }
    if (y[3] <= y[1] && y[2] <= y[4])
    {
    	if (x[1] < x[4])
    		x[1] = x[4];
    	else if (x[3] < x[2])
    		x[2] = x[3];
    }
    else if (x[3] <= x[1] && x[2] <= x[4])
    {
    	if (y[3] < y[2])
    		y[2] = y[3];
    	else if (y[1] < y[4])
    		y[1] = y[4];
    	printf("%d %d %d %d\n", x[1], y[1], x[2], y[2]);
    }
    if (x[5] <= x[1] && y[5] <= y[1] && x[2] <= x[6] && y[2] <= y[6])
    {
    	printf("NO");
    	return (0);
    }    
    printf("YES");
    return (0);
}