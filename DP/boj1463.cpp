#include<iostream>
#include<vector>

using namespace std;

// 1로 만들기
int main() {
	int n;
	cin >> n;
	vector<int> dp = vector<int>(n + 1);

	// 초기값 : dp[0],dp[1] = 0;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i / 2]+1, dp[i]);
		
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3]+1, dp[i]);
	}

	cout << dp[n];

	return 0;
}
