def solution(clothes):
    answer = 1 # 옷의 조합 수를 계산
    
    closet = {} 
    for Kind, Type in clothes:
        if Type not in closet.keys():
            closet[Type] = [Kind]
        else: # 만약 Type이 이미 존재하면, 해당 리스트에 새로운 의상 이름을 추가합니다.
            closet[Type] += [Kind]
    
    for key, value in closet.items(): 
        answer *= (len(value)+1) # 옷을 입지 않는 경우도 있기 때문에, +1
    
    return answer -1 # "아무것도 입지 않는 경우 제외"