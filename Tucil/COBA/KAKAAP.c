 #include <stdio.h>
 #include <conio.h>
 #include <time.h>
 #include <stdlib.h>
 #include <windows.h>
 #include <string.h>
 #include <mmsystem.h>
 #define Height 30
 #define Weight 60
 #pragma comment(lib, “winmm.lib”)
 
void map(char map[Height][Weight]);
void hidden();
void gotoxy(int x,int y);
void move(int x, int y, char map[Height][Weight]);
void musuh1(char map[Height][Weight]);
void musuh2(char map[Height][Weight]);
void musuh3(char map[Height][Weight]);
void musuh4(char map[Height][Weight]);
void end(FILE *X);
void leaderboard();
void usertemp();
void sortplayer();
void sort();
void menu();
void timer();

clock_t t;
FILE *user_file;
int h=40, w=10, he=30, we=20, score, i, j, l;
struct{
		double sec;
		char id[50];
}player, temp[50], temp3;
 struct{
 	int k, l;
 }temp1, temp2; 
	char musu1[Height][Weight], musu2[Height][Weight];
	 char map1[30][60] =
	{	
   { " _____________________________________________         _____" },
   { "|#############################################         ####|" },
   { "|#############################################         ####|" }, //finish
   { "|####                                       ##         ####|" },
   { "          #########    ###########          ##         ####|" },
   { "          #########    ##       ##          #######    ####|" },
   { "|####                  ##       ##                     ####|" },
   { "|########     ###   #####       #######       #############|" },
   { "|####         ###      ##    *  #######       ###   *  ####|" },
   { "|####         ###     ##            ###                ####|" },
   { "|####      ##############       ###########################|" },
   { "|####         ###                                      ####|" },
   { "|#########    ###               #######      ###       ####|" },
   { "|#########    #############     #######    ######    ######|" },
   { "|####   ##                      ##   ##      ###       ####|" },
   { "|####   ##    #############     ##   ##      ###       ####|" },
   { "|####   ##    #############          ######################|" },
   { "|####         ###                                      ####|" },
   { "|####         ###    #####   ##########      ##############|" },
   { "|####         ###      ###   ##########      ###       ####|" },
   { "|###############       ###          ###                ####|" },
   { "|####                  ###          ###      ###       ####|" },
   { "|####       *     #####################      ###       ####|" },
   { "|####                                ############      ####|" },
   { "|####       ##############           ##                ####|" },
   { "|####                  ###     ###   ##    ####        ####|" },
   { "|#################     ####################################|" },
   { "|##########################################################|" },
   { "|##########################################################|" },
   { "|__________________________________________________________|" }
   }; 
   
   char map3[Height][Weight] =
	{	
   { " __________________________________________________________" },
   { "|##########################################################|" },
   { "|##                                 ####          #########|" },
   { "|##                                 ####         ##########|" },
   { "|######   ##########   ####   ########    #################|" },
   { "|######   ##########   ####   ########  * #################|" },
   { "|######         ####   ####   ########    #################|" },
   { "|######         ####   ###############                #####|" },
   { "|###########    ####   ###############                #####|" },
   { "|###########    ####                      #########   #####|" },
   { "|###########    ####           ####################   #####|" },
   { "|###########    #######   ##########     #        #   #####|" },
   { "|###########    #######   ##########     #        #   #####|" },
   { "                         *        ##     #####    #         " },
   { "|######    ###   #####     ###    ##       ###    #########|" },
   { "|######    ###   #####     ###    #####    ###       ######|" },
   { "|######    ###   #####     ###    ###      ###       ######|" },
   { "|######                    ###    ###                ######|" },
   { "|######     ##################    ###############    ######|" },
   { "|######     ######                        ###        ######|" },
   { "|######     ######                                   ######|" },
   { "|######     #################################        ######|" },
   { "|######                           ################   ######|" },
   { "|######################    ###    ################   ######|" },
   { "|######################    ###                ####   ######|" },
   { "|######################    ###                #############|" },
   { "|########## *              ############    ################|" },
   { "|########################################H#################|" },
   { "|________________________________________C_______________| |" },
   { "|__________________________________________________________|" }
   };
   
   char map2[Height][Weight] =
	{		
   { " ___________________________________________________________" },
   { "|##########################################################|" },
   { "|##########################################################|" }, 
   { "|######  *      ####      ##########                        " },
   { "|######         ####      ##########                        " },
   { "|######         ####      ##########      #################|" },
   { "|##########     ####            ####      #################|" },
   { "|##########     ####            ####      #################|" },
   { "|##########     ####            ####                #######|" },
   { "|##########     ###########     ####                #######|" },
   { "|##########     ###########     ####      ####      #######|" },
   { "|######         ###########     ####      ####      #######|" },
   { "|######         ####                      ####      #######|" },
   { "|######     ########                      ####    * #######|" },
   { "|######     ########                      ####      #######|" },
   { "|######     ###############     ###########################|" },
   { "|######     ###############     ###########################|" },
   { "|######                                             #######|" },
   { "|######                                             #######|" },
   { "|#################     ####     ####     ######   * #######|" },
   { "|#################     ####     ####     ######     #######|" },
   { "|#################     ####     ####     ######     #######|" },
   { "|######                ####     ###############     #######|" },
   { "|######                ####     ###############     #######|" },
   { "|######     ######     ####     ####                #######|" },
   { "|######     ######     ####     ####                #######|" },
   { "|######     ###############################################|" },
   { "|##                                                      ##|" },
   { "|######     ############################################## |" },
   { "|_____#     #______________________________________________|" }
   };
 
 
 int main(){
 	char click, pilih;
	int x, y, n;
	PlaySound (TEXT("Relaxing Acoustic Guitar Instrumental Music - 10 mins.wav"), NULL, SND_SYNC | SND_LOOP);
	menu();
	srand(time(0));
	printf("Level: \n"
		   "1. Level 1\n"
		   "2. Level 2\n"
		   "3. Level 3\n");
	printf("Pilih level: ");
	scanf("%d", &pilih); 
	
	switch(pilih){
		case 1:{
			x=2; y=4;
			system("cls");
			map(map1);
			musuh1(map1);
			musuh2(map1);			
			t = clock();
			move(x, y, map1);
			
		}
		case 2:{
			x=4; y=27;
			system("cls");
			map(map2);
			musuh1(map2);
			musuh2(map2);
			t = clock();
			move(x, y, map2);
		}
		case 3:{
			x=4; y=13;
			system("cls");
			map(map3);
			musuh1(map3);
			musuh2(map3);
			t = clock();
			move(x, y, map3);
		}
	}
}






// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







void gotoxy(int x,int y){
COORD co;
co.X=x;
co.Y=y;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), co);
}

void hidden(){
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci;
GetConsoleCursorInfo(hOut,&cci);
cci.bVisible=0;//Assign 1 to display, assign 0 to hide
SetConsoleCursorInfo(hOut,&cci);
}

void move(int x, int y, char map[Height][Weight]){
	char click; int life=3, star=3, a = 1;
	gotoxy(62, 1); printf("Sisa Nyawa: %d", life);
				gotoxy(x,y); printf("O");
			  hidden();
			
			while(1){
			
				click = getch();
	 			switch (click){
	 				case 'w': {
					 if(map[y-1][x]=='#' || (y==0)) break; gotoxy(x--,y);				
	 					printf(" ");
	 					y--; x++;
 						gotoxy(x,y);
 						if(map[y][x] == '@'){ 
 							life--;
 							map[y][x] = ' '; 
							 gotoxy(62, 1); printf("Sisa Nyawa: %d", life);
 							sleep(2); 
 							if(life == 0){
 								system("cls");
 								gotoxy(0,0);
 							end(user_file);
							 }
						 }
						else if ((y==1 || x==58) && star == 0){
							system("pause");
 							system("cls");
 							gotoxy(0,0); 
							end(user_file);
 							break;
					     } 
						 else if(map[y][x]=='*'){
						 	star--;
						 	printf("O");
						 }
 						else printf("O");
 						
 					break;
		 			}								   	 //up
	 				case 's': {
	 					if(map[y+1][x]=='#' || y==29) break; gotoxy(x--,y);
	 					printf(" ");
 						y++; x++;
 						gotoxy(x,y);
 						if(map[y][x] == '@'){ 
 							life--;
 							map[y][x] = ' '; 
							 gotoxy(62, 1); printf("Sisa Nyawa: %d\n", life);
 							sleep(2); 
 							if(life == 0){
 								system("cls");
 								gotoxy(0,0);
 							end(user_file);;
							 }
						 }
						 else if ((y==1 || x==58) && star == 0){
							system("pause");
 							system("cls");
 							gotoxy(0,0); 
							end(user_file);
 							break;
						 }
						 else if (map[y][x]=='C'){
							system("pause");
 							system("cls");
 							gotoxy(0,0);
 							end(user_file);;
						 } 
						 else if(map[y][x]=='*'){
						 	star--;
						 	printf("O");
						 }
 						else printf("O");
 					
		 				break;
					 }											 //down
			 		case 'a': {
			 			if(map[y][x-1]=='#' || x==2) break; gotoxy(x--,y);
	 					printf(" ");
 						gotoxy(x,y);
 						if(map[y][x] == '@'){ 
 							life--;
 							map[y][x] = ' '; 
							 gotoxy(62, 1); printf("Sisa Nyawa: %d\n", life);
 							sleep(2); 
 							if(life == 0){
 								system("cls");
 								gotoxy(0,0);
 							end(user_file);;
							 }
						 }
						else if ((y==1 || x==58) && star == 0){
							system("pause");
 							system("cls");
 							gotoxy(0,0); 
							end(user_file);
 							break;
 						}
						 else if(map[y][x]=='*'){
						 	star--;
						 	printf("O");
						 }
 						else printf("O");
 						
		 				break;
					}											 //left
			 		case 'd': {
					 	if(map[y][x+1] == '#' || x==59) break; gotoxy(x--,y);	 				
	 					printf(" ");
 						x+=2;
 						gotoxy(x,y);
 						if(map[y][x] == '@'){ 
 							life--;
 							map[y][x] = ' '; 
							 gotoxy(62, 1); printf("Sisa Nyawa: %d\n", life);
 							sleep(2); 
 							if(life == 0){
 								system("cls");
 								gotoxy(0,0);
 							end(user_file);;
							 }
						 }
						 else if ((y==1 || x==58) && star == 0){
							system("pause");
 							system("cls");
 							gotoxy(0,0); 
							end(user_file);
 							break;
 						}
						 else if(map[y][x]=='*'){
						 	star--;
						    printf("O");
						 }
 						else printf("O");
 					
		 				break;
					 }										 //right
					case 27: {
						system("cls"); printf("terima kasih ^_^"); system("cls"); main();
						break;
					}
		 			} 				
					musuh1(map);
				musuh2(map);
			}
				
		}

