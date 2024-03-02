#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

// 쉬운 계단 수
/* 규칙성 찾기
값이 m으로 끝나는 n자리 숫자의 경우의  수는, 이전 자리수(n-1)에서 m-1값으로 끝나는 경우의 수 + m+1로 끝나는 경우의 수
dp[i][j] : 길이가 i인 계단 수 중 j로 끝나는 경우의 수
dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]; 
*/
int main(){
    int n;
    cin >> n;

    vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(10,1));
    dp[1][0] = 0; //n=1 : 0 ,1, 1, 1, ... 1
    for(int i = 2; i < n+1; i ++){
        for(int j=0; j<10; j++){
            dp[i][j] = ((j-1>=0?dp[i-1][j-1]:0) + (j+1<=9?dp[i-1][j+1]:0))%1000000000;
            // cout << "dp[" <<i<<"]["<<j<<"] = " << (j-1>=0?dp[i-1][j-1]:0) << " + " <<(j+1<=9?dp[i-1][j+1]:0) 
            // << " = " << dp[i][j]<< "\n" ;
        }
    }

    int result = accumulate(dp[n].begin(), dp[n].end(),0,[](int acc, int num){ return (acc+num)%1000000000;});
    cout << result;
    return 0;
}