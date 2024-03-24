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

// Is most pivotal function of this program. Creates contact struct, and asks users for values. It then puts both into the binary file.
void createContacts(char *fileName)
{
    int empId = -1;
    char rawFirstName [50];
    char * firstName; 
    char rawLastName [50];
    char * lastName; 
    char rawEmail [50];
    char * email; 
    char continueSearch [4];

    FILE * binaryFile;

    strcpy(continueSearch, "Yes");
    struct contact contact;

    while(strcmp(continueSearch, "Yes") == 0 || !strcmp(continueSearch, "No") == 0)
    {
        binaryFile = fopen(fileName, "a+");
        fseek(binaryFile, 0, SEEK_END);

        printf("Do you wish to enter a new contact (Yes or No)?: ");
        scanf("%s", continueSearch);
        printf("\n");

        if (strcmp(continueSearch, "Yes") == 0)
        {
            while(!(empId >= 1 && empId <= 9999))
            {
                printf("Employee Id: ");
                scanf("%d", &empId);
            }

            getchar();

            printf("First Name: ");
            fgets(rawFirstName, 50, stdin);
            rawFirstName[strlen(rawFirstName)-1] = '\0';

            printf("Last Name: ");
            fgets(rawLastName, 50, stdin);
            rawLastName[strlen(rawLastName)-1] = '\0';

            printf("Email: ");
            fgets(rawEmail, 50, stdin);
            rawEmail[strlen(rawEmail)-1] = '\0';
            
            firstName = malloc(sizeof(char) * strlen(rawFirstName) + 1);
            strcpy(firstName, rawFirstName);

            lastName = malloc(sizeof(char) * strlen(rawLastName) + 1);
            strcpy(lastName, rawLastName);
            
            email = malloc(sizeof(char) * strlen(rawEmail) + 1);
            strcpy(email, rawEmail);

            contact.empIdPosn = ftell(binaryFile) + sizeof(contact);

            contact.firstNamePosn = contact.empIdPosn + sizeof(int);

            contact.lastNamePosn = contact.firstNamePosn + sizeof(char) * (strlen(firstName)+1);

            contact.emailPosn = contact.lastNamePosn + sizeof(char) * (strlen(lastName)+1);

            contact.next = contact.emailPosn + sizeof(char) * (strlen(email)+1);

            fwrite(&contact, sizeof(contact), 1, binaryFile);
            
            fseek(binaryFile, contact.empIdPosn, SEEK_SET);
            fwrite(&empId, sizeof(int), 1, binaryFile);
            
            fseek(binaryFile, contact.firstNamePosn, SEEK_SET);
            fwrite(firstName, sizeof(char), strlen(firstName) + 1, binaryFile);
            
            fseek(binaryFile, contact.lastNamePosn, SEEK_SET);
            fwrite(lastName, sizeof(char),  strlen(lastName) + 1, binaryFile);
            
            fseek(binaryFile, contact.emailPosn, SEEK_SET);
            fwrite(email, sizeof(char), strlen(email) + 1, binaryFile);
            empId = -1;
            printf("\n");
            fclose(binaryFile);
        }
    }
    
}