void map(char mapp[Height][Weight]){
	int H, W;	 
	for(H=0;H<30;H++){
		for(W=0;W<60;W++){
			printf("%c", mapp[H][W]);
		} printf("\n");
	}
}

void musuh1(char mapp[Height][Weight]){
	int a, b; temp2.k = he; temp2.l = we;
	gotoxy(temp2.k, temp2.l); printf(" "); 
	do{
		a = ((rand() % 3) + -1); 
		b = ((rand() % 3) + -1);
		he += a;
		we += b;
	}while(mapp[we][he]!=' ' && mapp[we][he] == '#');
	
	
	 if(mapp[we][he] != '#'){
	  musu2[we][he] = '@'; musu2[temp2.l][temp2.k] = ' ';
		mapp[we][he] = '@'; mapp[temp2.l][temp2.k] = ' ';
		
		if((h>58 || h<=1) || (w>27 || w<=1)) {
		he = temp2.k; 
		we = temp2.l; 
		musu2[we][he] = ' '; musu2[temp2.l][temp2.k] = '@';
		mapp[we][he] = ' '; mapp[temp2.l][temp2.k] = '@';
		gotoxy(he, we); printf("%c", mapp[temp2.l][temp2.k]);
		} else gotoxy(he, we); printf("%c", mapp[we][he]);
	    
	} else {
		he = temp2.k; we = temp2.l;
	}
			
}

void musuh2(char mapp[Height][Weight]){
	int a, b; temp2.k = h; temp2.l = w;
	gotoxy(temp2.k, temp2.l); printf(" "); 
	do{
		a = ((rand() % 3) + -1); 
		b = ((rand() % 3) + -1);
		h += a;
		w += b;
	}while(mapp[w][h]!=' ' && mapp[w][h] == '#');
	
	
	 if(mapp[w][h] != '#'){
	  musu2[w][h] = '@'; musu2[temp2.l][temp2.k] = ' ';
		mapp[w][h] = '@'; mapp[temp2.l][temp2.k] = ' ';
		
		if((h>58 || h<=1) || (w>27 || w<=1)) {
		h = temp2.k; 
		w = temp2.l; 
		musu2[w][h] = ' '; musu2[temp2.l][temp2.k] = '@';
		mapp[w][h] = ' '; mapp[temp2.l][temp2.k] = '@';
		}; 		
	    gotoxy(h, w); printf("%c", mapp[w][h]);
	    
	} else {
		h= temp2.k; w = temp2.l;
	}
			
}

void end(FILE *X){
	int dat;
	t = clock() - t;
	score = t/CLOCKS_PER_SEC;
	printf ("\n");
	printf ("------------- GAME SELESAI ^_^ ---------------"
	"\n================ SCOREMU : %lf ===================\n\n", score);
	X = fopen("Data.dat", "ab"); 
	getchar();
	printf ("Username: ");
	gets (player.id);
	player.sec = score;
	fwrite(&player, sizeof(player), 1, X); 
	fclose(X);

	system("pause");
	system("cls");
	leaderboard();
}

