#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {


    srand(time(NULL)); 
	int c=2000000, avgames=0, p=0, min_turns=100, max_turns=1, h=0;
    int i=0, tp = 0, dv, turn=0, ttp=0;   //tp stands for the token position and dn the die value
	int tokenposition[101]={0}, rollnumber[600]={0};
    int l1 = 1, l2 = 4, l3 = 9, l4 = 21, l5 = 28, l6 = 36, l7 = 51, l8 = 71, l9 = 80;
    int s1 = 16, s2 = 47, s3 = 49, s4 = 56, s5 = 62, s6 = 64, s7 = 87, s8 = 93, s9 = 95, s10 = 98;

	for(i=0; i<c;i++){
	tp=0;
	turn=0;
    while (tp<=99){    
	if (turn>0){
		tokenposition[tp]=tokenposition[tp]+1;
	}
	turn = turn+1;
       dv = rand()%6+1;

       tp = tp + dv;

       ttp = tp - 100;

      
if(tp>100){
tp = tp - dv;}



      if(tp==l1){
          tp = tp + 37;}
       if (tp==l2) {
	      tp = tp + 10;
	
}
if (tp==l3) {
	      tp = tp + 22;
	
}
if (tp==l4) {
	      tp = tp + 21;
	
}
if (tp==l5) {
	      tp = tp + 56;
	
}
if (tp==l6) {
	      tp = tp + 8;
	
}
if (tp==l7) {
	      tp = tp + 16;
	
}
if (tp==l8) {
	      tp = tp + 20;
	
}
if (tp==l9) {
	
	tp = tp +20;
	
	  
	
}
if (tp==s1) {
	      tp = tp - 10;
	
}
if (tp==s2) {
	      tp = tp - 21;
	
}
if (tp==s3) {
	      tp = tp - 38;
	
}
if (tp==s4) {
	      tp = tp - 3;
	
}
if (tp==s5) {
	      tp = tp - 43;
	
}
if (tp==s6) {
	      tp = tp - 4;
	
}
if (tp==s7) {
	      tp = tp - 63;
	
}
if (tp==s8) {
	      tp = tp - 20;
	
}
if (tp==s9) {
	      tp = tp - 20;
	
}
if (tp==s10) {
	      tp = tp - 20;
	
}

if (tp==100) {
	
	tokenposition[100]=tokenposition[100]+1;
}
    }  
   

someline:avgames= avgames+turn;
if(turn<min_turns){
    min_turns=turn;}
   if(turn>max_turns){
	max_turns=turn;
}
rollnumber[turn]=rollnumber[turn]+1;
}
avgames=avgames/c;

printf("average number of rolls is %d\n", avgames);
for (p=0; p<101;p++){
	printf(" %d\n",  tokenposition[p]);
		
}
printf("Minimum turns to finish the game is %d and maximum turns is %d", min_turns, max_turns);
for (h=0; h<601;h++){
		printf(" %d\n", rollnumber[h]);
		}
	

}