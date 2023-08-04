class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int &n;
    int &m;
    int ans=0;
    bool visited[50][50]={0};

    bool inmap(int x,int y){
        return (x>=0 && x<n && y>=0 && y<m);
    }

    int f(int x,int y,vector<vector>int>>& arr){
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(!inmap(nx,ny)) continue;
            if(arr[nx][ny]==0){
                visited[nx][ny]=1;
                f(nx,ny,arr);
            }
            else ans+=1;
        }
    }
    int containVirus(vector<vector<int>>& isInfected) {
        n = isInfected.size();
        m = isInfected[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    visited[i][j]=1;
                    f(i,j,isInfected);
                }
            }
        }
        return ans;
    }
};