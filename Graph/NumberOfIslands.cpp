#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<bool>>&vis,int row,int col){
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]!='1' || vis[r][c]){
            return;
        }
        vis[r][c]=true;
        dfs(r-1,c,grid,vis,row,col);
        dfs(r,c-1,grid,vis,row,col);
        dfs(r,c+1,grid,vis,row,col);
        dfs(r+1,c,grid,vis,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis,row,col);
                    count++;
                }
            }
        }
        return count;
    }
};