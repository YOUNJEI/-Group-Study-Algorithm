#include <string>
#include <vector>

using namespace std;

int g_target;

int solve(int idx, char buho, vector<int> &numbers, int current_score)
{
    int count = 0;
    if (idx == numbers.size())
    {
        if (current_score == g_target)
            return (1);
        return (0);
    }
    if (buho == '+')
        current_score += numbers[idx];
    else if (buho == '-')
        current_score -= numbers[idx];
    
    count += solve(idx + 1, '+', numbers, current_score);
    count += solve(idx + 1, '-', numbers, current_score);
    return (count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    g_target = target;
    
    answer += solve(0, '+', numbers, 0);
    answer += solve(0, '-', numbers, 0);
    
    return (answer / 2);
}

int main()
{
  vector<int> vi;
  vi.push_back(1);
  vi.push_back(1);
  vi.push_back(1);
  vi.push_back(1);
  vi.push_back(1);
  
  solution(vi, 3);
  return (0);
}