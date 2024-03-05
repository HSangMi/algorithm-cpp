#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 노드의 거리 (BFS)
// 출발 노드에서 최소 몇개의 간선을 지나면 도착 노드에 갈수 있는지 
int cnt, node, edge;
vector<vector<int>> graph;
int BFS(int start, int end);
int main(){

    cin >> cnt >> node >> edge;
    graph = vector<vector<int>>(node+1);

    for(int i=0; i< edge; i++){
        int s, e;
        cin >> s >> e;
        // [{4, 3},{3,5},{},{}{6}]
        graph[s].push_back(e);
        graph[e].push_back(s);

    }

    for(int i = 0; i < cnt ; i++){
        int start, end;
        cin >> start >> end;
        cout << "#"<<i+1<<" " << BFS(start, end)<<"\n";

    }

    return 0;
}

int BFS(int start, int end){
 // 1. queue와 필요한 자료구조(방문체크 테이블, 플래그 등) 초기화
        priority_queue<int> q;
        int visited[node+1]={0};

        // 2. queue에 초기데이터(들) 세팅, 방문표시, +정답 관련 처리
        q.push(start);
        visited[start] = 1;

        // 3. queue에 데이터가 있는동안 반복
        while(!q.empty()){
            int cur = q.top();
            q.pop();

            // 정답확인
            if(cur == end)
                return visited[cur]-1;
            
            // 4. 조건에 해당하는 노드 가져와서 queue에 푸시 and 방문처리 
            // 조건 예시 : 연결노드, 4방향 ,8 방향 등
            vector<int> nodes = graph[cur];
            // 연결된 노드를 가져와서
            for(int n : nodes){
                // 미방문 노드 
                if(visited[n] == 0){
                    q.push(n);
                    visited[n] = visited[cur] + 1;
                }
            }
        }
        // 목적지에 방문하지 못한경우!!
        return -1;
}