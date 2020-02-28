#include <bits/stdc++.h>
using namespace std;

int N_queen_combination(int queens, int queen_so_far, int boxes, int vidx, string ans)
{
    if (queens == queen_so_far - 1)
    {
        cout << ans;
        cout << endl;
        return 1;
    }

    int count = 0;
    for (int i = vidx; i <= boxes; i++) 
    {

        count += N_queen_combination(queens, queen_so_far + 1, boxes, i + 1, ans + "b" + to_string(i) + "q" + to_string(queen_so_far) + " ");
    }
    return count;
}
int N_queen_permutation(int queens, int queen_so_far, vector<bool> boxess, string ans)
{
    if (queens == queen_so_far - 1)
    {
        cout << ans;
        cout << endl;
        return 1;
    }

    int count = 0;
    for (int i = 1; i < boxess.size(); i++)
    {
        if (!boxess[i])
        {
            boxess[i] = true;

            count += N_queen_permutation(queens, queen_so_far + 1, boxess, ans + "b" + to_string(i) + "q" + to_string(queen_so_far) + " ");
            boxess[i] = false;
        }
    }
    return count;
}
int main()
{
    int no_of_boxes = 7;
    int queens = 3;

   // N_queen_combination(queens, 1, no_of_boxes, 1, " ");
    vector<bool> boxess(8, false);
    N_queen_permutation(queens, 1, boxess, " ");
    return 0;
}