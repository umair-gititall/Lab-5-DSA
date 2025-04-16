#include "Queue.h"
#include <string>

class student {
	string name;
	int score;
	int timeTaken;
public:
	student() :name(""), score(0), timeTaken(0) {}
	student(string n) :name(n), score(0), timeTaken(0) {}
	void setScore(int s) { score = s; }
	void setTimeTaken(int t) { timeTaken = t; }
	friend ostream& operator <<(ostream &out, student obj)
	{
		out << obj.name << "\t\t  " << obj.score << "\t\t     " << obj.timeTaken;
		return out;
	}
};


int main()
{
	MyQueue <student> waiting(100);
	MyQueue <student> evaluated(100);
	string selection;

	while (true)
	{
		cout << "\t\t1. Add a student to the waiting queue" << endl;
		cout << "\t\t2. Start the quiz and generate scores" << endl;
		cout << "\t\t3. Display the scores, name and time taken by the students" << endl;
		cout << "\t\t4. Exit" << endl;
		cout << "root@console --> ";
		cin >> selection;

		system("cls");

		if (selection == "1")
		{
			cin.ignore();
			cout << "Enter Name :: ";
			getline(cin, selection);
			waiting.enqueue(student(selection));
		}
		else if (selection == "2")
		{
			while (!waiting.isEmpty())
			{
				student temp = waiting.dequeue();
				temp.setScore(rand() % 100);
				temp.setTimeTaken(rand() % 60);
				evaluated.enqueue(temp);
			}
			cout << "The Quiz has ended." << endl;
		}
		else if (selection == "3")
		{
			cout << endl << "Name\t\t Score\t\t Time_Taken" << endl;
			evaluated.display();
		}
		else if (selection == "4")
			break;
	}
}