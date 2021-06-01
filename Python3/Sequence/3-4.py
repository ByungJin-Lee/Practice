#id 입력, 확인 맞으면 메세지 출력, 종료시 Done!
inputId = input("Login: ")
list_ids = ['joe', 'sue', 'hani', 'sophie']
if inputId in list_ids:
    print("You are in!")
else:
    print("User unknown.")
print("Done!")
