股票买卖问题：
三个状态：天数、当天允许交易最大次数、当前持有状态(1表示持有，0表示未持有)
```C++
dp[i][k][0 or 1] 其中0<=i<=n-1,1<=k<=K

for i=[0,n)
    for 1<=k<=K
        for s 0 or 1
            dp[i][k][s]=max(buy,sell,rest) ，买入、卖出、不交易
状态转移：
dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
                不交易          卖出
dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
                不交易          买入
初始条件：
dp[-1][k][0]=0, 未开始，利润为0
dp[-1][k][1]=-inf 不可能
dp[i][0][0]=0 不允许交易
dp[i][0][1]=-inf 不可能

题一：k=1，最多一次交易
dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]+prices[i])
dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][0]-prices[i])
                              -prices[i]
由于k总为1，可舍去
int dp[n][2]
for(int i=0;i<n;i++)
    if(i-1==0)
        dp[i][0]=0
        dp[i][1]=-inf
        continue
    dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
    dp[i][1]=max(dp[i-1][1],-prices[i])
return dp[n-1][0]
int maxProfit(vector<int> prices)
{
    int n=prices.size();
    int dp_i_0=0,dp_i_1=INT_MIN;
    for(int i=0;i<n;i++)
    {
        dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
        dp_i_1=max(dp_i_1,-prices[i]);
    }
    return dp_i_0;
}
题二：k=inf
可认为k和k-1一样
dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])
int maxProfit(vector<int> prices)
{
    int n=prices.size();
    int dp_i_0=0,dp_i_1=INT_MIN;
    for(int i=0;i<n;i++)
    {
        auto temp=dp_i_0;
        dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
        dp_i_1=max(dp_i_1,temp-prices[i]);
    }
    return dp_i_0;
}

题三：k=inf 且卖出后等一天才能交易
dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i])
 持有            不交易       第i-2天买入                         

dp[i-2][0]=0 
int maxProfit(vector<int> prices)
{
    int n=prices.size();
    int dp_i_0=0,dp_i_1=INT_MIN,dp_i_2=0;
    for(int i=0;i<n;i++)
    {
        auto temp=dp_i_0;
        dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
        dp_i_1=max(dp_i_1,dp_i_2-prices[i]);
        dp_i_2=temp;
    }
    return dp_i_0;
}

题四：k=inf 每次卖出需手续费
dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee)

int maxProfit(vector<int>& prices,int fee)
{
    int n=prices.size();
    int dp_i_0=0,dp_i_1=INT_MIN;
    for(int i=0;i<n;i++)
    {
        auto temp=dp_i_0;
        dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
        dp_i_1=max(dp_i_1,temp-prices[i]-fee);
    }
    return dp_i_0;
}

题五：k=2 
dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
                不交易          卖出
dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
                不交易          买入

int maxProfit(vector<int>& prices)
{
    int max_k=2;
    int dp[n][max_k][2];
    for(int i=0;i<n;i++)
    {
        for(int k=max_k;k>=1;k--)
        {
            if(i-1==-1)
            {
                dp[i][k][0]=0;
                dp[i][k][1]=INT_MIN;
                continue;
            }
            dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
            dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
        }
    }
    return dp[n-1][2][0];
}

题六：k任意, 但一次交易需两天，故当max_k>n/2 相当于k无限
int maxProfit(int max_k,vector<int>& prices)
{
    auto n=prices.size();
    if(max_k>n/2)
        return maxProfit_k_inf(prices);
    
}
```C++