#include <stdio.h>
#include <string.h>
int main(){
	int n, i=0, j=1, k, a;
	char teks[101];
	printf("masukkan kalimat: ");
	gets(teks);
	n = strlen(teks);
	for(i=0 ; i<=n ; i++)
	{
		if(teks[i] == ' ')
		{
			j++;
		} 
	}
	printf("jumlah kata pada kalimat tersebut adalah: %d", j);
}
