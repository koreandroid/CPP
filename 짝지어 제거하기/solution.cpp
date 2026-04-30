#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> lastUnpairedLetter;
    for (char ch : s) {
        if (!lastUnpairedLetter.empty() && lastUnpairedLetter.top() == ch) {
            lastUnpairedLetter.pop();
        } else {
            lastUnpairedLetter.push(ch);
        }
    }

    return lastUnpairedLetter.empty();
}
