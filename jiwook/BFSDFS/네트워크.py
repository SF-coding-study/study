# "뭉탱이"의 개수 **
def solution(n, computers):
    def dfs(v): # v = 현재 탐색하고 있는 컴퓨터 번호
        # 현재 노드 방문 
        visited[v] = True
        
        # 현재 노드와 연결된 모든 노드를 확인
        for next_node in range(n):
            # 연결되어 있고(computers[node][next_node] == 1) 
            # 아직 방문하지 않은 노드(not visited[next_node])라면
            if computers[v][next_node] == 1 and not visited[next_node]:
                dfs(next_node)
    
    # 방문 여부를 체크할 리스트
    visited = [False] * n
    # 네트워크의 개수
    network_cnt = 0
    
    # 모든 노드를 순회하면서
    for v in range(n):
        # 아직 방문하지 않은 노드라면
        if not visited[v]:
            # 새로운 네트워크 발견
            network_cnt += 1
            # DFS로 연결된 모든 노드를 방문
            dfs(v)
    
    return network_cnt