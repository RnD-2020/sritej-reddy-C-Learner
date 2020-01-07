#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
//function declarations
void startGame();
void generateNewGame();
void generateOldGame();
void getLeaderBoard();
void printGame(int *,int );
void getName(char [] );
bool nameExists(FILE *,char []);
void playGame(char [],int *,int ,int );
void generateOneRandomly(int *,int );
bool won(int *,int );
bool furtherMovePossible(int *,int );
void storeInFile(char [],int ,int );
void storeNumberInFile(FILE *,int ,int ,int );
int no_of_digits(int );
void insertToFileFromThatPos(FILE *,char [],int ,int );
void saveStateToFile(char [],int ,int ,int []);
int* getStateFromFile(char [],int *,int *);
int getANumberFromFile(FILE *);
void downMove(int *,int );
void shiftdown(int *,int , int , int ,int);
void upMove(int *,int );
void shiftUp(int *,int , int , int ,int);
void leftMove(int *,int );
void shiftLeft(int *,int , int , int ,int);
void rightMove(int *,int );
void shiftRight(int *,int , int , int ,int);
bool isMergeble(int , int );
bool isFibonacci(int );
bool isPerfectSquare(int );




int main()
{
	startGame();
	return 0;
}

void startGame(){
	int c;
	printf("enter 1 - new game / 2 - resume game / 3 - leaderboard\n: ");
	scanf("%d",&c);
	switch (c) {
		case 1:
			generateNewGame();
			break;
		case 2:
			generateOldGame();
			break;
		case 3:
			getLeaderBoard();
			break;
		}
}

void generateNewGame() { //when a user looses and wants to play once again then we send some char c( other than '\0') so that his name wont be asked once again
		char name[20];
		getName(name);
		int n;
		printf("enter 2 - 2x2 game / 4 - 4x4 game / enter size(3 for 3x3)\n: ");
		scanf("%d",&n);
		int *a=(int *)calloc((n)*(n),sizeof(int));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				 *((a+i*n) + j)=0;
			}
		}
		generateOneRandomly(a,n);
		generateOneRandomly(a,n);
		playGame(name,a,0,n);
}

void generateOldGame() {
	char name[20];
	int *a,moves,n;
	a=getStateFromFile(name,&moves,&n);
	if(moves==-1){
		printf("\nno game is saved till now\nplease play a game and then save\n");
		printf("enter 1 - new game / 2 - leaderboard / any key to exit\n: ");
			int c ;
			scanf("%d",&c);
			if (c == 1) {
				generateNewGame();
			}
			if (c == 2) {
				getLeaderBoard();
			}
	}
	else playGame(name,a,moves,n);
}

void getLeaderBoard() {
		FILE *fp=fopen("fib_leaderboard.txt","r");
		char c,arr[100];
		int t=1;
		printf("\nSNO\tNAME\t\t  MOVES  BOARD(n=n*n)\n");
		c=fgetc(fp);
		printf("%c  \t",(t++)+48);
		while(c!=EOF && t<=20){
			fseek(fp,-1,SEEK_CUR);
			fgets(arr,100,fp);
			printf("%s",arr);
			c=fgetc(fp);
			if(c!=EOF)
				printf("%c  \t",(t++)+48);
		}
		fclose(fp);
}

void printGame(int *a,int n) {
	printf("\n\n\t\t\t");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", *(a+(i*n) + j));
		}
		printf("\n\t\t\t");
	}
	printf("\n");
}

void getName(char name[]) {
		printf("enter nick-name: ");
		scanf("%s",name);
		int k = 0;
		FILE *fp;
			while (true) {
				k = 0;
				if(fp=fopen("fib_leaderboard.txt","r")){
					if (nameExists(fp,name)) {
						k = 1;
					}
					fclose(fp);
				}
				if (k == 0) {
					if(fp=fopen("fib_state.txt","r")){
						printf("I");
						if (nameExists(fp,name)) {
							k = 1;
						}
						fclose(fp);	
					}
				}
				if (k == 0)
					break;
				printf("name is already taken choose other name: ");
				scanf("%s",name);
			}
	}

