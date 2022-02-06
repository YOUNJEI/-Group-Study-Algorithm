# https://programmers.co.kr/learn/courses/30/lessons/42577

def solution(phone_book):
    answer = True

    # 일단 정렬
    phone_book.sort()

    for i in range(len(phone_book)-1):
        if len(phone_book[i]) < len(phone_book[i+1]):
            if phone_book[i + 1][:len(phone_book[i])] == phone_book[i]:
                answer = False
                break
    return answer


phone_book1 = ["119", "97674223", "1195524421"]
phone_book2 = ["123", "456", "789"]
phone_book3 = ["12", "123", "1235", "567", "88"]

print(solution(phone_book1))
print(solution(phone_book2))
print(solution(phone_book3))