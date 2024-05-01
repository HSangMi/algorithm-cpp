#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main(){

    int N, M;
    int dx[] = {1,-1, 0,0};
    int dy[] = {0,0, 1,-1};

    cin >> N >> M;

    vector<vector<int>> miro = vector<vector<int>>(N, vector<int>(M));
    vector<vector<int>> visited = vector<vector<int>>(N, vector<int>(M,0));
    int distance = 0;
    // 입력
    for(int i=0; i < N; i++){
        string miros;
        cin >> miros;
        for(int j=0; j < M; j++){
            miro[i][j] =miros[j]-'0'; // char -> int
        }
    }

    // BFS시작
    // bfs(si, sj, ei, ej)
    queue<pair<int,int>> q ;
    q.push({0,0});
    visited[0][0] = 1;
    distance ++;

    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        // 종료 조건
        if(cur.first == N-1 && cur.second == M-1){
            break;
        }
            
        for(int k=0; k< 4; k++){
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            // 좌표범위 , 방문체크, 벽 확인
            if((nx < 0 || nx>=N || ny<0 || ny>=M) || visited[nx][ny]>0 ||miro[nx][ny]==0)
                continue; 

            q.push({nx, ny});
            visited[nx][ny] = visited[cur.first][cur.second] +1; 
        } 
    }

    cout << visited[N-1][M-1];

    return 0;
}