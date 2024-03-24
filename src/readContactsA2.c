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

// Prints out entire contacts in the binary file given as an argument. Does this through a while loop.
void readContacts(char *fileName)
{
    int structPos = 0;
    int empId = 0;
    char firstName [50];
    char lastName [50];
    char email [50];
    

    struct contact currentStruct;
    FILE * binaryFile = fopen(fileName, "a+");
    

    printf("Printing employee records saved on file: \n");

    while((fread(&currentStruct, sizeof(struct contact), 1, binaryFile) == 1))
    {
        fseek(binaryFile, structPos, SEEK_SET);
        fread(&currentStruct, sizeof(struct contact), 1, binaryFile);

        printf("************************\n");
        fseek(binaryFile, currentStruct.empIdPosn, SEEK_SET);
        fread(&empId, sizeof(int), 1, binaryFile);
        printf("Employee ID: %d \n", empId);

        fseek(binaryFile, currentStruct.firstNamePosn, SEEK_SET);
        fread(firstName, sizeof(char), currentStruct.lastNamePosn-currentStruct.firstNamePosn, binaryFile);
        printf("First Name: %s \n", firstName);

        fseek(binaryFile, currentStruct.lastNamePosn, SEEK_SET);
        fread(lastName, sizeof(char), currentStruct.emailPosn-currentStruct.lastNamePosn, binaryFile);
        printf("Last Name: %s \n", lastName);

        fseek(binaryFile, currentStruct.emailPosn, SEEK_SET);
        fread(email, sizeof(char), currentStruct.next - currentStruct.emailPosn, binaryFile);
        printf("Email: %s \n", email);
        printf("************************\n\n");

        structPos = currentStruct.next;
    }

}
