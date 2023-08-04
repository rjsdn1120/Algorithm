class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        # print(dp)
        for i in strs:
            cnt0,cnt1=0,0
            for j in i:
                if int(j)==0: cnt0+=1
                else: cnt1+=1
            
            mm=m;nn=n
            for im in range(mm,-1,-1):
                for jn in range(nn,-1,-1):
                    if cnt0>im or cnt1>jn: continue
                    dp[im][jn]= max(dp[im][jn],dp[im-cnt0][jn-cnt1]+1)
            # print(dp)
        return dp[m][n]