class Solution {
public:
    bool isSquare(int x)
    {
        for(int i=2;i*i<=x;i++)
        {
            if(!(x%(i*i))) return false;
        }
        return true;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(isSquare) continue;
            int ck[31]={0};
            for(int j=2;j<=i;j++)
            {
                if(!(nums[i]%j))
                {
                    ck[j]=1;
                    nums[i]/=j;
                }
            }
            for(int j=i+1;j<n;j++)
            {
                for(int k=2;k<=nums[j];k++){
                    
                }
            }
        }
            
    }
};