#include <stdio.h>
int main()
{
	int hari, bulan, tahun, a, b, c;
	printf("Jumlah hari: ");
	scanf("%d", &hari);
	tahun = hari/360;
	bulan = (hari%360)/30;
	hari = hari%30;
	printf("%d tahun %d bulan %d hari", tahun, bulan, hari);
}
