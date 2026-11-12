#include <stdio.h>

void displayroute(){

    printf("======BOOK ME TRANSPORT========\n\n");
    printf("Route 1 - Karachi to Hyderabad = Rs 800\n");
    printf("Route 2 - Karachi to Sukkur    = Rs 2200\n");
    printf("Route 3 - Karachi to Multan    = Rs 3500\n");
}
int getroute(){
int num;
printf("Enter the route number: ");
scanf("%d", &num); 

if( num > 3 || num < 1){
        printf("Invalid Input!");
        return 0;
    }

return num;
}
int getseat(){
int seatnum;
    printf("Enter the number of seats you want to book (1-6) : ");
    scanf("%d", &seatnum);

    if( seatnum > 6 || seatnum < 1){
        printf("Invalid Input!");
        return 0;
    }
    return seatnum;
}
int getfare(int num){
  int fare = 0;
    switch (num){
  
        case 1: fare =  800;
        break;
       
        case 2: fare =  2200;
        break;
     
        case 3: fare = 3500;
        break;
    }
     return fare;
}
int gettotalfare(int num, int seatnum){
    int totalfare;
if(num == 1){
    totalfare = seatnum*800;
}
else if(num == 2){
    totalfare = seatnum*2200;
}
else{
    totalfare = seatnum*3500;
}
return totalfare;

}
float getamount(int totalfare, char seat){
    float  amount = totalfare;

switch (seat){
   
case'E':  
case 'e': {
        amount = amount + 0;
        break;
    }
   
case 'B': 
case 'b': {
        amount = amount +(amount * 0.3);
        break;
    }
    default:
        printf("Invalid Input");
        break;
        return 0;
    }

    return amount;
}
void printticket(int num, int seatnum,char seat, float amount, int fare){

    printf("\n==========TICKET==========\n\n");
    switch (num){
        case 1: printf("ROUTE NAME : KARACHI TO HYDERABAD\n");
        break;
        case 2: printf("ROUTE NAME : KARACHI TO SUKKUR\n");
        break;
        case 3: printf("ROUTE NAME : KARACHI TO MULTAN\n");
        break;
    }
printf("NUMBER OF SEATS BOOKED : %d\n",seatnum);

switch (seat){
   
case'E':  
case 'e': {
printf("SEAT TYPE : Economy\n");
        break;
    }
   
case 'B': 
case 'b': {

printf("SEAT TYPE : Business\n");
break;
}
}

printf("FARE FOR 1 SEAT : %d\n", fare);
printf("TOTAL FARE : %.2f\n\n", amount);
printf("==========================\n");

}



int main(){
float totalFare = 0;
    displayroute();
    for(int i = 1; i <= 2; i++){

    int routenum = getroute();
    int seatnum = getseat();

    int oneseat = getfare(routenum);
    int faretotal = gettotalfare(routenum,seatnum);

     char seatType;
        printf("Enter the seat type (E for Economy and B for Business): ");
        scanf(" %c", &seatType);

    float totalAmount= getamount(faretotal,seatType);

 printticket(routenum, seatnum, seatType, totalAmount,oneseat);

    totalFare = totalFare + totalAmount;
    }
    printf("TOTAL BUS EARNING : Rs %.2f", totalFare);



    return 0;
}