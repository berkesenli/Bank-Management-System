This is a basic console application written in C that simulates the account creation and sign-in process for a banking system. It includes input validation and saves the entered user data to a local text file on the Windows operating system.

🌟 Features

Account Creation: Allows the user to input personal details, contact information, and address data.

Input Validation:

Checks for a 10-digit phone number.

Validates the email format (must contain @).

Checks for an 11-digit national ID (TC ID - based on Turkish system requirements).

Enforces a minimum 8-character password length and requires at least one special character (*, !, -, or ?).

Local Data Persistence (Non-Secure): Saves all entered user details to a file named userdata.txt on the user's local appdata folder.

Simple Sign-In: Allows the user to sign in immediately after registration using either their phone number or national ID and password (login is non-persistent and only checks in-memory variables from the current session).

Display User Data: Shows the user's stored information upon successful sign-in.

