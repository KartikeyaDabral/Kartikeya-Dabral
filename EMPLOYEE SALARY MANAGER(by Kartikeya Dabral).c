#include <stdio.h>
struct Employee {
    char name[50];
    float basicSalary;
    float DA;         // Dearness Allowance
    float HRA;        // House Rent Allowance
    float TA;         // Travel Allowance
    float netSalary;  // Net Salary
};
void calculateSalaryDetails(struct Employee *emp) {
     float DA_PERCENT = 140.0;  // DA is 140% of Basic
     float HRA_PERCENT = 15.0; // HRA is 15% of Basic
     float TA = 400.0;         // Fixed Travel Allowance
     float TAX_PERCENT = 5.0;  // Income Tax is 5%
    emp->DA = (DA_PERCENT / 100) * emp->basicSalary;
    emp->HRA = (HRA_PERCENT / 100) * emp->basicSalary;
    emp->TA = TA;
    float totalSalary = emp->basicSalary + emp->DA + emp->HRA + emp->TA;
    float incomeTax = (TAX_PERCENT / 100) * totalSalary;
    emp->netSalary = totalSalary - incomeTax;
}

int main() {
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name); 
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        calculateSalaryDetails(&employees[i]);
    }
    printf("\nEmployee Details:\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("%-20s %-15s %-10s %-10s %-10s %-15s %-15s\n", "Name", "Basic Salary", "DA", "HRA", "TA", "Net Salary", "Total Salary");
    printf("------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        float totalSalary = employees[i].basicSalary + employees[i].DA + employees[i].HRA + employees[i].TA;
        printf("%-20s %-15.2f %-10.2f %-10.2f %-10.2f %-15.2f %-15.2f\n", 
            employees[i].name, 
            employees[i].basicSalary, 
            employees[i].DA, 
            employees[i].HRA, 
            employees[i].TA, 
            employees[i].netSalary,
            totalSalary);
    }
    printf("------------------------------------------------------------------------------------------------------\n");

    return 0;
}
