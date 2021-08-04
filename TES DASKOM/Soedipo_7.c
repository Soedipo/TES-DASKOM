#include <stdio.h>
#include <string.h>
int main(){
	int n, i=0, j=0, k, a;
	char teks[101], t;
	printf("masukkan kalimat/kata: ");
	gets(teks);
	printf("Huruf yang ingin diketahui jumlahnya: ");
	scanf("%c", &t);
	n = strlen(teks);
	for(i=0 ; i<=n ; i++)
	{
		if(teks[i] == t)
		{
			j++;
		} 
	}
	printf("jumlah huruf %c : %d",t, j);
	return 0;
}
