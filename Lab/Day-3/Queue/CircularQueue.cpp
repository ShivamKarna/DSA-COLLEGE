// Circular QUEUE
// Queue as ADT in C++.

#include<iostream>
#include<stdexcept>
#include<array>
#include<utility>

template <typename T, size_t Capacity>

class CircularQueue{
private:
  std::array<T, Capacity> m_data{};
  size_t m_front{0};
  size_t m_rear{0};
  size_t m_size{0};
public:
  bool isEmpty() const noexcept{
    return m_size == 0;
  }
  bool isFull() const noexcept{
    return m_size == Capacity;
  }
  void enqueue(T element){
    if(isFull()){
      throw std::overflow_error("Queue is Full");
    }
    m_data[m_rear] = std::move(element);
    std::cout << m_data[m_rear] << " enqueued to Queue.\n";
    m_rear = (m_rear + 1) % Capacity;
    ++m_size;
  }
  T dequeue(){
    if(isEmpty()){
      throw std::underflow_error("Queue is Empty !");
    }
    T element = std::move(m_data[m_front]);
    std::cout << "Element " << element << " removed from Queue.\n";
    m_front = (m_front + 1) % Capacity;
    --m_size;
    return element;
  }
};

int main(){
  try
  {
    CircularQueue<int,5> que;

    que.enqueue(11);
    que.enqueue(22);
    que.enqueue(33);
    que.enqueue(44);
    que.enqueue(55);

    que.dequeue();
    que.dequeue();

    que.enqueue(66);
    que.enqueue(77);

    que.enqueue(88); // this will hit queue overflow
  }
  catch(const std::exception& e)
  {
    std::cerr <<"Error: " << e.what() << '\n';
  }
  return 0;
}