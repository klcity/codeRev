#include <iostream>


void showBoard(char game[3][3])
{
  std::cout << "-------------------" << std::endl;
  std::cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << std::endl;
  std::cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << std::endl;
  std::cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << std::endl;
}

bool isWin(char game[3][3])
{
  if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) return true;
  if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) return true;
  if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) return true;

  // column
  if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) return true;
  if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) return true;
  if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) return true;

  // diagonal
  if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) return true;
  if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) return true;

  return false;
}

 

int main()
{

  int i, j;
  char game[3][3]; // Tic-tac-toe
  
  bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
  bool hasWinner = false;

  std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl;
  
  for (int n=0; n<9; n++)
  {
    turn = !turn;  // use the not-operator to change true to false or false to true.

    if (turn == false)
      std::cout << "Player 1: ";
    else
      std::cout << "Player 2: ";

    int cnt = 0;
    do
    {
      std::cout << "Which cell to mark? i:[0..2], j:[0..2]: ";
      std::cin >> i >> j;
      if (i < 0 || i > 2) {
        std::cout << "please enter number 'i' in range 0 to 2" << std::endl;
      } else if (j < 0 || j > 2) {
        std::cout << "please enter number 'j' in range 0 to 2" << std::endl;
      } else if (game[i][j] != 0) { // if the cell is not default value 0
        std::cout << "the cell is already occupied, please input again." << std::endl;
      } else {
        break;
      }
      
      if (cnt++ > 3) { std::cout << "Overloop" << std::endl; break; }
      
    } while (true);
    
    
    
    if (turn == false)
      game[i][j] = 'X';
    else
      game[i][j] = 'O';

    if (isWin(game)){
      std::cout << "Win!" << std::endl;
      hasWinner = true;
      break; // need to terminate the problem
    }
    
    showBoard(game);
    
  }

  if (!hasWinner) // all celles with i=0 to 2 have been inputted above but no winner yet
     std::cout << "Tie!" << std::endl;

  // show the game to console
  showBoard(game);

  return 0;

}