bool nameExists(FILE *fp,char name[]){
	char c,t_name[20];
	int k=0;
	char temp[100]; // this is used woth fgets to move file pointer to next line
	while(true){
		k=0;
		c=fgetc(fp);
		while(c!=' '){
			t_name[k++]=c;
			c=fgetc(fp);
		}
		t_name[k]='\0';
		if(!strcmp(t_name,name))
			return 1;
		fgets(temp,100,fp);
		c=fgetc(fp);
		if(c==EOF)
			break;
		else fseek(fp,-1,SEEK_CUR);
	}
	return 0;
}

void playGame(char name[],int *a,int moves,int n) {
		while (true) {
			moves++;
			system("cls");
			printGame(a,n);
			if (won(a,n)) {
				storeInFile(name,moves,n);
				break;
			}
			if (furtherMovePossible(a,n)==false) {
				printf("Game Over \n enter 1 - new game / 2 - leaderboard / 3 - exit\n: ");
				int c ;
				scanf("%d",&c);
				if (c == 1) {
					generateNewGame();
					break;
				}
				if (c == 2) {
					getLeaderBoard();
					break;
				}
				break;
			}
			printf("enter 1 - UP / 2 - DOWN / 3 - RIGHT / 4 - LEFT\n\t\t\t 5 - save state of game\n: ");
			int c ;
			scanf("%d",&c);
			if (c == 1){
				moves++;
				upMove(a,n);
			}
			else if (c == 2){
				moves++;
				downMove(a,n);
			}
			else if (c == 3){
				moves++;
				rightMove(a,n);
			}
			else if (c == 4){
				moves++;
				leftMove(a,n);
			}
			else if(c==5){
				saveStateToFile(name,moves,n,a);
				break;
			}
			else printf("enter correct option");
			generateOneRandomly(a,n);
		}
	}

void generateOneRandomly(int *a,int n) {
		srand(time(0)); 
		int i = rand()%n, j = rand()%n;
		while ( *((a+i*n) + j) != 0) {
			i = rand()%n;
			j = rand()%n;
		}
		 *((a+i*n) + j) = 1;
	}

bool won(int *a,int n) {
		int win = 2 * n * n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ( *((a+i*n) + j) == win) {
					return true;
				}
			}
		}
		return false;
	}

bool furtherMovePossible(int *a,int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == n - 1 && j == n - 1) {
					break;
				} else if (i == n - 1) {
					if (isMergeble( *((a+i*n) + j),  *((a+i*n) + j+1))) {
						return true;
					}
				} else if (j == n - 1) {
					if (isMergeble( *((a+i*n) + j),  *((a+(i+1)*n) + j))) {
					return true;
					}
				} else if (isMergeble(*((a+i*n) + j),  *((a+i*n) + j+1)) || isMergeble(*((a+i*n) + j),  *((a+(i+1)*n) + j))) {
					return true;
				}
			}
		}
		return false;
	}

void storeInFile(char name[],int moves,int board) {
		FILE *fp;
		if(!(fp=fopen("fib_leaderboard.txt","r+"))){ //this true only for the first time the file gets created
			fp=fopen("fib_leaderboard.txt","w");
		}
		else{
			int t_moves;
			char c,temp[100];
			while(true){
				fseek(fp,21,SEEK_CUR);
				t_moves=getANumberFromFile(fp);
				if(t_moves>moves){ //this is true when we reach a row that has greater moves value than currect moves
					fseek(fp,-25,SEEK_CUR);
					break;
				}
				fgets(temp,100,fp);			
				c=fgetc(fp);
				if(c==EOF)
					break;
				else fseek(fp,-1,SEEK_CUR);
			}
		}
		insertToFileFromThatPos(fp,name,moves,board);
	}

void storeNumberInFile(FILE *fp,int m,int ten_pow,int n){
	while(n--){
		if(ten_pow){
			fputc(((m/ten_pow)%10)+48,fp);
			ten_pow/=10;
		}
		else fputc(' ',fp);
	}
}

int no_of_digits(int n){
	if(n<10)
		return 1;
	return 1+no_of_digits(n/10);
}

