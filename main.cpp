#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;

// EXERCISE 1

const int CAPACITY = 6;

void enqueue(int q[], int &front, int &rear, int value) {
    if (rear == CAPACITY - 1) {
        cout << "Queue is full.\n";
        return;
    }

    if (front == -1) {
        front = 0;
    }

    q[++rear] = value;
}

void dequeue(int q[], int &front, int &rear) {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Removed: " << q[front] << '\n';
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void peek(int q[], int front, int rear) {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front: " << q[front] << '\n';
}

void printQueue(int q[], int front, int rear) {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }

    for (int i = front; i <= rear; i++) {
        cout << q[i] << ' ';
    }
    cout << '\n';
}

void exercise1() {
    int q[CAPACITY];
    int front = -1, rear = -1;

    enqueue(q, front, rear, 10);
    enqueue(q, front, rear, 20);
    enqueue(q, front, rear, 30);
    dequeue(q, front, rear);
    enqueue(q, front, rear, 40);

    cout << "Queue: ";
    printQueue(q, front, rear);
    peek(q, front, rear);
}


// EXERCISE 2

struct Node {
    int data;
    Node* next;
};

void enqueue(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void dequeue(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Removed: " << temp->data << '\n';

    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
}

void peek(Node* head) {
    if (head == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front: " << head->data << '\n';
}

void printQueue(Node* head) {
    if (head == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    while (head != nullptr) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

bool searchQueue(Node* head, int value) {
    while (head != nullptr) {
        if (head->data == value) {
            return true;
        }
        head = head->next;
    }

    return false;
}

int countQueue(Node* head) {
    int count = 0;

    while (head != nullptr) {
        count++;
        head = head->next;
    }

    return count;
}

void clearQueue(Node*& head, Node*& tail) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
}

void exercise2() {
    Node* head = nullptr;
    Node* tail = nullptr;

    enqueue(head, tail, 10);
    enqueue(head, tail, 20);
    enqueue(head, tail, 30);
    dequeue(head, tail);
    enqueue(head, tail, 40);

    cout << "Queue: ";
    printQueue(head);
    peek(head);

    clearQueue(head, tail);
}


// EXERCISE 3

void exercise3() {
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    cout << "Front: " << q.front() << '\n';
    cout << "Back: " << q.back() << '\n';

    q.pop();

    cout << "Remaining: ";
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}


// EXERCISE 4

const int CIRC_CAPACITY = 5;

struct CircularQueue {
    int data[CIRC_CAPACITY];
    int front = 0;
    int count = 0;
};

bool circularEnqueue(CircularQueue& q, int value) {
    if (q.count == CIRC_CAPACITY) {
        cout << "Circular queue is full.\n";
        return false;
    }

    int rear = (q.front + q.count) % CIRC_CAPACITY;
    q.data[rear] = value;
    q.count++;

    return true;
}

bool circularDequeue(CircularQueue& q) {
    if (q.count == 0) {
        cout << "Circular queue is empty.\n";
        return false;
    }

    cout << "Removed: " << q.data[q.front] << '\n';
    q.front = (q.front + 1) % CIRC_CAPACITY;
    q.count--;

    return true;
}

void printCircularQueue(const CircularQueue& q) {
    for (int i = 0; i < q.count; i++) {
        cout << q.data[(q.front + i) % CIRC_CAPACITY] << ' ';
    }
    cout << '\n';
}

void exercise4() {
    CircularQueue q;

    for (int value : {10, 20, 30, 40, 50}) {
        circularEnqueue(q, value);
    }

    circularDequeue(q);
    circularDequeue(q);

    circularEnqueue(q, 60);
    circularEnqueue(q, 70);

    cout << "Logical queue: ";
    printCircularQueue(q);
}


// EXERCISE 5


void exercise5() {
    Node* head = nullptr;
    Node* tail = nullptr;

    enqueue(head, tail, 10);
    enqueue(head, tail, 20);
    enqueue(head, tail, 30);
    dequeue(head, tail);
    enqueue(head, tail, 40);

    cout << "Search 30: "
         << (searchQueue(head, 30) ? "Found" : "Not found")
         << '\n';

    cout << "Search 99: "
         << (searchQueue(head, 99) ? "Found" : "Not found")
         << '\n';

    cout << "Count: " << countQueue(head) << '\n';
    cout << "Queue unchanged: ";
    printQueue(head);

    clearQueue(head, tail);
}


// EXERCISE 6

void exercise6() {
    queue<int> q;
    stack<int> s;

    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}


// EXERCISE 7

void exercise7() {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < 10; i++) {
        string current = q.front();
        q.pop();

        cout << current << ' ';

        q.push(current + "0");
        q.push(current + "1");
    }

    cout << '\n';
}


// EXERCISE 8

void exercise8() {
    stack<int> s;
    queue<int> q;

    for (int value : {10, 20, 30, 40}) {
        s.push(value);
        q.push(value);
    }

    cout << "Stack (LIFO): ";
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    cout << "\nQueue (FIFO): ";
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }

    cout << '\n';
}



// EXERCISE 9

struct BenchNode {
    int data;
    BenchNode* next;
};

struct BenchLinkedQueue {
    BenchNode* head = nullptr;
    BenchNode* tail = nullptr;
};

void benchEnqueue(BenchLinkedQueue& q, int value) {
    BenchNode* node = new BenchNode{value, nullptr};

    if (q.tail == nullptr) {
        q.head = q.tail = node;
    } else {
        q.tail->next = node;
        q.tail = node;
    }
}

void benchDequeue(BenchLinkedQueue& q) {
    BenchNode* temp = q.head;
    q.head = q.head->next;

    if (q.head == nullptr) {
        q.tail = nullptr;
    }

    delete temp;
}

long long timeArrayQueue(int n) {
    CircularQueue q;
    // This benchmark uses a circular array sized for n items.
    int* data = new int[n];
    int front = 0, count = 0;

    auto start = chrono::steady_clock::now();

    for (int i = 0; i < n; i++) {
        data[(front + count) % n] = i;
        count++;
    }

    for (int i = 0; i < n; i++) {
        front = (front + 1) % n;
        count--;
    }

    auto stop = chrono::steady_clock::now();
    delete[] data;

    return chrono::duration_cast<chrono::microseconds>(
        stop - start).count();
}

long long timeLinkedQueue(int n) {
    BenchLinkedQueue q;

    auto start = chrono::steady_clock::now();

    for (int i = 0; i < n; i++) {
        benchEnqueue(q, i);
    }

    for (int i = 0; i < n; i++) {
        benchDequeue(q);
    }

    auto stop = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::microseconds>(
        stop - start).count();
}

void exercise9() {
    cout << left << setw(12) << "n"
         << setw(22) << "Array (us)"
         << setw(22) << "Linked list (us)" << '\n';

    for (int n : {1000, 10000, 100000}) {
        long long arrayTotal = 0;
        long long linkedTotal = 0;

        for (int repeat = 0; repeat < 3; repeat++) {
            arrayTotal += timeArrayQueue(n);
            linkedTotal += timeLinkedQueue(n);
        }

        cout << left << setw(12) << n
             << setw(22) << arrayTotal / 3.0
             << setw(22) << linkedTotal / 3.0 << '\n';
    }
}


// EXERCISE 10

struct BankCustomer {
    string name;
    int ticket;
    BankCustomer* next;
};

void addCustomer(BankCustomer*& head, BankCustomer*& tail,
                 string name, int ticket) {
    BankCustomer* node =
        new BankCustomer{name, ticket, nullptr};

    if (tail == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void serveCustomer(BankCustomer*& head, BankCustomer*& tail) {
    if (head == nullptr) {
        cout << "No customers waiting.\n";
        return;
    }

    BankCustomer* temp = head;
    cout << "Serving " << temp->name
         << ", ticket " << temp->ticket << '\n';

    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

void printWaiting(BankCustomer* head) {
    while (head != nullptr) {
        cout << head->name << "(" << head->ticket << ") ";
        head = head->next;
    }
    cout << '\n';
}

void exercise10() {
    BankCustomer* head = nullptr;
    BankCustomer* tail = nullptr;

    addCustomer(head, tail, "Ali", 1);
    addCustomer(head, tail, "Sara", 2);
    addCustomer(head, tail, "John", 3);

    printWaiting(head);
    serveCustomer(head, tail);
    printWaiting(head);

    while (head != nullptr) serveCustomer(head, tail);
}


// EXERCISE 11

struct PrintJob {
    string document;
    int pages;
    PrintJob* next;
};

void addJob(PrintJob*& head, PrintJob*& tail,
            string document, int pages) {
    PrintJob* node = new PrintJob{document, pages, nullptr};

    if (tail == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void printNextJob(PrintJob*& head, PrintJob*& tail) {
    if (head == nullptr) {
        cout << "No print jobs.\n";
        return;
    }

    PrintJob* temp = head;
    cout << "Printing " << temp->document
         << " (" << temp->pages << " pages)\n";

    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

void showJobs(PrintJob* head) {
    while (head != nullptr) {
        cout << head->document << "(" << head->pages
             << " pages) ";
        head = head->next;
    }
    cout << '\n';
}

void exercise11() {
    PrintJob* head = nullptr;
    PrintJob* tail = nullptr;

    addJob(head, tail, "Report.pdf", 10);
    addJob(head, tail, "Essay.docx", 4);
    addJob(head, tail, "Slides.pdf", 15);

    showJobs(head);
    while (head != nullptr) printNextJob(head, tail);
}


// EXERCISE 12

struct Patient {
    string name;
    int registration;
    Patient* next;
};

void registerPatient(Patient*& head, Patient*& tail,
                     string name, int registration) {
    Patient* node =
        new Patient{name, registration, nullptr};

    if (tail == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void callNextPatient(Patient*& head, Patient*& tail) {
    if (head == nullptr) {
        cout << "No patients waiting.\n";
        return;
    }

    Patient* temp = head;
    cout << "Calling " << temp->name
         << ", registration " << temp->registration << '\n';

    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

void showWaiting(Patient* head) {
    while (head != nullptr) {
        cout << head->name << "(" << head->registration << ") ";
        head = head->next;
    }
    cout << '\n';
}

void exercise12() {
    Patient* head = nullptr;
    Patient* tail = nullptr;

    registerPatient(head, tail, "Maya", 101);
    registerPatient(head, tail, "Omar", 102);
    registerPatient(head, tail, "Lina", 103);

    showWaiting(head);
    callNextPatient(head, tail);
    showWaiting(head);

    while (head != nullptr) callNextPatient(head, tail);
}


// EXERCISE 13

struct Shopper {
    string name;
    int items;
    Shopper* next;
};

void addShopper(Shopper*& head, Shopper*& tail,
                string name, int items) {
    Shopper* node = new Shopper{name, items, nullptr};

    if (tail == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void processShopper(Shopper*& head, Shopper*& tail,
                    int& totalItems) {
    if (head == nullptr) {
        cout << "No customers waiting.\n";
        return;
    }

    Shopper* temp = head;
    cout << "Checking out " << temp->name
         << ", items: " << temp->items << '\n';

    totalItems += temp->items;

    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;

    cout << "Total items checked out: " << totalItems << '\n';
}

void showShoppers(Shopper* head) {
    cout << "Waiting: ";
    while (head != nullptr) {
        cout << head->name << "(" << head->items << ") ";
        head = head->next;
    }
    cout << '\n';
}

void exercise13() {
    Shopper* head = nullptr;
    Shopper* tail = nullptr;
    int totalItems = 0;

    addShopper(head, tail, "Ali", 5);
    showShoppers(head);

    addShopper(head, tail, "Sara", 3);
    showShoppers(head);

    addShopper(head, tail, "Mina", 7);
    showShoppers(head);

    processShopper(head, tail, totalItems);
    showShoppers(head);

    processShopper(head, tail, totalItems);
    showShoppers(head);

    processShopper(head, tail, totalItems);
    showShoppers(head);
}


// EXERCISE 14

struct Task {
    string name;
    Task* next;
};

void addTask(Task*& head, Task*& tail, string name) {
    Task* node = new Task{name, nullptr};

    if (tail == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void processNext(Task*& head, Task*& tail) {
    if (head == nullptr) {
        cout << "No pending tasks.\n";
        return;
    }

    Task* temp = head;
    cout << "Processing: " << temp->name << '\n';

    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
}

void showPending(Task* head) {
    cout << "Pending tasks: ";
    while (head != nullptr) {
        cout << head->name << ' ';
        head = head->next;
    }
    cout << '\n';
}

void exercise14() {
    Task* head = nullptr;
    Task* tail = nullptr;

    addTask(head, tail, "Download");
    addTask(head, tail, "Backup");
    addTask(head, tail, "Update");

    showPending(head);
    processNext(head, tail);
    showPending(head);
    processNext(head, tail);
    showPending(head);
    processNext(head, tail);
    showPending(head);
}


int main() {
    cout << "\n=== Exercise 1: Array queue ===\n";
    exercise1();

    cout << "\n=== Exercise 2: Linked-list queue ===\n";
    exercise2();

    cout << "\n=== Exercise 3: Standard library queue ===\n";
    exercise3();

    cout << "\n=== Exercise 4: Circular queue ===\n";
    exercise4();

    cout << "\n=== Exercise 5: Search and count queue ===\n";
    exercise5();

    cout << "\n=== Exercise 6: Reverse queue using stack ===\n";
    exercise6();

    cout << "\n=== Exercise 7: Generate binary numbers ===\n";
    exercise7();

    cout << "\n=== Exercise 8: Stack vs queue ===\n";
    exercise8();

    cout << "\n=== Exercise 9: Big-O timing ===\n";
    exercise9();

    cout << "\n=== Exercise 10: Bank customer queue ===\n";
    exercise10();

    cout << "\n=== Exercise 11: Printer job scheduler ===\n";
    exercise11();

    cout << "\n=== Exercise 12: Hospital patient queue ===\n";
    exercise12();

    cout << "\n=== Exercise 13: Supermarket checkout ===\n";
    exercise13();

    cout << "\n=== Exercise 14: Task processing system ===\n";
    exercise14();
    return 0;
}
