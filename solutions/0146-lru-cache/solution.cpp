#include <unordered_map>
#include <cstddef>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity {capacity} { }
    
    int get(int key) {
        if (const auto it {m_cache.find(key)}; it != m_cache.end()) {
            m_recency.splice(m_recency.end(), m_recency, it->second.first);
            return it->second.second;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (const auto it {m_cache.find(key)}; it != m_cache.end()) {
            it->second.second = value;
            m_recency.splice(m_recency.end(), m_recency, it->second.first);
            return;
        }

        if (m_recency.size() >= m_capacity) {
            m_cache.erase(m_recency.front());
            m_recency.pop_front(); 
        }

        m_recency.push_back(key);
        m_cache[key] = std::pair(std::prev(m_recency.end()), value);
    }

private:
    int m_capacity {0};

    std::unordered_map<int, std::pair<std::list<int>::iterator, int>> m_cache;

    std::list<int> m_recency;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
