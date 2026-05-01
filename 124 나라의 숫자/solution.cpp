#include <string>

using namespace std;

string solution(int n)
{
    const char _124Digits[3] = {'1', '2', '4'};

    unsigned count = 0;
    unsigned char dc = 1;       // Stores the current digit count.

    unsigned amountToAdd = sizeof(_124Digits);
    while (count + amountToAdd < n)
    {
        count += amountToAdd;
        dc++;
        amountToAdd *= sizeof(_124Digits);
    }

    string result(dc, '\0');
    int i = -1;
    do
    {
        amountToAdd /= sizeof(_124Digits);

        int di = (n - count - 1) / amountToAdd;
        result[++i] = _124Digits[di];

        count += amountToAdd * di;
    } while (amountToAdd != 1U);

    return result;
}
