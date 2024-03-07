#include <iostream>
#include <vector>
using namespace std;

/**
 * 동전 2
 * n가지 종류의 동전. 합이 k가 되는 최소 동전 갯수
*/
void sol2294();
int solDP(int k);
int main() {
  sol2294();
  return 0;
}
// 동전 종류 n, 목표금액 k

// int dp[100001] = {987654321,};
vector<int> coin;
void sol2294(){
  int n,k;
  vector<int> dp(100001,987654321);
  cin >> n >> k;
  coin = vector<int>(n+1,0);
  for(int i=1 ; i<n+1 ; i++){
    cin >> coin[i];
    dp[coin[i]] =1;
  }

  dp[0] = 1;
  for(int i = 1; i<n+1; i++){
    for(int j = coin[i]; j<=k; j++){
      dp[j] = min(dp[j],dp[j-coin[i]]+1);
    }
  }

  if(dp[k] == 987654321) cout << -1;
  else 
    cout << dp[k];
  
}