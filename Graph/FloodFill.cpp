#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int sr,int sc,int color,vector<vector<int>>&image,int row,int col,int orgColor){
        if(sr<0 || sc<0 || sr>=row || sc>=col ||image[sr][sc]==color || image[sr][sc]!=orgColor){
            return;
        }
        image[sr][sc]=color;
        dfs(sr,sc-1,color,image,row,col,orgColor);
        dfs(sr-1,sc,color,image,row,col,orgColor);
        dfs(sr,sc+1,color,image,row,col,orgColor);
        dfs(sr+1,sc,color,image,row,col,orgColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        dfs(sr,sc,color,image,row,col,image[sr][sc]);
        return image;
    }
};