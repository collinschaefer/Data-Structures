#include <iostream>
#include <vector>
#include <list>
#include <ctime>

struct Queue
{
    int front, rear, capacity;
    int* queue;
    Queue(int c)
    {
        front = 0;
        rear = 0;
        capacity = c;
        queue = new int;
    }

    ~Queue() { delete[] queue; }

    // inserts an element at the end of the queue
    void queueInsert(int input)
    {
        if (capacity == rear) {
            printf("\nQueue is full\n");
            return;
        }
        else {
            queue[rear] = input;
            rear++;
        }
        return;
    }

    // deletes an element from the front of the queue
    void queueDelete()
    {
        if (front == rear) {
            printf("\nQueue is  empty\n");
            return;
        }
        else {
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
        return;
    }

    // print queue elements
    void queuePrint()
    {
        int i;
        if (front == rear) {
            printf("\nQueue is Empty\n");
            return;
        }

        for (i = front; i < rear; i++) {
            std::cout << queue[i] << " ";
        }
        return;
    }
};

// measures and prints the time to insert values into the queue, vector, and list
void insertComparison(Queue, std::vector<int>, std::list<int>);

// measures and prints the time to delete values from the queue, vector, and list
void deleteComparison(Queue, std::vector<int>, std::list<int>);

// measures and prints the time to print the queue, vector, and list
void printComparison(Queue, std::vector<int>, std::list<int>);

int main()
{
    int capacity = 500000;

    Queue myQueue(capacity);
    std::list<int> myList;
    std::vector<int> myVec;

    insertComparison(myQueue, myVec, myList);
    //deleteComparison(myQueue, myVec, myList);
    //printComparison(myQueue, myVec, myList);
    std::cout << "main";
    return 0;
}

void insertComparison(Queue myQueue, std::vector<int> myVec, std::list<int> myList)
{
    std::cout << "main";
    //clock_t startQ, stopQ, startV, stopV, startL, stopL;
   // startQ = clock();
    for(int i = 0; i < 500; ++i)
    {
        myQueue.queueInsert(i);
    }
    std::cout << "main";
   // stopQ = clock();
    //std::cout << "Queue insertion time: " << (double)( stopQ - startQ) << "\n";

    //startV = clock();
    for(int i = 0; i < 500; ++i)
    {
        myVec.insert(myVec.begin(), 1);
    }
    std::cout << "main";
    //stopV = clock();
    //std::cout << "Vector insertion time: " << double(stopV - startV) << "\n";

    //startL = clock();
    for(int i = 0; i < 500; ++i)
    {
        myList.insert(myList.begin(), 1);
    }
    //stopL = clock();
    //std::cout << "List insertion time: " << double(stopL - startL) << "\n";
    std::cout << "end ";

    return;
}

void timeDelete(Queue myQueue, std::vector<int> myVec, std::list<int> myList)
{

}

void timePrint(Queue myQueue, std::vector<int> myVec, std::list<int> myList)
{

}
