This is a basic console application in C that allows users to create a bank account, sign in using phone number or ID Number, validates inputs like phone, email, ID Number, and password, and saves all user information to a local text file in the Windows LOCALAPPDATA directory for future sessions.

⚙ Features

• Account Creation

• Collects personal details: first name, last name, phone number, email

• Collects address details: city, district, street, building number, apartment number

• TC ID (Turkey-based ID) validation (11 digits)

• Password validation (>=8 characters and at least one special character *, !, -, ?)

• Sign up and Sign in

• Allows sign in using phone number or ID number

• Validates credentials against stored data

• Persistent login possible across program restarts

• Data Storage

• User data is stored in BankSystemData.txt inside the LOCALAPPDATA directory

• File contains both account information and address information

• Saves passwords and sensitive info as plain text

• Input Validation

• Phone number: must be exactly 10 
 digits

• Email: must contain @

• Password: must meet complexity requirements

• TC ID: must be exactly 11 digits (Turkey Based)
