#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to save user information to file
void saveUserData(const char* firstName, const char* lastName, const char* phoneNumber, const char* email,
	const char* city, const char* district, const char* street, const char* buildingNumber,
	const char* apartmentNumber, const char* idnumber, const char* password) {

	char full_path[512];
	const char* appdata_path = getenv("LOCALAPPDATA");

	if (appdata_path == NULL) {
		printf("\n!!! ERROR: LOCALAPPDATA environment variable not found. Cannot save file. !!!\n");
		return;
	}

	// Constructing the full path to save the file in the users AppData\Local directory
    sprintf(full_path, "%s\\BankSystemData.txt", appdata_path);

	// Open the file in write mode
	FILE* file = fopen(full_path, "w");

	if (file == NULL) {
		// Error of opening file
		printf("\n!!! ERROR: Failed to open or create the record file (%s). Make sure the path is correct and you have write permissions. !!!\n", full_path);
		return;
	}

	// Printing user information to file
	fprintf(file, "--- BANK ACCOUNT INFORMATION ---\n");
	fprintf(file, "FirstName: %s\n", firstName);
	fprintf(file, "LastName: %s\n", lastName);
	fprintf(file, "Phone Number: +90 %s\n", phoneNumber);
	fprintf(file, "E-mail adress: %s\n", email);
	fprintf(file, "ID Number: %s\n", idnumber);
	fprintf(file, "Password: %s\n", password);
	fprintf(file, "\n--- ADDRESS INFORMATION ---\n");
	fprintf(file, "City: %s\n", city);
	fprintf(file, "District: %s\n", district);
	fprintf(file, "Street: %s\n", street);
	fprintf(file, "Building Num: %s\n", buildingNumber);
	fprintf(file, "Apartment Num: %s\n", apartmentNumber);
	fprintf(file, "-------------------------------\n");

	// Close the file
	fclose(file);
	printf("\n*** User Information successfully saved to the file %s. ***\n", full_path);
}

