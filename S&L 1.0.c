#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//int snakesandladders(){
	
//}
int main() {


    srand(time(NULL)); 
	int c=2000000, avgames=0, p=0, min_turns=100, max_turns=1, h=0, q=0, w=0;
    int i=0, tp = 0, dv, turn=0, ttp=0;   //tp stands for the token position and dn the die value
	int tokenposition[101]={0}, rollnumber[450]={0};
    int t[101]={0};
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
	{98,-20}   };
for (w=0;w<19;w++){
		t[array[w][0]]=array[w][1];
	
	}
	
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

tp=tp+t[tp];


if (tp==100) {
	
	tokenposition[100]=tokenposition[100]+1;
}
    }  
   

avgames= avgames+turn;
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
	printf(" yop %d %d\n", p, tokenposition[p]);
		
}
printf("Minimum turns to finish the game is %d and maximum turns is %d\n", min_turns, max_turns);
for (h=1; h<451;h++){
		printf(" %d\n", rollnumber[h]);
		}

}