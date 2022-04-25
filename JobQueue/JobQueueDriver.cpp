/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	JobQueue PC;
	int choice;
	int num;
	int qsize;
	string produce;
	while (choice != 3) {
		menu();
		cin >> choice;
		switch(choice) {
			case 1:
				cout << "Enter the number of jobs to be created:" << endl;
				cin >> num;
				for (int i = 0; i < num; i++) {
					cout << "Job" << i+1 << ":" << endl;
					cin >> produce;
					PC.enqueue(produce);
				}
				break;
			case 2:
				cout << "Enter the number of jobs to be dispatched:" << endl;
				cin >> num;
				qsize = PC.queueSize();
				for (int i = 0; i < num; i++) {
					if (i == qsize) {
						cout << "No more jobs to consume from queue" << endl;
						i = num;
					}
				}
				break;
			case 3:
			cout << "Number of jobs in the queue:" << PC.queueSize();
				break;
		}
	}
}
