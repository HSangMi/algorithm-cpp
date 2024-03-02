#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
void sol_1();
void sol_2();
void sol_3();

/**
 * 오르막 수 개수 구하기 
 * 2차원 => 1차원으로 처리할 수도있다
 * 규칙성을 찾을 때, 접근 방식에 따라 코드가 달라질 수있닽
 * 
*/
int main(){

    sol_3();
    return 0;
}

/*
방법 1 : 뒤쪽에 하나씩 붙여서 규칙성 찾기
- dp[] 2차원으로 설계/반복처리

- dp[i][j] : i자릿수 중 j로 끝나는 오르막 수의 갯수

*/
void sol_1(){
    int n;
    cin >> n;
    vector<vector<int>> dp 
    = vector<vector<int>>(n+1,vector<int>(10,1));

    for(int i = 2; i < n+1; i++){
        for(int j =0; j< 10; j++){
            dp[i][j] = accumulate(dp[i-1].begin()+j,dp[i-1].end(),0,[](int acc, int num){ return (acc+num)%10007;}); 
        }
    }
    int result = accumulate(dp[n].begin(),dp[n].end(),0,[](int acc, int num){ return (acc+num)%10007;}); 

    cout << result;

}
/*
방법 1-2. 1차원 dp 테이블로 바꿔보기
dp[i] : 각 숫자에 대해(0~9) N-1 번 처리 한 경우의 수 저장
*/
void sol_2(){
int n;
    cin >> n;
    vector<int> dp 
    = vector<int>(10,1);

    for(int i = 2; i < n+1; i++){ // N-1번 처리
        for(int j =0; j< 10; j++){
            dp[j] = accumulate(dp.begin()+j,dp.end(),0,[](int acc, int num){ return (acc+num)%10007;}); 
        }
    }
    int result = accumulate(dp.begin(),dp.end(),0,[](int acc, int num){ return (acc+num)%10007;}); 

    cout << result;
}

/*
방법2. 앞쪽에 한자리씩 붙이기
=> 그 전 숫자까지 까지의 합(dp[j-1]에 누적되고 있음) + 자기 자신(j)일때 방법 합
dp[j] = dp[j] + dp[j-1]
*/
void sol_3() {
    int n;
    cin >> n;
    vector<int> dp(10, 1); // 1차원 dp 테이블
    // i 자릿수를 가지는, j를 마지막 숫자로 가지는 오르막수
    for (int i = 2; i <= n; i++) { // 자릿수N -1 번 처리
        for (int j = 1; j < 10; j++) {
            dp[j] = (dp[j] + dp[j - 1]) % 10007;
        }
    }

    int result = accumulate(dp.begin(), dp.end(), 0, [](int acc, int num) {
        return (acc + num) % 10007;
    });

    cout << result;
}

