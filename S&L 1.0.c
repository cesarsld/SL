#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); 
	int c=300000, avgames=0, p=0;
    int i=0, tp = 0, dv, turn=0, ttp=0;   //tp stands for the token position and dn the die value
	int tokenposition[100];
    int l1 = 1, l2 = 4, l3 = 9, l4 = 21, l5 = 28, l6 = 36, l7 = 51, l8 = 71, l9 = 80;
    int s1 = 16, s2 = 47, s3 = 49, s4 = 56, s5 = 62, s6 = 64, s7 = 87, s8 = 93, s9 = 95, s10 = 98;

	for(i=0; i<c;i++){
	tp=0;
	turn=0;
    while (tp<100){    
	if (turn>0){
		tokenposition[tp]=tokenposition[tp]+1;
	}
	turn = turn+1;
       dv = rand()%6+1;

       tp = tp + dv;

       ttp = tp - 100;

      
if(tp>100){
tp = 100- ttp;}



      if(tp==l1){
          tp = tp + 37;}
       else if (tp==l2) {
	      tp = tp + 10;
	
}
else if (tp==l3) {
	      tp = tp + 22;
	
}
else if (tp==l4) {
	      tp = tp + 21;
	
}
else if (tp==l5) {
	      tp = tp + 56;
	
}
else if (tp==l6) {
	      tp = tp + 8;
	
}
else if (tp==l7) {
	      tp = tp + 16;
	
}
else if (tp==l8) {
	      tp = tp + 20;
	
}
else if (tp==l9) {
	tp = tp +20;
	      goto someline;
	
}
else if (tp==s1) {
	      tp = tp - 10;
	
}
else if (tp==s2) {
	      tp = tp - 21;
	
}
else if (tp==s3) {
	      tp = tp - 38;
	
}
else if (tp==s4) {
	      tp = tp - 3;
	
}
else if (tp==s5) {
	      tp = tp - 43;
	
}
else if (tp==s6) {
	      tp = tp - 4;
	
}
else if (tp==s7) {
	      tp = tp - 63;
	
}
else if (tp==s8) {
	      tp = tp - 20;
	
}
else if (tp==s9) {
	      tp = tp - 20;
	
}
else if (tp==s10) {
	      tp = tp - 20;
	
}
else if (tp==100){
	goto someline;
}


    }  
        

someline:avgames= avgames+turn;
}
avgames=avgames/c;
printf("average number of rolls is %d\n", avgames);
for (p=0; p<100;p++){
	printf("%d = %d\n", p, tokenposition[p]);
}
}