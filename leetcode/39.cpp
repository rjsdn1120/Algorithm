class Solution {
public:
    vector<vector<int>> ans;
    void f(int x,int target,vector<int> arr,int sum,vector<int>& candidates){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(arr);
            return;
        }
        for(int i=x;i<candidates.size();i++){
            sum+=candidates[i];
            arr.push_back(candidates[i]);
            f(i,target,arr,sum,candidates);
            sum-=candidates[i];
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        f(0,target,arr,0,candidates);
        return ans;
    }
};