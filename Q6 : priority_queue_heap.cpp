#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert Element
    void insert(int value) {
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    // Delete Highest Priority Element
    void deleteMax() {
        if (size == 0) {
            cout << "Priority Queue is Empty\n";
            return;
        }

        cout << "Deleted Element: " << heap[0] << endl;

        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);
    }

    // Get Highest Priority Element
    int getMax() {
        if (size == 0) {
            cout << "Priority Queue is Empty\n";
            return -1;
        }
        return heap[0];
    }

    // Display Queue
    void display() {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(20);
    pq.insert(50);
    pq.insert(10);
    pq.insert(40);
    pq.insert(30);

    pq.display();

    cout << "Highest Priority Element: "
         << pq.getMax() << endl;

    pq.deleteMax();

    pq.display();

    return 0;
}
