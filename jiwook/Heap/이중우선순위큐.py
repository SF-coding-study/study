# 큐에서 최댓값과 최솟값을 계산하여 삭제해야 하기 때문에 우선순위 큐를 사용 (heapq 모듈)
# 파이썬의 heapq는 최소 힙 → D -1에는 heappop()을 사용
# 리스트를 heapify하고 원소를 삽입하면 리스트가 정렬
# 그러면, 마지막 원소는 최댓값이므로 최댓값을 계산해줄 필요 없이 마지막 원소를 pop → D 1에는 리스트 기본 함수 pop()을 사용
from heapq import heapify, heappush, heappop

def solution(operations):
    answer = []
    hq = []
    
    for operation in operations:
        alphabet, number = operation.split()
        number = int(number)

        if alphabet == 'I':
            heappush(hq, number)    
        else: # alphabet == 'D'
            if hq: # 빈 큐에서 데이터를 삭제하라는 연산이 주어졌을 시 무시
                if number == -1:
                    heappop(hq) # 최솟값을 삭제
                else:
                    hq.sort()
                    hq.pop() # 최댓값을 삭제
                    
    # 모든 연산을 처리한 후
    hq.sort()
    if hq: # 큐가 비어있지 않음
        answer = [hq[-1], hq[0]]
    else: # 큐가 비어있음
        answer = [0, 0]
        
    return answer