void insertToFileFromThatPos(FILE *fp,char name[],int moves,int board){
	FILE *t=fp;
	char arr[10000];	//this is used to store rest of file from fp pos
	char c=fgetc(fp);
	int n,k=0;
	if(c==EOF)
		arr[0]='\0';
	else while(c!=EOF){		
			arr[k++]=c;
			c=fgetc(fp);
		}
	fseek(fp,-(k+1),SEEK_CUR);
	n=20;
	k=0;
	while(n--){
		if(name[k]!='\0')
			fputc(name[k++],fp);
		else fputc(' ',fp);
	}
	fputc(' ',fp);
	storeNumberInFile(fp,moves,pow(10,no_of_digits(moves)-1),3);
	fputc(' ',fp);
	storeNumberInFile(fp,board,pow(10,no_of_digits(board)-1),2);
	fputc('\n',fp);
	fputs(arr,fp);
}

void saveStateToFile(char name[],int moves,int board,int *a) {
		FILE *fp=fopen("fib_state.txt","w");
		int k=0;
		while(name[k]!='\0'){
			fputc(name[k++],fp);
		}
		fputc(' ',fp);
		k=no_of_digits(moves);
		storeNumberInFile(fp,moves,pow(10,k-1),k);
		fputc(' ',fp);
		k=no_of_digits(board);
		storeNumberInFile(fp,board,pow(10,k-1),k);
		fputc(' ',fp);
		for(int i=0;i<board;i++){
			for(int j=0;j<board;j++){
					fputc(*((a+i*board) + j)+48,fp);
					fputc(' ',fp);
			}
		}
	}

int* getStateFromFile(char name[],int *moves,int *board) {
		FILE *fp;
		int *a;
		if(!(fp=fopen("fib_state.txt","r"))){
			*moves=-1;
		}
		if(fp){
			int k=0;
			char c=fgetc(fp);
			while(c!=' '){
				name[k++]=c;
				c=fgetc(fp);
			}
			*moves=getANumberFromFile(fp);
			*board=getANumberFromFile(fp);
			int t=*board;
			a=(int *)calloc((t)*(t),sizeof(int));
			for(int i=0;i<*board;i++){
				for(int j=0;j<*board;j++){
					c=fgetc(fp);
					*((a+i*(*board)) + j)=c-48;
					c=fgetc(fp);
				}
			}
		}
		return a;
	
	}

int getANumberFromFile(FILE *fp) {
		int n=0;
		char c=fgetc(fp);
		while(c!=' '){
			n=n*10;
			n+=(c-48);
			c=fgetc(fp);
		}
		while(c==' '){ //this loop is moving fp to a point after spaces..this is for other task in storeInFilefunction
			c=fgetc(fp);
		}
		fseek(fp,-1,SEEK_CUR);
		return n;
	}

void removeZeroesOfColumnsDownMove(int *a,int n){ //q is 1 when called from downMove or 0 for upMove
	int j=n-1;
	for(int k=0;k<n;k++){ //this gives a coloumn number in every iteration
		j=n-1;
		for(int i=n-1;i>=0;i--){ //this is for row index
			if(*(a+i*n+k)!=0){
				*(a+j*n+k)=*(a+i*n+k);
				j--;
			}
		}
		while(j>=0){
			*(a+j*n+k)=0;
			j--;
		}
	}
}

void removeZeroesOfColumnsUpMove(int *a,int n){ //q is 1 when called from downMove or 0 for upMove
	int j=0;
	for(int k=0;k<n;k++){ //this gives a coloumn number in every iteration
		j=0;
		for(int i=0;i<n;i++){ //this is for row index
			if(*(a+i*n+k)!=0){
				*(a+j*n+k)=*(a+i*n+k);
				j++;
			}
		}
		while(j<n){
			*(a+j*n+k)=0;
			j++;
		}
	}
}

void removeZeroesOfaRowLeftMove(int *a,int n){
	int j=0;
	for(int k=0;k<n;k++){		//this gives a coloumn number in every iteration
		j=0;
		for(int i=0;i<n;i++){ //this is for row 
			if(*(a+k*n+i)!=0){
				*(a+k*n+j)=*(a+k*n+i);
				j++;
			}
		}
		while(j<n){
			*(a+k*n+j)=0;
			j++;
		}
	}
}


