#include <string>

#define N_MAX       12

using namespace std;

int g_answer;

void dive(int, int, bool *, unsigned char (*)[N_MAX]);

int solution(int n)
{
    g_answer = 0;

    bool isColumnOccupied[N_MAX] = {false};
    unsigned char diagAttackedCounts[N_MAX][N_MAX] = {0};
    dive(n, 0, isColumnOccupied, diagAttackedCounts);

    return g_answer;
}

void dive(int n, int r, bool isColumnOccupied[], unsigned char diagAttackedCounts[][N_MAX])
{
    if (n == r) {
        g_answer++;
    }

    for (int c = 0; c < n; c++) {
        if (!isColumnOccupied[c] && diagAttackedCounts[r][c] == 0) {
            // First, begin the preprocess.
            isColumnOccupied[c] = true;

            int nextCoord[2] = {r + 1, c + 1};
            while (nextCoord[0] < n && nextCoord[1] < n)
            {
                diagAttackedCounts[nextCoord[0]][nextCoord[1]]++;

                nextCoord[0]++;
                nextCoord[1]++;
            }
            nextCoord[0] = r + 1;
            nextCoord[1] = c - 1;
            while (nextCoord[0] < n && nextCoord[1] >= 0)
            {
                diagAttackedCounts[nextCoord[0]][nextCoord[1]]++;

                nextCoord[0]++;
                nextCoord[1]--;
            }

            // And then, call recursively.
            dive(n, r + 1, isColumnOccupied, diagAttackedCounts);

            // Lastly, end the postprocess.
            isColumnOccupied[c] = false;

            nextCoord[0] = r + 1;
            nextCoord[1] = c + 1;
            while (nextCoord[0] < n && nextCoord[1] < n)
            {
                diagAttackedCounts[nextCoord[0]][nextCoord[1]]--;

                nextCoord[0]++;
                nextCoord[1]++;
            }
            nextCoord[0] = r + 1;
            nextCoord[1] = c - 1;
            while (nextCoord[0] < n && nextCoord[1] >= 0)
            {
                diagAttackedCounts[nextCoord[0]][nextCoord[1]]--;

                nextCoord[0]++;
                nextCoord[1]--;
            }
        }
    }
}
