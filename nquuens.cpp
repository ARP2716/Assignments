#include<iostream>
#include<vector>
using namespace std;

bool issafe(vector<vector<int>> &v,int x,int y,int n)
{
    for(int row = 0; row < x ; row ++)
    {
        if(v[row][y]==1)
        {
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row >=0 && col >=0)
    {
        if(v[row][col]==1)
        {
            return false;
        }
        row -- ;
        col --;
    }
    row = x;
    col = y;
    while(row >=0 && col < n)
    {
        if(v[row][col]==1)
        {
            return false;
        }
        row -- ;
        col ++;
    }
    return true;
}
bool solveQueen(int n,int x,vector<vector<int>> &v)
{
    if(x>=n)
    {
        return true;
    }
    for(int col = 0 ; col < n;col++)
    {
        if(issafe(v,x,col,n))
        {
            v[x][col]=1;

            if(solveQueen(n,x+1,v))
            {
                return true;
            }
            v[x][col]=0;
        }
    }
    return false;
   
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n,0));
    
    if(solveQueen(n,0,v))
    {
        for(int i=0;i<n;i++)
        {
            for(int j =0 ;j<n;j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}