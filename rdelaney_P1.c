/* Basic tax calculator in C. The program will prompt for a Employee#, Employee name, & gross pay.
   It will then compare gross pay against taxes & insurance costs and provide a bill of costs and
   netpay for the Employee who was entered.
   author: Reese Delaney
   date: 10/9/2026
    */


// Include standard input/output and character type libraries
#include <stdio.h>
#include <ctype.h>

// Main function
int main(void) {

    // Define constants for tax rates and costs
    const double Federal_Tax_Rate = 0.175;
    const double State_Tax_Rate = 0.091;
    const double Social_Security_Tax_Rate = 0.062;
    const double Medicare_Tax_Rate = 0.0145;
    const double Retirement_Rate_Cost = 0.0929;
    
    const double Health_Ins_Cost = 51.48;
    const double Life_Insurance_Cost = 3.71;

    // Initialize variables for deductions, net pay, and percentage take-home
    float total_deductions = -1.00f;

    float net_pay = -1.00f;

    float percent_take_home = -1.00f;

    // Initialize loop control variable

    int loop_active = 1;

    // Initialize variables for employee ID, name, and gross pay

    int employee_id = 0;
    char employee_name[80] = "";
    int gross_pay = 0; 

    // Print required welcome message as shown on the sample output

    printf("Hello, this is a C program.\n");

    // Print a blank line for formatting
    printf("\n");

    // Loop to get a valid employee ID
    while (loop_active == 1) {

        // Initialize a variable to track the validity of the input
        int valid = 1;

        // Prompt the user to enter the employee ID
        printf("Enter employee's id: ");

        // Try reading an integer value for the employee ID
        if (scanf("%4d", &employee_id) != 1) {

            // If the input is not a valid integer, print an error message and clear the input buffer
            printf("Invalid text entered. Please enter a numeric value.\n");
            // Print a blank line for formatting
            printf("\n");
            // Clear the input buffer to remove any residual characters
            while (getchar() != '\n'); 
            // Continue to the next iteration of the loop to prompt for input again
            continue;                   
        }

        // If previous checks pass, check if the ID is within the 4-digit range
        if (employee_id < 0 || employee_id > 9999) {
            // If the ID is not within the valid range, print an error message and set valid to 0
            printf("Invalid input. Employee ID must be between 0 and 9999.\n");
            // Print a blank line for formatting
            printf("\n");
            // Set valid to 0 to indicate that the input is not valid
            valid = 0;
        }

        // If the input is not valid, prompt the user to try again; otherwise, exit the loop
        if (!valid) {
            // If the input is not valid, prompt the user to try again
            printf("Please try again.\n");
            // Print a blank line for formatting
            printf("\n");
        } else {
            // If the input is valid, exit the loop by setting loop_active to 0
            loop_active = 0;
        }
    }

    // Clean up residual newline from the ID input buffer before entering employee name input loop
    while (getchar() != '\n');

    // Set Loop control variable to 1 to enter the employee name input loop 
    loop_active = 1;

    // Loop to get a valid employee name
    while (loop_active == 1) {
        // Initialize a variable to track the validity of the input
        int valid = 1;

        // Prompt the user to enter the employee's full name
        printf("Enter employee's full name: ");
        
        // Try reading a string value for the employee name, allowing spaces and limiting to 79 characters
        if (scanf(" %79[^\n]", employee_name) != 1) {
            // If the input is not a valid string, print an error message and return an error
            printf("Error reading employee name.\n");
            // Print a blank line for formatting
            printf("\n");
            // Return an error code to indicate failure
            return 1;
        }

        // If previous check passes, check if the name is empty or contains any digits                              
        if (employee_name[0] == '\0') {

            // Print error if string is empty
            printf("Name cannot be empty. Please enter a valid employee name.\n");
            // Print a blank line for formatting
            printf("\n");
            // Set valid to 0 to indicate that the input is not valid 
            valid = 0;
        } else {

            // Iterate through the string to make sure there is no digits found
            for (int i = 0; employee_name[i] != '\0'; i++) {
                // Check if digit is found
                if (isdigit((unsigned char)employee_name[i])) {
                    // If digit is found mark as invalid
                    valid = 0;
                    // Break loop
                    break; 
                }
            }
        }

        // If loop run is invalid
        if (!valid) {
            // Print error to user indicating digit can not be in name
            printf("Invalid input. Name cannot contain a digit.\n");
            // Print new line for formatting
            printf("\n");
        } else {
            // If loop run is good set loop control to 0
            loop_active = 0;
        }
    }

    // Clean up residual newline from the ID input buffer before entering program output
    while (getchar() != '\n');


    // Set loop control to 1 before entering gross pay loop
    loop_active = 1;

    // Loop to get a valid gross pay
    while (loop_active == 1) {
        // Initialize a variable to track the validity of the input
        int valid = 1;

        // Prompt user to enter gross salary
        printf("Enter monthly gross salary for %s: ", employee_name);

        // Try reading an integer value
        if (scanf("%d", &gross_pay) != 1) {
            // If entered value is not an integer, print an error message.
            printf("Invalid text entered. Please enter a numeric value.\n");
            // Print new line for formatting
            printf("\n");
            // Clear inputer buffer before asking the user to enter gross salary again
            while (getchar() != '\n'); 
            // Reset loop
            continue;
        }

        // Check if gross pay is more than zero to prevent zero divison
        if (gross_pay <= 0) {
            // If gross pay is zero, as user to try again
            printf("Invalid input. Gross pay must be greater than zero.\n");
            // Print new line for formatting
            printf("\n");
            // Set to 0 to invalidate loop
            valid = 0;
        }

        // If loop is not valid
        if (!valid) {
            // Ask user to try again
            printf("Please try again.\n");
            // Print new line
            printf("\n");
        } else {
            // If loop run is good, set loop control to 0
            loop_active = 0;
        }
    }

    // Clear buffer after reading pay
    while (getchar() != '\n');

    // Calculate deductions for taxes
    double federal_tax = gross_pay * Federal_Tax_Rate;
    double state_tax = gross_pay * State_Tax_Rate;
    double social_security_tax = gross_pay * Social_Security_Tax_Rate;
    double medicare_tax = gross_pay * Medicare_Tax_Rate;
    double retirement_cost = gross_pay * Retirement_Rate_Cost;
    
    // Print a line for formatting
    printf("\n");

    // Print line indicating employee name & employee id as shown in sample output
    printf("Paycheck for %s, employeeId %d\n", employee_name, employee_id);

    // Print new line for formatting:
    printf("\n");

    // Print Gross Amount using %d since gross_pay is an int
    printf("%-25s ................. $ %d.00\n",
        "Gross Amount:", gross_pay);
    
    // Calculate total deductions
    total_deductions = federal_tax + state_tax + social_security_tax + medicare_tax + retirement_cost + Health_Ins_Cost + Life_Insurance_Cost;
    
    // Print all deductions
    printf("\nDeductions\n");
    printf("%-25s ................. $ %2.2f\n",
        "Federal Tax:", federal_tax);
    printf("%-25s ................. $ %2.2f\n",
        "State Tax:", state_tax);
    printf("%-25s ................. $ %2.2f\n",
        "Social Security Tax:", social_security_tax);
    printf("%-25s ................. $ %2.2f\n",
        "Medicare Tax:", medicare_tax);
    printf("%-25s ................. $ %2.2f\n",
        "Retirement Plan:", retirement_cost);
    printf("%-25s ................. $ %2.2f\n",
        "Health Insurance:", Health_Ins_Cost);
    printf("%-25s ................. $ %2.2f\n",
        "Life Insurance:", Life_Insurance_Cost);
    
    // Print new line for formatting
    printf("\n");

    // Calculate netpay
    net_pay = gross_pay - total_deductions;
    // Print netpay
    printf("%-25s ................. $ %2.2f\n",
        "Net Pay:", net_pay);

    // Calculate Percent Takehome
    percent_take_home = (net_pay / gross_pay) * 100;

    // Print Percent Takehome
    printf("%-25s ................. %% %2.2f\n",
        "Percent take home:", percent_take_home);

    // Print new line for formatting
    printf("\n");
    
    // Return 0 for success
    return 0;
} 