class CircularQueue:
  def __init__(self,capacity:int):
    self.capacity = capacity
    self.data = [None] * capacity
    self.front = 0
    self.rear = 0
    self.size = 0


  def is_empty(self)->bool:
    return self.size == 0
  
  def is_full(self)->bool:
    return self.size == self.capacity
    
  def enqueue(self,element: int)->None:
    if(self.is_full()):
      raise OverflowError("Queue is Full !")
    
    self.data[self.rear] = element
    self.rear = (self.rear + 1) % self.capacity

    self.size += 1
    print(f"Enqueued element : {element}")

  def dequeue(self)->int:
    if(self.is_empty()):
      raise IndexError("Queue is Empty")
    
    element = self.data[self.front]
    self.front = (self.front + 1) % self.capacity
    self.size -= 1
    print(f"Dequeued Element : {element}")
    return element

try:
    q = CircularQueue(5)
    q.enqueue(11)
    q.enqueue(22)
    q.enqueue(33)
    q.enqueue(44)
    q.enqueue(55)
    
    # This will trigger the OverflowError
    q.enqueue(66) 

except OverflowError as e:
    print(f"Caught expected error: {e}")

try:
    q.dequeue()
    q.enqueue(66)
except IndexError as e:
    print(f"Error: {e}")