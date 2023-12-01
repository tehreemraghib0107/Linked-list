#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
class NodeDoubly {
public:
    int data;
    NodeDoubly* next;
    NodeDoubly* p;

    NodeDoubly(int value) {
        data = value;
        next = NULL;
        p = NULL;
    }
};
class singly {
public:
    Node* head;
    Node* tail;

    singly() {
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void addhead(int value) {
        Node* newNode = new Node(value);
        newNode->next = NULL;

        if (head == NULL && tail == NULL) {  //First node to insert
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addtail(int value) {
        Node* newNode = new Node(value);

        if (head == NULL && tail == NULL) {  //First node to insert
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deletehead() {
        if (head == NULL && tail == NULL) {   
            cout << "LL is empty" << endl;
        }
        else if (head == tail) {        // Single node case
            delete tail;
            tail = NULL;
            head = NULL;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deletetail() {
        if (head == NULL && tail == NULL) {
            cout << "LL is empty" << endl;
        }
        else if (head == tail) {
            delete tail;
            tail = NULL;
            head = NULL;
        }
        else {
            Node* temp = head;
            Node* prev = NULL;
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            if (prev != NULL) {
                prev->next = NULL;
                tail = prev;
            }
            else {
                head = NULL;
                tail = NULL;
            }
        }
    }

    void insert(int value, int index) {     // with the help of ai
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->next = NULL;

        if (index == 1) {
            newNode->next = head;
            head = newNode;
            if (tail == NULL) {
                tail = newNode;
            }
        }
        else {
            Node* t = head;
            for (int i = 1; i < index - 1 && t != NULL; i++) {     
                t = t->next;
            }
            newNode->next = t->next;
            t->next = newNode;
            if (newNode->next == NULL) {
                tail = newNode;
            }
        }
    }

    int max() {
        if (head == NULL) {
            cout << "LinkedList is empty. " << endl;
            return -1; 
        }

        Node* temp = head;
        int max = temp->data;
        temp = temp->next;
        while (temp != NULL) {
            if (temp->data > max) {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }
    

    int search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Element found" << endl;
                return 1;
            }
            temp = temp->next;
        }
        return -1;
    }

    int count() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        cout << "Number of nodes are = " << count << endl;
        return count;
    }

    float average() {
        if (head == NULL) {
            cout << "LinkedList is empty. " << endl;
            return 0;
        }

        Node* current = head;
        int sum = 0;
        int count = 0;

        while (current != NULL) {
            sum += current->data;
            count++;
            current = current->next;
        }

        cout << "Average = " << (float)sum / count << endl;
        return (float)sum / count;
    }

    void Reverse() {
        Node* temp = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (temp != NULL) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            head = prev;
        }
    }

    bool detectloop() {                //with the help of youtube video
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
        }
    }
    bool palindrome() // with the help of youtube video
    {
    	Node* start=head;
        Node* end= head;
      
    	while(end!= NULL && end->next!=NULL ) // finding middle element
		{
    		start=start->next;
    		end=end->next->next;
		}
	
		 // reverse second half of linked list
		Node* prev= NULL;
		Node* next;
		Node* curr=start;
		while(curr!= NULL)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		// comparing first half and second half
		end= head;
		while(prev!=NULL)
		{
		  if(end->data != prev->data)
		  {
			return false;
		  }
		  end=end->next;
		  prev=prev->next;
     	}
     	return true;
   }
};
class doubly {
public:
    Node* head;
    Node* tail;

    doubly() {
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void doublyaddHead(int key) {
        Node* newNode = new Node(key);
        newNode->next = NULL;
        newNode->pre = NULL;
        if (head == NULL && tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }

    void doublyaddTail(int key) {             
        Node* newNode = new Node(key);
        newNode->pre = NULL;
        newNode->next = NULL;
        if (head == NULL && tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void doublydeleteHead() {
        if (head == NULL && tail == NULL) {
            cout << "DLL is empty" << endl;
        }
        else if (head == tail) {
            delete tail;
            tail = NULL;
            head = NULL;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->pre = NULL;
            delete temp;
        }
    }

    void doublydeleteTail() {
        if (head == NULL && tail == NULL) {
            cout << "DLL is empty" << endl;
        }
        else if (head == tail) {
            delete tail;
            tail = NULL;
            head = NULL;
        }
        else {
            Node* temp = tail;
            tail = tail->pre;
            tail->next = NULL;
            delete temp;
        }
    }

       void doublyinsert(int value, int index) {  //with the help of ai
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->next = NULL;
        newNode->pre = NULL;

        if (index == 1) {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
            if (tail == NULL) {
                tail = newNode;
            }
        }
        else {
            Node* t = head;
            for (int i = 1; i < index - 1 && t != NULL; i++) {
                t = t->next;
            }
            newNode->next = t->next;
            newNode->pre = t;
            t->next = newNode;
            if (newNode->next != NULL) {
                newNode->next->pre = newNode;
            }
            else {
                tail = newNode;
            }
        }
    }

    int doublymax() {
        Node* temp = head;
        int max = temp->data;
        temp = temp->next;
        while (temp != NULL) {
            if (temp->data > max) {
                max = temp->data;
            }
            else {
                temp = temp->next;
            }
        }
        return max;
    }

    int search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Element found" << endl;
                return 1;
            }
            temp = temp->next;
        }
        return -1;
    }

    int count() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        cout << "Number of nodes are = " << count << endl;
        return count;
    }

    float average() {
        if (head == NULL) {
            cout << "DLL is empty. " << endl;
            return 0;
        }

        Node* current = head;
        int sum = 0;
        int count = 0;

        while (current != NULL) {
            sum += current->data;
            count++;
            current = current->next;
        }

        cout << "Average = " << (float)sum / count << endl;
        return (float)sum / count;
    }

    void Reverse() {
        Node* temp = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (temp != NULL) {
            next = temp->next;
            temp->next = prev;
            temp->pre = next;
            prev = temp;
            temp = next;
            head = prev;
        }
    }

    bool detectloop() {            //with the help of youtube video
        Node* low = head;
        Node* high = head;
        while (high != NULL && high->next != NULL) {
            low = low->next;
            high = high->next->next;
            if (low == high) {
                return true;
            }
        }
        return false;
    }
};

            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};


class CircularSinglyLinkedList { 
private:
    Node* head;

public:
    CircularSinglyLinkedList() {
        head = NULL;
    }
void insert (int value)
		{
			Node* newNode = new Node (value);
			if (!head) 
			{
            head = newNode;
            head->next = head;
        } 
		else {
            Node* t = head;
            while (t->next != head)
			 {
                t = t->next;
            }
             t->next = newNode;
            newNode->next = head;
        }
    }
     void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } 
		while (t != head);
        cout << endl;
    }
    
