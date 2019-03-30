#include<iostream>
#include <conio.h> //header file to clear screen AND for kbhit()
#include<cstdlib>			// FOR SYSTEM CALLS	
#include<stdbool.h>
#include<time.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
/*** snake grid****/
#define n 10
#define m 14
/*** pacman grid****/
#define n1 15
#define m1 30

static int score=0;
/*****common method*****/
void delay(double sec){
	double millisec=1000*sec;
	clock_t start=clock();
	while(clock()<(start+millisec));
}
/* tictactoe methods*/
int checkForWin(char square[])
{
    int returnValue = 0;

    if (square[1] == square[2] && square[2] == square[3])
    {
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}

void displayBoard(char square[])
{
    system("cls");

    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

void markBoard(char square[],int choice,char mark, int player)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid move ");

        player--;
        getch();
    }
}

void ticTacToe(){
/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT

set the board with the correct character,
x or o in the correct spot in the array
**********************************************/
	char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int choice, player;
    int gameStatus;

    char mark;

    player = 1;

    do
    {
      displayBoard(square);

      // change turns
      player = (player % 2) ? 1 : 2;

      // get input
      printf("Player %d, enter a number: ", player);
      scanf("%d", &choice);

      // set the correct character based on player turn
      mark = (player == 1) ? 'X' : 'O';

      // set board based on user choice or invalid choice
      markBoard(square, choice, mark, player);

      gameStatus = checkForWin(square);

      player++;

    }while (gameStatus == -1);

    if (gameStatus == 1)
        printf("==>\aPlayer %d win ", --player);	// \a  alarm bell
    else
        printf("==>\aGame draw");
}

/******bollywood game method*************/

void bollywood(){
/**************************************
toss to choose player  then player wish to choose
-input movie name
-choose type of movie bollywood /hollywood		// one can make guess == size of word movie type
player- will guess if match then place that alphabet on its position   until all match otherwise game in progress
two choices 1)	guess alphabets		2) make move
****************************************/
	string mvName;
	system("cls");
	cout<<"Enter movie name :";
	cin>>mvName;
	int size=mvName.size();
	string type;
	cout<<"type Bollywood if it is hindi movie, Hollywood if it is english movie "<<endl;
	cin>>type;
	
	// required data is saved in above variable now game begins
	system("cls");			// to clear screen	
	cout<<"\t*****************Bollywood Game*************************"<<endl;
	string originalName =mvName;
	int j;
	int count=0;
	for(j=0;j<size;j++)
	{
		if(mvName.at(j)!='a'&& mvName.at(j)!='e'&& mvName.at(j)!='i'&& mvName.at(j)!='o'&& mvName.at(j)!='u'&& mvName.at(j)!='A'&&mvName.at(j)!='E'&&mvName.at(j)!='I'&&mvName.at(j)!='O'&&mvName.at(j)!='U')
		{
			mvName.at(j)='_';
			count++;
		}
	}
	if(count==0){
		cout<<"GAME OVER";		// CASE WHEN THERE IS NO BLANK ALL ARE VOWELS
		return ;
	}
	cout<<mvName<<endl<<type<<endl;
	char ch;			// choice
	int i=0;		// wrong guess made cross to that type
	do {
		cout<<endl<<"enter your choice"<<endl;
		cin>>ch;
		bool match=false;
		for(int i=0;i<size;i++)
		{
			if(ch==originalName.at(i))	{
				match=true;
				mvName.at(i)=ch;
				break;
			}
		}
		if(match==false){
			//	not matched
			if(type.at(i)=='d')
			{
				cout<<"Game Over"<<endl;
				system("pause");
				return ;
			}
			cout<<"Not matched, Be carefull"<<endl;
			type.at(i)='*';
			i++;
		}
		
		cout<<mvName<<endl;
		cout<<type<<endl;
	}
	while(mvName!=originalName);
	cout<<"Congratulations, you win."<<endl;
	return ;
}

/**************snake Game Method************/
class X
{
	public:
		int r;
		int c;
		X(){		}
		X(int r,int c)
		{
			this->r=r;
			this->c=c;
		}
};

queue<X> q;

