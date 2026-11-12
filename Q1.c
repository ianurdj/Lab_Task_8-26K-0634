#include <stdio.h>
void displaypacks(){
    printf("MOBILE RECHARGE\n");
    printf("1 - 100\n2 - 200\n3 - 500\n4 - 1000.\n");
}
int getpack(){
    int pack;

     printf("Enter the pack: ");
     scanf("%d", &pack);
     if(pack < 1 || pack > 4){printf("Invalid Input"); return 0;}

     return pack;
}
long long getmobile(){
    long long num;
    printf("Enter the mobile number ( 11 digit ) : ");
    scanf("%lld", &num);
return num;
}

int getamount(int pack){

    switch(pack){
        case 1: 
        return 100;

        case 2: return 200;

        case 3: return 500;

        case 4: return 1000;
    }

}
float gettax(int amount){
     
    float tax;
    tax = amount * 0.15;
    return tax;  
}
float getbonus(int amount){
    float bonus;
if ( amount >= 500)
bonus = (amount * 0.10);

else {
    bonus = 0;
}
return bonus;
}
void slip(long long mobile, int amount, float tax, float bonus){


printf("Mobile number : %lld\n", mobile);
printf("Recharge amount : %d\n", amount);
printf("Tax : %.2f\n", tax);
if ( bonus > 0){
printf("bonus : %.2f\n", bonus);}
printf("Total balance : %.2f\n", amount + bonus);
printf("Total money charged : %.2f\n", amount + tax);

}
int main(){
     displaypacks();
float totalSpent = 0;
     for(int i=1; i<=3; i++){
         printf("\n========== RECHARGE %d ==========\n", i);

    int pack = getpack();
 long long mobile = getmobile();
 int amount = getamount(pack);
 float tax = gettax(amount);
 float bonus = getbonus(amount);
 slip(mobile, amount, tax, bonus);

    totalSpent = totalSpent + amount + tax;
    
    if(i == 3)
        {
            printf("\nYou have reached the maximum recharge limit!\n");
            break;
        }
int choice;
        printf("\nDo you want another recharge?\n");
        printf("1. Yes\n");
        printf("2. Exit\n");
        printf("Enter choice ( 1 - 2): ");
        scanf("%d", &choice);

        if(choice == 2)
        {
            break;
        }
    }

    printf("\n========== FINAL SUMMARY ==========\n");
    printf("Total Money Spent: Rs. %.2f\n", totalSpent);

    return 0;
}