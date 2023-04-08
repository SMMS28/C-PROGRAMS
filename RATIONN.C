we#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
struct ration_card {
    char holder_name[50];
    char card_number[20];
    
    char address[100];
    
    char city[50];
    char state[50];
    int no_of_family_members;
    int ration_given;

  
};

struct ration_card cards[100];
int card_count = 0;

void add_card()



{
    struct ration_card new_card;
    printf("Enter holder name: ");
    scanf("%s", new_card.holder_name);
    printf("Enter card number: ");
    scanf("%s", new_card.card_number);
    printf("Enter address: ");
    scanf("%s", new_card.address);
    printf("Enter city: ");
    scanf("%s", new_card.city);
    printf("Enter state: ");
    scanf("%s", new_card.state);
    printf("Enter number of family members: ");
    scanf("%d", &new_card.no_of_family_members);
    printf("Has ration been given (1 for yes, 0 for no): ");
    scanf("%d", &new_card.ration_given);
    cards[card_count++] = new_card;
    printf("Ration card added successfully!\n");
}

void display_ration_status(char* card_number)
{
    int card_index = -1;
    for(int i = 0; i < card_count; i++) {
        if(strcmp(cards[i].card_number, card_number) == 0) {
            card_index = i;
            break;
        }
    }
    if(card_index == -1) {
        printf("Invalid card number\n");
    } else {
        if(cards[card_index].ration_given) {
            printf("Ration has been given for card number %s\n", cards[card_index].card_number);
            printf("GIVEN ITEMS ARE :\n");
            printf("RICE      :  20 kgs \n");
            printf("SUGAR     :  05 kgs\n");
            printf("RED GRAM  :  02 kgs\n");
            printf("KEROSINE  :  05 lits\n");
        } else
         {
            printf("Ration has not been given for card number %s\n", cards[card_index].card_number);
        }
    }
}

int main()
{
    while(1) {
        time_t t;
        time(&t);
        printf("____________________________\n");
        printf("____________________________\n \n ");
        printf("WELCOME TO 26(A) WARD RATION SHOP \t    \t   \t   \t");
        printf("%s", ctime(&t));
        printf("SHOP TIMINGS MONDAY TO FRIDAY :\n");
        printf("10:00 AM TO 05:00 PM\n");
        printf("SHOP WILL BE CLOSED ON EVERY \nSATURDAYS AND SUNDAYS\n");
        printf("_________________\n");
        printf("OFFICER DETAILS \nNAME.     : P SANDEEP KUMAR \n");
        printf("DOB.      :28-08-1972\n");
        printf("AGE.      :50\n");
        printf("MOBILE NO : XXXXXXXXXX\n");
        printf("E-MAIL.   : sandeep@gmail.com\n");
        printf("_________________\n");
        printf("HOW MAY I HELP YOU \n");
        printf("1. Add ration card\n");
        printf("2. Check ration status\n");
        printf("3. Exit\n");
        printf("PLEASE ENTER YOUR CHOICE :");
        int choice;
        scanf("%d", &choice);
        if(choice == 1) {
            add_card();
        } else if(choice == 2) 
        {
            char card_number[20];
            printf("Enter card number: ");
            scanf("%s", card_number);
            display_ration_status(card_number);
        } else if(choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
