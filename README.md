# Contact Management System

### Overview
The **Contact Management System** is a simple C program designed to help manage a small contact list. It allows users to:
- Add new contacts
- Update existing contacts
- List all contacts
- Exit the application

### Features
- **Input Validation**: Ensures user inputs are valid, preventing crashes or invalid entries.
- **Menu-Driven Interface**: Easy-to-use interface for selecting different functionalities.
- **Contact Storage**: Handles up to 20 contacts in memory.

### How It Works
1. **Add Contact**: Save a new contact by providing a name and phone number.
2. **Update Contact**: Modify the phone number of an existing contact using their name.
3. **List Contacts**: View all stored contacts with their names and phone numbers.
4. **Exit**: Quit the application gracefully.

### File Structure
The program is implemented in a single file with the following main components:
- **`person` Struct**: Defines a contact with `name` and `phone` fields.
- **Functions**:
  - `is_valid_integer`: Validates if an input is an integer.
  - `main_menu`: Displays and manages the main menu.
  - `create_new_contact`: Adds a new contact.
  - `update_contact`: Updates an existing contact.
  - `list_all`: Displays all contacts.
  - `return_to_menu_or_exit`: Handles navigation or exit.

### How to Run
1. Compile the program using a C compiler:
   ```bash
   gcc -o contact_manager main.c
2. Run the executable:
   ```
   ./contact_manager

### Program Limits
Maximum Contacts: The program can store up to 20 contacts.
Name/Phone Length: Names and phone numbers can be up to 20 characters.

### Author
- Name: Regan
- Organization: Regan's Tech Lab
