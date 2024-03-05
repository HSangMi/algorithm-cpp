### BFS ###

* 대표 문제 유형
    * 최소거리
    * 미로찾기
    * 단계적으로 뻗어나가기


* BFS 형태
    `bfs(start, end)`
    1. queue
    2. 필요한 자료구조 ( vistied[] , flag .. ) 초기화
        => q=[], visited=[]; 
    3. queue에 초기데이터 입력, visited[] 표시, + 정답처리 코드 
        => q.push(start), visited[start] =1
    ```
    // example
    while q : // queue에 데이터가 있는동안
        cur = q.pop(0) // 데이터 1개 꺼냄
        // 정답확인은 이 위치 추천(꺼낸 다음)

        // 4방향, 8방향, 연결된 노드, 등 조건에 맞으면 Q에 삽입!
        for(n in arr){
            if(조건){
                // queue에 추가
                q.push(n);
                // 방문표시
                visited[n]=1;
                // or
                // 거리누적
                visited[n] = visited[cur]+1;
            }
        }

    ```

