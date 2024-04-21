#include<iostream>
#include<vector>

using namespace std;
/*
연속합
dp[i] : i번쨰 위치에서 연속합의 최댓값!
*/

int main(){
    int n ;
    int maxV = -1001;
    cin >> n;
    vector<int> arr = vector<int>(n,0);
    vector<int> dp = vector<int>(n,0);
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
        dp[i] = arr[i];
        if(i > 0 && dp[i-1] > 0){
            dp[i] = dp[i-1] + arr[i];
        }
        maxV = max(dp[i], maxV);
    }
    cout << maxV;


    return 0;
}