/*
Count all possible paths from top left to bottom right

The task is to count all the possible paths from top left to bottom right of a m X n matrix with the constraints that from each cell you can either move only to right or down.

*/

class Solution {
  public:
  
    long long int arr[101][101];
    int mod = 1e9 + 7;
    long long int solve(int row,int col,int m,int n)
    {
        if(row>=m or col>=n)return 0;
        
        if(row==m-1 and col==n-1)
        {
            return 1;
        }
        
        if(arr[row][col]!=-1)
        return arr[row][col];
        
        
        long long int right = solve(row,col+1,m,n);
        long long int down = solve(row+1,col,m,n);
        
        return arr[row][col]=(right+down)%mod;
        
    }
    
    long long int numberOfPaths(int m, int n){
 
        memset(arr,-1,sizeof(arr));
        
        return solve(0,0,m,n);
        
    }
};
