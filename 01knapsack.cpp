// A dynamic programming based solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i][w - wt[i - 1]],
							K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main()
{
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int rodLength = 4;
	int n = sizeof(price) / sizeof(price[0]);

	cout << knapSack(rodLength, length, price, n);

	return 0;
}
