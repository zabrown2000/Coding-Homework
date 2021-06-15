/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 2
This program will implement a queue using 2 stacks*/

#include <iostream>
#include "QueueStack.h"
using namespace std;
int main() {
	Queue* Q;
	Q = new QueueStack();
	try {
		for (int i = 0; i < 10; i++)
			Q->enqueue(i);
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "first on Q is: " << Q->front() << endl;
	cout << "take out 2 elemets:" << endl;
	cout << Q->dequeue() << ' ' << Q->dequeue() << endl;
	cout << "first on Q is: " << Q->front() << endl;
	Q->enqueue(8);
	Q->enqueue(9);
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	return 0;
}

/*first on Q is: 0
take out 2 elemets:
1 0
first on Q is: 2
2 3 4 5 6 7 8 9 8 9
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework8.2\Debug\Homework8.2.exe (process 24512) exited with code 0.
Press any key to close this window . . .
*/