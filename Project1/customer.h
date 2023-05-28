#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer {
    char firstName[100];
    char lastName[100];
    char streetAddress[100];
    char city[100];
    char province[100];
    char postalCode[9]; // Increase size to 9 to include null terminator
};

struct Customer getCustomerInfo();

#endif
