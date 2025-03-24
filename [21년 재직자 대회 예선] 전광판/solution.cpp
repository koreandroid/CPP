#include <cstdio>
#include <algorithm>

#define T_MAX 1000

class ProblemSolver {

    int answer = -1;

    const unsigned char bulbState[10] = {
        0b1110111,      // 0
        0b0010010,      // 1
        0b1011101,      // 2
        0b1011011,      // 3
        0b0111010,      // 4
        0b1101011,      // 5
        0b1101111,      // 6
        0b1110010,      // 7
        0b1111111,      // 8
        0b1111011,      // 9
    };

public:
    unsigned solve(const int a, const int b);

private:
    unsigned char getState(const int num, const unsigned pv) const;
};

int main()
{
    int t;
    scanf("%d", &t);

    if (!(1 <= t && t <= T_MAX)) {
        printf("The value of T is invalid. It should be between 1 and %d.\n", T_MAX);
        return -1;
    }

    ProblemSolver ps;

    for (int i = 0; i < t; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%u\n", ps.solve(a, b));
    }

    return 0;
}

unsigned ProblemSolver::solve(const int a, const int b)
{
    answer = 0;

    for (unsigned pv = 10000; pv; pv /= 10) {
        unsigned char stateDiff = getState(a, pv) ^ getState(b, pv);
        while (stateDiff)
        {
            answer += stateDiff % 2;
            stateDiff >>= 1;
        }
    }

    return (unsigned)answer;
}

unsigned char ProblemSolver::getState(const int num, const unsigned pv) const
{
    if (pv > num) {
        return 0b0000000;
    }

    return bulbState[(num / pv) % 10];
}
