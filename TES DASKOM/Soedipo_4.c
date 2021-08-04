#include <stdio.h>
int main()
{
	int n, a, i ,j, k, b;
	printf("jumlah baris: ");
	scanf("%d", &n);
	a = n;
	b=0;
	for(i=0 ; i<=n ; i++)
	{
		for(k=a ; k>0 ; k--)
		{
			printf(" ");		
		}
		for(j=0 ; j<=b ; j++)
			{
				printf("O");
			}
		printf("\n");
		b+=2;
		a--;
	}
}
