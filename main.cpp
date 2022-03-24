#include <graphics.h>
#include <time.h>
#include <windows.h>

int turn(int t)
{
    // x ->1  O->0

    if (t = 10)
    {
        return -1;
    }

    else if (t % 2 == 1)
    {
        return 1;
    }

    else if (t % 3 == 0)
    {
        return 0;
    }
}
// turn calculation over

// win condition
int wincondition(int square[3][3])
{
    // -1 No win yet
    // 0 o win
    // 1 x win

    int row = 0;
    int col = 0;

    // for x

    // for rows
    for (row = 0; row < 3; row++)
    {
        int count = 0;

        for (col = 0; col < 3; col++)
        {
            if (square[row][col] == 1)
            {
                count++;
            }
        }

        if (count == 3)
        {
            return 1;
        }
    }

    // for columns
    for (col = 0; col < 3; col++)
    {
        int count = 0;

        for (row = 0; row < 3; row++)
        {
            if (square[row][col] == 1)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return 1;
        }
    }

    // for left diagonal

    row = 0;
    col = 0;
    int count = 0;

    for (row = 0; row < 3; row++)
    {
        if (square[row][col] == 1)
        {
            count++;
        }
        col++;
        if (count == 3)
        {
            return 1;
        }
    }

    // for right diagonal
    row = 0;
    col = 2;
    count = 0;

    for ( row = 0; row <=2; row++)
    {

        if (square[row][col] == 1)
        {
            count++;
        }
        col--;
        if (count == 3)
        {
            return 1;
        }
    }

    // for  0 **************************

    row = 0;
    col = 0;

    // for rows
    for (row = 0; row < 3; row++)
    {
        int count = 0;

        for (col = 0; col < 3; col++)
        {
            if (square[row][col] == 0)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return 0;
        }
    }

    // for columns
    for (col = 0; col < 3; col++)
    {
        int count = 0;

        for (row = 0; row < 3; row++)
        {
            if (square[row][col] == 0)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return 0;
        }
    }

    // for left diagonal

    row = 0;
    col = 0;
    count = 0;

    for (row = 0; row < 3; row++)
    {
        if (square[row][col] == 0)
        {
            count++;
        }
        col++;
        if (count == 3)
        {
            return 0;
        }
    }

    // for right diagonal
    row=0;
    col = 2;
    count = 0;

    for (  ; row <=2; row++)
    {

        if (square[row][col] == 0)
        {
            count++;
        }
        col--;
        if (count == 3)
        {
            return 0;
        }
    }

    return -1;
}
// win condition over

// draw lines
void draw_lines()
{
    // Building Board
    line(480, 0, 480, 480);
    line(160, 0, 160, 480);
    line(320, 0, 320, 480);
    line(480, 0, 480, 480);
    line(0, 160, 480, 160);
    line(0, 320, 480, 320);
}

// line drawing over

void clear_screen()
{
    // 1

    setfillstyle(1, 0);
    bar(0, 0, 640, 480);
}

void print_nums()
{
    char *arr[9] = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
    int count = 0;
    while (count < 9)
    {

        int x = count % 3;
        int y = count / 3;

        outtextxy(5 + 160 * x, 140 + 160 * y, arr[count]);
        count++;
    }
}

void print_X(int X, int Y)
{

    X = 80 + X * 160;
    Y = 80 + Y * 160;

    int R = 70;

    line(X - (R / 1.414), Y - (R / 1.414), X + (R / 1.414), Y + (R / 1.414));

    line(X + (R / 1.414), Y - (R / 1.414), X - (R / 1.414), Y + (R / 1.414));

    // radius =40
}

void print_Y(int X, int Y)
{

    X = 80 + X * 160;
    Y = 80 + Y * 160;

    int R = 70;

    circle(X, Y, R);
}

int main()
{

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");
    // ready

    // 2
    // declaring array
    int Matrix[3][3] = {-1};

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            Matrix[i][j] = -1;
        }
    }

    int T = 1;

    // Coding starts Here **************************

    while (T <=9 && wincondition(Matrix)==-1)
    {

        clear_screen();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (Matrix[i][j] == 1)
                {
                    print_X(i, j);
                }

                else if (Matrix[i][j] == 0)
                {
                    print_Y(i, j);
                }
            }
        }

        delay(100);

        draw_lines();

        print_nums();

        // Print message for turn

        if (T % 2 == 1)
        {
            // X turn
            outtextxy(500, 240, "X's Turn");

            outtextxy(500, 260, "Enter the number");
            outtextxy(500, 280, "to select cell");

            int num = getch() - '0';

            Matrix[num % 3][num / 3] = 1;

            //
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {

                    if (Matrix[i][j] == 1)
                    {
                        print_X(i, j);
                    }

                    else if (Matrix[i][j] == 0)
                    {
                        print_Y(i, j);
                    }
                }
            }
        }

        else
        {

            outtextxy(500, 240, "O's Turn");

            outtextxy(500, 260, "Enter the number");
            outtextxy(500, 280, "to select cell");

            int num = getch() - '0';

            Matrix[num % 3][num / 3] = 0;

            //

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {

                    if (Matrix[i][j] == 1)
                    {
                        print_X(i, j);
                    }

                    else if (Matrix[i][j] == 0)
                    {
                        print_Y(i, j);
                    }
                }
            }
        }

        delay(200);
        T++;
    }

    if (wincondition(Matrix) == 1)
    {
        clear_screen();
        outtextxy(320, 240, "X wins");
    }

    else if (wincondition(Matrix) == 0)
    {
        clear_screen();
        outtextxy(320, 240, "O wins");
    }

    else
    {
        clear_screen();
        outtextxy(320, 240, "The Game is Tie");
    }



     getch();
    closegraph();

    return 0;
}