void leaderboard(){
	FILE *user_file2;
	int m, n;
	
	sortplayer();
	
	printf ("\n\t====================== PREMIUM =======================\n\n");
	user_file = fopen("Data.dat", "rb"); 
	while (fread (&player, sizeof(player), 1, user_file) == 1){
		printf ("\t%d. Nama\t\t: %s\n", i, player.id); 
		printf ("\t   Username\t: %f\n", player.sec);
		printf ("\n");
		i++;
		}
			
	fclose(user_file); 
	
	printf("-------------------------------------------------------------------\n\n"
		   "Menu: "
		   "\t<1> Kembali\n"
		   "\t<2> Exit"
		   "\n\n    Pilih: ");
	scanf("%d", &n);
	switch(n){
		case 1:
			system("cls");
			menu();
			break;
		case 2:
			system("cls"); printf("Terimakasih ^_^");
			exit(0);
			break;
		default:
			system ("cls");
			printf ("Menu tidak tersedia, silahkan ulangi\n\n");
			system ("pause");
			system ("cls");
			main();
	}
}

void sort(int i, int j){
	for (i=0;i<l+1;i++){
        for (j=0;j<=l+1-j;j++)
  		{
        	if (strcmp(temp[j].id, temp[j+1].id) < 0){
                temp3=temp[j];
    			temp[j]=temp[j+1];
    			temp[j+1]=temp3;
            }
  		}
    }
}

void sortplayer(){
	FILE *user_file2;
	int m, n;	
	usertemp();
	l = i - 1;
	sort(m, n);
	user_file = fopen("Data.dat", "rb");
	user_file2 = fopen("Data2.dat", "wb");
	for(i = 0 ; i <= l ; i++){
		strcpy(player.id, temp[i].id);
		player.sec = temp[i].sec;
		fwrite(&player, sizeof(player), 1, user_file2); 
	}
	
	fclose(user_file);
	fclose(user_file2);
	remove("Data.dat");
	rename("Data2.dat","Data.dat");
}

void usertemp(){
	i=0;
	user_file = fopen("Data.dat", "rb");
	while (fread(&player,sizeof (player),1, user_file)==1){
			strcpy(temp[i].id, player.id); temp[i].sec = player.sec;
			i++;
	}
	fclose(user_file);
}

void menu(){
    int n;
    printf("\t\t Maze Runner \n\n");
    printf("Menu Awal\n");
    printf("1.Play\n2.Leaderboard\n3.intruksi\n4.Exit\n\n");
    printf("masukkan pilihan Menu: ");
    scanf("%d",&n);
  
    switch(n) 

        {

              case 1: 
              system("cls");
              break;

              case 2:
              system("cls");
              leaderboard();
              break;
              
              case 3:
              system("cls");
              printf("Instruksi\n");
              printf("Cara menjalankan Karakter dengan cara menekan wasd.\n"); 
              printf("Di game ini disediakan 3 stage dan di setiap stage ada musuh dan bintang.\n");
              printf("bintang ini berfungsi untuk melanjutkan ke stage berikutnya.\n"); getch(); system("cls"); menu();           
              break;
            
              case 4:
              printf("Terimakasih ^_^");
              exit(0);
              break;
           
              default:
              printf("Menu tidak tersedia");
        }
}

/*void mapp1(int y){
	int a, b;
	if (y==1){
		main();
	} 
}

void mapp2(int x){
	if (x==58){
		main();
	} 
}

void mapp3(int x){
	if (x==58){
		main();
	} 
}*/


/*if(mapp[w][h] != '#' && ((h>58 || h<=1) || (w>27 || w<=1))) {
		h = temp2.k; w = temp2.l;
		musu2[w][h] = ' '; musu2[temp2.l][temp2.k] = '@';
		mapp[w][h] = ' '; mapp[temp2.l][temp2.k] = '@';
		gotoxy(h, w); printf("%c", mapp[temp2.l][temp2.k]);
		}	
		
	else if(mapp[w][h] != '#' && ((h<=58 || h>1) || (w<=27 || w>1))){
	 	
		musu2[w][h] = '@'; musu2[temp2.l][temp2.k] = ' ';
		mapp[w][h] = '@'; mapp[temp2.l][temp2.k] = ' ';
		gotoxy(h, w); printf("%c", mapp[w][h]);
	}*/
/*int musuh(){
	int x, y, a, b;
	gotoxy(x, y); printf("O");
	srand(1);
	while(1){
		a = ((rand() % (3)) + -1);
		b = ((rand() % (3)) + -1);
	x += a;
	y += b;
	if((x!=0 && y!=0) && (x>0 && y>0)){
			gotoxy(x,y);
 	printf("%d ", x);
	} if (x<=0) x += 2; if(y<=0) y += 2;

	usleep (100000);
	}
	return 0;
}*/

