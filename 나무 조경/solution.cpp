#include <cstdio>
#include <functional>

#define MAX_HEIGHT 10
#define MAX_BINDING_COUNT 4

unsigned solve2By2();
unsigned solve3By3();
unsigned solve4By4();

int main()
{
    int n;
    scanf("%d", &n);

    unsigned answer;
    switch (n) {
        case 2:
            answer = solve2By2();
            break;
        case 3:
            answer = solve3By3();
            break;
        case 4:
            answer = solve4By4();
            break;
        default:
            printf("The value of N is invalid. It should be between 2 and 4.\n");
            return -1;
    }

    printf("%u", answer);

    return 0;
}

unsigned solve2By2()
{
    unsigned answer = 0;
    for (int i = 0; i < 4; i++) {
        unsigned height;
        scanf("%u", &height);

        answer += height;
    }

    return answer;
}

unsigned solve3By3()
{
    unsigned sum = 0;
    unsigned min = MAX_HEIGHT;
    for (int i = 0; i < 9; i++) {
        unsigned height;
        scanf("%u", &height);

        sum += height;
        if (i % 2 == 0 && height < min) {
            min = height;
        }
    }

    return sum - min;
}

unsigned solve4By4()
{
    unsigned heights[16];
    for (int i = 0; i < 16; i++) {
        scanf("%u", &heights[i]);
    }

    unsigned answer = 0;
    bool boundChecks[16] = {0};

    std::function<void(const int, const unsigned, const unsigned)> dive;
    dive = [&](const int k, const unsigned count, const unsigned heightAccum)
    {
        if (k == 16 || count == MAX_BINDING_COUNT) {
            if (heightAccum > answer) {
                answer = heightAccum;
            }

            return;
        }

        dive(k + 1, count, heightAccum);

        if (!boundChecks[k]) {
            if (k % 4 <= 2 && !boundChecks[k + 1]) {
                boundChecks[k] = boundChecks[k + 1] = true;
                dive(k + 2, count + 1, heightAccum + heights[k] + heights[k + 1]);
                boundChecks[k] = boundChecks[k + 1] = false;
            }
            if (k <= 11) {
                boundChecks[k] = boundChecks[k + 4] = true;
                dive(k + 1, count + 1, heightAccum + heights[k] + heights[k + 4]);
                boundChecks[k] = boundChecks[k + 4] = false;
            }
        }
    };

    dive(0, 0, 0);

    return answer;
}
