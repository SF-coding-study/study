def solution(citations):
    citations.sort(reverse=True)  # "h번 이상 인용된 논문 수"
            #  내림차순 정렬했을 때, n의 순서가 n번째 이상이면 된다.
    for idx, citation in enumerate(citations): #idx로 현재까지 확인한 논문의 수
        if idx >= citation:  # 논문 수가 인용 횟수보다 크거나 같아지는 지점
            return idx      # 더 이상 그만큼의 인용횟수를 가진 논문이 없는 지점
    return len(citations)  # 모든 논문이 모든 논문 수보다 많이 인용된 경우

# [10, 10, 10] 이나 [10, 11] 같이 모든 요소(모든 논문의 인용 횟수)가 리스트의 길이보다 큰 예라면, H- index는 3([10, 10, 10] ), 2([10, 11])가 되어야 한다.리스트의 길이가 H-index