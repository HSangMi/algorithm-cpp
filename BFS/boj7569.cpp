#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
토마토 : 전부 익는데 걸리는 날짜
=> 익은 토마토와 가장 먼거리를 저장하고있는 애!

* 3차원 배열 팁 ! h -> n -> m 순서로 for문
* 가장 먼 요소는 bfs에서 가장 마지막에 pop 됨.
*/

struct Position{
    int x;
    int y;
    int z;
};

int N,M,H;
vector<vector<vector<int>>> tomato;
vector<vector<vector<int>>> visited;
queue<Position> q ;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void print();

// void bfs(int i , int j, int k);
int main(){

    cin >> M >> N >> H;

    tomato = vector<vector<vector<int>>>(H,vector<vector<int>>(N, vector<int>(M,0)));
    visited = vector<vector<vector<int>>>(H,vector<vector<int>>(N, vector<int>(M,-1)));
    
    for(int i = 0; i < H ; i++){
        for(int j = 0; j < N ; j++){
            for(int k = 0; k < M; k++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    q.push({i,j,k});
                    visited[i][j][k] = 0;
                } 
            }
        }
    }
    
    Position cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        // 6방향
        for(int i=0; i < 6; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            // 범위 체크
            if(nx < 0 || ny <0 || nz < 0 || nx >= H || ny >=N || nz >= M){
                continue;
            }
            // 안익은 토마토였고,, 방문한 적이 없거나, 이전 방문기록보다 먼저 도달한경우?
            if(tomato[nx][ny][nz]== 0 && (visited[nx][ny][nz] == -1)){
                visited[nx][ny][nz] = visited[cur.x][cur.y][cur.z]+1;
                q.push({nx, ny, nz});
            } 

        }
    }

    for(int i = 0; i < H ; i++){
        for(int j = 0; j < N ; j++){
            for(int k = 0; k < M; k++){
                if(tomato[i][j][k]==0 && visited[i][j][k]==-1){
                    cout << -1;
                    print();
                    return 0;
                }

            }
        }
    }
    cout << visited[cur.x][cur.y][cur.z];

    return 0;
}
