class Solution:

    def f(self, x, nums,check,dp):
        # print(x,check,dp)
        if check[len(nums)-1]:
            return
        for i in range(nums[x],0,-1):
            if x+i >= len(nums): continue
            if check[x+i]: continue
            check[x+i]=True
            self.f(x+i,nums,check,dp)

    def canJump(self, nums: List[int]) -> bool:
        check = [False] * len(nums)
        dp = [0] * len(nums)
        check[0]=True
        self.f(0,nums,check,dp)
        return check[len(nums)-1]
        