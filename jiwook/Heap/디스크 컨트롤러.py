# 최적 스케줄링 증명:
# 동시에 처리할 수 있는 A작업, B작업이 존재하고
# A작업 : i(대기시간) + m(처리시간)
# B작업 : j(대기시간) + n(처리시간) 이고 m > n 이 항상 성립한다고 가정.

# A작업 먼저 처리할 경우:
# 총 소요시간 : i + m + j + n + m = i + j + n + 2m

# B작업 먼저 처리할 경우:
# 총 소요시간 : i + m + j + n + n = i + j + 2n + m

# m > n이 성립하므로 B작업을 먼저 처리하는 것이 총 소요시간이 더 적음
# 따라서, 동시에 실행할 수 있는 작업 중 처리시간이 적은 작업을 먼저 처리하는 것이 최적

import heapq

def solution(jobs):
    answer = 0          # 총 소요시간을 저장할 변수
    now = 0            # 현재 시점
    i = 0              # 처리 완료된 작업의 개수
    start = -1         # 이전 작업의 완료 시점
    heap = []          # 처리 대기 중인 작업을 저장할 최소 힙
    
    # 모든 작업을 처리할 때까지 반복
    while i < len(jobs):
        # 현재 시점(now)에서 처리 가능한 모든 작업을 확인
        for job in jobs:
            # job[0]: 작업이 요청된 시점
            # 이전 작업 완료 시점(start)과 현재 시점(now) 사이에 요청된 작업을 힙에 추가
            if start < job[0] <= now:
                # 힙에 [작업 소요시간, 작업 요청시점] 추가
                # 최소 힙이므로 소요시간이 작은 작업이 우선 처리됨
                heapq.heappush(heap, [job[1], job[0]])
        
        # 처리 대기 중인 작업이 있는 경우
        if heap:
            current = heapq.heappop(heap)    # 가장 소요시간이 작은 작업 선택
            start = now                      # 현재 시점을 이전 작업 완료 시점으로 저장
            now += current[0]                # 현재 시점에 작업 소요시간을 더함
            # 작업의 총 소요시간(대기시간 + 처리시간) 추가
            # now - current[1]: (작업 완료시점 - 작업 요청시점)
            answer += now - current[1]       
            i += 1                          # 완료된 작업 개수 증가
        else:
            # 처리 대기 중인 작업이 없는 경우 시간을 1ms 증가
            now += 1
            
    # 모든 작업의 평균 소요시간의 정수부분을 반환
    return answer // len(jobs)