#ifndef MOVETOFRONT_H
#define MOVETOFRONT_H

#include "SelfOrderedListADT.h"""

template <typename E>
class MoveToFront : public SelfOrderedListADT<E> {
private:

	Link<E>* head;       // Pointer to list header
	Link<E>* tail;       // Pointer to last element
	Link<E>* curr;       // Access to current element
	int cnt;    	       // Size of list
	int numberOfCompares;  // var to store number of comparisons 

    void update() { //_________________________________________________________CHECK LOGIC________________________________________________________________
        if (curr != head) {
            Link<E>* prev = head;
            while (prev->next != curr) {
                prev = prev->next;
            }
            Link<E>* newHead = new Link<E>;
            newHead->element = curr->element;
            newHead->frequency = curr->frequency;
            newHead->next = head;
            head = newHead;
            Link<E>* temp = prev->next;
            if (tail == prev->next) tail = prev;
            prev->next = prev->next->next;
        }
    }

public:
	MoveToFront() {
		numberOfCompares = 0;
		cnt = 0;
		head = tail = curr = new Link<E>;
	}
	~MoveToFront() {

	}

    bool find(const E& it) { //__________________________________CHeck LOGIC________________________________________________________
        bool isFound = false;
        curr = head;
        while (curr->next != NULL && curr->element != it) {
            curr = curr->next;
            numberOfCompares++;
        }
        if (curr->element != it && curr == tail) {
            if (size() > 0) {
                numberOfCompares++;
            }
            add(it);
        }
        else {
            curr->frequency++;
            isFound = true;
            numberOfCompares++;
        }
        update();
        return isFound;
    }

    void add(const E& it) {
        if (cnt > 0) {
            tail = tail->next = new Link<E>(it, NULL);
            curr = tail;
            cnt++;
        }
        else {
            head = new Link<E>(it, NULL);
            tail = curr = head;
            cnt++;
        }
    }

    int getCompares() const { return numberOfCompares; }
    int size() const { return cnt; }

    void printlist() {
        curr = head; // start at the head 
        while (curr->next != NULL) {
            std::cout << curr->element << "-" << curr->frequency << "  ";
            curr = curr->next;
        }
        std::cout << "\n\n";
    }

    void printlist(int n) {
        curr = head; //start at the head
        for (int i = 0; i < n; i++) {
            std::cout << curr->element << "-" << curr->frequency << "  ";
            curr = curr->next;
            if (curr == NULL) { // check to make sure next number entered is at least the size of list 
                break;
            }
        }
        std::cout << "\n\n";
    }
};


#endif /* MOVETOFRONT_H */