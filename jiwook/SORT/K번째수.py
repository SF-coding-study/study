def solution(array, commands):
    return list(map(lambda x:sorted(array[x[0]-1:x[1]])[x[2]-1], commands))
#O(m * n log n) -> commands의 개수(m)만큼 정렬 작업