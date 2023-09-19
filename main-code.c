#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[5][5]; //mp = move player.
int n = 3, win1, win2, tk, starter, tp; //tk = tedad nobataye computer.
int mp[3], mc[3]; //move playe & move computer.
int temp = 0, turn;

void input() {
    int xxx;
    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            a[i][j] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            printf("%d | ",a[i][j]);
        }
        printf("%d\n", a[i][n]);
    }
    printf("press 0 to start the game\n");
    scanf("%d", &xxx);
}

void Chek_Ofoghi() {
    int meghdar = 0, arzesh = 0;
    for (int i = 1; i <= n; i++) {
        int j = 1, bool = 1;
        while (bool == 1 && j <= n - 1) {
            if (a[i][j] != a[i][j + 1])
                bool = 0;
            else
                j++;
        }
        if (bool == 1) {
           meghdar = a[i][1];
           arzesh = 1;
           break;
        }
    }
    if (arzesh == 1 && meghdar == 1)
        win1 = 1;
    else if (arzesh == 1 && meghdar == 2)
        win2 = 1;
}

void Chek_Amodi() {
    int meghdar = 0, arzesh = 0;
    for (int i = 1; i <= n; i++) {
        int j = 1, bool = 1;
        while (bool == 1 && j <= n - 1) {
            if (a[j][i] != a[j + 1][i])
                bool = 0;
            else
                j++;
        }
        if (bool == 1) {
           meghdar = a[1][i];
           arzesh = 1;
           break;
        }
    }
    if (arzesh == 1 && meghdar == 1)
        win1 = 1;
    else if (arzesh == 1 && meghdar == 2)
        win2 = 1;
}

void Chek_Ghotr_Asli() {
    int bool = 1;
    for (int i = 1; i <= n - 1; i ++) 
        if (a[i][i] != a[i + 1][i + 1])
            bool = 0;
    
    if (bool == 1 && a[1][1] == 1)
        win1 = 1;
    else if (bool == 1 && a[1][1] == 2)
        win2 = 1;
}

void Chek_Ghotr_Faree() {
    int bool = 1;
    int i = 1;
    int j = n;
    while (i <= n - 1 && j > 0 && bool != 0) {
        if (a[i][j] != a[i + 1][j - 1])
            bool = 0;
        else {
            i++;
            j--;
        }
    }
    if (bool == 1 && a[1][n] == 1)
        win1 = 1;
    else if (bool == 1 && a[1][n] == 2)
        win2 = 1;
}

void check() {
    Chek_Amodi();
    Chek_Ofoghi();
    Chek_Ghotr_Asli();
    Chek_Ghotr_Faree();
}