void removeZeroesOfaRowRightMove(int *a,int n){
	int j;
	for(int k=0;k<n;k++){		//this gives a coloumn number in every iteration
		j=n-1;
		for(int i=n-1;i>=0;i--){ //this is for row 
			if(*(a+k*n+i)!=0){
				*(a+k*n+j)=*(a+k*n+i);
				j--;
			}
		}
		while(j>=0){
			*(a+k*n+j)=0;
			j--;
		}
	}
}
	// gets triggered when down arrow is pressed
void downMove(int *a,int n) {
	removeZeroesOfColumnsDownMove(a,n);
		int k = n - 1, l = n - 2;
		while (l >= 0) {
			for (int i = 0; i < n; i++) {
				if (isMergeble(*((a+l*n) + i), *((a+k*n) + i))) {
					shiftdown(a,i, k, l,n);
				}
			}
			
			k--;
			l--;
		}
	}

	// shifts down the tiles by 1
void shiftdown(int *a,int col, int k, int l,int n) {
		*((a+k*n) + col) += *((a+l*n) + col);
		for (int i = l; i > 0; i--) {
			*((a+i*n) + col) = *((a+(i-1)*n) + col);
		}
		*((a+0*n) + col) = 0;
	}

	// gets triggered when up arrow is pressed
void upMove(int *a,int n) {
		removeZeroesOfColumnsUpMove(a,n);
		int k = 0, l = 1;
		while (l < n) {
			for (int i = 0; i < n; i++) {
				if (isMergeble(*((a+l*n) + i), *((a+k*n) + i))) {
					shiftUp(a,i, k, l,n);
				}
			}
			k++;
			l++;
		}
	}

	// shifts up the tiles by 1
void shiftUp(int *a,int col, int k, int l,int n) {
		*((a+k*n) + col) += *((a+l*n) + col);
		for (int i = l; i < n - 1; i++) {
			*((a+i*n) + col) = *((a+(i+1)*n) + col);
		}
		*((a+(n-1)*n) + col) = 0;
	}

	// gets triggered when left arrow is pressed
void leftMove(int *a,int n) {
	removeZeroesOfaRowLeftMove(a,n);
		int k = 0, l = 1;
		while (l < n) {
			for (int i = 0; i < n; i++) {
				if (isMergeble( *((a+i*n) + l),  *((a+i*n) + k))) {
					shiftLeft(a,i, k, l,n);
				}
			}
			k++;
			l++;
		}
	}

	// shifts left the tiles by 1
void shiftLeft(int *a,int row, int k, int l,int n) {
		 *((a+row*n) + k) += *((a+row*n) + l);
		for (int i = l; i < n - 1; i++) {
			*((a+row*n) + i) = *((a+row*n) + i+1);
		}
		*((a+row*n) + n-1) = 0;
	}

	// gets triggered when right arrow is pressed
void rightMove(int *a,int n) {
		removeZeroesOfaRowRightMove(a,n);
		int k = n - 1, l = n - 2;
		while (l >= 0) {
			for (int i = 0; i < n; i++) {
				if (isMergeble(*((a+i*n) + l),  *((a+i*n) + k))) {
					shiftRight(a,i, k, l,n);
				}
			}
			k--;
			l--;
		}
	}

	// shifts right the tiles by 1
void shiftRight(int *a,int row, int k, int l,int n) {
		 *((a+row*n) + k) += *((a+row*n) + l);
		for (int i = l; i > 0; i--) {
			*((a+row*n) + i) = *((a+row*n) + i-1);
		}
		*((a+row*n) + 0) = 0;
	}

bool isMergeble(int i, int j) {
		if (j == 0)
			return true;
		if (isFibonacci(i + j))
			return true;
		return false;
	}

bool isFibonacci(int n) {
		return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
	}

bool isPerfectSquare(int x) {
		int s = sqrt(x);
		return (s * s == x);
	}		