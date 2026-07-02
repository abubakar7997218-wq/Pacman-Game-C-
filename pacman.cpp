#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

void maze();
void read();
void xycord(int x, int y);
char getCharAtxy(short int x, short int y);
void erasepm(int x, int y);
void printpm(int x, int y);
void printg(int x, int y);
void printScore(int score, int lives, int high);
void gameOver();  
fstream score_data;

int x = 5, y = 5;
int gx[5] = {20, 70, 40, 90, 55};
int gy[5] = {8, 18, 12, 22, 28};
int large = 0;
int high = 0;
int score = 0;
int lives = 3;
bool g[5] = {true, true, true, true, true};
bool gameover = true;

int main()
{
    system("chcp 65001 > nul");
    SetConsoleOutputCP(CP_UTF8);
    system("cls");  
    system("Color 0A");
    read();
    maze();
    printScore(score, lives, high);
    
    while (gameover)
    {
        xycord(x, y);

        if (GetAsyncKeyState(VK_UP))
        {
            char next = getCharAtxy(x, y - 1);
            if (next == ' ' || next == '.' || next == '$')
            {
                erasepm(x, y);
                y = y - 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }
        
        if (GetAsyncKeyState(VK_DOWN))
        {
            char next = getCharAtxy(x, y + 1);
            if (next == ' ' || next == '.' || next == '$')
            {
                erasepm(x, y);
                y = y + 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            char next = getCharAtxy(x - 1, y);
            if (next == ' ' || next == '.' || next == '$')
            {
                erasepm(x, y);
                x = x - 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }
        
        if (GetAsyncKeyState(VK_RIGHT))
        {
            char next = getCharAtxy(x + 1, y);
            if (next == ' ' || next == '.' || next == '$')
            {
                erasepm(x, y);
                x = x + 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }
        
        if (score > large)
        {
            large = score;
        }
        else if (large > high)
        {
            high = large;
            printScore(score, lives, high);
        }
        
        if (g[0])
        {
            char nextPos = getCharAtxy(gx[0] + 1, gy[0]);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[0], gy[0]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[0], gy[0]);
                    cout << " ";
                }
                gx[0]++;
                if (gx[0] > 100)
                {
                    g[0] = false;
                }
            }
            else
            {
                g[0] = false;
            }
        }
        else
        {
            char nextPos = getCharAtxy(gx[0] - 1, gy[0]);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[0], gy[0]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[0], gy[0]);
                    cout << " ";
                }
                gx[0]--;
                if (gx[0] < 2)
                {
                    g[0] = true;
                }
            }
            else
            {
                g[0] = true;
            }
        }
        printg(gx[0], gy[0]);
        
        if (g[1])
        {
            char nextPos = getCharAtxy(gx[1] + 1, gy[1]);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[1], gy[1]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[1], gy[1]);
                    cout << " ";
                }
                gx[1]++;
                if (gx[1] > 100)
                {
                    g[1] = false;
                }
            }
            else
            {
                g[1] = false;
            }
        }
        else
        {
            char nextPos = getCharAtxy(gx[1] - 1, gy[1]);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[1], gy[1]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[1], gy[1]);
                    cout << " ";
                }
                gx[1]--;
                if (gx[1] < 2)
                {
                    g[1] = true;
                }
            }
            else
            {
                g[1] = true;
            }
        }
        printg(gx[1], gy[1]);
        
        if (g[2])
        {
            char nextPos = getCharAtxy(gx[2], gy[2] + 1);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[2], gy[2]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[2], gy[2]);
                    cout << " ";
                }
                gy[2]++;
                if (gy[2] > 30)
                {
                    g[2] = false;
                }
            }
            else
            {
                g[2] = false;
            }
        }
        else
        {
            char nextPos = getCharAtxy(gx[2], gy[2] - 1);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[2], gy[2]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[2], gy[2]);
                    cout << " ";
                }
                gy[2]--;
                if (gy[2] < 2)
                {
                    g[2] = true;
                }
            }
            else
            {
                g[2] = true;
            }
        }
        printg(gx[2], gy[2]);

        if (g[3])
        {
            char nextPos = getCharAtxy(gx[3], gy[3] + 1);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[3], gy[3]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[3], gy[3]);
                    cout << " ";
                }
                gy[3]++;
                if (gy[3] > 30)
                {
                    g[3] = false;
                }
            }
            else
            {
                g[3] = false;
            }
        }
        else
        {
            char nextPos = getCharAtxy(gx[3], gy[3] - 1);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[3], gy[3]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[3], gy[3]);
                    cout << " ";
                }
                gy[3]--;
                if (gy[3] < 2)
                {
                    g[3] = true;
                }
            }
            else
            {
                g[3] = true;
            }
        }
        printg(gx[3], gy[3]);
        
        if (g[4])
        {
            char nextPos = getCharAtxy(gx[4] + 1, gy[4]);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[4], gy[4]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[4], gy[4]);
                    cout << " ";
                }
                gx[4]++;
                if (gx[4] > 100)
                {
                    g[4] = false;
                }
            }
            else
            {
                g[4] = false;
            }
        }
        else
        {
            char nextPos = getCharAtxy(gx[4] - 1, gy[4]);
            if (nextPos == '.' || nextPos == ' ' || nextPos == 'p')
            {
                if (nextPos == '.')
                {
                    xycord(gx[4], gy[4]);
                    cout << ".";
                }
                else
                {
                    xycord(gx[4], gy[4]);
                    cout << " ";
                }
                gx[4]--;
                if (gx[4] < 2)
                {
                    g[4] = true;
                }
            }
            else
            {
                g[4] = true;
            }
        }
        printg(gx[4], gy[4]);
        for (int i = 0; i < 5; i++)
        {
            if (x == gx[i] && y == gy[i])
            {
                lives--;
                printScore(score, lives, high);
                if (lives == 0)
                {
                    high = score;
                    score_data.open("Scoring File.txt", ios::out);
                    score_data << high;
                    score_data.close();
                    gameover = false;
                    system("cls");
                    xycord(0, 0);
                    gameOver();  // Fixed function call
                }
                else
                {
                    x = 5;
                    y = 5;
                    Sleep(1000);  
                    printpm(x, y);
                }
            }
        }
        
        if (score > 2500)
        {
            gameover = false;
            xycord(0, 34);
            cout << "YOU WON THE GAME!";
        }

        Sleep(70);
    }
    
    return 0;  
}

