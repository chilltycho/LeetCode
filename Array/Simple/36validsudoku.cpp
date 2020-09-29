#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool isValidSudoKu(vector<vector<char>> &board)
{
    vector<vector<int>> row(9, vector<int>(9, 0));
    vector<vector<int>> col(9, vector<int>(9, 0));
    vector<vector<int>> box(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            int val = board[i][j] - '1';
            int box_index = (i / 3) * 3 + j / 3;
            if (row[i][val] == 0 && col[j][val] == 0 && box[box_index][val] == 0) //行、列、九宫格内无重复
            {
                row[i][val] = 1;
                col[j][val] = 1;
                box[box_index][val] = 1;
            }
            else
                return false;
        }
    }
    return true;
}

bool isValidSudoKu_1(vector<vector<char>> &board)
{
    vector<int> wow(9, 0);//9行，9列，9格用9个数代替
    int mux1, mux2, mux3, box_index;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;

            mux1 = 0x01 << (board[i][j] - '1');//最低9位放行号0
            mux2 = 0x01 << 9 << (board[i][j] - '1');//中间9位放列号
            mux3 = 0x01 << 9 << 9 << (board[i][j] - '1');//最高9位放九宫格区域号
            box_index = (i / 3) * 3 + j / 3;
            if ((wow[i] & mux1) != mux1 && (wow[j] & mux2) != mux2 && (wow[box_index] & mux3) != mux3)
            {
                wow[i] = wow[i] | mux1;
                wow[j] = wow[j] | mux2;
                wow[box_index] = wow[box_index] | mux3;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{
    vector<char> row1{'8', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> row2{'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> row3{'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> row4{'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> row5{'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> row6{'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> row7{'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> row8{'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> row9{'.', '.', '.', '.', '8', '.', '.', '7', '9'};

    vector<vector<char>> vi{row1, row2, row3, row4, row5, row6, row7, row8, row9};
    cout << isValidSudoKu_1(vi);
}