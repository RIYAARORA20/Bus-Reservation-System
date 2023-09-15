#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct BinarySearchTree BST;

struct BinarySearchTree {
    int PassnNo; // busNo0SeatNo.
    char name[10];
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
};

BST *root = NULL;

int cost(BST *r); // calculates costs
void status(); // shows bus and seats status
void busLists(); // shows buslist and do booking seat and return customer ID
void DisplaySeat(int bus[33]); // Display the seats of buses
void cancel(int x); // cancel the booking
BST *reservationInfo(BST *, int, int *); // Display Reservation Info
BST *insert(BST **r, int custID); // inserting a node

int busSeat[32][9] = {0};

BST *reservationInfo(BST *r, int s, int *custIDmatched) {
    if (r == NULL)
        return NULL;
    BST *presentnode = r;
    while (presentnode) {
        if (presentnode->PassnNo == s) {
            *custIDmatched = 1;
            printf("\n-----------------------------------------------------------------");
            printf("\n||              NAME: %10s                               ||", (presentnode->name));
            printf("\n||              CUSTOMER ID: %d                              ||", presentnode->PassnNo);
            printf("\n||              BUS NUMBER: %d                                  ||", (presentnode->PassnNo) / 1000);
            printf("\n||              SEAT NUMBER: %d                                 ||", (presentnode->PassnNo) % 100);
            printf("\n||              TICKET COST: Rs.%d                             ||", cost(presentnode));
            printf("\n-----------------------------------------------------------------");
            getchar(); // Wait for user input
            return r;
        } else if (presentnode->PassnNo > s)
            presentnode = presentnode->left;
        else
            presentnode = presentnode->right;
    }
    return NULL;
}

BST *insert(BST **r, int custId) {
    if (*r == NULL) {
        *r = (BST *)malloc(sizeof(BST));
        (*r)->PassnNo = custId;
        if (*r == NULL) {
            printf("No memory\n");
            return NULL;
        } else {
            (*r)->left = (*r)->right = NULL;
            printf("\n   ENTER THE PERSON NAME: ");
            scanf("%s", (*r)->name);
        }
    } else {
        if ((*r)->PassnNo > custId) {
            (*r)->left = insert(&((*r)->left), custId);
        } else if ((*r)->PassnNo < custId) {
            (*r)->right = insert(&((*r)->right), custId);
        }
    }
    return *r;
}

void DisplaySeat(int bus[33]) {
    int i;
    for (i = 1; i <= 32; i++) {
        if (i < 10 && i > 0) {
            printf("0%d .", i);
        } else {
            printf("%d .", i);
        }
        {
            if (bus[i] == 0)
                printf("EMPTY ");
            else
                printf("BOOKED"); // reservation
        }
        printf("         ");
        if (i % 4 == 0)
            printf("\n");
    }
}

void login() {
    char userName[20] = "user";
    char passWord[10] = "team18";
    char matchPass[10];
    char matchUser[10];
    int value;
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION");
    printf("\n\n=========================================================================================\n\n");
    do {
        printf("\n\nUserName: ");
        scanf("%s", matchUser);

        printf("\nPassWord: ");
        scanf("%s", matchPass);

        value = strcmp(passWord, matchPass);
        if (value != 0) {
            printf("\nINVALID DETAILS TRY AGAIN...\n");
        } else {
            printf("\nLOGGED IN SUCCESSFULLY...\n");
            break;
        }
    } while (1);
}

int cost(BST *r) {
    int cost, buscost;
    buscost = (r->PassnNo) / 1000;
    switch (buscost % 3) {
        case 1:
            return 70;
        case 2:
            return 55;
        case 0:
            return 40;
        default:
            return 0;
    }
}

void status() {
    int busNum;
    busLists();
    do {
        printf("\n\nENTER YOUR BUS NUMBER : ");
        scanf("%d", &busNum);
        if (busNum <= 0 || busNum >= 10) {
            printf("\n  PLEASE ENTER CORRECT BUS NUMBER !!\n");
        } else {
            printf("\n");
            DisplaySeat(busSeat[busNum]);
            break;
        }
    } while (1);
}

void busLists() {
    printf("-----------------------------------------------------------------------------------------");
    printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
    printf("-----------------------------------------------------------------------------------------");
    printf("\n1\tGangaTravels         \tDharan to Kavre       \tRs.70   \t\t07:00  AM");
    printf("\n2\tPhaphara Travels     \tKavre To Dharan       \tRs.55    \t\t01:30  PM");
    printf("\n3\tShiv Ganga Travels   \tAllahabad To Gorakhpur\tRs.40    \t\t03:50  PM");
    printf("\n4\tSuper Deluxe         \tPokhara To Benigha    \tRs.70    \t\t01:00  AM");
    printf("\n5\tSai Baba Travels     \tMaitidevi To Janakpur \tRs.55    \t\t12:05  AM");
    printf("\n6\tShine On Travels     \tMadhubani to Patna    \tRs.40    \t\t09:30  AM");
    printf("\n7\tMayur Travels        \tPatna To Gaya         \tRs.70   \t\t11:00  PM");
    printf("\n8\tRajjo Travels       \tBegusarai To Patna     \tRs.55    \t\t08:15  AM");
    printf("\n9\tShree Travels        \tGaya To Chhapra       \tRs.40    \t\t04:00  PM");
    printf("\n");
    printf("\n   PRESS 'ENTER' KEY TO CONTINUE ");
    getchar(); // Wait for user input
}

