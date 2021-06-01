#단어를 입력받아서 각 단어의 길이가 4인 단어만 화면에 출력
list_words = eval(input("Enter word list: "))

for aWord in list_words:
    if(len(aWord) == 4):
        print(aWord)
