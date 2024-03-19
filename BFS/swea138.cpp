#include <iostream>
#include <queue>
#include <vector>
#include <map>

/**
 * Contact
 * 가장 나중에 연락 받게 되는 사람 중 번호가 가장 큰사람
*/
using namespace std;

int main(){

    int edge, startNode;
    cin >> edge >> startNode;
    vector<vector<int>> graph = vector<vector<int>>(101);
    vector<int> visited = vector<int>(101,-1);

    queue<int> q;
    for(int i=1; i<edge+1; i= i+2){
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        // graph.push_back({s, e});
    }

    q.push(startNode);
    // visited 
    visited[startNode] = 0;
    int lastNode;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int e : graph[cur]){
            if(visited[e]==-1){
                visited[e] = visited[cur]+1;
                q.push(e);
            }
        }
    }

    int maxDist =-1;
    int maxNode = startNode;
    // 정답찾는 로직은 BFS 로직 안쪽으로 넣는게 더 좋을 듯 
    for(int i=1; i < visited.size()+1 ; i++){
    //  if(visited[maxNode] < visited[i]) 
    //      || (visited[maxNode] == visited[i]) && maxNode < i))
        if(max(maxDist, visited[i]) == visited[i]){
            if(maxDist == visited[i])
                maxNode = max(maxNode,i);
            maxDist = visited[i];        
        }
    }
    cout << maxNode;
    return 0;
}