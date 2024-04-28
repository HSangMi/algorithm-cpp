#include<iostream>
#include<vector>
using namespace std;
/*
퇴사 - DP로 풀어보기(N 값이 클 경우)

dp[i] : i번째 상담 결정 시 최대 수익(뒤부터 접근)
* 뒤에서 접근하는 경우 코드가 더 간단해 지는 경우!

// max(가능시 상담o, 상담x)
max(dp[n+T[n]] +P[n], dp[n+1])
*/
int N;
vector<int> Time;
vector<int> Pay;
vector<int> dp;
int main(){
    cin >> N;
    Time = vector<int>(N, 0);
    Pay = vector<int>(N, 0);
    dp = vector<int>(N+1, 0);   // n+1연산 할수있게 한개 더 추가
    for(int i = 0; i < N; i++){
        cin >> Time[i] >> Pay[i];
    }

    for(int n = N-1; n >= 0; n--){
        // 상담이 가능한 경우
        if(n+Time[n] <=N){
            dp[n] = max(dp[n+Time[n]]+Pay[n],dp[n+1]);
        }
        // 상담이 불가능한 경우
        else{
            dp[n] = dp[n+1];
        }
    }
    cout << dp[0];
    return 0;
}