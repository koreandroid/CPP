#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

#define N_MAX 100

class WholeNumber {

    char *mDigits;
    unsigned mLength;

public:
    WholeNumber() : WholeNumber((unsigned long long)0) {}

    WholeNumber(const unsigned long long number) {
        std::string str = std::to_string(number);

        mLength = str.length();
        mDigits = new char[mLength + 1];

        std::copy(str.begin(), str.end(), mDigits);
        mDigits[mLength] = '\0';
    }

    WholeNumber(WholeNumber * const number) {
        mDigits = number->toCharArray();
        mLength = number->mLength;
    }

    WholeNumber(char * const str) {
        mDigits = str;
        mLength = strlen(str);
    }

    ~WholeNumber() {
        delete[] mDigits;
    }

    WholeNumber * operator + (WholeNumber& operand) {
        unsigned l = std::max(mLength, operand.mLength) + 1;        // Temporary length.

        char * const result = new char[l + 1];
        signed carry = 0;
        for (int i = 1; i <= l - 1; i++) {
            const signed temp = carry + digitAt(i - 1) + operand.digitAt(i - 1);
            result[l - i] = temp % 10 + '0';
            carry = temp / 10;
        }
        result[0] = carry + '0';

        if (result[0] == '0') {
            for (int i = 0; i < l - 1; i++) {
                result[i] = result[i + 1];
            }

            l--;
        }

        result[l] = '\0';

        WholeNumber *temp = new WholeNumber(result);
        return temp;
    }

    unsigned digitAt(const unsigned m) const {
        if (m >= mLength) {
            return 0;
        }

        return mDigits[mLength - 1 - m] - 48;
    }

    char * toCharArray() const {
        char * const arr = new char[mLength + 1];

        std::copy(mDigits, mDigits + mLength + 1, arr);

        return arr;
    }
};

int main() {
    int n;

    // Get an input for the value N, which is between 4 and 100.
    scanf("%d", &n);

    WholeNumber *pathCounts[N_MAX][N_MAX];
    WholeNumber zero;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pathCounts[i][j] = &zero;
        }
    }

    pathCounts[0][0] = new WholeNumber(1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            unsigned integer;
            scanf("%u", &integer);

            if (integer == 0 || pathCounts[i][j] == &zero) {
                continue;
            }

            // Jump to the bottom.
            if (i + integer < n) {
                if (pathCounts[i + integer][j] == &zero) {
                    pathCounts[i + integer][j] = new WholeNumber(pathCounts[i][j]);
                } else {
                    WholeNumber * const prev = pathCounts[i + integer][j];
                    pathCounts[i + integer][j] = *prev + *pathCounts[i][j];

                    delete prev;
                }
            }
            // Jump to the right.
            if (j + integer < n) {
                if (pathCounts[i][j + integer] == &zero) {
                    pathCounts[i][j + integer] = new WholeNumber(pathCounts[i][j]);
                } else {
                    WholeNumber * const prev = pathCounts[i][j + integer];
                    pathCounts[i][j + integer] = *prev + *pathCounts[i][j];

                    delete prev;
                }
            }
        }
    }

    const char * const answer = pathCounts[n - 1][n - 1]->toCharArray();
    printf("%s", answer);

    delete[] answer;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pathCounts[i][j] != &zero) {
                delete pathCounts[i][j];
            }
        }
    }

    return 0;
}
