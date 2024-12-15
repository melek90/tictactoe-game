#include <stdio.h>
#include <stdlib.h>
#define max 100
#include <time.h>
#include <stdbool.h>


bool winner(char m[3][3], char c) {

    for (int i = 0; i < 3; i++) {
        if ((m[i][0] == c && m[i][1] == c && m[i][2] == c) ||
            (m[0][i] == c && m[1][i] == c && m[2][i] == c)) {
            return true;
        }
    }
    if ((m[0][0] == c && m[1][1] == c && m[2][2] == c) ||
        (m[0][2] == c && m[1][1] == c && m[2][0] == c)) {
        return true;
    }
    return false;
}




void saisie(char m[3][3],char name[max]){
    int x,y,i,j,h,c=0;
    srand(time(NULL));
    h=rand()%2;
    while(c<9){
    if(h==1){
        puts(name);
        printf("turn \n");
        do{
        printf("donner ligne(0-2)");
        scanf("%d",&x);
        printf("donner colone(0-2)");
        scanf("%d",&y);


        }while(m[x][y]!=' ');
         m[x][y]='X';
         if (winner(m,'X')){
            printf("\n%s is the winner!\n", name);
            for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf(" %c ", m[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("---|---|---\n");
        }
            return;
         }

         h=0;



    }
    else{
        printf("pc turn ; \n");
        do{
            x=rand()%3;
            y=rand()%3;
        }while(m[x][y]!=' ');
        m[x][y]='O';
            if (winner(m, 'O')) {
                printf("\nPC is the winner!\n");
            for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf(" %c ", m[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("---|---|---\n");
        }
                return;
            }
        h=1;
    }

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf(" %c ", m[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("---|---|---\n");
        }
c++;

}printf("its a draw try again \n");}



int main(){
    int a,b;
    char m[3][3],name[max];
    for(a=0;a<3;a++){
        for(b=0;b<3;b++){
            m[a][b]=' ';
        }
    }
    printf("***************** \n");
    printf("donner votre nom;");
    gets(name);
    saisie(m,name);




    return 0;
}
