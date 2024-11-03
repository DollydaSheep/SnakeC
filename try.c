#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void print(int arr[9][18], int foodX,  int foodY){
    system("cls");
    for(int i=0;i<9;i++){
        for(int j=0;j<18;j++){
            if(arr[i][j]==1){
                printf("O");
            }else if(arr[i][j]==2){
                printf("9");
            }else if(i == foodX && j == foodY){
                printf("*");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}


int main(){
    char c = 'd';
    char prevC;

    int arr[9][18] = {0};

    int foodX = 2;
    int foodY = 14;

    int body = 3;

    int* snakeX = malloc(body*sizeof(int));
    int* snakeY = malloc(body*sizeof(int));

    snakeX[0] = 4;
    snakeX[1] = 4;
    snakeX[2] = 4;

    snakeY[0] = 4;
    snakeY[1] = 3;
    snakeY[2] = 2;

    int indI = 4;
    int indJ = 4;

    int tempI, tempJ;

    arr[indI][indJ] = 2;
    arr[4][3] = 1;
    arr[4][2] = 1;

    print(arr,foodX,foodY);
    
    while(1){
        if(kbhit()){
            prevC = c;
            c = getch();
            (prevC == 'a' && c == 'd') ? c = 'a' : "";
            (prevC == 'd' && c == 'a') ? c = 'd' : "";
            (prevC == 'w' && c == 's') ? c = 'w' : "";
            (prevC == 's' && c == 'w') ? c = 's' : "";
            if(c=='z'){
                return 0;
            }
        }
        tempI = indI;
        tempJ = indJ;
        switch(c){
            case 'a':
                if(indJ > 0){
                    indJ--;
                }else{
                    indJ = 17;
                }
                break;
            case 'd':
                if(indJ < 17){
                    indJ++;
                }else{
                    indJ = 0;
                }
                break;
            case 's':
                if(indI < 8){
                    indI++;
                }else{
                    indI = 0;
                }
                break;
            case 'w':
                if(indI > 0){
                    indI--;
                }else{
                    indI = 8;
                }
                break;
        }

        if(indI == foodX && indJ == foodY){
            body++;
            foodX = rand() % (8 + 1);
            foodY = rand() % (17 + 1);
            while(arr[foodX][foodY]==1){
                foodX = rand() % (8 + 1);
                foodY = rand() % (17 + 1);
            }
            snakeX = realloc(snakeX, body*sizeof(int));
            snakeY = realloc(snakeY, body*sizeof(int));
        }else if(arr[indI][indJ]==1){
            printf("GAME OVER!\n");
            return 0;
        }else{
            arr[snakeX[body-1]][snakeY[body-1]] = 0;
        }

        
        for(int i=body-1;i>0;i--){
            snakeX[i] = snakeX[i-1];
            snakeY[i] = snakeY[i-1];
            arr[snakeX[i]][snakeY[i]] = 1;
        }
        snakeX[0] = indI;
        snakeY[0] = indJ;

        arr[snakeX[0]][snakeY[0]] = 2;
        // arr[tempI][tempJ] = 0;
        // arr[indI][indJ] = 1;
        usleep(2*100000);
        print(arr,foodX,foodY);
    }
}

