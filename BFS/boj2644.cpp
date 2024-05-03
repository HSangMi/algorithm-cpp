#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 촌수계산
int N; // 전체 사람 수
int p1, p2; // 계산할 두사람
int connect; // 관계 수
int dist;
int main(){
    cin >> N;
    cin >> p1 >> p2;
    cin >> connect;

    vector<vector<int>> tree = vector<vector<int>>(N+1, vector<int>());
    vector<int> visited = vector<int>(N+1,0);

    for(int i = 0; i <connect; i++){
        int m1, m2;
        cin >> m1 >> m2;
        tree[m1].push_back(m2);
        tree[m2].push_back(m1);
    }

    // 촌수계산 시작(BFS)
    queue<int> q;
    q.push(p1);
    visited[p1] = 1;
    while(!q.empty()){

        int cur = q.front();
        q.pop();
        if(cur == p2){
            cout << visited[cur]-1;   // dist저장이 이게 맞나 체크는해야함
            return 0;
        }

        for(int conn : tree[cur]){
            if(visited[conn] == 0){
                visited[conn] = visited[cur] +1;
                q.push(conn);
            }
        }


    }

    cout << -1;
    return 0;
}