#include <stdio.h>

void displayroom(){

    printf("=====Together Care=====\n");
    printf("General Ward  = Rs 1500/day\n");
    printf("Semi Private  = Rs 3500/day\n");
    printf("Private       = Rs 6000/day\n");

}
int getroom(){
int room;
    printf("\nEnter the room type (1-3) : ");
    scanf("%d", &room);

    return room;
}
int getdays(){
    int days;
    printf("\nEnter the number of days you want to stay(1-30) : ");
    scanf("%d", &days);

    return days;
}
int roomcharges(int room, int days){
  int charges = 0;

switch(room){
  
    case 1 : 
    charges = 1500*days;
    break;
     case 2:
     charges = 3500*days;
     break;

     case 3 :
     charges = 6000*days;
     break;
}
     return charges;
}
float medicinebill(){

    float bill;

    printf("Enter the medicine bill: ");
    scanf("%f", &bill);

return bill;
}
float getservice(float bill){
   float servicecharge;

   servicecharge = bill + (bill * 0.05);

return servicecharge;
}
float getamount(int charges, float servicecharge){
    float amount= 0;
    amount = charges + servicecharge;

    return amount;
}

float getdiscount(int days, float amount ){

 float discount =0;

 if( days >= 7){
 discount = (amount * 0.08);}
else{
    discount = 0;
}

 return discount;
}
float gettotal(float amount, float discount){
    float totalAmount;
    totalAmount = amount - discount;
    return totalAmount;
}
void printbill(int room,int days,int charges,float servicecharge,float totalAmount,float discount, float bill,int ask){
   
    printf("\n==========BILL SLIP==========\n");
switch(room){
  
    case 1 : printf("ROOM NAME : GENERAL WARD\n"); 
    break;
     case 2: printf("ROOM NAME : SEMI PRIVATE\n"); 
     break;
     case 3 :printf("ROOM NAME : PRIVATE\n"); 
     break;
}
    printf("Days Staying : %d\n", days);
    switch(room){
  
    case 1 : printf("Room charges :  Rs 1500\n");
    break;
    case 2: printf("Room charges  : Rs 3500\n"); 
    break;
    case 3 :printf("Room charges  : Rs 6000\n");
    break;
}
   
      printf("Medicines bill : Rs %.2f\n",bill);
      printf("Service Charges : 5%%\n");
      printf("Medicine bill + Service Charges : Rs %.2f\n", servicecharge);
      if ( discount > 0){
      printf("Discount : Rs %.2f\n", discount);}
      if ( ask == 1){ printf("Discount on being a senior citizen : Rs 1000\n");}
       printf("Total Amount : Rs %.2f\n", totalAmount );
        
}

int main(){
    int ask;
displayroom();
int room = getroom();
int days = getdays();
int Charges = roomcharges(room, days);
float bill = medicinebill();
float Service_Charges = getservice(bill);
float Amount = getamount(Charges, Service_Charges); 
float discount = getdiscount(days, Amount);
float totalAmount = gettotal(Amount, discount);

printf("Is the Patient Senior Citizen? ( 1 for Yes, 2 For No) : ");
scanf("%d", &ask);

if ( ask == 1){ totalAmount = totalAmount - 1000;}
else if ( ask == 2){
    totalAmount = totalAmount;
}
printbill(room,days,Charges,Service_Charges,totalAmount,discount,bill,ask);


    return 0;
}