void snakeGen(char a[n][m])		// call by reference
{
	X x1;
	// Use current time as seed for random generator 
    srand(time(0));
    	int hr, hc;
	int tr, tc;
// for head coord in grid
	hr=rand()%n;	
	hc=rand()%m;
// for tail coord in grid
	tr=rand()%3+(hr-1);
	if(tr<0)		// case if head is at corner.
		tr=-tr;
		
	if(tr==hr)
	{
		tc=rand()%3+(hc-1);
		while(tc==hc)
			tc=rand()%3+(hc-1);
			
		if(tc<0)
			tc=-tc;	
		else if(tc>=m)
			tc=rand()%2+(hc-1);
	}
	else {					// --> if(tr<tc || tr>tc) tc=hc;
		tc=hc;		
	}
// head is represented by 0
// body  & tail by 1
	a[hr][hc]='0';
	a[tr][tc]='1';
// initial position of snake  in queue 
	x1.r=tr;
	x1.c=tc;
	q.push(x1);
	x1.r=hr;
	x1.c=hc;
	q.push(x1);
}

void fruit(char a[n][m])
{
	int fr;
	int fc;
	fr=rand()%n;			
	fc=rand()%m;
	vector<int> vrow;
	vector<int> vcol;
	vector<int> vr;		
	vector<int> vc;
	queue<X> temp=q;
	//--->object to access temp queue each element .
	X x;
	while(!temp.empty()){
		x=temp.front();
		vrow.push_back(x.r);
		vcol.push_back(x.c);
		temp.pop();
	}
	sort(vrow.begin(),vrow.end());
	sort(vcol.begin(),vcol.end());
	int k=0;
	for(int i=0,j=0;i<n ;i++)
	{
		if(j<vrow.size() && vrow[j]==k){
			j++;
		}
		else{					// donot push same value multiple times bcz of using i-- in if condition
			vr.push_back(i);
		}
	}
	k=0;
	for(int i=0,j=0; i<m; i++)
	{
		if(j<vcol.size() && vcol[j]==k){
			j++;
		}
		else{
			k++;
			vc.push_back(i);
		}
	}
	
	for(int i=0;i<vrow.size();i++)		//---> size of vrow and vcol will same, storing coordinates of snake.
	{
		int s=vr.size();
		int s1=vc.size();
		while(vrow[i]==fr && vcol[i]==fc){
			fr=vr[rand()%s];
			fc=vc[rand()%s1];
			if(vrow.size()==n && vcol.size()==m)
			{
				fr=rand()%n;
				fc=rand()%m;
				break;
			}
		}
	}	
	a[fr][fc]='@';
}

bool haveFruit(char a[][m]){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='@')
				return true;
		}
	}
	return false;
}

int  snakeMovement(char a[n][m],char move)
{
	bool isFruit = false;
					        	//---> obj x2 to move head to new pos.
	X x2=q.back();				//---> x2 other feature to clean traces of tail left after single move (set to ' ').
				   				//----> x2 object have coord of head now
	if( move=='w' && x2.r -1>=0  && a[x2.r-1][x2.c]!='1') //--->up
		{
			if(a[x2.r-1][x2.c]=='=' || a[x2.r-1][x2.c]=='|')
				return -1;
			
			if(a[x2.r-1][x2.c]=='@')
				isFruit=true;
				
			a[x2.r-1][x2.c]='0';	//---->head
			a[x2.r][x2.c]='1';		//---->tail
			q.push(X(x2.r-1,x2.c));
		}
	else if(move=='s' && x2.r +1<n &&a[x2.r+1][x2.c]!='1') //--->down	
		{
			if(a[x2.r+1][x2.c]=='=' || a[x2.r+1][x2.c]=='|')
				return -1;
				
			if(a[x2.r+1][x2.c]=='@')
				isFruit=true;
				
			a[x2.r+1][x2.c]='0';
			a[x2.r][x2.c]='1';
			q.push(X(x2.r+1,x2.c));
		}
	else if(move=='a' && x2.c-1>=0 &&a[x2.r][x2.c-1]!='1') //--->left
		{
			if(a[x2.r][x2.c-1]=='=' || a[x2.r][x2.c-1]=='|')
				return -1;
				
			if(a[x2.r][x2.c-1]=='@')
				isFruit=true;
			
			a[x2.r][x2.c-1]='0';
			a[x2.r][x2.c]='1';
			q.push(X(x2.r,x2.c-1));
		}
	else if(move=='d' && x2.c+1<m && a[x2.r][x2.c+1]!='1')   //--->right
		{
			if(a[x2.r][x2.c+1]=='=' || a[x2.r][x2.c+1]=='|')
				return -1;
				
			if(a[x2.r][x2.c+1]=='@')
				isFruit=true;
				
			a[x2.r][x2.c+1]='0';
			a[x2.r][x2.c]='1';
			q.push(X(x2.r,x2.c+1));
		}
	else if(move!='a'&& move!='s'&& move!='d'&& move!='w'){		//--->invalid move
			return 1;
	}
	else if(move=='q'){				//---> quiting game
		return 0;		
	}
	else{							//--->rule's voilation
		return -1;
	}
	
	if(!isFruit){					//-->clearing tail previous pos.
		x2=q.front();
		a[x2.r][x2.c]=' ';
		q.pop();
	}
	else{
		score+=10;
		fruit(a);
	}
	
	return 1;
}

