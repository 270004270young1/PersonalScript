/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int findPath(int** map, int position[2],int size);

void move(int** map, int position[2], int* count,int size) {
    map[position[0]][position[1]] = 1;
    *count += findPath(map, position,size);
    map[position[0]][position[1]] = 0;
}

int findPath(int** map, int position[2],int size) {
    int count = 0;

    if (position[0] >= size && position[1] >= size)
        return 1;

    

    int row = position[0];
    int col = position[1];
    int rowPlus1 = position[0] + 1;
    int rowMinus1 = position[0] - 1;
    int colPlus1 = position[1] + 1;
    int colMinus1 = position[1] - 1;

    int rowColPlus1[2] = { row,colPlus1 };
    int rowColMinus1[2] = { row,colMinus1 };
    int rowPlus1Col[2] = { rowPlus1,col };
    int rowMinus1Col[2] = { rowMinus1,col };
   
    if (col <= 0 && row <= 0) {

        if (map[row][colPlus1] == 0) {
            move(map, rowColPlus1, &count ,size);
        }
        if (map[rowPlus1][col] == 0) {
            move(map, rowPlus1Col, &count ,size);
        }
    }
    else if (col >= size && row <= 0) {
        if (map[row][colMinus1] == 0) {
            move(map, rowColMinus1, &count ,size);
        }
        if (map[rowPlus1][col] == 0) {
            move(map, rowPlus1Col, &count ,size);
        }
    }
    else if (row >= size && col <= 0) {
        if (map[rowMinus1][col] == 0) {
            move(map, rowMinus1Col, &count ,size);
        }
        if (map[row][colPlus1] == 0) {
            move(map, rowColPlus1, &count ,size);
        }
    }
    else if (col <= 0) {
        
        

            if (map[rowPlus1][col] == 0) {
                move(map, rowPlus1Col, &count,size);
            }
        

        

            if (map[rowMinus1][col] == 0) {
                move(map, rowMinus1Col, &count,size);
            }
        
       

        
        if (map[row][colPlus1] == 0) {
            move(map, rowColPlus1, &count,size);
        }
    }
    else if (col >= size) {

        

            if (map[rowPlus1][col] == 0) {
                move(map, rowPlus1Col, &count,size);
            }
        
        

            if (map[rowMinus1][col] == 0) {
                move(map, rowMinus1Col, &count,size);
            }
        
        if (map[row][colMinus1] == 0) {
            move(map, rowColMinus1, &count,size);
        }
    }
    else if (row <= 0) {
        

            if (map[row][colPlus1] == 0) {
                move(map, rowColPlus1, &count,size);
            }
        
        

            if (map[row][colMinus1] == 0) {
                move(map, rowColMinus1, &count,size);
            }
        

        if (map[rowPlus1][col] == 0) {
            move(map, rowPlus1Col, &count,size);
        }
    }
    else if (row >= size) {
        

            if (map[row][colPlus1] == 0) {
                move(map, rowColPlus1, &count,size);
            }
        
       

            if (map[row][colMinus1] == 0) {
                move(map, rowColMinus1, &count,size);
            }
        

        if (map[rowMinus1][col] == 0) {
            move(map, rowMinus1Col, &count,size);
        }
    }
    else {
        if (map[row][colPlus1] == 0) {
            move(map, rowColPlus1, &count,size);
        }
        if (map[row][colMinus1] == 0) {
            move(map, rowColMinus1, &count,size);
        }
        if (map[rowPlus1][col] == 0) {
            move(map, rowPlus1Col, &count,size);
        }
        if (map[rowMinus1][col] == 0) {
            move(map, rowMinus1Col, &count,size);
        }
    }

    return count;
}

int main()
{
    int size;
    cout << "Enter the size of the board" << endl;
    cin >> size;

    int** map = new int*[size];
    for (int i = 0; i < size; i++) {
        map[i] = new int[size];
        for (int j = 0; j < size; j++) {
            map[i][j] = 0;
        }
    }
    map[0][0] = 1;
    
    int position[2] = { 0,0 };
    cout << findPath(map, position,size-1);

    return 0;
}
