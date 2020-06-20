#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);

	vector<int> a(m);
	vector<int> b(n);

	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int now;
			scanf("%d", &now);

			if (now == 0)
				printf("0 ");
			else
				printf("%d ", min(a[j], b[i]));
		}
		printf("\n");
	}

	return 0;
}