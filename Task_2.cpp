#include "Queue.h"
#include <string>

class customer {
	string name;
public:
	customer() :name("") {}
	customer(string n) :name(n) {}
	friend ostream& operator <<(ostream &out, const customer &obj)
	{
		out << obj.name;
		return out;
	}
};


int main()
{
	circularQueue <customer> waiting(3);
	string selection; int size{};

	while (true)
	{
		cout << "\t\t1. Add a customer to the queue" << endl;
		cout << "\t\t2. Remove the first customer from the queue" << endl;
		cout << "\t\t3. Display the number of customers waiting in line" << endl;
		cout << "\t\t4. View the first customer in the queue" << endl;
		cout << "\t\t5. View the last customer in the queue" << endl;
		cout << "\t\t6. Exit" << endl;
		cout << "root@console --> ";
		cin >> selection;

		system("cls");

		if (selection == "1")
		{
			if(!waiting.isFull())
			{
				cin.ignore();
				cout << "Enter Name :: ";
				getline(cin, selection);
				waiting.enqueue(customer(selection));
				size++;
			}
		}
		else if (selection == "2")
		{
			if (!waiting.isEmpty())
			{
				cout << "Customer :: ";
				cout << waiting.dequeue();
				size--;
			}
		}
		else if (selection == "3")
			cout << "Total Customers in line : " << size << endl;
		else if (selection == "4")
			cout << "Front of Queue : " << waiting.peek() << endl;
		else if (selection == "5")
			cout << "Last of Queue :" << waiting.peekLast() << endl;
		else if (selection == "6")
			break;
	}
}