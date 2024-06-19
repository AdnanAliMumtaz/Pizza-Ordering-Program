# Pizzeria Management System
This is a simple command-line based pizzeria management system implemented in C++. Users can add credit, order pizzas of different sizes, and customize them with various toppings. The system ensures that users have sufficient credit to place orders and provides options to add more credit if needed.

## Features
- **Add Credit**: Users can add credit to their account.
- **Order Pizza**: Users can order pizzas of sizes 7-inch, 9-inch, and 14-inch with optional toppings.
- **Checkout**: Calculates and displays the total price of the order and deducts from the available credit.
- **User Input Validation**: Ensures valid input from the user throughout the program.

## How to Use
1. **Adding Credit**
   - Select option `1` from the main menu.
   - Enter the amount of credit you wish to add (must be between 1 and 999).

2. **Ordering Pizza**
   - Select option `2` from the main menu.
   - Choose the size of the pizza (7-inch, 9-inch, or 14-inch).
   - Add toppings as desired until you complete your order.
   - The system will prompt you to check out, where it will verify if you have enough credit.

3. **Exiting**
   - Select option `0` from the main menu to exit the program.

## Screenshots of Console
### Main Menu
<img width="900" alt="Menu" src="https://github.com/AdnanAliMumtaz/Pizza-Ordering-Program/assets/81415901/79733616-8259-4436-b9b4-a518867e9ea4">

### Ordering Pizza
<img width="900" alt="OrderingPizza" src="https://github.com/AdnanAliMumtaz/Pizza-Ordering-Program/assets/81415901/1d8016d1-e80a-491c-a9e9-3684cf10aa41">

### Checkout
<img width="900" alt="Checkout" src="https://github.com/AdnanAliMumtaz/Pizza-Ordering-Program/assets/81415901/8479e55f-1d2f-4442-a3ae-dba7afa1e267">

## Usage Notes
- **Input Validation**: The system validates user input to ensure it meets the expected format and range.
- **Credit Management**: Keep track of your credit balance throughout the session.
- **Order Review**: Review your pizza order and decide whether to proceed with checkout or add more credit.\

## Future Work
- **User Accounts**: Introduce user accounts to store credit balances and order histories.
- **Enhanced Customization**: Expand pizza customisation options with additional toppings and special requests.
