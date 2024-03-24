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

// Searches for a employee id in the binary file using the keyId argument and a while loop
int searchContacts(char *fileName, int keyId)
{
    FILE * binaryFile = fopen(fileName, "a+");
    
    struct contact currentStruct;
    
    int structPos = 0;
    int empId = 0;
    char firstName [50];
    char lastName [50];
    char email [50];

    while((fread(&currentStruct, sizeof(struct contact), 1, binaryFile) == 1))
    {
        fseek(binaryFile, structPos, SEEK_SET);
        fread(&currentStruct, sizeof(struct contact), 1, binaryFile);

        fseek(binaryFile, currentStruct.empIdPosn, SEEK_SET);
        fread(&empId, sizeof(int), 1, binaryFile);
        
        if(empId == keyId)
        {
            break;
        }
        structPos = currentStruct.next;
    }

    if(empId == keyId)
    {
        printf("************************\n");
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
        printf("************************\n");
        printf("\n");
        return 1;
    }
    else
    {
        printf("\n");
        return 0;
    }


}
