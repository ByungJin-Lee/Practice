#모음이 없는 경우 True

def noVowel(s):
    for aSpell in s:
        if aSpell in "aeiouAEIOU":
            return False
    return True

print(noVowel(input("Enter String: ")))

