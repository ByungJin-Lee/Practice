#학생의 과제 점수 리스트가 다음과 같이 주어졌을 때,
grades = [9,7,7,10,3,9,6,6,2]
#아래 코드를 작성하라
#(a) 7점을 맞은 과제 수를 세는 수식
print(grades.count(7))
#(b) 마지막 과제 점수를 4점으로 바꾸는 문장
grades[len(grades)-1] = 4
#(c) 최대 점수를 계산하는 수식
print(max(grades))
#(d) 리스트 grades를 정렬하는 문장
grades.sort()
print(grades)
#(e) 평균 점수를 계산하는 수식 
print(sum(grades)/len(grades))
