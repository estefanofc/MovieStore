# Movie Store

## Checklist

Development Platform: CLion on MacOS

Tested on CSS Linux Lab: Yes, assignment requirement

Tested on Travis: Yes

clang-tidy messages: TODO (Explain all messages and why you are ignoring them)

valgrind messages: no memory leaks

## Command Functionality Checklist

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: CommandFactory -> Create(). If there's an invalid
 command, class will output exception message

invalid movie type: MovieFactory -> Create(). If there's an invalid
                     movie, class will output exception message

invalid customer ID: Customer -> Constructor. If there's an invalid customerID
, class will output exception message
 
invalid movie: MovieFactory -> Create(). If there's an invalid movie, class
 will output exception message

factory classes: MovieFactory, CommandFactory

hashtable: HashTable stores a <int, Customer*> key-value pair to store
 customer pointers

container used for comedy movies: vector pointer

function for sorting comedy movies: Movie -> lessThan()

function where comedy movies are sorted: MovieStore -> sortByKey()

functions called when retrieving a comedy movie based on title and year
: Movie -> getMovie()

functions called for retrieving and printing customer history: History -> run()

container used for customer history: vector<string>

functions called when borrowing a movie: Borrow -> run()

explain borrowing a movie that does not exist: Customer cannot borrow
 nonexistent movie, this action results in displaying an exception. Handled
  in Borrow -> run()

explain borrowing a movie that has 0 stock: not allowed, Customer cannot
 borrow a movie that has 0 stock. Handled in Borrow -> run()

explain returning a movie that customer has not checked out: not permitted
, since customer has a map collection of all movies checked alongside its stock

any static_cast or dynamic_cast used: yes, used to implement comparison
 methods in movie children classes: Movie -> lessThan(), equals()

## Ignored Warnings
Classic.cpp:15:54: warning: field 'MLastName' will be initialized after field
 'Year'

Classic.cpp:16:30: warning: field 'Year' will be initialized after field 'Month'

Customer.h:39:7: warning: private field 'ID' is not used

History.cpp:19:48: warning: unused parameter 'Movies' [-Wunused-parameter]

Inventory.cpp:15:36: warning: unused parameter 'Customers' [-Wunused-parameter]
