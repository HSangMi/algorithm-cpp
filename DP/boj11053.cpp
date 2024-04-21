#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 가장 긴 증가하는 부분수열 (LIS, Longest Increasing Subsequence)
6
10 20 10 30 20 50

dp[i] : i 번째 숫자 추가 시 최대 길이
    => i번째 숫자보다 작은 값을 대상으로, 최대 값을 가진 수열에서 + 1
    => dp[0]~dp[i-1] 중 최댓값 + 1 (단 arr[i] 보다 작은 경우)

*/
int main(){
    int n ;
    int answer = 1;
    cin >> n;

    vector<int> arr = vector<int>(n+1,0);
    vector<int> dp = vector<int>(n+1,0);
    for(int i = 1; i < n+1; i ++){
        cin >> arr[i];
    }

    dp[1] = 1;
    for(int i = 2; i < n+1 ; i++){
        int mx = 0;
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]){
                mx = max(dp[j], mx);
            }
            dp[i] = mx+1;
        }
        if(answer < dp[i])
            answer = dp[i];
    }

    cout << answer;
    return 0;
}