#include "queue.h"


// circular array implementation of queue
queue::queue(){
    rear = 0;  // rear used as the count of queue items
    front = 0;  // front points to queue front
	for(int i=0; i<MAX_CAP; i++)
		item[i]=0;
}

// precondition: queue is not full 
void queue::enqueue(int data){
    int pos = (front+rear) % MAX_CAP;
    item[pos] = data;
    rear++;  
	cout << "enqueu: front=" << front << " rear=" << rear << endl;
}

// precondition: queue is not empty
int queue::dequeue(){
    int pos = front; 
    front = (front+1) % MAX_CAP;
    rear--; 
	cout << "dequeue: front=" << front << " rear=" << rear << endl;
    return item[pos];
}

void queue::dump(ostream &os){
    for(int i=0; i<rear; i++)
        os<<item[(front+i)%MAX_CAP]<<endl;
}

int queue::size(){
    return rear;
}

bool queue::empty(){
    return (rear == 0) ? true : false;
}

bool queue::full(){
    return (size() == MAX_CAP) ? true : false;
    
}
