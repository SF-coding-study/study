def solution(nums):
    answer = len(set(nums))  # 중복을 제거한 폰켓몬 종류의 개수
    if answer > len(nums) // 2:  # 만약 폰켓몬 종류 수가 선택할 수 있는 폰켓몬 수보다 많으면
        return len(nums) // 2  # N/2만큼의 폰켓몬을 선택할 수 있으므로 N/2를 반환
    return answer  # 그렇지 않으면, 폰켓몬 종류 수를 반환
