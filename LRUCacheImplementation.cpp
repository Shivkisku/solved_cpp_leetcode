#include <iostream>
#include <unordered_map>
#include <deque>

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!m.count(key) || m[key] == -1) return -1;
        q.push_back(key);
        visited[key]++;
        return m[key];
    }

    void put(int key, int value) {
        if (!m.count(key) || m[key] == -1) count++;
        else visited[key]++;
        if (count > capacity) {
            while (visited[q.front()]) visited[q.front()]--, q.pop_front();
            m[q.front()] = -1;
            q.pop_front();
            count--;
        }
        q.push_back(key);
        m[key] = value;
    }

private:
    std::unordered_map<int, int> m;
    std::unordered_map<int, int> visited;
    std::deque<int> q;
    int count = 0;
    int capacity = 0;
};

int main() {
    LRUCache obj(2);
    obj.put(1, 1);
    obj.put(2, 2);
    std::cout << obj.get(1) << std::endl;  // Output: 1
    obj.put(3, 3);
    std::cout << obj.get(2) << std::endl;  // Output: -1
    obj.put(4, 4);
    std::cout << obj.get(1) << std::endl;  // Output: -1
    std::cout << obj.get(3) << std::endl;  // Output: 3
    std::cout << obj.get(4) << std::endl;  // Output: 4

    return 0;
}
