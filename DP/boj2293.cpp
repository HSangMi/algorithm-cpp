#include <iostream>
#include <vector>
using namespace std;

// 동전1
int dp[100001];
vector<int> coin;
int main() {
  // 동전 종류 n, 목표금액 k
  int n, k;
  cin >> n >> k;

  coin = vector<int>(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> coin[i];
  }
  // 아무것도 내지 않는 것도 한가지 방법
  dp[0] = 1;

  // 동전 종류 갯수만큼 반복
  for (int i = 1; i < n + 1; i++) {
    // 사용하는 동전보다 큰 금액(j=coin[i])부터 ~ 목표금액까지 갱신
    for (int j = coin[i]; j <= k; j++) {
      // j 금액을 만들기 위한 경우의 수 
      // coin[i]를 쓰지않고 만든 경우의 수 (dp[j])
      // + coin[i]를 쓰고 만드는 경우의 수(dp[j- coin[i]])로 갱신!
      dp[j] = dp[j] + dp[j - coin[i]];
    }
  }

  cout << dp[k];

  return 0;
}