#ifndef COUNT_H
#define COUNT_H

#include "link.h"
#include "SelfOrderedListADT.h"
#include <iostream>



template <typename E>
class Count : public SelfOrderedListADT<E> {
private:

    Link<E>* head;       // Pointer to list header
    Link<E>* tail;       // Pointer to last element
    Link<E>* curr;       // Access to current element
    int cnt;    	       // Size of list
    int numberOfCompares;  // var to store number of comparisons 
    void update() {
        // update the list 
        if (cnt == 1) {
            curr = head;
        } else {
            // Start at curr head back one spot at a time swapping elemnts based on the frequency
            // two placeholders to rearrange list 
            Link<E>* temp = new Link<E>;
            Link<E>* prev = new Link<E>;
            // reorder 
            while (curr != head) {
                prev = head;//start at head again move to one previous to curr
                while (prev->next != curr) { // takes us to one previous to curr
                    prev = prev->next;
                }
                // switch prev and curr if needed by frequency 
                if (curr->frequency > prev->frequency) {
                    // set the temp object 
                    temp->element = prev->element;
                    temp->frequency = prev->frequency;
                    //set prev to curr
                    prev->element = curr->element;
                    prev->frequency = curr->frequency;
                    // set curr now to previous
                    curr->element = temp->element;
                    curr->frequency = temp->frequency;
                }
                curr = prev; // go one spot back
            }
        }
    }

public:

    // constructor 
    Count() {
        numberOfCompares = 0;
        cnt = 0;
        head = tail = curr = new Link<E>;
    }

    // destructor
    ~Count() {

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
        } else {
            curr->frequency++;
            isFound = true;
            numberOfCompares++;
        }
        update();
        return isFound;
    }

    void add(const E & it) {
        if (cnt > 0) {
            tail = tail->next = new Link<E>(it, NULL);
            curr = tail;
            cnt++;
    } else {
        head = new Link<E>(it, NULL);
        tail = curr = head;
        cnt++;
        }
    }

    int getCompares() const { return numberOfCompares; }
    int size() const {return cnt;}

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
#endif /* COUNT_H */