void cancel(int randomNum) {
    int reservationNo;
    int seatNumber;
    int choice;
    char c;
    int seatCancel;
    do {
        printf("\nENTER YOUR RESERVATION NUMBER : ");
        scanf("%d", &reservationNo);
        if (reservationNo == randomNum) {
            printf("\nRESERVATION NUMBER IS IT CORRECT ? %d \nENTER (Y/N) : ", reservationNo);
            scanf(" %c", &c);
            if (c == 'y' || c == 'Y') {
                printf("\n\n============================================\n\n");
                printf("   ENTER THE BUS NUMBER: ");
                scanf("%d", &choice);

                printf("\n HOW MANY SEATS DO WANT TO CANCEL : ");
                scanf("%d", &seatCancel);
                int i;
                for (i = 0; i < seatCancel; i++) {
                    printf("   \nENTER THE SEAT NUMBER: ");
                    scanf("%d", &seatNumber);

                    busSeat[choice][seatNumber] = 0;
                }
                printf("\n\nYOUR RESERVATION HAS BEEN CANCELLED !!\n\n");
                printf("\n  PRESS 'ENTER' KEY TO CONTINUE \n");
                getchar(); // Wait for user input
                DisplaySeat(busSeat[choice]);
                break;
            } else if (c == 'n' || c == 'N') {
                printf("\nYOUR RESERVATION CANCELLATION HAS BEEN DENIED\n");
                break;
            }
        } else {
            printf("\nNOT FOUND!! ENTER THE CORRECT RESERVATION NUMBER\n");
        }
    } while (1);
}

int main() {
    srand(time(0));
    int randomNum = rand();
    int num, i, custID, reservationNo;
    BST *root1;
    login();
    do {
        printf("\n\n====================================================================\n\n");
        printf("\t\t\tBUS RESERVATION\t\t");
        printf("\n\n=====================================================================\n");
        printf("\n====================");
        printf("  MAIN MENU ");
        printf("=====================\n\n");
        printf("   [1] VIEW BUS LIST \n\n");
        printf("   [2] BOOK TICKETS\n\n");
        printf("   [3] CANCEL BOOKING\n\n");
        printf("   [4] BUSES SEATS INFO\n\n");
        printf("   [5] RESERVATION INFO\n\n");
        printf("   [6] EXIT\n");
        printf("\n=====================================================\n");
        printf("\n   ENTER YOUR CHOICE: ");
        scanf("%d", &num);
        switch (num) {
            case 1:
                busLists();
                break;
            case 2:
                busLists();

                int CustId, choice, seats;

            busChoice:
                printf("\n\nCHOOSE YOUR BUS  : ");
                scanf("%d", &choice);
                if (choice <= 0 || choice > 9) {
                    printf("\nENTER VALID BUS NUMBER !! \n");
                    getchar(); // Wait for user input
                    goto busChoice;
                }
                printf("\n");
                DisplaySeat(busSeat[choice]);
            busSeatChoice:
                printf("\n\nNO. OF SEATS YOU NEED TO BOOK : ");
                scanf("%d", &seats);
                if (seats <= 0) {
                    printf("\nENTER VALID SEAT NUMBER!!\n");
                    getchar(); // Wait for user input
                    goto busSeatChoice;
                } else if (seats > 32) {
                    printf("\nENTER VALID SEAT NUMBER WE HAVE ONLY 32 SEATS IN A BUS !!\n");
                    getchar(); // Wait for user input
                    goto busSeatChoice;
                }
                int seatNumber;
                for (i = 1; i <= seats; i++) {
                    printf("\n\n==================================================================================\n\n");
                seat:
                    printf("   ENTER THE SEAT NUMBER: ");
                    scanf("%d", &seatNumber);
                    if (seatNumber <= 0) {
                        printf("\n   ENTER VALID SEAT NUMBER!!\n\n");
                        getchar(); // Wait for user input
                        goto seat;
                    } else if (seatNumber > 32) {
                        printf("\n   ENTER VALID SEAT NUMBER WE HAVE ONLY 32 SEATS IN A BUS !!\n\n");
                        getchar(); // Wait for user input
                        goto seat;
                    }
                    CustId = choice * 1000 + seatNumber; // Customer ID
                    busSeat[choice][seatNumber] = 1;
                    root = insert(&root, CustId);
                    printf("\n   YOUR CUSTOMER ID IS : %d", CustId);
                    printf("\n\n==================================================================================\n\n");
                }
                printf("\nYOUR RESERVATION NUMBER IS : %d\n", randomNum);
                printf("\nPLEASE NOTE DOWN YOUR RESERVATION NUMBER FOR CANCEL BOOKING TICKETS!!\n");
                printf("PRESS 'ENTER' KEY TO CONTINUE ");
                getchar(); // Wait for user input
                break;

            case 3:
                cancel(randomNum);
                break;
            case 4:
                status();
                break;
            case 5:
            takingReservationNo:
                printf("\n   ENTER YOUR RESERVATION NUMBER :");
                scanf("%d", &reservationNo);

                if (randomNum == reservationNo) {
                cust:
                    printf("\n   ENTER YOUR CUSTOMER ID :");
                    scanf("%d", &custID);
                    int custIDmatched = 0;
                    root1 = reservationInfo(root, custID, &custIDmatched);
                    if (custIDmatched == 0) {
                        printf("\n   ENTER CORRECT CUSTOMER ID!!\n");
                        goto cust;
                    }
                } else {
                    printf("\n INVALID RESERVATION NUMBER PLEASE ENTER CORRECT RESERVATION NUMBER !!\n");
                    goto takingReservationNo;
                }
                break;
            case 6:
                printf("\n\n=====================================================================\n\n");
                printf("THANK YOU FOR USING THIS BUS RESERVATION SYSTEM");
                printf("\n\nPRESS ANY KEY TO EXIT THE PROGRAM !! \n");
                getchar(); // Wait for user input
                exit(0);
            default:
                printf("\n\n   INVALID INPUT CHOOSE CORRECT OPTION\n");
                break;
        }
    } while (1);

    return 0;
}