    void insertfirst(int value) {
        Node* newNode = new Node(value);
        Node* t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertlast(int value) {
        Node* newNode = new Node(value);
        Node* t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
    }
    void deletefirst() {
        if (!head) {
            cout << "List is empty" <<endl;
            return;
        }
        Node* t = head;
        while (t->next != head) {
            t = t->next;
        }
        if (head == head->next) {
            delete head;
            head = NULL;
        } else {
            t->next = head->next;
            delete head;
            head = t->next;
        }
    }

    void deletelast() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* t = head;
        Node* p = NULL;
        while (t->next != head) {
            p = t;
            t = t->next;
        }
        if (head == head->next) {
            delete head;
            head = NULL;
        } else {
            p->next = head;
            delete t;
        }
    }
    
    void insertatindex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (index == 0) {
            insertfirst(value);
            return;
        }
        Node* t = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!t) {
                cout << "Index out of bounds." << endl;
                delete newNode;
                return;
            }
            t = t->next;
        }
        newNode->next = t->next;
        t->next = newNode;
    }

    bool search(int value) {
        if (!head) {
            return false;
        }

        Node* t = head;
        do {
            if (t->data == value) {
                return true;
            }
            t = t->next;
        } while (t != head);

        return false;
    }

    void reverse() {
        if (!head || head->next == head) {
            return;
        }
        Node *p = NULL, *curr = head, *nextNode = NULL;
        do {
            nextNode = curr->next;
            curr->next = p;
            p = curr;
            curr = nextNode;
        } 
		while (curr != head);
        head->next = p;
        head = p;
    }
    int max() {
        if (!head) {
            cout << "List is empty." << endl;
            return INT_MIN;
        }

        Node* t = head;
        int maxValue = INT_MIN;
        do {
            if (t->data > maxValue) {
                maxValue = t->data;
            }
            t = t->next;
        } while (t != head);

        return maxValue;
    }

    double avg() {
        if (!head) {
            cout << "List is empty." << endl;
            return 0.0;
        }
        Node* t = head;
        int sum = 0;
        int count = 0;
        do {
            sum += t->data;
            ++count;
            t = t->next;
        } 
		while (t != head);
        return static_cast<double>(sum) / count;
    }
    bool detectLoop() {
    if (!head) {
        return 	false; // Empty list, no loop
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Loop detected
        }
    }

    return false; // No loop
}
		
};

class CircularDoublyLinkedList {
private:
    NodeDoubly* head;

public:
    CircularDoublyLinkedList() {
        head = NULL;
    }
CircularDoublyLinkedlist(){
	   head= NULL;
	   }
	   
    void insert(int value) {
        NodeDoubly* newNode = new NodeDoubly(value);
        if (!head) {
            head = newNode;
            head->next = newNode;
            head->p = newNode;
        } 
		else {
            newNode->next = head;
            newNode->p = head->p;
            head->p->next = newNode;
            head->p = newNode;
        }
    }

   void display() {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    NodeDoubly* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
   }
   
    void insertfirst(int value) {
        NodeDoubly* newNode = new NodeDoubly(value);
        if (!head) {
            head = newNode;
            head->next = newNode;
            head->p = newNode;
        } else {
            newNode->next = head->next;
            newNode->p = head;
            head->next->p = newNode;
            head->next = newNode;
        }
        head = newNode;
    }

