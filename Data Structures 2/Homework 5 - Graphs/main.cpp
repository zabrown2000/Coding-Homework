#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph g;
	try {
		string v1, v2, name;
		int choice;
		cout << "Choose one of the following:\n";
		cout << "1-to add a task\n";
		cout << "2 - to add a priority rule\n";
		cout << "3 - to print all the graph\n";
		cout << "4 - print a recommended task order\n";
		cout << "5 - exit\n";
		do
		{
			cin >> choice;
			switch (choice)
			{
			case 1:cout << "Enter the task you want to add\n";
				cin >> v1;
				if (!g.addv(v1)) cout << "ERROR\n";
				break;
			case 2:cout << "Enter earlier task and the later task\n";
				cin >> v1 >> v2;
				if (!g.adde(v1, v2)) cout << "ERROR\n";
				break;
			case 3:
				cout << "The graph:\n";
				g.printAll();
				cout << endl;
				break;
			case 4:
				cout << "The recommended order:\n";
				g.topologicalSort();
				cout << endl;
				break;
			case 5:cout << "byebye";  break;
			default:cout << "ERROR\n";

			}
		} while (choice != 5);
	}
	catch (string s)
	{
		cout << s << endl;
	}
	return 0;
}


/*Read a new task and create a corresponding vertex
• Read an ordering constraint (task A can start only after task B is done) and create
a corresponding edge)
• Print the graph
• Print a suggested order of the tasks, using topological ordering of the tasks and
printing the resulting linked list
• Exit: deleting all allocated data structures
*/