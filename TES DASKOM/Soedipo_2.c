#include <stdio.h>
int main(){
	int n, a, i, j;
	printf("jumlah baris: ");
	scanf("%d", &n);
	
	for(i=0 ; i<=n ; i++)
	{
		a = 1;
		for(j=0 ; j<i ; j++)
		{
			printf("%d", a);
			a+=1;
		}
		printf("\n");
	}
}
