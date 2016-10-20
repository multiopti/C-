#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
public:
// String representing the name of the account's owner
string name;
// The account number
int id;
// The current account balance
double balance;
};
// Allows the user to enter via the keyboard information
// about an account and adds that account to the database.
void add_account(vector<Account>& accts) {
string name;
int number;
double amount;
cout << "Enter name, account number, and account balance: ";
cin >> name >> number >> amount;
Account acct;
acct.name = name;
acct.id = number;
acct.balance = amount;
accts.push_back(acct);
}
// Print all the accounts in the database
void print_accounts(const vector<Account>& accts) {
int n = accts.size();
for (int i = 0; i < n; i++)
cout << accts[i].name << "," << accts[i].id
<< "," << accts[i].balance << endl;
}
void swap(Account& er1, Account& er2) {
Account temp = er1;
er1 = er2;
er2 = temp;
}
bool less_than_by_name(const Account& e1, const Account& e2) {
return e1.name < e2.name;
}
bool less_than_by_id(const Account& e1, const Account& e2) {
return e1.id < e2.id;
}
bool less_than_by_balance(const Account& e1, const Account& e2) {
return e1.balance < e2.balance;
}
// Sorts a bank account database into ascending order
// The comp parameter determines the ordering
void sort(vector<Account>& db,
bool (*comp)(const Account&, const Account&)) {
int size = db.size();
for (int i = 0; i < size - 1; i++) {
int smallest = i;
for (int j = i + 1; j < size; j++)
if (comp(db[j], db[smallest]))
smallest = j;
if (smallest != i)
swap(db[i], db[smallest]);
}
}
// Allows a user interact with a bank account database.

// The Point class defines the structure of software
// objects that model mathematical, geometric points
class Point {
public:
double x; // The point's x coordinate
double y; // The point's y coordinate
};
int main() {
// Declare some point objects
Point pt1, pt2;
// Assign their x and y fields
pt1.x = 8.5; // Use the dot notation to get to a part of the object
pt1.y = 0.0;
pt2.x = -4;
pt2.y = 2.5;
// Print them
cout << "pt1 = (" << pt1.x << "," << pt1.y << ")" << endl;
cout << "pt2 = (" << pt2.x << "," << pt2.y << ")" << endl;
// Reassign one point from the other
pt1 = pt2;
cout << "pt1 = (" << pt1.x << "," << pt1.y << ")" << endl;
cout << "pt2 = (" << pt2.x << "," << pt2.y << ")" << endl;
// Are pt1 and pt2 aliases? Change pt1's x coordinate and see.
pt1.x = 0;
cout << "pt1 = (" << pt1.x << "," << pt1.y << ")" << endl;
// Note that pt2 is unchanged
cout << "pt2 = (" << pt2.x << "," << pt2.y << ")" << endl;

// The simple database of bank accounts
vector<Account> customers;
// User command
char cmd;
// Are we done yet?
bool done = false;
do {
cout << "[A]dd [N]ame [I]D [B]alance [Q]uit==> ";
cin >> cmd;
switch (cmd) {
case 'A':
case 'a':
// Add an account
add_account(customers);
break;
case 'P':
case 'p':
// Print customer database
print_accounts(customers);
break;
case 'N':
case 'n':
// Sort database by name
sort(customers, less_than_by_name);
print_accounts(customers);
break;
case 'I':
case 'i':
// Sort database by ID (account number)
sort(customers, less_than_by_id);
print_accounts(customers);
break;
case 'B':
case 'b':
// Sort database by account balance
sort(customers, less_than_by_balance);
print_accounts(customers);
break;
case 'Q':
case 'q':
done = true;
break;
}
}
while (!done);
}
