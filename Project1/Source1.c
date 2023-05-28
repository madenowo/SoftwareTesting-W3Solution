#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "customer.h"

struct Customer getCustomerInfo() {
    struct Customer customer;

    printf("Enter your first name: ");
    fgets(customer.firstName, sizeof(customer.firstName), stdin);
    customer.firstName[strcspn(customer.firstName, "\n")] = '\0';

    printf("Enter your last name: ");
    fgets(customer.lastName, sizeof(customer.lastName), stdin);
    customer.lastName[strcspn(customer.lastName, "\n")] = '\0';

    printf("Enter your street address: ");
    fgets(customer.streetAddress, sizeof(customer.streetAddress), stdin);
    customer.streetAddress[strcspn(customer.streetAddress, "\n")] = '\0';

    printf("Enter your city: ");
    fgets(customer.city, sizeof(customer.city), stdin);
    customer.city[strcspn(customer.city, "\n")] = '\0';

    printf("Enter your province: ");
    fgets(customer.province, sizeof(customer.province), stdin);
    customer.province[strcspn(customer.province, "\n")] = '\0';

    int validPostalCode = 0;
    while (!validPostalCode) {
        printf("Enter your postal code: ");
        fgets(customer.postalCode, sizeof(customer.postalCode), stdin);

        for (int i = 0; customer.postalCode[i]; i++) {
            customer.postalCode[i] = toupper((unsigned char)customer.postalCode[i]);
        }

        if (strlen(customer.postalCode) != 8 || customer.postalCode[7] != '\n') {
            validPostalCode = 0;
        }
        else {
            validPostalCode = 1;
        }

        if (!validPostalCode) {
            printf("Invalid Entry: Enter your postal code again.\n");
        }
    }

    return customer;
}

int main() {
    struct Customer customer = getCustomerInfo();

    printf("\nYou entered: %s %s, %s, %s, %s, %s\n",
        customer.firstName, customer.lastName,
        customer.streetAddress, customer.city,
        customer.province, customer.postalCode);

    return 0;
}