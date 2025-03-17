#include <cstdio>
#include <algorithm>

#define S_MAX 100000

class ProblemSolver {

    const double *resistances;
    const char *sp;     // Pointer variable of a string representing the circuit.

    double answer;

    int cursor = -1;

    double temp[S_MAX / 4] = {0};

public:
    ProblemSolver(
        const double * const resistances,
        const char * const sp
    ) : resistances(resistances), sp(sp) {}

    double solve();

private:
    double calculateNext(const unsigned parenthesesDepth);
};

int main() {
    int n;

    // Get an input for the value N, which is between 1 and 9.
    scanf("%d", &n);

    double * const resistances = new double[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &resistances[i]);
    }

    char s[S_MAX + 1];
    scanf("%s", s);

    ProblemSolver ps(resistances, s);
    printf("%lf", ps.solve());

    delete[] resistances;

    return 0;
}

/**
 * This function solves the problem and returns the answer.
 */
double ProblemSolver::solve() {
    cursor++;
    answer = calculateNext(1);

    return answer;
}

/**
 * This function calculates and returns the temporary resistance value.
 */
double ProblemSolver::calculateNext(const unsigned parenthesesDepth) {
    char op = '-';      // Operator.
    do
    {
        // Check for parenthesis and get a resistance value.
        double value;
        if (sp[++cursor] == '(') {
            temp[parenthesesDepth + 1] = 0;
            value = calculateNext(parenthesesDepth + 1);
        } else {
            value = resistances[sp[++cursor] - '0' - 1];
        }

        // Calculate the resistance.
        switch (op) {
            case '-':
                temp[parenthesesDepth] += value;
                break;
            case '|':
                temp[parenthesesDepth] = 1 / (1 / temp[parenthesesDepth] + 1 / value);
                break;
        }

        // Postprocess the string.
        if (sp[++cursor] == ')') {
            return temp[parenthesesDepth];
        } else {
            op = sp[cursor];
        }
    } while (true);
}
