//C program to solve N Queen Problem using backtracking 
#include <stdio.h>
int count=0;
// To Display the solution  
void display(int N,int board[N][N])
{
    printf("\nSolution %d:\n", count );
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
		if(board[i][j]==1){
			printf(" Q ");
		    
		}else
		    {
		        printf(" _ ");
		    }
		}
		printf("\n");
	}
}

int isSafe(int N,int board[N][N], int row, int col)
{
	int i, j;

	
	for (i = 0; i < row; i++)
		if (board[i][col])
			return 0;

		for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return 0;

	 
	for (i = row, j = col; i >= 0 && j < N; i--, j++)
		if (board[i][j])
			return 0;

	return 1;
}

//A recursive  function to solve N Queen problem 
int nQueen(int N,int board[N][N], int rows)
{
	

	for (int i = 0; i < N; i++) {

		if (isSafe(N,board, rows, i)) {

			board[rows][i] = 1;
			if (rows== N-1){
			    count ++;
	    display(N,board);
	
	}else{


			if (nQueen( N,board, rows+ 1))
				return 1;
	}
			board[rows][i] = 0; // BACKTRACK
			
		}
	}

	return 0;
}

int main()
{
    
    int n;
    printf("enter the size of board");
    scanf("%d",&n);
    int a[n][n];
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			a[i][j]=0;
		}
	}
	nQueen(n,a, 0);
	if(count!=0){
	printf("\nTotal solutions are:%d",count);}
	else
	{
	    printf("\nSolution does not exist");
	}
	return 0;
}


