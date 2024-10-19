
def solution(progresses, speeds):
    days = []
    time=[]
    cnt=0
    for i in range(len(progresses)):
        days.append(-(-(100-progresses[i])//speeds[i]))
    # print(days)  ##  7  3  9  (70 //30 ->2.xx -> 올림을 -로 바꾸고 나눔)
    max_day=days[0]
    for day in days:
        if day > max_day:  # 새로운 최대 일수 발견
            time.append(cnt)  # 이전까지 누적된 카운트 저장
            cnt=1  # 카운트 리셋
            max_day=day  # 최대 일수 업데이트
        else:
            cnt+=1  # 현재 그룹에 포함되는 기능 카운트 증가
    time.append(cnt)
    

    return time