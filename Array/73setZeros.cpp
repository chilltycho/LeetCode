/*若矩阵某元素为0,将该行、该列均设为0*/
#include<vector>
#include<iostream>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    auto r=matrix.size();
    auto c=matrix[0].size();
    bool isfirstrow=false,isfirstcol=false;
    //先统计首行或首列是否有0
    for(size_t i=0;i<r;i++)
    {
        if(matrix[i][0]==0)
            isfirstcol=true;
    }
    for(size_t j=0;j<c;j++)
    {
        if(matrix[0][j]==0)
            isfirstrow=true;
    }
    //若matrix[i][j]为0,将对应首行，首列元素置0
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    //根据首行首列0情况置零
    for(int i=1;i<r;i++)
    {
        if(matrix[i][0]==0)
            for(int j=0;j<c;j++)
                matrix[i][j]=0;
    }
    for(int j=1;j<c;j++)
    {
        if(matrix[0][j]==0)
            for(int i=0;i<r;i++)
                matrix[i][j]=0;
    }
    
    if(isfirstrow)
    {
        for(int j=0;j<c;j++)
            matrix[0][j]=0;
    }
    if(isfirstcol)
    {
        for(int i=0;i<r;i++)
            matrix[i][0]=0;
    }
}