void maze()
{
    cout << "##################################################################################################################" << endl;
    cout << "#...................................................##..................................................$........#" << endl;
    cout << "#...................................................##..........##...............................................#" << endl;
    cout << "#............#####################...#######........##..........##..............$................................#" << endl;
    cout << "#............#####################...#######........##..........##...........####################................#" << endl;
    cout << "#...................................................##..........##...........####################................#" << endl;
    cout << "#...................................................##..........##...............................................#" << endl;
    cout << "#...............##..............................#########.......##...............................................#" << endl;
    cout << "#.......$.......##..............................#########.....###############....................................#" << endl;
    cout << "#....#######....##............................................###############.......................$............#" << endl;
    cout << "#...............##..................................................##.........#########.........................#" << endl;
    cout << "#...............##....................................##............##...........................................#" << endl;
    cout << "#....#######....##....................................##............##...........................................#" << endl;
    cout << "#...............########################..............##........$...##...........................................#" << endl;
    cout << "#...........    ########################..............##............##...........................................#" << endl;
    cout << "#.....................................##..............##..............................####################.......#" << endl;
    cout << "#.....................................##..............##..............................####################.......#" << endl;
    cout << "#.....................................##..............##.........................................................#" << endl;
    cout << "#...........................#....................................................................................#" << endl;
    cout << "#.....################......#.........##..........###########################....................................#" << endl;
    cout << "#.......................#.............##.........................................................................#" << endl;
    cout << "#.......................#.......................................................................$................#" << endl;
    cout << "#.....................#######....................................................................................#" << endl;
    cout << "#........$............#######....................................................................................#" << endl;
    cout << "#.........................#.............##########################...............................................#" << endl;
    cout << "#.........................#.............##########################................###################............#" << endl;
    cout << "#.....################....#.......................................##..............###################............#" << endl;
    cout << "#.........................#...............................................##..........$..........................#" << endl;
    cout << "#......################...................................................##.....................................#" << endl;
    cout << "#.................................##########################..............##.....................................#" << endl;
    cout << "#.................................##########################..............##.....................................#" << endl;
    cout << "#.........................................................................##.....................................#" << endl;
    cout << "##################################################################################################################" << endl;
}

void xycord(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize = {1, 1};
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : '\0';
}

void erasepm(int x, int y)
{
    xycord(x, y);
    cout << " ";
}

void printpm(int x, int y)
{
    xycord(x, y);
    cout << "p";
}

void printScore(int score, int lives, int high)
{
    xycord(0, 33);
    cout << "Score: " << score << " ";
    xycord(12, 33);
    cout << "LIVES: " << lives << " ";
    xycord(26, 33);
    cout << "HIGH SCORE: " << high << "  ";
}

void printg(int x, int y)
{
    xycord(x, y);
    cout << "g";
}

void read()
{
    score_data.open("Scoring File.txt", ios::in);
    score_data >> high;
    score_data.close();
}

void gameOver() 
{
    system("cls");
    cout << "\n\n\n";
    cout << "   ██████╗  █████╗ ███╗   ███╗███████╗    ██████╗ ██╗   ██╗███████╗██████╗ \n";
    cout << "  ██╔════╝ ██╔══██╗████╗ ████║██╔════╝   ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n";
    cout << "  ██║  ███╗███████║██╔████╔██║█████╗     ██║   ██║██║   ██║█████╗  ██████╔╝\n";
    cout << "  ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝     ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n";
    cout << "  ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗   ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n";
    cout << "   ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝    ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n";
    cout << "\n\n";
    cout << "                 💀 YOU HAVE BEEN DESTROYED 💀\n";
    cout << "               ---------------------------------\n";
    cout << "                 Press any key to exit...\n\n";
  
}