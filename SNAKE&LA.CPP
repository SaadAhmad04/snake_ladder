#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include <time.h>

struct SNL{
	int pos1;
	int pos2;
};

int loc = 0, num = 0;
char name[10];
SNL l[5] = {{11,32} , {38,44} , {51,76} , {59,84} , {72,95}};
SNL s[5] = {{99,9} , {73,39} , {62,43} , {48,8} , {26,18}};
char design();
void board(int [10][10],int);

int main(){
	int m[10][10];
	int ch1,ch2,i,j,k=0,c=0;
	clrscr();
	design();
	gotoxy(27,16);
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch1;
	if(ch1 == 2)
		exit(1);
	else{
		clrscr();
		randomize();
		do{
			cout<<endl<<"PRESS 1 TO ROLL THE DICE"<<endl;
			cout<<"PRESS 2 TO DISPLAY THE BOARD"<<endl;
			cout<<"PRESS 3 TO LEAVE THE GAME"<<endl;
			cout<<"ENTER YOUR CHOICE : ";
			cin>>ch2;
			if(ch2 == 3)
				exit(1);
			else if(ch2 == 2)
				board(m,loc);
			else{
				num = random(6)+1;
				cout<<endl<<"The dice shows : "<<num<<endl;
				if(num > 100-loc)
					cout<<"You need only "<<100-loc<<" moves to win"<<endl;
				else{
					loc = loc+num;
					cout<<"Your position is : "<<loc<<endl;
					for(k=0;k<5;k++){
						if(l[k].pos1 == loc){
							loc = l[k].pos2;
							cout<<endl<<"WOW! You got the ladder"<<endl;
							cout<<"Now your position is : "<<loc<<endl;
							break;
						}
						else if(s[k].pos1 == loc){
							loc = s[k].pos2;
							cout<<endl<<"AWW! The snake has bitten you"<<endl;
							cout<<"Now your position is : "<<loc<<endl;
							break;
						}
					}
				}
				c++;
			}
		}while(loc != 100);
		if(loc == 100)
			cout<<endl<<"CONGURATULATIONS!"<<name<<" YOU HAVE WON THE GAME IN "<<c<<" MOVES";
			getch();
	}
	getch();
	return 0;
}

char design(){
	int i;
	for(i=0;i<78;i++){
		gotoxy(i,0);
		cprintf("*");
		delay(10);
	}
	for(i=0;i<24;i++){
		gotoxy(79,i);
		cprintf("*");
		delay(10);
	}
	for(i=79;i>=1;i--){
		gotoxy(i,23);
		cprintf("*");
		delay(10);
	}
	for(i=23;i>=1;i--){
		gotoxy(1,i);
		cprintf("*");
		delay(10);
	}
	gotoxy(31,9);
	cprintf("Let's start the game");
	gotoxy(31,11);
	cprintf("ENTER YOUR NAME - ");
	cscanf("%s",&name);
	gotoxy(27,13);
	cprintf("CLICK 1 : To start the game");
	gotoxy(27,14);
	cprintf("CLICK 2 : To exit the game");
}

void board(int m[10][10],int currentPos){
	int i,j,k,no=100;
	for(i=0;i<10;i++){
		if(i%2 == 0){
			for(j=0;j<10;j++){
				m[i][j] = no--;
			}
		}
		else{
			for(j=9;j>=0;j--){
				m[i][j] = no--;
			}
		}
	}
	cout<<endl;
		clrscr();
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				for(k=0;k<5;k++){
					if(s[k].pos1 == m[i][j]){
						cout<<"S\t";
						break;
					}
					else if(l[k].pos1 == m[i][j]){
						cout<<"L\t";
						break;
					}
					else if(currentPos == m[i][j]){
						cout<<"*\t";
						break;
					}
					else{
						if(k==4){
							cout<<m[i][j]<<"\t";
							break;
						}
					}
				}
			}
		       cout<<"\n";
		}
}
