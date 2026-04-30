#include <string>
#include <vector>

#define PERSONAL_IND_COUNT          4
#define PERSONAL_TYPE_COUNT_PER     2

#define PERSONAL_TYPE_MAX_ALPH      'T'

using namespace std;

const char g_typeAlphs[PERSONAL_IND_COUNT][PERSONAL_TYPE_COUNT_PER] = {
    {'R', 'T'},
    {'C', 'F'},
    {'J', 'M'},
    {'A', 'N'}
};

string solution(vector<string> survey, vector<int> choices) {
    unsigned short scores[PERSONAL_TYPE_MAX_ALPH - 'A'] = {0};

    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 4) {
            continue;
        }

        if (choices[i] < 4) {
            scores[survey[i][0] - 'A'] += 4 - choices[i];
        } else {
            scores[survey[i][1] - 'A'] += choices[i] - 4;
        }
    }

    char answer[PERSONAL_IND_COUNT + 1] = {0};
    for (int i = 0; i < PERSONAL_IND_COUNT; i++) {
        answer[i] = (scores[g_typeAlphs[i][0] - 'A'] < scores[g_typeAlphs[i][1] - 'A']) ? g_typeAlphs[i][1] : g_typeAlphs[i][0];
    }

    return answer;
}
