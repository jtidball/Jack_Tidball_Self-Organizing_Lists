
// Self Organizing Lists Project 4 

#include <iostream>
#include "Count.h"
#include "MoveToFront.h"
#include "Transpose.h"

using namespace std;

int main() {

	std::cout << "Jack Tidball Project 4 Self Ordered Lists \n";
	char addArray[] = {'A','B','C','D','E','F','G','H'};
	char findArray[] = { 'F','D','F','G','E','G','F','A','D','F','G','E','H','I' };

	std::cout << "Count Heuristic: ";
	Count<char>* CNTList = new Count<char>();
		for (int i = 0; i < sizeof(addArray); i++) {
			CNTList->add(addArray[i]);
		}
		for (int i = 0; i < sizeof(findArray); i++) {
			CNTList->find(findArray[i]);
		}
		std::cout << "Size of list : " << CNTList->size() << "\n";
		std::cout << "Number of Compares : " << CNTList->getCompares() << "\n";
		CNTList->printlist();

	std::cout << "Move to Front Heuristic: ";
	MoveToFront<char>* MTFList = new MoveToFront<char>();
		for (int i = 0; i < sizeof(addArray); i++) {
			MTFList->add(addArray[i]);
		}
		for (int i = 0; i < sizeof(findArray); i++) {
			MTFList->find(findArray[i]);
		}
		std::cout << "Size of list : " << MTFList->size() << "\n";
		std::cout << "Number of Compares : " << MTFList->getCompares() << "\n";
		MTFList->printlist();

	std::cout << "Transpose Heuristic: ";
	Transpose<char>* transList = new Transpose<char>();
		for (int i = 0; i < sizeof(addArray); i++) {
			transList->add(addArray[i]);
		}
		for (int i = 0; i < sizeof(findArray); i++) {
			transList->find(findArray[i]);
		}
		std::cout << "Size of list : " << transList->size() << "\n";
		std::cout << "Number of Compares : " << transList->getCompares() << "\n";
		transList->printlist();
		 
}