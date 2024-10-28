def solution(numbers):
    
    numbers = [str(i) for i in numbers]
    numbers.sort(key = lambda x: x*3, reverse = True)
    # x*3을 하는 이유는 numbers의 원소가 1000 이하이므로 최대 3자리수까지 비교하기 위함
    # "3" * 3 = "333"
    # "34" * 3 = "343434"
    return str(int(''.join(numbers)))
    # 4. 결과가 "000"과 같은 경우 "0"으로 return
    # O(nlogn)  Timsort= Merge sort와 Insertion sort의 하이브리드 알고리즘