// 백준 17298 오큰수
// https://www.acmicpc.net/problem/17298

/*
크기가 N인 수열 A = A1, A2, ..., AN이 있다.
수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
그러한 수가 없는 경우에 오큰수는 -1이다.
예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1 이다.
A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1 이다.
*/

#include <iostream>
#include <vector>

using namespace std;

#define _DATA int
#define MAX_SIZE 1000001

// Stack 클래스 구현 (배열 기반)
class Stack {
private:
    _DATA _d[MAX_SIZE];
    int cur;

public:
    // Stack의 생성자 (cur 0으로 초기화)
    Stack() { this->cur = 0; }

    // PUSH 구현
    void push(_DATA n) {
        if (cur < MAX_SIZE - 1)
            this->_d[this->cur++] = n;
    }

    // POP 구현
    _DATA pop(void) {
        if (empty())
            return -1;
        _DATA _temp;
        _temp = this->_d[this->cur - 1];
        this->cur--;
        return _temp;
    }

    // SIZE 구현
    int size(void) {
        return this->cur;
    }

    // EMPTY 구현
    bool empty(void) {
        if (this->cur == 0)
            return true;
        else
            return false;
    }

    // TOP 구현
    _DATA top(void) {
        if (empty())
            return -1;
        else
            return this->_d[this->cur - 1];
    }
};

int main(void) {
    int _loopn;
    int _input;
    vector<int> _vi;            // 입력을 담을 벡터
    vector<int> _answer;        // 정답을 담을 벡터
    Stack _s;
    _vi.clear();
    _answer.clear();

    cin >> _loopn;

    for (int i = 0; i < _loopn; i++) {
        cin >> _input;

        if (_vi.size() == 0)
            // 처음 들어오는 입력은 무조건 _vi에 저장 후 반복문 종료
            _vi.push_back(_input);
        else if (_vi[i-1] < _input) {
            // 입력으로 들어온 숫자가 바로 이전 숫자보다 크다면, 오큰수 이므로 정답에 입력으로 들어온 숫자 추가
            _answer.push_back(_input);
            if (!(_s.empty())) {  // if stack is not empty
              // 스택에 저장된 대기열이 있다면, 입력으로 들어온 수와 비교하여
              // 입력으로 들어온 수보다 작다면 오큰수로 정답 지정.
                while (!(_s.empty())) {
                  // 스택이 empty 될때까지 대기열 검사
                    if (_vi[_s.top()-1] >= _input)
                      // 저장된 대기열 번호가 입력보다 크다면 오큰수가 아니므로. 반복문 탈출 
                        break;
                    _answer[_s.pop()-1] = _input;
                }
            }
          // _vi에 입력 추가
            _vi.push_back(_input);
        }
        else if (_vi[i-1] >= _input) {
            // 입력으로 들어온 숫자가 바로 이전 숫자보다 작다면, 스택에 index 저장하고
            // _answer에 임시로 -2 저장 후 다음 입력을 받을 준비
            // _answer에 저장된 -2는 추후 다음 입력과 비교하여 오큰수인지 판단 혹은 오큰수가 없을경우 마지막에 -1로 변경
            _s.push(i);
            _vi.push_back(_input);
            _answer.push_back(-2);
        }

    }
    
    // 마지막 숫자는 항상 오큰수가 존재하지 않기 때문에, -1
    _answer.push_back(-1);

    for (int i = 0; i < _answer.size(); i++) {
        if (_answer[i] == -2)
          // 오큰수가 존재하지 않는 index는 -1로 변경
            _answer[i] = -1;
        cout << _answer[i] << " ";
    }

    return 0;
}