void  snakeGrid(char a[n][m])
{
	system("cls");
	cout<<"\tSCORE :"<<score<<endl;
	cout<<"\t================"<<endl;
	for( int i=0;i<n;i++)
	{	cout<<"\t|";
		for(int  j=0;j<m;j++)
		{
			cout<<a[i][j];
		}	
		cout<<"|"<<endl;
	}
	cout<<"\t================"<<endl;
	
	if( !haveFruit(a)){		// due to bug 
		fruit(a);
	}
}

void snakeGame(){
	char arr[][m]={ {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
					{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} };
	snakeGen(arr);
	fruit(arr);
	
	int returnValue=1;
	char move;
	while(1){
		
		if(kbhit()){
			move=getch();
			returnValue = snakeMovement(arr, move);
			goto label;
		}		
		if(move=='a' || move=='s' || move=='d' || move=='w')
			returnValue=snakeMovement(arr,move);	
	
	label:
	if(score==100){
		cout<<"\tCongractulations!!! Level Completed"<<endl;
		return ;
	}
	if(returnValue==0){
		cout<<"\tGame Quit"<<endl;
		return ;
	}
	
	if(returnValue==-1){
		cout<<"\tGame Over"<<endl;
		return ;
	}
		snakeGrid(arr);
		delay(1);
	}
}

/*******pac man method***********/

class CP		//--->CurrentPosition
{	public:
	int row;
	int col;
	bool isHorizantal;	// enemy movement
	bool isForward;		// for enemy dir after colliding walls
		CP(){		}
		CP(int r,int c,bool flag,bool dir){
			row=r;
			col=c;
			isHorizantal=flag;
			isForward=dir;
		}
};
static int counter=0;

int numOfFruits(char a[][m1]){
	int count=0;
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++)
			if(a[i][j]=='o' || a[i][j]=='0')
				count++;	
	}
	return count;
}

queue<CP> que;
CP enemyPos;

queue<char> tq;			// queue for storing   initial values stored enemy position before enemy generation

void enemyGen(char a[n1][m1])
{		
	int numOfEnemy=n1/3;
	int er,ec;				//--->enemy row & col.
	srand(time(0));			//--->diff rand num generation for each compiltion & set seed to curr time.
	while(numOfEnemy-- >0){
		er=rand()%n1;
		ec=rand()%m1;
		// if newEnemy at obstacle, oldEnemy or ActorInitialPostion recreate it. 
		while(a[er][ec]=='X' || a[er][ec]=='#' || a[er][ec]=='A'){
			er=rand()%n1;
			ec=rand()%m1;
		}
		bool isHorizantal;	// even direction
		if(er%2==0 && ec%2==0){
			isHorizantal=true;
		}
		else
			isHorizantal=false;
			
		que.push(CP(er,ec,isHorizantal,false));
									//---> storing initial position of enemy before gen., storing either furit or otherwise(space).
		tq.push(a[er][ec]);			//---> order will be maintained so while checking must use pop() .
		a[er][ec]='#';				//----> size of q and tq queue will be same.	
	}
}

queue<CP> qtemp;
queue<char> temp;	// after while loop setting initial pos. values of enemy to queue
int returnValue;

