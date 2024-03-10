/**
 * 미로1
 * 16x16 미로에서 출발-> 도착에 도달할 수 있으면 1, 없으면 0
 * 풀이[1] : BFS, visited테이블에 계산된 값을 처리할 필요는x, 단순 방문여부만 표시
 * 풀이[2] : DFS, 단순 경로가 있는지만 파악할 때, 간단히 구현 가능(재귀)
 * 
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(pair<int,int> cur);

int N = 16;
int dx[] = {1, 0, -1 , 0};
int dy[] = {0, 1, 0 , -1};
vector<vector<int>> miro = vector<vector<int>>(N+1,vector<int>(N+1,0));
vector<vector<int>> visited;
int main(){
    int cmd;
    cin >> cmd;
    // while(cmd){
        pair<int, int> start, end;
        for(int i = 0; i < N; i++ ){
            string line;
            cin >> line;
            for(int j = 0; j < N; j++){
                int k = line[j] - '0';
                miro[i+1][j+1] = k; 
                if(k == 2){
                start = {i+1,j+1};            
                }else if(k == 3){
                end = {i+1,j+1};
                }
            }
        }
        visited = vector<vector<int>>(N+1,vector<int>(N+1, 0));
        visited[start.first][start.second]=1;
        DFS(start);
        cout << "#" << cmd << " "<< visited[end.first][end.second] << "\n"; 
    // }
    return 0;
}
void DFS(pair<int,int> cur){
    // 사방 체크
    for(int i = 0; i < 4; i++){
        int nextX = cur.first + dx[i];
        int nextY = cur.second + dy[i];
        // 미로 범위 내이고, 벽이 아니고, 미방문 이라면
        if(nextX > 0 && nextY > 0 && nextX < N+1 && nextY <N+1
            && miro[nextX][nextY] != 1  && visited[nextX][nextY] == 0
        ){
            visited[nextX][nextY] = 1;
            DFS({nextX, nextY});
        }
    }
}
