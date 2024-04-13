#include<iostream>
#include<vector>
using namespace std;

int n;
int main(){

    cin >> n;
    // pair(0으로끝나는 경우 수, 1로 끝나는 경우 수)
    vector<pair<long long,long long>> dp = vector<pair<long long,long long>>(n+1);
     
     dp[1] = {0,1};
     for(int i =2; i <= n; i++){
        // dp[i-1].first * 2 + dp[i-1].second;
        dp[i] = {dp[i-1].first + dp[i-1].second, dp[i-1].first};
     }

     cout << dp[n].first + dp[n].second;

    return 0;
}