int enemyMovement(char a[][m1]){
	
	while(!que.empty()){	
		enemyPos=que.front();
		int r=enemyPos.row;
		int c=enemyPos.col;
		bool isEven=enemyPos.isHorizantal;
		bool flag=enemyPos.isForward;	
		if(isEven){		//---> horizantal movement.	
			if(flag==false && c+1<m1 && a[r][c+1]!='X' /*&& a[r][c+1]!='A'*/ && a[r][c+1]!='#'){
				if(a[r][c+1]=='A'){
					returnValue=-1;
					return returnValue;
				}
				temp.push(a[r][c+1]);
				a[r][c+1]='#';		    
				a[r][c]=tq.front();
				tq.pop();
				if(a[r][c+3]=='#' && c+3<m1)					//----> in the case of cross collision of enemies
					flag=true;
				if(c+2==m1 || a[r][c+2]=='X'|| a[r][c+2]=='#')
					flag=true;
					
				CP obj(r,c+1,isEven,flag);
				qtemp.push(obj);
	        }
			else {
				if(a[r][c-1]=='A'){
					returnValue=-1;
					return returnValue;
				}
				temp.push(a[r][c-1]);
				a[r][c-1]='#';
				a[r][c]=tq.front();
				tq.pop();
				if(a[r][c-3]=='#' && c-3>=0)
					flag=false;
				if(c-2<0 || a[r][c-2]=='X' || a[r][c-2]=='#')
					flag=false;
				CP obj(r,c-1,isEven,flag);
				qtemp.push(obj);
			}
		}
		
		else{			//---> vertical movement
			if(flag==false && r-1>=0  && a[r-1][c]!='X' /*&& a[r-1][c]!='A'*/ && a[r-1][c]!='#'){
				if(a[r-1][c]=='A'){
					returnValue=-1;
					return returnValue;
				}
				temp.push(a[r-1][c]);
				a[r-1][c]='#';
				a[r][c]=tq.front();
				tq.pop();
				if(a[r-3][c]=='#' && r>=0)
			 		flag=true;
				if(r-2<0 || a[r-2][c]=='X' || a[r-2][c]=='#'){
					flag=true;
			 	}
			 
				CP obj(r-1,c,isEven,flag);
				qtemp.push(obj);
			}
			
			else {
				if(a[r+1][c]=='A'){
					returnValue=-1;
					return returnValue;
				}
				temp.push(a[r+1][c]);
				a[r+1][c]='#';
				a[r][c]=tq.front();
				tq.pop();
				if(a[r+3][c]=='#' && r<n1)
					flag=false;
				if(r+2==n1 || a[r+2][c]=='X' || a[r+2][c]=='#'){
					flag=false;
				}
				
				CP obj(r+1,c,isEven,flag);
				qtemp.push(obj);
			}
		}
		que.pop();
	}
	while(!temp.empty()){
		tq.push(temp.front());
		temp.pop();
	}
	while(!qtemp.empty()){
		que.push(qtemp.front());
		qtemp.pop();
	}
	return 1;
}

