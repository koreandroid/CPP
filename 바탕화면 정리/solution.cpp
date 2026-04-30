#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    int lurow = wallpaper.size() - 1;
    int lucol = wallpaper[0].length() - 1;
    int rdrow = 0;
    int rdcol = 0;

    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].length(); j++) {
            if (wallpaper[i][j] == '#') {
                lurow = (i < lurow) ? i : lurow;
                lucol = (j < lucol) ? j : lucol;
                rdrow = (i > rdrow) ? i : rdrow;
                rdcol = (j > rdcol) ? j : rdcol;
            }
        }
    }

    return {lurow, lucol, rdrow + 1, rdcol + 1};
}
