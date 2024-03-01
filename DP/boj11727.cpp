#include<iostream>
#include<vector>
using namespace std;

// 2*n 타일링
int main(){

    /**
     * 사용할 수 있는 블록 : 2x1, 1x2, 2x2
     * 길이를 연장 할 수 있는 최소단위
     *   +1(1가지 방법- 2x1) , +2(2가지 방법 : 1x2두개, 2x2하나)
     * 
     * dp[i] : 2xi 직사각형을 채울 수 있는 방법의 수
     * dp[i] = dp[i-1]*(+1증가하는 방법) + dp[i-2]*(+2증가하는 방법)
     * dp[i] = dp[i-1]*1 + dp[i-2]*2
     * */ 
    int n ; 
    cin >> n;
    vector<int> dp = vector<int>(n+1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    // (A+B)%C = ( (A%C)+(B%C) ) % C
    for(int i=3; i<n+1; i++){
        dp[i] = (dp[i-1]*1 + dp[i-2]*2)%10007;
    }
    cout << dp[n]%10007;
    return 0;
}