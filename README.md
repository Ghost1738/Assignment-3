Objective
Give practice implementing a queue via a linked list.
Give practice designing a functioning program without all function prototypes being given.
Give practice following and implementing rules in a simulation.
Background Story
Our theater always shows block buster movies and there is constantly high demand for tickets. Tickets
need to be purchased in advance from the ticketing center. The ticketing center has 12 queues (numbered
from 1 to 12) and some booths (max 12) to handle those queues. Due to a recent hurricane in the other
part of the state, many ticketing employees are on leave to take care family at their home cities affected
by the hurricane. So, due to the shortage of employees we are operating only b number of booths (0< b
≤ 12) operated by b number of employees. The booths are numbered from 1 to b. All the customers must
arrive and stand in one of the 12 queues before getting redirected to one of the booths (we assume this
redirection takes no time.)
Upon arrival, a customer enters the name (a single string with max length 50 with all upper case letters)
and number of tickets nt (0< nt ≤500) in the kiosk. The time of arrival t (0 ≤ t ≤ 109) is automatically
recorded and is unique for each customer. After receiving this data, the system extracts the first letter of
the name and gets its position p (0 ≤ p < 26) in the alphabet. For example, if the name is ADAM, then p
for ADAM is 0. (A = 0, B = 1, ..., Z = 25) Then the system automatically assigns a queue number q
based on the following strategy:
1. The queue number q of a customer is p%13, if p%13≠0
2. If p%13 is zero, then the customer is assigned to the first nonempty queue with the least number
of customers across all of the queues. If the least number is same for multiple queues, then the
customer is assigned the first queue (based on the queue number) out of those queues. If the very
first customer is in this category, assign them to the first queue. We define the size of a queue to
be the total number of people that have previously been in that queue at any point.
Processing the customers
For the purposes of this problem, we assume that before the employees start processing customers, it is
known in advance which of the queues will be non-empty at some point in time. Let the number of
queues that receive at least 1 customer at some point in time equal k.
Due to the shortage of employees, for all of the cases your program will be run, k ≥ b.
The k queues will be split amongst the b booths as follows:
Each booth will receive customers from at least ⌊𝒌
𝒃⌋ queues, where ⌊𝑥⌋, represents the greatest integer
less than or equal to x. (This is the technical way to define integer division for positive integers,
mathematically. It's called the floor function.)
The first k%b booths will receive one more queue. The queues will be assigned in numerical order, with
the smallest queues being assigned to booth 1, the next smallest queues being assigned to booth 2, and
so forth.
Let's consider a couple examples.
Let the non-empty queues be 1, 3, 4, 8, 9 and 12 and let there be 4 booths.
Since ⌊6
4⌋ = 1, each booth will have at least 1 queue assigned to it and the first 6%4 = 2 booths will
receive customers from two queues.
Thus, for this example, all customers from queues 1 and 3 will go to booth 1, all customers from queues
4 and 8 will go to booth 2, all customers from queue 9 will go to booth 3 and all customers from queue
12 will go to booth 4.
For the second example, let the non-empty queues be 2, 3, 4, 6, 7, 8, 9, 10, 11 and 12, and let there be 3
booths. ⌊10
3 ⌋ = 3 and 10%3 = 1. Thus, the queues will be assigned to booths as follows:
Booth 1: Queues 2, 3, 4, 6
Booth 2: Queues 7, 8, 9
Booth 3: Queues 10, 11, 12
The booths start processing customers at time t = 0. As soon as the first customer arrives at a booth, the
employee at that booth starts processing her order. The processing time (in seconds) of a customer is
calculated by 30 + number of tickets * 5. For example, if a customer buys 8 tickets, then it would take
30 + 8*5 = 70 seconds to process her transaction.
If a customer arrives in the queue before her assigned booth is ready, she will continue to wait in her
queue until that booth is ready to call her up to process her order.
The Problem
Write a program that reads in information about customers: customer name, number of tickets and time
of arrival, and uses this information to determine which booth each customer will buy tickets from, and
at what time they will complete their transaction.
Input
The first line will contain 2 positive integers, n (n ≤ 500,000), the number of customers purchasing
tickets and b (b ≤ 12), the number booths operating on that day.
The following n lines will have information about each customer. These n lines will be sorted from
earliest arrival time to latest arrival time. Each of these lines will start with the name of the customer, a
single string of 1 to 50 uppercase letters, followed by a positive integer, nt (0 < nt ≤ 500), representing
the number of tickets the customer is buying, and another unique positive integer, t (t ≤ 109), representing
the time, in seconds, from the beginning of the simulation that the customer steps into a line. It is
guaranteed that all of the check in times are unique and that all of the customer names are unique as well.
These pieces of information will be separated by white space on the line. (Please just use scanf to read
in the input!)
The Output
For each booth and for each customer served by the booth print the checkout time, in the order that they
get checked out from that booth.
For each booth, print a single header line with the following format:
Booth Y
where Y represents the booth number, starting with 1.
For each customer who bought tickets at that booth, output a single line with the following format:
CUSTOMER from line X checks out at time T.
where CUSTOMER is the name of the customer checking out, X is the queue they came from before
arriving at the booth, and T is the number of seconds AFTER the start of the simulation, that they
complete checking out. (Thus, this time is the time they get called by the booth, plus the time it takes
them to process.)
After each booth, output a blank line.
