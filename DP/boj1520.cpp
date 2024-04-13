#include<iostream>
#include<vector>

using namespace std;
int DP(int i, int j);

int n,m;
int dx[] = {1, -1 , 0 ,0};
int dy[] = {0,0, 1, -1}; 
vector<vector<int>> map;
vector<vector<int>> dp;
    
int main(){

    cin >> n >> m;

     map = vector<vector<int>>(n+1, vector<int>(m+1));
     dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));

    for(int i = 1; i<=n; i++){
        for(int j =1; j<=m; j++){
            cin >> map[i][j]; 
        }
        
    }
    dp[1][1] = 1;
    // dp[i][j] = dp[i+1][j] + dp[i-1][j] + dp[i][j+1] + dp[i][j-1];

    for(int i = 1; i<=n; i++){
        for(int j =1; j<=m; j++){
            // DP 함수 호출
            DP(i,j);
        }
    }

    cout << dp[n][m];

    return 0 ; 
}
int DP(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] =0;
    for(int k = 0; k < 4 ; k++){
        int bx = i+dx[k];   // 올수 있는 좌표
        int by = j+dy[k];
        if(bx > 0 && by >0 && bx <=n && by <=m){
            if(map[bx][by] > map[i][j]){
                dp[i][j] = dp[i][j] + DP(bx, by);
            }
        }
    }

    return dp[i][j] ;
}

/*------------ 해설 ------------
단순 순회로는 상하좌우 방향 중 아직 탐색하지 않은방향(하, 우 방향)에 대해 처리하지 못함
=> 깊이우선탐색(DFS)을 통해 4방향을 계산해줘야함 

* dp[i][j] : (1,1)좌표에서 (i,j)까지의 경로 갯수
=> 네방향으로 부터, 범위내 좌표에서,
    prev_i, prev_j > cur_i, cur_j 

* 범위 체크 팁 ! 범위밖 좌표들을 코드에 영향을 주지 않는값들로 감싸서 초기화
    => 때에 따라 0, -1, int_max ...
    => 이 문제의 경우 지도의 범위밖을 0 으로 초기화 한다면, 계산에 영향을 주지않고 처리가능

* dp[1][1] = 1
* ans : dfs(N,M)
* 단순 dfs로는 값이 큼(500*500) => 메모이제이션 필요(중복계산x)
    => 방문처리를 위해 -1로 초기화

dfs(ci, cj){
    if dp[ci][cj] != -1 
        return dp[ci][cj];
    // 누적을 위한 초기화
    dp[ci][cj] = 0;
    if(네방향으로 부터, 범위내 좌표에서,
        내리막길이면 (prev_i, prev_j > cur_i, cur_j))
        dp[ci][cj] += dfs[pi][pj];
}
*/ 
