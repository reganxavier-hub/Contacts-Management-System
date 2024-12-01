/*
 * Program: Contact Management System
 * Author: Regan
 * Language: C
 * Project: Command Line Argument based
 * Description: A simple contact management program that allows users to 
 *              add new contacts, update existing contacts, list all contacts, 
 *              and exit the application. The program includes input validation 
 *              to ensure smooth operation.
 * Organization: Regan's Tech Lab
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CONTACTS 20 // Maximum number of contacts allowed

int no_of_contacts_count = 0; // Counter to keep track of the number of contacts

typedef struct {
    char name[20];  // Field to store the contact's name
    char phone[20]; // Field to store the contact's phone number
} person;

person people[MAX_CONTACTS]; // Global array to store contacts

// Function to check if a string is a valid integer
int is_valid_integer(const char *input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (!isdigit(input[i])) // Check if each character is a digit
        {
            return 0; // Return 0 if a non-digit character is found
        }
    }
    return 1; // Return 1 if all characters are digits
}

// Function to display the main menu and get a valid option from the user
int main_menu()
{
    char input[10]; // String to store user input
    int option = 0; // Variable to store the selected menu option

    while (1) // Loop until a valid option is selected
    {
        printf("\nWelcome to the Main Menu\n");
        printf("**********************************\n");
        printf("1. Add new contact\n");
        printf("2. Update existing contact\n");
        printf("3. List all contacts\n");
        printf("4. Exit\n");
        printf("**********************************\n");
        printf("Select an option: ");
        scanf("%s", input); // Read input as a string

        if (is_valid_integer(input)) // Check if the input is a valid integer
        {
            option = atoi(input); // Convert the string to an integer
            if (option >= 1 && option <= 4) // Ensure the option is within range
            {
                return option; // Return the valid option
            }
        }
        printf("Invalid option! Please enter a number between 1 and 4.\n");
    }
}

// Function to ask the user if they want to return to the main menu or exit
void return_to_menu_or_exit()
{
    char choice[5]; // String to store the user's choice
    printf("\nDo you want to return to the main menu? (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0 || strcmp(choice, "y") == 0)
    {
        // If the user chooses "yes", return to the main menu
        return;
    }
    else
    {
        // Exit the program if the user chooses "no"
        printf("Goodbye!\n");
        exit(0);
    }
}

// Function to create a new contact
void create_new_contact()
{
    if (no_of_contacts_count >= MAX_CONTACTS) // Check if the contact list is full
    {
        printf("Contact list is full. Cannot add more contacts.\n");
        return_to_menu_or_exit();
        return;
    }

    // Prompt the user for contact details
    printf("Name: ");
    scanf("%s", people[no_of_contacts_count].name);
    printf("Mobile number: ");
    scanf("%s", people[no_of_contacts_count].phone);

    // Increment the contact counter and confirm the addition
    printf("Saving contact...\n");
    no_of_contacts_count++;
    printf("Contact saved successfully!\n");
    return_to_menu_or_exit(); // Ask if the user wants to return to the main menu
}

// Function to list all contacts
void list_all()
{
    if (no_of_contacts_count == 0) // Check if the contact list is empty
    {
        printf("No contacts available.\n");
        return_to_menu_or_exit();
        return;
    }

    // Print all contacts
    printf("\nListing all contacts:\n");
    for (int i = 0; i < no_of_contacts_count; i++)
    {
        printf("Name: %s | Phone: %s\n", people[i].name, people[i].phone);
    }
    return_to_menu_or_exit(); // Ask if the user wants to return to the main menu
}

// Function to update an existing contact
void update_contact()
{
    char search_name[20]; // String to store the name to search for
    printf("Enter the name of the contact to update: ");
    scanf("%s", search_name);

    for (int i = 0; i < no_of_contacts_count; i++) // Search for the contact
    {
        if (strcmp(people[i].name, search_name) == 0) // Contact found
        {
            printf("Enter new phone number for %s: ", search_name);
            scanf("%s", people[i].phone); // Update the phone number
            printf("Contact updated successfully!\n");
            return_to_menu_or_exit(); // Ask if the user wants to return to the main menu
            return;
        }
    }

    // If the contact is not found
    printf("Contact with name '%s' not found.\n", search_name);
    return_to_menu_or_exit();
}

// Main function to handle the program's flow
int main(void)
{
    while (1) // Infinite loop to keep the program running until the user exits
    {
        int option = main_menu(); // Get the user's choice from the main menu

        switch (option)
        {
        case 1:
            printf("\nAdd new contact\n");
            create_new_contact(); // Call the function to add a new contact
            break;

        case 2:
            printf("\nUpdate existing contact\n");
            update_contact(); // Call the function to update a contact
            break;

        case 3:
            printf("\nList all contacts\n");
            list_all(); // Call the function to list all contacts
            break;

        case 4:
            printf("\nGoodbye!\n");
            return 0; // Exit the program
            break;

        default:
            printf("Unexpected error.\n"); // Handle unexpected errors
        }
    }

    return 0; // Return 0 to indicate successful execution (redundant due to infinite loop)
}
