/**
 * 미로의 거리
 * - 최소 몇 칸을 지나면 출발지에서 도착지에 다다를지 구하기
 * - 경로가 없는 경우 0 출력
 * 5<= n <= 100
 * 0 = 통로 , 1 = 벽, 2 = 출발, 3 = 도착
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> miro;
int tc, n;

int dx[] = {1, 0, -1 , 0};
int dy[] = {0, 1, 0 , -1};

int BFS(pair<int,int> start, pair<int,int> end);
int main(){
    cin >> tc >> n;
    pair<int,int> start, end;
    miro = vector<vector<int>>(n+1,vector<int>(n+1));
    
    for(int i=1; i < n+1; i++){
        string line;
        cin >> line;
        for(int j=1; j < n+1 ; j++){
            int k = line[j-1] - '0'; // char to int
            miro[i][j] = k;
            if(k == 2){
                start = {i,j};            
            }else if(k == 3){
                end = {i,j};
            }
        }
    }
    for(int i = 0; i < tc ; i++){
        cout << "#"<<i+1<<" " << BFS(start, end)<<"\n";

    }

    return 0;
}
int BFS(pair<int,int> start, pair<int,int> end){

    // queue, 필요한 자료구조 선언일
    priority_queue<pair<int,int>> q;
    vector<vector<int>> visited = vector<vector<int>>(n+1,vector<int>(n+1, -1));


    // 큐에 넣고, 방문처리
    q.push(start);
    visited[start.first][start.second] = 0;

    while(!q.empty()){
        pair<int,int> cur = q.top();
        q.pop();
        // 도착지 확인
           if(miro[cur.first][cur.second]==3){
                return visited[cur.first][cur.second]-1;
            }
        // 사방 체크
        for(int i = 0; i < 4; i++){
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];
            // 미로 범위 내이고, 벽이 아니고, 미방문 이라면
            if(nextX > 0 && nextY > 0 && nextX < n+1 && nextY <n+1
                && miro[nextX][nextY] != 1  && visited[nextX][nextY] == -1
            ){
                q.push({nextX,nextY});
                visited[nextX][nextY] = visited[cur.first][cur.second] +1;
            }
        }
    }
    return 0;

}
