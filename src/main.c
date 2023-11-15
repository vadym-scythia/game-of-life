#include <stdio.h>

int main() 
{
    int board[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }

    board[4][4] = 1;
    board[4][5] = 1;
    board[3][4] = 1;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    int loop = 0;
    int steps = 3;
    while (loop < steps) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int neighb1 = i - 1 < 0 || j - 1 < 0 ? 0 : board[i-1][j-1];
                int neighb2 = i - 1 < 0 ? 0 : board[i-1][j];
                int neighb3 = i - 1 < 0 || j + 1 < 0 ? 0 : board[i-1][j+1];
                int neighb4 = j - 1 < 0 ? 0 : board[i][j-1];
                int neighb5 = j + 1 < 0 ? 0 : board[i][j+1];
                int neighb6 = i + 1 < 0 || j - 1 < 0 ? 0 : board[i+1][j-1];
                int neighb7 = i + 1 < 0 ? 0 : board[i+1][j];
                int neighb8 = i + 1 < 0 || j + 1 < 0 ? 0 : board[i+1][j+1]; 
                int sum = neighb1 + neighb2 + neighb3 + neighb4 + neighb5 + neighb6 + neighb7 + neighb8;
                int curr_cell = board[i][j];

                if (curr_cell == 1 && sum < 2) {
                    board[i][j] = 0;
                }
                else if (curr_cell == 1 && (sum == 2 || sum == 3)) {
                    continue;
                }
                else if (curr_cell == 1 && sum > 3) {
                    board[i][j] = 0;
                }
                else if (curr_cell == 0 && sum == 3) {
                    board[i][j] = 1;
                }
            }
        }

        printf("\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        loop++;
    }

    scanf("%d");

    return 0;
}
