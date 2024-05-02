#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int bfs(int start , int end);

int N;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<string> miro;
vector<vector<int>> visited;
int main(){
    cin >> N;

    miro = vector<string>(N);
    visited = vector<vector<int>>(N,vector<int>(N,0));
    for(int i = 0; i < N; i++){
        cin >> miro[i];
    }

    vector<int> ans ;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){            
            if(miro[i][j]== '0' || visited[i][j]==1) continue;
            ans.push_back(bfs(i,j));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i = 0; i< ans.size(); i ++){
        cout << ans[i] << "\n";
    }

    return 0;
}
int bfs(int start , int end){
    queue<pair<int,int>> q;
    q.push({start,end}); // start;
    int count = 1;
    visited[start][end] = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(miro[nx][ny]=='1' && visited[nx][ny]==0){
                q.push({nx, ny});
                count ++;
                visited[nx][ny] = 1;
            }
        }
        
    }
    return count;
}