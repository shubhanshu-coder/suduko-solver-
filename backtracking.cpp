// #include<iostream>
// using namespace std;

// // rat in maze
// bool isSafe(int** arr,int x, int y ,int n){
//     if ( arr[x][y]=1 && x<n && y<n)
//     {
//         return true;
//     }
//     return false;
// }

// bool RatinMaze(int** arr, int x, int y, int n, int** SolArr){
//     if (x==n-1 && y==n-1)
//     {
//         SolArr[x][y]=1;
//         return true;
//     }
//     if (isSafe(arr,x,y,n))
//     {
//         SolArr[x][y]=1;
//         if (RatinMaze(arr,x+1,y,n,SolArr))
//         {
//             return true;
//         }
//         if (RatinMaze(arr,x,y+1,n,SolArr))
//         {
//             return true;
//         }
//         SolArr[x][y]=0;//backtracking code
//         return false;
//     }
// }



// int main(){
//     int n;
//     cin>>n;

//     int** arr=new int*[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i]=new int[n];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin>>arr[i][j];
//         }
        
//     }
//     int** SolArr=new int*[n];
//     for (int i = 0; i < n; i++)
//     {
//         SolArr[i]=new int[n];
//         for (int j = 0; j < n; j++)
//         {
//             SolArr[i][j]=0;
//         }
        
//     }
//     if (RatinMaze(arr,0,0,n,SolArr))
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout<<SolArr[i][j];
//             }cout<<endl;
            
//         }
        
//     }
    
        
//     return 0;
// }




//suduko solver

// A Backtracking program in
// C++ to solve Sudoku problem
#include <bits/stdc++.h>
using namespace std;




#define N 9


bool FindUnassignedLocation(int grid[N][N],
							int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

bool checkInRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool checkInCol(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool checkInBox(int grid[N][N], int boxStartRow,
			int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow]
					[col + boxStartCol] ==
									num)
				return true;
	return false;
}



bool isSafe(int grid[N][N], int row,
			int col, int num)
{
	
	return !checkInRow(grid, row, num)
		&& !checkInCol(grid, col, num)
		&& !checkInBox(grid, row - row % 3,
						col - col % 3, num)
		&& grid[row][col] == 0;
}

bool SolveSudoku(int grid[N][N])
{
	int row, col;

	if (!FindUnassignedLocation(grid, row, col))
	
		return true;

	
	for (int num = 1; num <= 9; num++)
	{
		
	
		if (isSafe(grid, row, col, num))
		{
			
			
			grid[row][col] = num;

			
			if (SolveSudoku(grid))
				return true;

		
			grid[row][col] = 0;
		}
	}
	
	// This  backtracking code
	return false;
}









void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
}


int main()
{
	
	int grid[N][N] = { { 0, 0, 7, 4, 9, 1, 6, 0, 5 },
					{ 2, 0, 0, 0, 6, 0, 3, 0, 9 },
					{ 0, 0, 0, 0, 0, 7, 0, 1, 0 },
					{ 0, 5, 8, 6, 0, 0, 0, 0, 4 },
					{ 0, 0, 3, 0, 0, 0, 0, 9, 0 },
					{ 0, 0, 6, 2, 0, 0, 1, 8, 7 },
					{ 9, 0, 4, 0, 7, 0, 0, 0, 2 },
					{ 6, 7, 0, 8, 3, 0, 0, 0, 0 },
					{ 8, 1, 0, 0, 4, 5, 0, 0, 0 } };
	if (SolveSudoku(grid) == true)
		printGrid(grid);
	else
		cout << "No solution exists";

	return 0;
}


