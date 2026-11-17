class MyCircularQueue {
public:
    MyCircularQueue(std::size_t k) : m_size {k + 1}, m_queue(k + 1) { }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        m_queue[m_tail] = value;

        m_tail = (m_tail + 1) % m_size;
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        m_head = (m_head + 1) % m_size;
        
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : m_queue[m_head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;

        std::size_t lastIdx {(m_tail - 1 + m_size) % m_size};
        
        return m_queue[lastIdx];
    }
    
    bool isEmpty() {
        return m_head == m_tail;
    }
    
    bool isFull() {
        return ((m_tail + 1) % m_size) == m_head; 
    }

private:
    std::size_t m_size {0};
    
    std::size_t m_head {0};
    
    std::size_t m_tail {0};
    
    std::vector<int> m_queue;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