    void insertlast(int value) {
        NodeDoubly* newNode = new NodeDoubly(value);
        if (!head) {
            head = newNode;
            head->next = newNode;
            head->p = newNode;
        } else {
            newNode->next = head->next;
            newNode->p = head;
            head->next->p = newNode;
            head->next = newNode;
            head = newNode; 
        }
    }

    void deletefirst() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head =NULL;
        } 
		else {
            NodeDoubly* t = head->next;
            head->next = t->next;
            t->next->p = head;
            delete t;
        }
    }

    void deletelast() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            NodeDoubly* t = head->p;
            t->p->next = head;
            head->p = t->p;
            delete t;
        }
    }

    void insertatindex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }
        NodeDoubly* newNode = new NodeDoubly(value);
        if (!head || index == 0) {
            insertfirst(value);
            return;
        }
        NodeDoubly* t = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!t) {
                cout << "Index out of bounds." << endl;
                delete newNode;
                return;
            }
            t = t->next;
        }
        newNode->next = t->next;
        newNode->p = t;
        t->next->p = newNode;
        t->next = newNode;
    }
   bool search(int value) {
    if (!head) {
        cout << "List is empty." << endl;
        return false;
    }
    NodeDoubly* t = head;  
    do {
        if (t->data == value) {
            cout << "Value " << value << " found in the list." << endl;
            return true;
        }
        t = t->next;
    } 
    while (t != head);
    cout << "Value " << value << " not found in the list." << endl;
    return false;
}
    
    void reverse() {
        if (!head || head->next == head) {
            return;
        }
        NodeDoubly* p = NULL;
        NodeDoubly* curr = head;
        NodeDoubly* nextNode = NULL;
        do {
            nextNode = curr->next;
            curr->next = p;
            p = curr;
            curr = nextNode;
        } while (curr != head);
        head->next = p;
        head = p;
    }
     int max() {
        if (!head) {
            cout << "List is empty." << endl;
            return INT_MIN;
        }
        NodeDoubly* t = head;
        int maxValue = INT_MIN;
        do {
            if (t->data > maxValue) {
                maxValue = t->data;
            }
            t = t->next;
        } 
		while (t != head);
        return maxValue;
    }
     double avg() {
        if (!head) {
            cout << "List is empty." << endl;
            return 0.0;
        }
        NodeDoubly* t = head;
        int sum = 0;
        int count = 0;
        do {
            sum += t->data;
            ++count;
            t = t->next;
        }
		 while (t != head);
        return static_cast<double>(sum) / count;
    }
    bool detectLoop() {
    if (!head) {
        return false; // Empty list, no loop
    }

    NodeDoubly* slow = head;
    NodeDoubly* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Loop detected
        }
    }
    return false; // No loop
   }
};

int main() { 

	singly List;
    int choice;

    do {
        cout << "\nLinked List Operations:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Index\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Search\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                List.addHead(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                List.addTail(value);
                break;
            case 3:
                int index;
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                List.insertAtIndex(value, index);
                break;
            case 4:
                List.deleteHead();
                break;
            case 5:
                List.deleteTail();
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                if (List.search(value)) {
                    cout << "Element found in the list.\n";
                } else {
                    cout << "Element not found in the list.\n";
                }
                break;
            case 7:
                List.display();
                break;
            case 8:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    doubly myList;
    int choice;

    do {
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Index\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Search\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                myList.addHead(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                myList.addTail(value);
                break;
            case 3:
                int index;
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insertAtIndex(value, index);
                break;
            case 4:
                myList.deleteHead();
                break;
            case 5:
                myList.deleteTail();
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                if (myList.search(value)) {
                    cout << "Element found in the list.\n";
                } else {
                    cout << "Element not found in the list.\n";
                }
                break;
            case 7:
                myList.display();
                break;
            case 8:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
   
   CircularSinglyLinkedList circularList;
    int choice, value;

    do {
        cout << "\nCircular Singly Linked List Operations:\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Front\n";
        cout << "3. Delete at Front\n";
        cout << "4. Delete at End\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                circularList.insert(value);
                break;
            case 2:
                cout << "Enter value to insert at front: ";
                cin >> value;
                circularList.insertAtFront(value);
                break;
            case 3:
                circularList.deleteAtFront();
                break;
            case 4:
                circularList.deleteAtEnd();
                break;
            case 5:
                cout << "Circular Singly Linked List: ";
                circularList.display();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);


   CircularDoublyLinkedList myLList;
    int choice;

    do {
        cout << "\nCircular Doubly Linked List Operations:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Index\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Search\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                myLList.addHead(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                myLList.addTail(value);
                break;
            case 3:
                int index;
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                myLList.insertAtIndex(value, index);
                break;
            case 4:
                myLList.deleteHead();
                break;
            case 5:
                myLList.deleteTail();
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                if (myLList.search(value)) {
                    cout << "Element found in the list.\n";
                } else {
                    cout << "Element not found in the list.\n";
                }
                break;
            case 7:
                myLList.displayForward();
                break;
            case 8:
                myLList.displayBackward();
                break;
            case 9:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
    
