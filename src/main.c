#include <stdio.h>

#define HORZ 10
#define VERT 10

int main() 
{
    int board[HORZ][VERT];

    for (int i = 0; i < HORZ; i++) {
        for (int j = 0; j < VERT; j++) {
            board[i][j] = 0;
        }
    }

    board[1][1] = 1;
    board[2][2] = 1;
    board[3][0] = 1;
    board[3][1] = 1;
    board[3][2] = 1;

    // draw initial board setup 
    for (int i = 0; i < HORZ; i++) {
        for (int j = 0; j < VERT; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    int loop = 0;
    int steps = 10;
    while (loop < steps) {
        printf("\n");
        for (int i = 0; i < HORZ; i++) {
            for (int j = 0; j < VERT; j++) {
                // check neighbours' values and boundaries of the board
                int neighb1 = i - 1 < 0 || j - 1 < 0 ? 0 : board[i-1][j-1];
                int neighb2 = i - 1 < 0 ? 0 : board[i-1][j];
                int neighb3 = i - 1 < 0 || j + 1 == VERT ? 0 : board[i-1][j+1];
                int neighb4 = j - 1 < 0 ? 0 : board[i][j-1];
                int neighb5 = j + 1 == VERT ? 0 : board[i][j+1];
                int neighb6 = i + 1 == HORZ || j - 1 < 0 ? 0 : board[i+1][j-1];
                int neighb7 = i + 1 == HORZ ? 0 : board[i+1][j];
                int neighb8 = i + 1 == HORZ || j + 1 == VERT ? 0 : board[i+1][j+1];
                int sum = neighb1 + neighb2 + neighb3 + neighb4 + neighb5 + neighb6 + neighb7 + neighb8;
                int curr_cell = board[i][j];

                // apply rules
                if (curr_cell == 1 && sum < 2) {
                    board[i][j] = 0;
                }
                else if (curr_cell == 1 && (sum == 2 || sum == 3)) {
                    printf("%d ", board[i][j]);
                    continue;
                }
                else if (curr_cell == 1 && sum > 3) {
                    board[i][j] = 0;
                }
                else if (curr_cell == 0 && sum == 3) {
                    board[i][j] = 1;
                }
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        loop++;
    }

    scanf("%d");

    return 0;
}
