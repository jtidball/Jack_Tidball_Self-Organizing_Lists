#ifndef TRANSPOSE_H
#define TRANSPOSE_H

template <typename E>
class Transpose : public SelfOrderedListADT<E> {
private:

    Link<E>* head;       // Pointer to list header
    Link<E>* tail;       // Pointer to last element
    Link<E>* curr;       // Access to current element
    int cnt;    	       // Size of list
    int numberOfCompares;  // var to store number of comparisons 

    void update() { //_________________________________________________________CHECK LOGIC________________________________________________________________
        Link<E>* prev = new Link<E>;
        Link<E>* temp = new Link<E>; 

        if (cnt == 1) {
            curr = head;
        }
        if (curr != head) {
            prev = head;
            while (prev->next != curr) {
                prev = prev->next;
            }
            temp->element = curr->element;
            temp->frequency = curr->frequency;
            curr->element = prev->element;
            curr->frequency = prev->frequency;
            prev->element = temp->element;
            prev->frequency = temp->frequency;

            curr = prev;
        }
    }

public:
    Transpose() {
        numberOfCompares = 0;
        cnt = 0;
        head = tail = curr = new Link<E>;
    }
    ~Transpose() {

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

#endif /* TRANSPOSE_H */