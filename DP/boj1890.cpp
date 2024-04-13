#include<iostream>
#include<vector>
using namespace std;
//https://www.acmicpc.net/problem/1890

int N;
vector<vector<int>> map;
vector<vector<long long>> dp;
int dx[] = {1, 0};
int dy[] = {0, 1};

int main(){
    cin >> N;
    map = vector<vector<int>>(N+1, vector<int>(N+1, 0));
    dp = vector<vector<long long>>(N+1, vector<long long>(N+1, 0));
        
    for(int i =1; i <=N; i ++){
        for(int j =1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i =1; i <=N; i ++){
        for(int j =1; j<=N; j++){
            if(map[i][j] == 0) break;
            if(dp[i][j] == 0) continue;
            for(int k=0; k<2; k++){
                int next_i = i + dx[k]*map[i][j];
                int next_j = j + dy[k]*map[i][j];
                if(next_i > 0 && next_j > 0 && next_i <= N && next_j <= N){
                    dp[next_i][next_j] += dp[i][j];
                }
            }
        }
    }

    cout << dp[N][N];

    return 0;
}

/*--------- 문어 해설 ---------
dp[i][j] : (1,1)에서 시작하여 i,j로 오는 경로 수
- 오른쪽, 아래쪽으로만 이동하는경우 순회하면서 처리해도됨

* dp[i][j]==0인 인 경우, map[i][j]==0인 경우 처리할 필요없음!
* 우측, 아래, 범위 내 조건을 충족할 경우, 점프 위치에 경로 수 누적

*/ 