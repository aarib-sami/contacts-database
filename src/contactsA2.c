#include "../include/givenA2.h"

/*
Student Name: Aarib Sami
Student ID: 1270732
Due Date: March 8th, 2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

// Is main function that goes through a loop, giving user options to enter. Each option corresponds to a function.
int main(int argc, char* argv[])
{
    int choice;
    int keyId = -1;

    createContacts(argv[1]);

    do
    {
        printf("Enter a choice:\n");
        printf("1 to print, 2 to search, 3 to create more, -1 to exit: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n");
            readContacts(argv[1]);
            break;
        case 2:
            keyId = -1;
            while(!(keyId >= 1 && keyId <= 9999))
            {
                printf("\n");
                printf("Enter a valid keyID between 1-9999: ");
                scanf("%d", &keyId);
                printf("\n");
            }
            int result = searchContacts(argv[1], keyId);
            if (result == 0){printf("No match found.\n\n");}
            break;
        case 3:
            printf("\n");
            createContacts(argv[1]);
            break;
        case -1:
            printf("\nExiting\n");
            break;
        default: printf ("Invalid, will exit\n"); 
        }
    } while (choice != -1);
    
    return 1;
}
