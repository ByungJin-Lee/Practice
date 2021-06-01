#대입문을 차례대로 수행하라
s1 = 'ant'
s2 = 'bat'
s3 = 'cod'

#그리고 s1, s2, s3과 연산자 +, *를 이용하여 다음과 같이 계산되는 Python 수식을 작성하라
#(a) 'ant bat cod'
print(s1+ " " + s2+ " "+s3)
#(b) 'ant ant ant ant ant ant ant ant ant ant'
print((s1 + " ")*10)
#(c) 'ant bat bat cod cod cod'
print(s1 + " " + (s2+ " ")*2 + (s3 + " ")*3)
#(d) 'ant bat ant bat ant bat ant bat ant bat ant bat ant bat'
print((s1+" "+s2 + " ")*7)
#(e) 'batbatcod batbatcod batbatcod batbatcod batbatcod'
print((s2*2+s3+" ")*5)
