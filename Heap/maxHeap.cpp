#include <iostream>
using namespace std;

class MaxHeap {
private:
    int *heapArray;
    int capacity;
    int size;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index > 0 && heapArray[parent(index)] < heapArray[index]) {
            swap(heapArray[parent(index)], heapArray[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heapArray[left] > heapArray[maxIndex])
            maxIndex = left;
        if (right < size && heapArray[right] > heapArray[maxIndex])
            maxIndex = right;

        if (maxIndex != index) {
            swap(heapArray[maxIndex], heapArray[index]);
            heapifyDown(maxIndex);
        }
    }

public:
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heapArray = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heapArray;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        heapArray[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    int extractMax() {
        if (size == 0) {
            cerr << "Heap is empty!" << endl;
            return -1;
        }

        int max = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifyDown(0);

        return max;
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10);

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);

    maxHeap.display();

    int max = maxHeap.extractMax();
    if (max != -1) {
        cout << "Extracted max value: " << max << endl;
        maxHeap.display();
    }

    return 0;
}
