from collections import deque
#최단거리 유형
def solution(maps):
    n = len(maps)        # 행 개수
    m = len(maps[0])     # 열 개수
    
    # 이동할 수 있는 4방향 정의 (상, 하, 좌, 우)
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    # 방문 거리를 저장할 2차원 리스트
    visited = [[-1] * m for _ in range(n)]
    
    def bfs(start_x, start_y):
        q = deque()
        # 시작점 추가
        q.append((start_x, start_y))
        # 시작점 방문 표시 (거리 1)
        visited[start_x][start_y] = 1
        
        while q:
            x, y = q.popleft()
            
            # 현재 위치에서 4방향으로 이동해보기
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                # 맵을 벗어나지 않고
                if 0 <= nx < n and 0 <= ny < m:
                    # 벽이 아니고            아직 방문하지 않은 곳이라면
                    if maps[nx][ny] == 1 and visited[nx][ny] == -1:
                        # 큐에 추가하고
                        q.append((nx, ny))
                        # 이전 위치까지의 거리 + 1
                        visited[nx][ny] = visited[x][y] + 1
    
    # (0,0)에서 BFS 시작
    bfs(0, 0)
    
    # 상대 팀 진영(n-1, m-1)까지의 거리 반환
    return visited[n-1][m-1]