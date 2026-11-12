#include <stdio.h>

void displayrule(){

    printf("\n======PEARL CAB SERVICES ========\n\n");
    printf("Base Fare                = Rs 150\n");
    printf("Fare/km for first 10km   = Rs 60\n");
    printf("Fare/km after 10km       = Rs 45\n");
}

int getdistance()
{
int distance;
printf("\nEnter the distance in km(1-200): ");
scanf("%d", &distance); 

if( distance > 200 || distance < 1){
        printf("Invalid Input!");
        return 0;;
    }

return distance;
}

int getmins()
{
int mins;
    printf("Enter the waiting time in minutes (0-120) : ");
    scanf("%d", &mins);

    if( mins > 120 || mins < 0){
        printf("Invalid Input!");
        return 0;
    }
    return mins;
}

int getcharge(int distance)
{
  int charge ;
    if( distance > 0 && distance <= 10){
        charge = distance * 60;
    }
    else{
        charge = distance * 45;
    }
     return charge;
}
int getwaiting(int mins){
    int waitingcharge;

if(mins>0 && mins <=5){
    waitingcharge = 0;
}

else{
    waitingcharge = mins*10;
}
return waitingcharge;
}

float getamount(int charge, int waitingcharge)
{
    float  amount = charge + waitingcharge;
    return amount;
}


float getnight(float amount){
int hour;
float fare = 0;
    printf("Enter the hour of trip (0-23) : ");
    scanf("%d", &hour);

    if( hour > 23 || hour < 0){
        printf("Invalid Input!");
        return 0;
    }
    else if( hour == 22 || hour == 23 || hour <6 ){
        fare = amount + (amount * 0.25);
    }
    else{
        fare = amount;
    }
    return fare;
}

void printreceipt(int distance, int mins , float amount){

    printf("\n==========RECEIPT==========\n\n");

printf("DISTANCE : %dkm\n", distance);
printf("WAITING TIME (in mins): %d\n", mins);
printf("TOTAL FARE : %.2f\n\n", amount);
printf("\n===========================\n");

}

int main(){
float totalFare = 0;
float highestfare=0;
    displayrule();
    for(int i = 1; i <= 3; i++){

    int Distance = getdistance();
    int Minutes= getmins();
    int Charge = getcharge(Distance);
    int WaitingCharge = getwaiting(Minutes);
    float totalAmount= getamount(Charge,WaitingCharge);
 printreceipt(Distance, Minutes,totalAmount);

    totalFare = totalFare + totalAmount;
    if(totalAmount > highestfare){
        highestfare  = totalAmount;
    }

    }
      printf("\n=====================================\n");
    printf("\nTOTAL EARNING : Rs %.2f\n", totalFare);
    printf("HIGHEST EARNING OF THE DAY: Rs %.2f", highestfare);
    printf("\n=====================================");
    return 0;
}