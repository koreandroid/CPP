#include <cstdio>

#define N_MAX 10
#define M_MAX 50
#define K_MAX 50

class ProblemSolver {

    const int n;
    const int m;
    const int k;
    const int *dedicatedWeights;

    unsigned answer = M_MAX * K_MAX;

    unsigned setUpWeights[N_MAX];
    unsigned setUpCount = 0;

    bool setUpChecks[N_MAX] = {0};

public:
    ProblemSolver(
        const int n,
        const int m,
        const int k,
        const int * const dedicatedWeights
    ) : n(n), m(m), k(k), dedicatedWeights(dedicatedWeights) {}

    unsigned solve();

private:
    void updateAnswer(const unsigned weight);

    unsigned calculateWeight();

    void setUpNextRail();
};

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    int * const dedicatedWeights = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &dedicatedWeights[i]);
    }

    ProblemSolver ps(n, m, k, dedicatedWeights);
    printf("%u", ps.solve());

    delete[] dedicatedWeights;

    return 0;
}

unsigned ProblemSolver::solve()
{
    setUpNextRail();

    return answer;
}

void ProblemSolver::updateAnswer(const unsigned weight)
{
    if (weight < answer) {
        answer = weight;
    }
}

unsigned ProblemSolver::calculateWeight()
{
    unsigned pos = 0;
    unsigned kCount = 1, accum = 0, sum = 0;
    do
    {
        if (accum + setUpWeights[pos] <= m) {
            accum += setUpWeights[pos];
        } else if (kCount < k) {
            accum = setUpWeights[pos];
            kCount++;
        } else {
            break;
        }

        sum += setUpWeights[pos];
        pos = (pos + 1) % n;
    } while (true);

    return sum;
}

void ProblemSolver::setUpNextRail()
{
    if (setUpCount == n) {
        updateAnswer(calculateWeight());
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!setUpChecks[i]) {
            setUpWeights[setUpCount++] = dedicatedWeights[i];
            setUpChecks[i] = true;

            setUpNextRail();
            setUpCount--;
            setUpChecks[i] = false;
        }
    }
}
