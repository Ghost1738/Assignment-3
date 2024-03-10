#include <stdio.h>

#define MAX_CUSTOMERS 500000
#define MAX_BOOTHS 12

typedef struct {
    char name[51]; // 1 to 50 uppercase letters + '\0'
    int numTickets;
    int arrivalTime;
    int boothNumber;
    int transactionTime;
} Customer;

void processCustomers(Customer customers[], int numCustomers, int numBooths);

int main() {
    int numCustomers, numBooths;

    // Input number of customers and booths
    scanf("%d %d", &numCustomers, &numBooths);

    if (numCustomers <= 0 || numCustomers > MAX_CUSTOMERS || numBooths <= 0 || numBooths > MAX_BOOTHS) {
        printf("Invalid input for the number of customers or booths.\n");
        return 1;
    }

    Customer customers[MAX_CUSTOMERS];

    // Input customer information
    for (int i = 0; i < numCustomers; ++i) {
        // Assuming names without spaces
        scanf("%s %d %d", customers[i].name, &customers[i].numTickets, &customers[i].arrivalTime);
    }

    processCustomers(customers, numCustomers, numBooths);

    return 0;
}

void processCustomers(Customer customers[], int numCustomers, int numBooths) {
    int currentTime = 0;

    for (int booth = 1; booth <= numBooths; ++booth) {
        printf("Booth %d\n", booth);

        for (int i = 0; i < numCustomers; ++i) {
            if (customers[i].boothNumber == booth) {
                // Output customer information
                printf("%s from line %d checks out at time %d.\n",
                       customers[i].name, i + 1, customers[i].transactionTime + currentTime);
            }
        }

        // Output a blank line after each booth
        printf("\n");
    }
}
