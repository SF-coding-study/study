import heapq
def solution(scoville, K):

    count = 0
    
    # heapq.heapify(): 리스트를 최소 힙으로 변환
    # 최소 힙: 부모 노드가 자식 노드보다 작은 값을 가지는 이진 트리
    heapq.heapify(scoville)
    
    # while 루프 조건:
    # 1. len(scoville) > 1: 최소 2개의 음식이 있어야 섞을 수 있음
    # 2. scoville[0] < K: 가장 작은 스코빌 지수가 K보다 작을 때만 계속 섞음
    while len(scoville) > 1 and scoville[0] < K:
       
        count += 1
        
        # heappop(): 힙에서 가장 작은 값을 제거하고 반환
        # first: 가장 맵지 않은 음식의 스코빌 지수
        first = heapq.heappop(scoville)
        # second: 두 번째로 맵지 않은 음식의 스코빌 지수
        second = heapq.heappop(scoville)
        
        # 문제에서 주어진 공식대로 두 음식을 섞어서 새로운 스코빌 지수 계산
        # heappush(): 계산된 새로운 스코빌 지수를 힙에 추가
        heapq.heappush(scoville, first + (second * 2))
    
    # 모든 반복이 끝난 후:
    # - 힙의 root(가장 작은 값)가 K보다 작으면 목표를 달성할 수 없으므로 -1 반환
    # - 그렇지 않으면 섞은 횟수(count) 반환
    return -1 if scoville[0] < K else count