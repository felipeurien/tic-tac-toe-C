#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct coordenada
{
    short x;
    short y;        
};
    
struct tateti
{
    char tablero [3][3];
    int turn;
    bool finished;
    struct coordenada cursor;
};

typedef struct tateti tateti_t;

tateti_t nuevoTateti (){
    
    tateti_t juego;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            juego.tablero [i][j] = ' ';
        }
    }
    
    juego.turn = 0;
    juego.finished = false;
    juego.cursor.x = 0; 
    juego.cursor.y = 0; 

    return juego;
}

char inputUser (){

    char movimiento;

    do {scanf("%c", &movimiento);}
    while(movimiento != 'w' && movimiento != 'a' && movimiento != 's' && movimiento != 'd' && movimiento != ' ' && movimiento != 'q' );
    
    return movimiento;
}



void printTablero (tateti_t juego){
    system("clear");
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (j == juego.cursor.x && i == juego.cursor.y ){
                printf("%c", '*');
            } else {
                printf("%c", juego.tablero [i][j]);
            }
            if (j < 2){
                printf(" | ");
            } 
        }
        printf("\n");
        if(i < 2){
            printf("%s", "--+---+--");
        }    
        printf("\n");
    }

}

void insertarEnTablero(tateti_t *juego){
    char decision = 'x';
    if(juego->turn %2 != 0){
        decision = 'o';
    }
    juego->turn ++;
    juego->tablero [juego->cursor.y][juego->cursor.x] = decision;
}

void ejecutarMovimiento(char input, tateti_t *juego) {
    if(input == 'w'){ 
        (*juego).cursor.y--;
    } 
    if(input == 's'){ 
        (*juego).cursor.y++;
    }
    if(input == 'a'){ 
        (*juego).cursor.x--;
    }
    if(input == 'd'){ 
        (*juego).cursor.x++;
    }
    if(input == 'q'){
        exit(0);
    }
    // VUELVE
    if((*juego).cursor.x > 2) {
        (*juego).cursor.x = 0;
    }
    if((*juego).cursor.x < 0) {
        (*juego).cursor.x = 2;
    }
    if((*juego).cursor.y > 2) {
        (*juego).cursor.y = 0;
    }
    if((*juego).cursor.y < 0) {
        (*juego).cursor.y = 2;
    }

    if(input == ' '){
        insertarEnTablero(juego);
    }
}

int main (){

    tateti_t juego = nuevoTateti();
    while(true){
        printTablero(juego);
        char input = inputUser();
        ejecutarMovimiento(input, &juego);
    }

    return 0;
}







