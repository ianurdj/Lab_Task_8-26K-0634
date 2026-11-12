
#include <stdio.h>

int main() {

    double cp, sp, q;        
    double tc, ts, pl, p;    //  total cost,totalselling,profitloss, percentage.

  
    double* ptrcp = &cp;
    double* ptrsp = &sp;
    double* ptrq = &q;

    double* ptrtc = &tc;
    double* ptrts = &ts;
    double* ptrpl = &pl;
    double* ptrp = &p;


    printf("Enter cost price: ");
    scanf("%lf", ptrcp);

    printf("Enter selling price: ");
    scanf("%lf", ptrsp);

    printf("Enter quantity sold: ");
    scanf("%lf", ptrq);

   
    *ptrtc = *ptrcp * *ptrq;
    *ptrts = *ptrsp * *ptrq;

    *ptrpl = *ptrts - *ptrtc;

   
    if (*ptrpl > 0) {
        printf("\nProfit = %.2lf\n", *ptrpl);
    }
    else if (*ptrpl < 0) {
        printf("\nLoss = %.2lf\n", -*ptrpl);
    }
    else {
        printf("\nNo profit no loss\n");
    }

   
    if (*ptrtc != 0) {
        *ptrp = (*ptrpl / *ptrtc) * 100;
        printf("Profit/Loss Percentage = %.2lf%%\n", *ptrp);
    }

  
    double *ptrl;

    if (*ptrcp > *ptrsp) {
        ptrl = ptrcp;
        printf("\npoints to Cost Price\n");
    }
    else {
        ptrl = ptrsp;
        printf("\npoints to Selling Price\n");
    }

    printf("Larger value = %.2lf\n", *ptrl);

   
    printf("\n---------- ADDRESS TABLE ----------\n");

    printf("Variable       Address\n");
    printf("cp             %p\n", (void*)&cp);
    printf("sp             %p\n", (void*)&sp);
    printf("q              %p\n", (void*)&q);
    printf("tc             %p\n", (void*)&tc);
    printf("ts             %p\n", (void*)&ts);
    printf("pl             %p\n", (void*)&pl);
    printf("p              %p\n", (void*)&p);

    printf("\nPointer        Address\n");
    printf("ptrcp          %p\n", (void*)&ptrcp);
    printf("ptrsp          %p\n", (void*)&ptrsp);
    printf("ptrq           %p\n", (void*)&ptrq);
    printf("ptrtc          %p\n", (void*)&ptrtc);
    printf("ptrts          %p\n", (void*)&ptrts);
    printf("ptrpl          %p\n", (void*)&ptrpl);
    printf("ptrp           %p\n", (void*)&ptrp);
    printf("ptrl           %p\n", (void*)&ptrl);

    return 0;
}

