#include <iostream>
#include <math.h>

struct limits {
    int lower_limit;
    int upper_limit;
};

limits grid[9] = {{0, 2}, {0, 2}, {0, 2},
                  {3, 5}, {3, 5}, {3, 5},
                  {6, 8}, {6, 8}, {6, 8}};

int sudoku[9][9] = {};

//Function to check whether number fits into target row
bool check_row(int row, int target) {
  for (int i = 0; i < 9; i++) {
    if (target == sudoku[row][i]) {
      return true;
    }
  }
  return false;
}

//Function to check whether number fits into target column
bool check_col(int col, int target) {
  for (int i = 0; i < 9; i++) {
    if (target == sudoku[i][col]) {
      return true;
    }
  }
  return false;
}

//Function to check whether number fits into target sub-grid
bool check_sub_grid(int target, int row_lower_limit, int row_upper_limit, int col_lower_limit, int col_upper_limit) {
  for (int row = row_lower_limit; row <= row_upper_limit; row++) {
    for (int col = col_lower_limit; col <= col_upper_limit; col++) {
      if (sudoku[row][col] == target) {
        return true;
      }
    }
  }
  return false;
}

bool is_valid(int row, int col, int num) {
  if(!check_row(row, num)){
    if(!check_col(col, num)){
      if(!check_sub_grid(num, grid[row].lower_limit, grid[row].upper_limit, grid[col].lower_limit, grid[col].upper_limit)){
        return true;
      }
    }
  }
  return false;
}

bool find_empty_cell(int &row, int &col) {
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (sudoku[row][col] == 0) {
        return true;
      }
    }
  }
  return false;
}

bool solve_sudoku() {
  int row, col;
  if (!find_empty_cell(row, col)) {
    return true; // No empty cells left, puzzle is solved
  }
  else if (find_empty_cell(row,col) == true){
    for (int num = 1; num <= 9; num++) {
      if (is_valid(row, col, num)) {
        sudoku[row][col] = num; // Place the number

        if (solve_sudoku()) {
          return true;
          }
      sudoku[row][col] = 0; // Reset the cell and backtrack
      }
    }
  }
  return false;
}

void print_sudoku() {
    printf("\n");
    //A line of dashes is needed to separate different rows, double the number of rows and add one
    // 9 * 2 + 1 = 19, on odd rows print out dashes, on even rows print out cell values from sudoku indexed by half of new value minus one
    for (int row = 1; row <= 19; row++) {
        if(row % 2){
            printf("+");
            for(int dash = 1; dash < 36; dash++){
                if(dash % 4 == 0){
                    printf("+");
                }
                else{
                printf("%c", '-');
                }
            }
        printf("+%c", '\n');
        }
        else{
            printf("%c", '|');
            for (int col = 0; col < 9; col++) {
                printf(" %d |", sudoku[row/2 - 1][col]);
            }
            printf("\n");
        }
    }
}

int main(){
    int k = 0;
    const char* pos;
    for(int i = 0; i < 9; i++){
        if (i == 0){pos = "st";};
        if (i == 1){pos = "nd";}
        if (i == 2){pos = "rd";}
        if (i >= 3){pos = "th";}
        printf("Enter %d%s row: \n", i + 1, pos);
        std::cin >> k;
        for(int j = 0; j < 9; j++){
            sudoku[i][j] = (k / static_cast<int>(pow(10, (8 - j))))%10;
        }
        k = 0;
    }
    printf("\n UNSOLVED SUDOKU");
    print_sudoku();

    if (solve_sudoku()) {
        printf("\n SOLVED SUDOKU");
        print_sudoku();
    }
    else {
        printf("No solution exists.\n");
    }
    return 0;
}
