///////////////////////RESTA UM///////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int coluna, int linha){
	COORD point;
	point.X = coluna; point.Y = linha; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
main()
{
	printf("@@@@@  @@@@@ @@@@@ @@@@@ @@@@@   @\n");
	printf("@   @@ @     @       @   @   @  @@\n");
	printf("@@@@@  @@@   @@@@    @   @@@@@ @ @\n");
	printf("@ @    @        @    @   @   @   @\n");
	printf("@  @   @@@@@ @@@@    @   @   @  @@@\n");
	printf("                Regras:           \n");
	printf("O objetivo do jogo eh fazer com que todas as peças sejam removidas\n");
	printf("ateh sobrar uma, cada movimento se consiste em pular uma peca por cima da outra\n");
	printf("e o destino da peca sempre deve ser uma lacuna vazia,sempre que pular por cima\n");
	printf("de uma peca a mesma deve ser retirada do jogo.\n");
	printf("Para se movimentar use as teclas W A S D e Space para pular\n");
	printf("     Pressione qualquer tecla para continuar");
	getch();	
	system("cls");
	int i,j;
	int linha=4,coluna=8;
	char tabuleiro [9][17]=
	{201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187,
	 186,' ',' ',' ',' ',' ','@',' ','@',' ','@',' ',' ',' ',' ',' ',186,
	 186,' ',' ',' ',' ',' ','@',' ','@',' ','@',' ',' ',' ',' ',' ',186,
	 186,' ','@',' ','@',' ','@',' ','@',' ','@',' ','@',' ','@',' ',186,
	 186,' ','@',' ','@',' ','@','[','O',']','@',' ','@',' ','@',' ',186,
	 186,' ','@',' ','@',' ','@',' ','@',' ','@',' ','@',' ','@',' ',186,
	 186,' ',' ',' ',' ',' ','@',' ','@',' ','@',' ',' ',' ',' ',' ',186,
	 186,' ',' ',' ',' ',' ','@',' ','@',' ','@',' ',' ',' ',' ',' ',186,
	 202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188};
	while(1){
		int pecas=0,possibilidades=0;
		char movimento;
		gotoxy(0,0);
		for(i=0;i<9;i++){
			for(j=0;j<17;j++){
				printf("%c",tabuleiro[i][j]);
			}
			printf("\n");
		}
		movimento=tolower(getch());
		if(movimento=='d' && coluna<14 && tabuleiro[linha][coluna+2]!=' '){
			if(tabuleiro[linha][coluna-1]=='['){
				tabuleiro[linha][coluna-1]=' ';
			}
			if(tabuleiro[linha][coluna+1]==']'){
				tabuleiro[linha][coluna+1]=' ';
			}
			coluna+=2;
			if(tabuleiro[linha][coluna-1]==' '){
				tabuleiro[linha][coluna-1]='[';
			}
			if(tabuleiro[linha][coluna+1]==' '){
				tabuleiro[linha][coluna+1]=']';
			}
		}
		if(movimento=='a' && coluna>2 && tabuleiro[linha][coluna-2]!=' '){
			if(tabuleiro[linha][coluna-1]=='['){
				tabuleiro[linha][coluna-1]=' ';
			}
			if(tabuleiro[linha][coluna+1]==']'){
				tabuleiro[linha][coluna+1]=' ';
			}
			coluna-=2;
			if(tabuleiro[linha][coluna-1]==' '){
				tabuleiro[linha][coluna-1]='[';
			}
			if(tabuleiro[linha][coluna+1]==' '){
				tabuleiro[linha][coluna+1]=']';
			}
		}
		if(movimento=='w' && linha>1 && tabuleiro[linha-1][coluna]!=' '){
			if(tabuleiro[linha][coluna-1]=='['){
				tabuleiro[linha][coluna-1]=' ';
			}
			if(tabuleiro[linha][coluna+1]==']'){
				tabuleiro[linha][coluna+1]=' ';
			}
			linha-=1;
			if(tabuleiro[linha][coluna-1]==' '){
				tabuleiro[linha][coluna-1]='[';
			}
			if(tabuleiro[linha][coluna+1]==' '){
				tabuleiro[linha][coluna+1]=']';
			}
		}
		if(movimento=='s' && linha<7 && tabuleiro[linha+1][coluna]!=' '){
			if(tabuleiro[linha][coluna-1]=='['){
				tabuleiro[linha][coluna-1]=' ';
			}
			if(tabuleiro[linha][coluna+1]==']'){
				tabuleiro[linha][coluna+1]=' ';
			}
			linha++;
			if(tabuleiro[linha][coluna-1]==' '){
				tabuleiro[linha][coluna-1]='[';
			}
			if(tabuleiro[linha][coluna+1]==' '){
				tabuleiro[linha][coluna+1]=']';
			}
		}
		if(movimento==' '){
			gotoxy(0,0);
			tabuleiro[linha][coluna-1]='(';
			tabuleiro[linha][coluna+1]=')';
			for(i=0;i<9;i++){
				for(j=0;j<17;j++){
					printf("%c",tabuleiro[i][j]);
				}
				printf("\n");
			}
			movimento=tolower(getch());
			if(movimento=='d'){
				if(tabuleiro[linha][coluna]=='@' && tabuleiro[linha][coluna+2]=='@' && tabuleiro[linha][coluna+4]=='O'){
					tabuleiro[linha][coluna-1]='[';
					tabuleiro[linha][coluna+1]=']';
					tabuleiro[linha][coluna]='O';
					tabuleiro[linha][coluna+2]='O';
					tabuleiro[linha][coluna+4]='@';
				}
			}
			if(movimento=='a'){
				if(tabuleiro[linha][coluna]=='@' && tabuleiro[linha][coluna-2]=='@' && tabuleiro[linha][coluna-4]=='O'){
					tabuleiro[linha][coluna-1]='[';
					tabuleiro[linha][coluna+1]=']';
					tabuleiro[linha][coluna]='O';
					tabuleiro[linha][coluna-2]='O';
					tabuleiro[linha][coluna-4]='@';					
				}
			}
			if(movimento=='w'){
				if(tabuleiro[linha][coluna]=='@' && tabuleiro[linha-1][coluna]=='@' && tabuleiro[linha-2][coluna]=='O'){
					tabuleiro[linha][coluna-1]='[';
					tabuleiro[linha][coluna+1]=']';
					tabuleiro[linha][coluna]='O';
					tabuleiro[linha-1][coluna]='O';
					tabuleiro[linha-2][coluna]='@';	
				}							
			}
			if(movimento=='s'){
				if(tabuleiro[linha][coluna]=='@' && tabuleiro[linha+1][coluna]=='@' && tabuleiro[linha+2][coluna]=='O'){
					tabuleiro[linha][coluna-1]='[';
					tabuleiro[linha][coluna+1]=']';
					tabuleiro[linha][coluna]='O';
					tabuleiro[linha+1][coluna]='O';
					tabuleiro[linha+2][coluna]='@';	
				}								
			}
			tabuleiro[linha][coluna-1]='[';
			tabuleiro[linha][coluna+1]=']';				
		}
		for(i=0;i<9;i++){
			for(j=0;j<17;j++){
				if(tabuleiro[i][j]=='@'){
					pecas++; 
				}
			}
		}
		for(i=0;i<9;i++){
			for(j=0;j<17;j++){
				if(tabuleiro[i][j]=='@' && tabuleiro[i][j+2]=='@' && tabuleiro[i][j+4]=='O')
					possibilidades++;
				if(tabuleiro[i][j]=='@' && tabuleiro[i][j-2]=='@' && tabuleiro[i][j-4]=='O')
					possibilidades++;
				if(tabuleiro[i][j]=='@' && tabuleiro[i-1][j]=='@' && tabuleiro[i-2][j]=='O')
					possibilidades++;
				if(tabuleiro[i][j]=='@' && tabuleiro[i+1][j]=='@' && tabuleiro[i+2][j]=='O')
					possibilidades++;
			}
		}
		if(pecas==1){
			gotoxy(0,0);
			for(i=0;i<9;i++){
				for(j=0;j<17;j++){
					printf("%c",tabuleiro[i][j]);
				}
				printf("\n");
			}
			printf("Venceu o Jogo!\n");
			printf("Restou apenas uma peca");
			break;
			getch();
		}
		if(possibilidades==0){
			gotoxy(0,0);
			for(i=0;i<9;i++){
				for(j=0;j<17;j++){
					printf("%c",tabuleiro[i][j]);
				}
				printf("\n");
			}
			printf("Fim De Jogo\n");
			printf("Restaram %d Pecas",pecas);
			break;
			getch();
		}
	}
}
