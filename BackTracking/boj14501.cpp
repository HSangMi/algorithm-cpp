#include<iostream>
#include<vector>
using namespace std;

/*
퇴사
1 < N <= 15 이기 떄문에, 완전탐색 가능(2^15)
    (참고 : 이진트리 형태의 경우 N <=50 이 마지노선)
* 풀이1 완전탐색(백트랙킹)
- n(종료조건) : 날짜(index) : n >=N 
- 가능한 모든경우를 트리로 표현 가능
    - 상담 받을 경우, 비용더하고 상담일 만큼 건너 뛴 날짜에서 다시 분기
    - 상담 안받을 경우, 다음 날 상담을 받을 지 분기
=> 재귀로 생긴(백트랙킹) 한 부분을 dfs로 짜줌
    dfs(n, sm)
    1. 종료조건 처리
        if (n>=N) 
            ans <- max(ans, sum);
            return;
    2. 하부함수 호출 
        // 상담 하는경우(상담끝나는 날로이동, 수익은 더하고)
        if (n + T[n] <= N)
            dfs(n+T[n], sum+p[n]); 

        // 상담 안하는 경우(다음날로 이동, 수익은 그대로)
        dfs(n+1, sum)
*/
int N;
vector<int> Time;
vector<int> Pay;
int ans = 0;
void dfs(int n, int sum);
int main(){
    cin >> N;
    Time = vector<int>(N, 0);
    Pay = vector<int>(N, 0);
    for(int i = 0; i < N; i++){
        cin >> Time[i] >> Pay[i];
    }

    // 백트랙킹은 제일 위에 함수를 호출하면 계산 되도록 함
    dfs(0,0); // 

    cout << ans;
    return 0;
}

void dfs(int n, int sum){
    // 1. 종료조건
    if(n >= N){
        ans = max(ans, sum);
        return;
    }

    // 2. 하부함수 호출 : 트리의 화살표 개수만큼 호출(선택지 만큼)
    // -> 상담 하거나/ 안하거나

    //2-1 상담 하는 경우(퇴사일 전 완료 가능할 경우)
    if(n+Time[n]<=N)
        dfs(n+Time[n], sum+Pay[n]);
    //2-2 상담 안하는 경우(항상 가능)
    dfs(n+1, sum);

}