void displayGrid(char a[][m1])
{
	system("cls");
	cout<<"Score :"<<score<<endl;
	cout<<"\t\t================================"<<endl;
	for(int i=0;i<n1;i++) {
		cout<<"\t\t|";
		for(int j=0;j<m1;j++)
		{
			cout<<a[i][j];
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t================================"<<endl;
}

// initial position of actor.	
static int ar=0;	// row coords of actor
static int ac=0;	// cols coords of actor

int actorMovement(char a[][m1])
{
	char press;
	if(kbhit()){		//---->for actor movement
		press=getch();
		if(press=='q')
		{
			cout<<"\nI QUIT"<<endl;
			return -1;
		}
		else if(press=='a' && ac-1>=0 && a[ar][ac-1]!='X')	//--->move left
		{
			if(a[ar][ac-1]=='#')
				return -1;
			if(a[ar][ac-1]=='o'){
				score+=10;
				counter++; 
			}
			else if(a[ar][ac-1]=='0'){
				score+=100;	
				counter++;
			}
			a[ar][ac-1]='A';
			a[ar][ac]=' ';
			ac--;
		}
		else if(press=='d' && ac+1<m1 && a[ar][ac+1]!='X')	//--->move right
		{	
			if(a[ar][ac+1]=='#')
				return -1;
				
			if(a[ar][ac+1]=='o'){
				score+=10;
				counter++;
			}
			else if(a[ar][ac+1]=='0'){
				score+=100;
				counter++;
			}
			a[ar][ac+1]='A';
			a[ar][ac]=' ';
			ac++;
		}
		else if(press=='w' && ar-1>=0 && a[ar-1][ac]!='X')	//--->move up
		{	
			if( a[ar-1][ac]=='#')
				return -1;
			if(a[ar-1][ac]=='o'){
				score+=10;
				counter++;
			}
			else if(a[ar-1][ac]=='0'){
				score+=100;
				counter++;
			}
			a[ar-1][ac]='A';
			a[ar][ac]=' ';
			ar--;
		}
		else if(press=='s' && ar+1<n1 && a[ar+1][ac]!='X')	//--->move DOWN
		{	
			if(a[ar+1][ac]=='#')
				return -1;
			if(a[ar+1][ac]=='o'){
				score+=10;
				counter++;
			}
			else if(a[ar+1][ac]=='0'){
				score+=100;
				counter++;
			}
			a[ar+1][ac]='A';
			a[ar][ac]=' ';
			ar++;
		}
		else if(press!='a' || press!='s' || press!='d' || press!='w'){	
		}	
	
		else{
			cout<<"\nGAME OVER"<<endl;
			return -1;
		}
	}
	return 1;
}

void pacMan(){
/**********************************************
	X	 obstacles
	#	 enemy
	A    player
	o    small fruit
	0    large fruit
    enemy even horizantal mov
    odd then move vertical
************************************************/
char a[n1][m1]={
	{'A',' ',' ',' ',' ',' ','o','0','o',' ',' ',' ',' ','o','o','o',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ','o','0','o'},
	{' ',' ',' ','X','X',' ',' ',' ',' ',' ',' ',' ',' ','o','o','o',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ','X',' ',' ','o',' ','X','X','X',' ',' ',' ',' ','o',' ','0','o',' ',' ',' ','X','X',' ',' '},
	{'X','X',' ',' ',' ',' ',' ','X',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X',' ','o'},
	{'X','X',' ',' ',' ',' ','X','X','X',' ','o',' ',' ',' ',' ',' ',' ',' ',' ','o','X','X',' ',' ',' ',' ',' ',' ',' ','o'},
	{'X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ',' ','X','X','0',' ',' ',' ',' ',' ',' ','o'},
	{' ',' ',' ','o','o',' ',' ','o','o',' ',' ',' ',' ','X',' ',' ',' ',' ',' ','0','X','X',' ',' ',' ',' ',' ',' ',' ','0'},
	{' ',' ',' ','o','o',' ',' ','o','o',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ','X','X','o',' ',' ',' ',' ',' ',' ','o'},
	{'o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','o'},
	{'o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','o'},
	{'o',' ','X','0','X',' ',' ',' ',' ',' ','o','o',' ','X','X',' ',' ',' ',' ','o','0',' ','o',' ',' ','X','X','X',' ','o'},
	{'o',' ','X','X','X',' ',' ',' ',' ',' ','o','o',' ','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
	{'0',' ',' ','o','o','0','o',' ',' ',' ',' ',' ',' ',' ','o','0','o','o',' ',' ',' ',' ',' ',' ',' ','X','X','X','X','X'} };

	enemyGen(a);
	displayGrid(a);
	cout<<"\t\t\tBOARD SETUP...\n";
	system("pause");
	int valueReturnByActor;
	int valueReturnByEnemy;	
	int count=numOfFruits(a);
	
  while(1)
  {		
  	if(count==counter){
  		cout<<"\n\tWINNER WINNER CHICKEN DINNER!!!\n";
  		cout<<"\t\tTotal Score :"<<score<<endl;
  		break;
	}
	valueReturnByActor=actorMovement(a);
	valueReturnByEnemy=enemyMovement(a);		//--> delay will be used for enemy movement.
	if(valueReturnByActor==-1 || valueReturnByEnemy==-1)		// game over
	{
		cout<<"\nGAME OVER";
		break;
	}
	displayGrid(a);
	
	delay(1);			//---> delay in seconds.
   }
   return ;
}

void printGames(){
	cout<<"Games you have :\n"<<endl;
	cout<<"\t1. Tic Tac Toe"<<endl;
	cout<<"\t2. Snake Game"<<endl;
	cout<<"\t3. Bollywood ( Guess the movie )"<<endl;
	cout<<"\t4. Pac-man\n\n"<<endl;
}

int main(){
	cout<<"\t\t\tWelcome to Console Gaming Application\n\n";
	printGames();
	int choice;
	cout<<"Enter your choice :";
	cin>>choice;
	switch(choice){
		case 1:	ticTacToe();
			break;
		case 2: snakeGame();
			break;
		case 3: bollywood();
			break;
		case 4: pacMan();
			break;
	}
}
