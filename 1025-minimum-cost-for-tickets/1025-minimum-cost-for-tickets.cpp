class Solution {
public:
int dp[366];
int solve(vector<int>& days, vector<int>& costs,int n,int i){
    if(i>=n) return 0;

    if(dp[i]!=-1){
        return dp[i];
    }

    // for 1 pass 
    int cost_1=costs[0]+solve(days,costs,n,i+1);

    //for 2 pass

    int j=i;
    int max_day=days[i]+7;
    while(j<n && days[j]<max_day){
        j++;
    }
    int cost_2=costs[1]+solve(days,costs,n,j);
    
     j=i;
    max_day=days[i]+30;
    while(j<n && days[j]<max_day){
        j++;
    }
    int cost_3=costs[2]+solve(days,costs,n,j);
    return dp[i]=min({cost_1,cost_2,cost_3});

}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        int n=days.size();

        return solve(days,costs,n,0);
        
    }
};