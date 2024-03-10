#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 500000
#define MAX_BOOTHS 12

typedef struct {
    char name[51]; // 1 to 50 uppercase letters + '\0'
    int numTickets;
    int arrivalTime;
    int transactionTime;
} Customer;

typedef struct {
    Customer *data;
    int front, rear;
} Queue;

void enqueue(Queue *queue, Customer customer);
Customer dequeue(Queue *queue);

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

void enqueue(Queue *queue, Customer customer) {
    queue->data[queue->rear++] = customer;
}

Customer dequeue(Queue *queue) {
    return queue->data[queue->front++];
}

void processCustomers(Customer customers[], int numCustomers, int numBooths) {
    Queue boothQueues[MAX_BOOTHS];

    for (int i = 0; i < numBooths; ++i) {
        boothQueues[i].data = (Customer *)malloc(sizeof(Customer) * numCustomers);
        boothQueues[i].front = boothQueues[i].rear = 0;
    }

    // Distribute customers to booth queues based on arrival time
    for (int i = 0; i < numCustomers; ++i) {
        int boothIndex = i % numBooths;
        enqueue(&boothQueues[boothIndex], customers[i]);
    }

    int currentTime = 0;

    for (int booth = 0; booth < numBooths; ++booth) {
        printf("Booth %d\n", booth + 1);

        while (boothQueues[booth].front < boothQueues[booth].rear) {
            // Dequeue and process customers from the booth queue
            Customer currentCustomer = dequeue(&boothQueues[booth]);
            currentCustomer.transactionTime = currentTime;
            printf("%s from line %d checks out at time %d.\n",
                   currentCustomer.name, currentCustomer.arrivalTime, currentCustomer.transactionTime);
            currentTime += currentCustomer.numTickets * 2; // Assuming 2 seconds per ticket
        }

        // Output a blank line after each booth
        printf("\n");
    }

    for (int i = 0; i < numBooths; ++i) {
        free(boothQueues[i].data);
    }
}

