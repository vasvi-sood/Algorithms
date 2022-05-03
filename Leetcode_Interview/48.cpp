class Solution {
    void printmatrix(vector<vector<int>>& matrix)
    {
for(int i=0;i<matrix.size();i++)
{
    for(int j=0;j<matrix.size();j++)
    {
      cout<<matrix[i][j]<<" ";  
    }
    cout<<endl;
}
    
    
    }
    void rotate4(vector<vector<int>>& matrix,int row,int col)
    {
         int val=matrix[row][col];
        int n=matrix.size();
        for(int i=0;i<4;i++)
        {
            // cout<<"rotating "<<val<<endl;
         
        int nrow=col,ncol=n-1-row,nval=matrix[nrow][ncol];
            matrix[nrow][ncol]=val;
            val=nval;
            row=nrow;
            col=ncol;
               // printmatrix(matrix);
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
          int n=matrix.size();
        if(n<=1)
            return;
      int tot=0;
        // queue<vector<int>> q;
        // q.push({matrix[0][0],0,0});
      int i=0;int start1=0,start2=n-2;
        while(start1<=start2)
        {
            for(int j=start1;j<=start2;j++)
           rotate4(matrix,i,j);
            i++;
            start1++;
            start2--;
            
        }
    }
};