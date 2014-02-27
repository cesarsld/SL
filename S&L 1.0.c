#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int turn = 0, tokenposition[101] = {0};
void snakesandladders() {
     int i = 0, dv = 0, tp = 0, t[101] = {0};
          int array[19][2]={
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
     for (i=0;i<19;i++){
          t[array[i][0]]=array[i][1];
          }

     while (tp<=99){    
          if (turn>0){
               tokenposition[tp]=tokenposition[tp]+1;
          }
          turn = turn+1;
          dv = rand()%6+1;
          tp = tp + dv;
	      
          if(tp>100){
               tp = tp - dv;
               tokenposition[tp]=tokenposition[tp]-1;
          }
          tp=tp+t[tp];

          if (tp==100) {
               tokenposition[100]=tokenposition[100]+1;
          }
     }
	   
}
int main() {
     srand(time(NULL)); 
     int c=2000000,h=0,p=0 ,  avgames=0;
     int rollnumber[450]={0}, j=0;
		
     for(j=0; j<c;j++){
          turn=0;
          snakesandladders();
          avgames= avgames+turn;
          rollnumber[turn]=rollnumber[turn]+1;
     }
          avgames=avgames/c;

printf("average number of rolls is %d\n", avgames);
     for (p=0; p<101;p++){
	     printf("%d %d\n", p, tokenposition[p]);
          }

     for (h=1; h<451;h++){
          printf(" %d\n", rollnumber[h]);
          }

}