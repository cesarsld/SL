#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fp, *fs;

int minrolls[500][7]={0}, a=0;                                                           /*minrolls[y] stores all the different combinations to finish the game in 7 rolls*/
int turn = 0, tokenposition[101] = {0}, t[101] = {0};                                    /*tokenposition[z] stores how many time the token landed on a specific square*/
int snakesandladders[19][2]={                                                            /*Initialising 2-dimensional snakesandladders to input the number of square your token moves if it lands on a snake or ladder */
               {1, 37},
               {4,10},
               {9,22},
               {21,21},
               {28,56},
               {36,8},
               {51,16},
               {71,20},
               {80,20},
               {16,-10},
               {47,-21},
               {49,-38},
               {56,-3},
               {62,-43},
               {64,-4},
               {87,-63},
               {93,-20},
               {95,-20},
               {98,-20}  
          };



void board(){
     int i=0;
     for (i=0;i<19;i++){
          t[snakesandladders[i][0]]=snakesandladders[i][1];                              /*Use of the 2D snakesandladders to create a single dimension snakesandladders that holds the value of snakes and ladders on their specific position*/
     }

}


void game() {
     int dv = 0, tp = 0;                                                                 /*dv is the die value, tp the current position of the token*/
     int b=0, i=0, u=0;                                                                  /*counters*/
               
     while (tp<=99){
          turn = turn+1;
          dv = rand()%6+1;                                                               /*random function added to simulate the properties of a 6-faced die*/
          tp = tp + dv;                                                                  /*Adds die value to the token position*/
          if(tp>100){                                                                    /* If command used here to come back to previous position of the token if it went above 100*/
               tp = tp - dv; 
               tokenposition[tp]--;                                                      /*decrement the position the token landed on because technically, the token didn't move*/
          }
          tp=tp+t[tp];                                                                   /*Moves token if it lands on a snake or ladder*/
          tokenposition[tp]++;                                                           /* increments by 1 the position on which the token landed*/
          if (turn<=7) {
               minrolls[a][b]=dv;                                                        /*Registers the first 7 rolls of the game*/
               b=b+1;
          }
     }

     if (turn ==7 && tp==100){                                                           /*If a game is finished in 7 rolls, increment a to store a new combinations of diw values on the next 7-roll win*/
          a++;
          for (i=0; i<a-1;i++){
               if (minrolls[i][0]==minrolls[a-1][0] && minrolls[i][1]==minrolls[a-1][1] && minrolls[i][2]==minrolls[a-1][2] && minrolls[i][3]==minrolls[a-1][3] && minrolls[i][4]==minrolls[a-1][4] && minrolls[i][5]==minrolls[a-1][5] && minrolls[i][6]==minrolls[a-1][6]) { 
                    a--;                                                                 /*if the most recent combination is a duplicate of a previous combination, decrement a to overwrite this combination*/
				
               }
          }
     }
     if(turn >7 && tp==100){                                                             /*if a game is finished in more than 7 rolls, reset current die values to 0*/
          for (u=0; u<7; u++){
               minrolls[a][u]=0;
          }
     }

}


int main() {
     srand(time(NULL));                                                                  /*use time as seed to make the random number generator as random as possible*/
     board();
     int c=50000000,j=0, likelysqr=0, leastsqr=0, r=0, s=100000000;                     /*c is the number of games simulated, avgames the mean value of number of rolls, likelysqr is the most common square and leastsqr, the least likely*/
     long avgames=0;                                                                     /*using a long int to allow putting all the different roll numbers*/
     int likelyroll=0, minimumroll=0, l=0, m=0;
     int rollnumber[500]={0};                                                            /*rollnumber[x] hold the number of times a game has finished in x rolls*/
     int p=0, h=0, q=0, z=0;                                                             /*counters*/
		
     for(j=0; j<c;j++){
          turn=0;                                                                        /*resets turn to 0*/
          game();
          avgames= avgames+turn;                                                         /*adds all the turns together*/
          rollnumber[turn]++;
     }
     printf("%ld\n", avgames);
     avgames=avgames/c;
     printf("average number of rolls is %ld\n", avgames);
     fs=fopen("position.txt", "w+");
     for (p=0; p<101;p++){
          if(r<tokenposition[p]){                                                        /*Finds the most likely square*/
               likelysqr=p; 
               r=tokenposition[p] ;
          if (s>tokenposition[p] && tokenposition[p]>0){                                 /*Finds the least common square*/
               leastsqr=p;
               s=tokenposition[p];
}

     }
         fprintf(fs,"%d %d\n", p, tokenposition[p]);                                     /*loads data to position.txt*/
     }
     fclose(fs);
     fp=fopen ("roll.txt", "w+");     
     printf("The most common square C is %d and the least common square is %d\n", likelysqr, leastsqr);
     for (h=1; h<451;h++){
          if(l<rollnumber[h]){                                                           /*Finds the most likely number of rolls*/
               likelyroll=h;
               l=rollnumber[h];
          }           
          fprintf(fp,"%d %d\n",h, rollnumber[h]);                                        /*loads data to roll.txt*/
     }
     fclose(fp);
     printf("the most likely number of roll is %d\n", likelyroll);
     
     for (z=0; z<500;z++) {	   
          for (q=0; q<7;q++) {
	          if(minrolls[z][q]>0){
                    m=z+1;
	          }
          }
     }
     printf("there are %d paths to finish the game in Nmin rolls", m);
};