void play_computer() {
    tk++;
    if (starter == 0) { // computer shro mikone.
        int mv3;
        if (tk == 1) {
           a[2][2] = 2;
        }
        if (tk == 2) {
            switch(mp[0]) {
                case 11:
                a[1][2] = 2;
                mc[2] = 32;
                break;
               
                case 12:
                a[1][3] = 2;
                mc[2] = 31;
                break;
               
                case 13:
                a[1][2] = 2;
                mc[2] = 32;
                break;
               
                case 21:
                a[1][1] = 2;
                mc[2] = 33;
                break;
               
                case 23:
                a[1][3] = 2;
                mc[2] = 31;
                break;
               
                case 31:
                a[3][2] = 2;
                mc[2] = 12;
                break;
               
                case 32:
                a[3][3] = 2;
                mc[2] = 11;
                break;
               
                case 33:
                a[3][2] = 2;
                mc[2] = 12;
                break;
           } 
       }
        if (tk == 3) {
            int x = mc[2] / 10;
            int y = mc[2] % 10;
            if (a[x][y] == 0) {
                a[x][y] = 2;
                temp++; //bazi tamome;
            }
            else {
                if (a[1][1] == 0)
                    a[1][1] = 2;
                else if (a[1][2] == 0)
                    a[1][2] = 2;
                else if (a[1][3] == 0)
                    a[1][3] = 2;
                else if (a[2][1] == 0)
                    a[2][1] = 2;
            }
       }
   }
   
    else if (starter == 1){ // player shro karde.
        if (tk == 1) {
            if (a[2][2] == 0) 
                a[2][2] = 2;
            else
                a[3][2] = 2;
        }
        if (tk == 2) {
            if (a[2][2] == 1) {
                switch(mp[1]) {
                    case 11:
                    a[3][3] = 2;
                    break;
                   
                    case 12:
                    a[3][3] = 2;
                    break;
                   
                    case 13:
                    a[3][1] = 2;
                    break;
                   
                    case 21:
                    a[2][3] = 2;
                    break;
                   
                    case 23:
                    a[2][1] = 2;
                    break;
                   
                    case 31:
                    a[1][3] = 2;
                    break;
                   
                    case 32:
                    a[1][2] = 2;
                    break;
                   
                    case 33:
                    a[1][1] = 2;
                    break;
                } 
            }
            else if (a[2][2] == 2) {
                switch(mp[1]) {
                    case 11:
                        if (a[1][2] == 1)
                            a[1][3] = 2;
                        else if (a[1][3] == 1)
                            a[1][2] = 2;
                            
                        else if (a[2][1] == 1) 
                            a[3][1] = 2;
                        else if (a[3][1] == 1)
                            a[2][1] = 2;
                    break;
                    
                    case 13:
                        if (a[1][2] == 1)
                            a[1][1] = 2;
                        else if (a[1][1] == 1)
                            a[1][2] = 2;
                            
                        else if (a[2][3] == 1) 
                            a[3][3] = 2;
                        else if (a[3][3] == 1)
                            a[2][3] = 2;
                        break;
                    case 31:
                        if (a[1][1] == 1)
                            a[2][1] = 2;
                        else if (a[2][1] == 1)
                            a[1][1] = 2;
                            
                        else if (a[3][2] == 1) 
                            a[3][3] = 2;
                        else if (a[3][3] == 1)
                            a[3][2] = 2;
                        break;
                    case 33:
                        if (a[1][3] == 1)
                            a[2][3] = 2;
                        else if (a[2][3] == 1)
                            a[1][3] = 2;
                            
                        else if (a[3][1] == 1) 
                            a[3][2] = 2;
                        else if (a[3][2] == 1)
                            a[3][1] = 2;
                        break;  
                    case 12:
                        if (a[1][1] == 0)
                            a[1][1] = 2;
                        else
                            a[1][3] = 2;
                    break;
                   
                    case 21:
                    if (a[1][1] == 0)
                            a[1][1] = 2;
                        else
                            a[3][1] = 2;
                    break;
                   
                    case 23:
                    if (a[1][3] == 0)
                            a[1][3] = 2;
                        else
                            a[3][3] = 2;
                    break;
                   
                   
                    case 32:
                    if (a[3][1] == 0)
                            a[3][1] = 2;
                        else
                            a[3][3] = 2;
                    break;
                } 
            }
        }
        if (tk == 3) {
            if (a[2][2] == 1) {
                if (a[3][1] == 0)
                    a[3][1] = 2;
                else if (a[1][2] == 0)
                    a[1][2] = 2;
                else if (a[1][3] == 0)
                    a[1][3] = 2;
                else if (a[2][1] == 0)
                    a[2][1] = 2;
            }
            else if(a[2][2] == 2) {
                if (a[1][1] == 2 && a[3][3] == 0)
                    a[3][3] = 2;
                else if (a[3][3] == 2 && a[1][1] == 0)
                    a[1][1] = 2;
                else if (a[1][2] == 2 && a[3][2] == 0)
                    a[3][2] = 2;
                else if (a[3][2] == 2 && a[1][2] == 0)
                    a[1][2] = 2;
                else if (a[1][3] == 2 && a[3][1] == 0)
                    a[3][1] = 2;
                else if (a[3][1] == 2 && a[1][3] == 0)
                    a[1][3] = 2;
                else if (a[2][1] == 2 && a[2][3] == 0)
                    a[2][3] = 2;
                else if (a[2][3] == 2 && a[2][1] == 0)
                    a[2][1] = 2;
                else {
                    if (a[1][1] == 0)
                        a[1][1] = 2;
                    else if (a[1][2] == 0)
                        a[1][2] = 2;
                    else if (a[1][3] == 0) 
                        a[1][3] = 2;
                    else if(a[2][1] == 0)
                        a[2][1] = 2;
                    else if (a[2][3] == 0)
                        a[2][3] = 2;
                    }
            }
        }
   }
   //system("clear");
   for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            printf("%d | ",a[i][j]);
        }
        printf("%d\n", a[i][n]);
    }
}

void play_player() {
    printf("inter two number : ");
    int x,y;
    scanf("%d %d", &x, &y);
    //system("clear");
    if (a[x][y] == 0) {
        a[x][y] = 1;
        mp[tp] = (10 * x) + y;
        tp++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - 1; j++) {
                printf("%d | ",a[i][j]);
            }
            printf("%d\n", a[i][n]);
        }
    }
    else {
        printf("your numbers are incorrect\n");
        play_player();
    }
    
}

void Play_Game() {
	turn = clock();
	starter = turn % 2; // if starter == 0 ---> computer shro mikone   &&   if starter == 1 ---> player shro mikone.
	if (starter == 0) 
	    printf("coumputer started the game\n");
	else
	    printf("player start the game\n");
    while (temp < 6) {
        if (turn % 2) 
            play_player();
        else
            play_computer();
        temp++;
        turn++;
    }
}

void output() {
    //system("clear");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            printf("%d | ",a[i][j]);
        }
        printf("%d\n", a[i][n]);
    }
    if (win1 == 1) 
        printf("Winner is player");
    else if (win2 == 1)
        printf("Winner is coumputer");
    else
        printf("Draw");
}

int main()
{
    input();
    Play_Game();
    check();
    output();
	return 0;
}
