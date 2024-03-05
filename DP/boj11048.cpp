#include <iostream>
#include <vector>
using namespace std;


// 이동하기

// 제한적인 방향에서의 미로찾기 이기때문에 DP로 푸는게 가능.(DP표를 채우는 것이 가능)
// 사방에서 올 수 있었다면 DFS 적용해서 풀이
vector<vector<int>> dp;
vector<vector<int>> miro;
int DP(int x, int y);
int main(){
    int n, m;
    cin >> n >> m;

    miro = vector<vector<int>>(n,vector<int>(m,0));
    dp = vector<vector<int>>(n,vector<int>(m,-1));
    
    for(int i =0; i < n ; i++){
        for(int j=0; j < m; j++){
            cin >> miro[i][j];
        }
    }
    cout << DP(n-1,m-1);
    return 0;
}

int DP(int x, int y){
    if(x<0 || y<0){
        return 0;
    }
    if(dp[x][y] < 0){
       dp[x][y] = miro[x][y] + max(max(DP(x-1, y), DP(x, y-1)), DP(x-1,y-1)); 
    }
    return dp[x][y];
}