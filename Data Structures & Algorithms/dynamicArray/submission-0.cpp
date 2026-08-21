class DynamicArray {
private:
    int* vec;
    int size;
    int capacity;
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->vec = new int[capacity];
    }

    int get(int i) {
        return *(vec+i);
    }

    void set(int i, int n) {
        *(vec+i) = n;
    }

    void pushback(int n) {
        if(size == capacity) {
           resize(); 
        }
        vec[size] = n;
        size ++;
    }

    int popback() {
        size --;
        return vec[size];

    }

    void resize() {
        int *new_vec = new int[capacity*2];
        
        for(int i = 0; i < this->size; i++) {
            new_vec[i] = vec[i];
        }
        delete[] vec;
        vec = new_vec;
        capacity *= 2;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};
