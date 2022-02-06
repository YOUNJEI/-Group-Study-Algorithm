def solution(phone_book):
    diction = {}
    answer = True
    for i in phone_book:
        diction[i] = 0

    for j in phone_book:
        number = ""
        for k in j:
            number += k
            if number in diction and number != j:
                return False

    return answer