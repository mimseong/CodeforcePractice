#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n, k;
		scanf("%d %d", &n, &k);

		for (int j = 0; j < n; j++)
			printf("%c", 'a' + (j % k));
		printf("\n");
	}

	return 0;
}