#include <string>
#include <vector>
#include <iostream>

bool *g_visit = NULL;
using namespace std;

void reset_visit(int n)
{
    for (int i = 0; i < n; i++)
        g_visit[i] = false;
}

void find_path(int idx, int n, vector<vector<int>> &computers)
{
    g_visit[idx] = true;
    for (int i = 0; i < n; i++)
    {
        if (computers[idx][i] && g_visit[i] == false)
            find_path(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    g_visit = new bool[n];
    reset_visit(n);
    
    for (int i = 0; i < n; i++)
    {
        if (g_visit[i] == false)
        {
            answer++;
            find_path(i, n, computers);
        }
    }
    delete[] g_visit;
    return answer;
}

int main(void)
{
    vector<int> temp;
    vector<vector<int>> vi;

    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(0);
    vi.push_back(temp);
    temp.clear();
    
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(0);
    vi.push_back(temp);
    temp.clear();

    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(1);
    vi.push_back(temp);
    temp.clear();

    cout<<solution(3, vi);
    return (0);
}