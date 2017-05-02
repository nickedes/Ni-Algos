#include <stdio.h>

int main()
{
	int n, i, l, k, j, q;
	scanf("%d", &n);

	int p[n], m[n][n];

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			m[i][j] = -1;
		}
	}

	for (i = 0; i < n; ++i)
	{
		m[i][i] = 0;
	}

	// length
	for(l = 2; l < n; ++l)
	{
		for (i = 1; i < n - l + 1; ++i)
		{
			j = i + l - 1;
			for (k=i; k<=j-1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j] || m[i][j] == -1)
                    m[i][j] = q;
            }
		}
	}


	printf("%d ",m[1][n-1]);
	return 0;
}