int main() {

	// Variables
	int choice;
	char firstName[32];
	char lastName[32];
	char phoneNumber[64];
	char phoneNumberLogin[64];
	char email[64];
	char emailLogin[64];
	char* atsignlocation;
	char city[32];
	char district[32];
	char street[32];
	char buildingNumber[32];
	char apartmentNumber[32];
	char idnumber[32];
	char idnumberLogin[32];
	char password[64];
	char passwordLogin[64];
	int choice2;
	int choice3;
	char* minussignlocation;
	char* questionmarklocation;
	char* asterisklocation;
	char* exclamationmarklocation;

	// Main Menu
	printf("\n");
	printf("        WELCOME TO BANK ACCOUNT SYSTEM\n\n");
	printf("        ******************************\n\n");
	printf("        (1) CREATE A BANK ACCOUNT\n");
	printf("        (2) ALREADY A USER? SIGN IN\n");
	printf("        (3) EXIT\n\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	while (choice != 1 && choice != 2 && choice != 3)
	{
		printf("Invalid choice please enter your choice again: ");
		scanf("%d", &choice);
	}

	switch (choice)
	{
	case 1:
		printf("--- CREATING ACCOUNT ---\n");

		printf("First name: ");
		scanf("%s", firstName);

		printf("Last name: ");
		scanf("%s", lastName);

		printf("Phone number (without spaces): +90 ");
		scanf("%s", phoneNumber);

		while (strlen(phoneNumber) != 10)
		{
			printf("Invalid phone number (must be 10 digits) please enter again: ");
			scanf("%s", phoneNumber);
		}

		printf("Email: ");
		scanf("%s", email);


		atsignlocation = strchr(email, '@');
		while (atsignlocation == NULL)
		{
			printf("Invalid email address please enter again: ");
			scanf("%s", email);
			atsignlocation = strchr(email, '@');
		}

		printf("Address details:\n");
		printf("City: ");
		scanf("%s", city);
		printf("District: ");
		scanf("%s", district);
		printf("Street: ");
		scanf("%s", street);
		printf("Building Number: ");
		scanf("%s", buildingNumber);
		printf("Apartment Number: ");
		scanf("%s", apartmentNumber);


		printf("TC ID: ");
		scanf("%s", idnumber);

		// ID digits may be change depends on country (I based Turkey here)
		while (strlen(idnumber) != 11)
		{
			printf("Invalid ID Number (must be 11 digits) please enter again: ");
			scanf("%s", idnumber);
		}

		printf("Set your password (Your password must be more or equal to 8 digits and have at least ONE special character (*,!,-,?)): ");
		scanf("%s", password);

		while (strlen(password) < 8)
		{
			printf("Your password must be more or equal to 8 digits please enter a strong password: ");
			scanf("%s", password);
		}

		minussignlocation = strchr(password, '-');
		questionmarklocation = strchr(password, '?');
		asterisklocation = strchr(password, '*');
		exclamationmarklocation = strchr(password, '!');

		while (minussignlocation == NULL && questionmarklocation == NULL && asterisklocation == NULL && exclamationmarklocation == NULL)
		{
			printf("Your password must have at least ONE special character (*,!,-,?)");
			scanf("%s", password);
			minussignlocation = strchr(password, '-');
			questionmarklocation = strchr(password, '?');
			asterisklocation = strchr(password, '*');
			exclamationmarklocation = strchr(password, '!');
		}

		// Function call to save user information to file
		saveUserData(firstName, lastName, phoneNumber, email, city, district, street,
			buildingNumber, apartmentNumber, idnumber, password);

		printf("-----Your account has been succesfuly created-----\n");
		printf("Press (1) for signing in - Press (2) for exit: ");
		scanf("%d", &choice2);

		if (choice2 == 1) {
			goto signin;
		}
		else {
			break;
		}

	case 2:
	signin:
		printf("----- SIGN IN -----\n");
		printf("Enter (1) to continue with phone number, Enter (2) to continue with ID Number: ");
		scanf("%d", &choice3);
		while (choice3 != 1 && choice3 != 2)
		{
			printf("Invalid choice please enter your choice again: ");
			scanf("%d", &choice3);
		}
		if (choice3 == 1)
		{
			printf("Phone Number: ");
			scanf("%s", phoneNumberLogin);


			while (strcmp(phoneNumber, phoneNumberLogin) != 0)
			{
				printf("Wrong phone number please enter again: ");
				scanf("%s", phoneNumberLogin);
			}


			printf("Password: ");
			scanf("%s", passwordLogin);


			while (strcmp(password, passwordLogin) != 0)
			{
				printf("Wrong password please enter again: ");
				scanf("%s", passwordLogin);
			}


			goto endmenu;
		}
		else if (choice3 == 2)
		{
			printf("TC ID: ");
			scanf("%s", idnumberLogin);


			while (strcmp(idnumber, idnumberLogin) != 0)
			{
				printf("Wrong ID Number please enter again: ");
				scanf("%s", idnumberLogin);
			}


			printf("Password: ");
			scanf("%s", passwordLogin);


			while (strcmp(password, passwordLogin) != 0)
			{
				printf("Wrong password please enter again: ");
				scanf("%s", passwordLogin);
			}


			goto endmenu;
			break;
		}
	case 3:
		return 0; break;
	}

	// End Menu

endmenu:

	printf(" --------------------------------------------------------------------------------------------------\n");
	printf("| %s %s\n", firstName, lastName);
	printf("| ID: %s\n", idnumber);
	printf("| Ph. Number: +90 %s\n", phoneNumber);
	printf("| Email Add: %s\n", email);
	printf("| City: %s\n", city);
	printf("| District: %s\n", district);
	printf("| Street: %s\n", street);
	printf("| Build No: %s\n", buildingNumber);
	printf("| Apart No: %s\n", apartmentNumber);
	printf(" --------------------------------------------------------------------------------------------------\n");


	return 0;
}
