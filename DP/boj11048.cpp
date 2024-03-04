#include <iostream>
#include <vector>
using namespace std;

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