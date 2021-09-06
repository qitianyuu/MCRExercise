#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<set>

bool isWin(char game[3][3]){
    bool win = false;
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
    // column
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    // diagonal
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    return win;
}

void print_chessboard(char game[3][3]){
    system("clear");
    std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl;
    std::cout << " " << game[0][0] << " | " << game[0][1] << " | " << game[0][2] << std::endl;
    std::cout << " -- --- -- " << std::endl;
    std::cout << " " << game[1][0] << " | " << game[1][1] << " | " << game[1][2] << std::endl;
    std::cout << " -- --- -- " << std::endl;
    std::cout << " " << game[2][0] << " | " << game[2][1] << " | " << game[2][2] << std::endl;
}

bool is_right_input(int i, int j){
    bool b1, b2;
    b1 = b2 = false;
    if (i == 0 || i == 1 || i == 2) {
        b1 = true;
    }
    if (j == 0 || j == 1 || j == 2) {
        b2 = true;
    }
    return b1 && b2;
}

bool is_right_position(int i, int j, char game[3][3]){
    if (game[i][j] == ' ') {
        return true;
    }
    return false;
}


int  main(){
//    行、列索引
    int i, j;
    //    棋盘
    //    初始化问题 √
    char game[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}}; // Tic-tac-toe
    //    重复代码 √
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
    std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl;
    int n;
    for (n=0; n<9; n++){
        print_chessboard(game);
        turn = !turn;  // use the not-operator to change true to false or false to true.
        if (turn == false)
            std::cout << "Player 1: ";
        else
            std::cout << "Player 2: ";
        //           输入检测
        while(true){
            std::cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
               std::cin >> i >> j;
            // 输入校验 √
            bool flag1 = is_right_input(i, j);
            // 位置校验 √
            bool flag2 = is_right_position(i, j, game);
            if(flag1 && flag2){
               break;
            }
        }
        // 记录player
        if (turn == false)
           game[i][j] = player1;
        else
           game[i][j] = player2;
        if (isWin(game)){
            std::cout << "Win!" << std::endl;
            break; // need to terminate the problem
        }
    }
    
//    判断和棋逻辑错误 √
    if (n==9 && !isWin(game)) // all celles with i=0 to 2 have been inputted above but no winner yet
       std::cout << "Tie!" << std::endl;

    // show the game to console
    std::cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << std::endl;
    std::cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << std::endl;
    std::cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << std::endl;
    return 1;
}

