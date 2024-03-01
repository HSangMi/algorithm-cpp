#include <iostream>
#include <vector>

using namespace std;

// 피보나치
int main()
{
	int n;
	cin >> n;
	vector<int> dp = vector<int>(n + 1);
	// dp[i] : i번째의 피보나치 수
	// 초기값 dp[0]=0, dp[1] = 1;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i-2];
	}

	cout << dp[n];
	return 0;
    }