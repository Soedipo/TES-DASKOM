#include <stdio.h>
#include <string.h>
int main(){
	char teks[101][101], cari[101];
	int n, i, j, a[101], x[101], y=1;
	printf("masukkan jumlah kalimat/kata: ");
	scanf("%d", &n);
	printf("Masukkan Kalimat : \n");
	getchar();
	
	for(i=1 ; i<=n ; i++)
	{
		printf("%d. ", i);
		gets(teks[i]); 
	}
	
	for(i=1 ; i<=n ; i++)
	{
		a[i]=strlen(teks[i]);
	}
	
	printf("Cari : ");
	gets(cari);
	
	for(i=1 ; i<=n ; i++)
	{
		x[i]=0;
		for(j=0 ; j<=a[i] ; j++)
		{
			if(teks[i][j]==cari[j] && teks[i][j]!='\0')
			{
				x[i]++;
			}
		}
	}
	for(i=1 ; i<=n ; i++)
	{
		if(x[i]>=3)
		{
			printf("%d. %s\n", y, teks[i]);
			y++;
		}
	} 
}
