def solution(numbers, target):
    # +, - 부호에 따른 각 숫자에서 2가지 경우의 수
    def dfs(idx, current_sum):
            # 모든 숫자를 다 사용했을 때
            if idx == len(numbers):
                # 현재 합계가 타겟과 같다면 1, 아니면 0
                return 1 if current_sum == target else 0

            # 현재 숫자를 더하는 경우의 수 + 현재 숫자를 빼는 경우의 수
            plus = dfs(idx + 1, current_sum + numbers[idx])
            minus = dfs(idx + 1, current_sum - numbers[idx])

            return plus + minus
        # idx 0부터 시작, 초기 합계는 0
    return dfs(0, 0)