//Code contributed by Priyanshu Chatterjee(PriyanshuChatterjee) to the Ultimate DSA Repository
//This code is to a basic example on how to Implement a Circular queue using C++
//Here I've included different operations like --> Enqueue, Dequeue, isEmpty, isFull, Count, Display

//includeing the necessary header file
#include<iostream>
using namespace std;

//The main class containing all the codes for the operations using as member functions.
class CircularQueue{
    //Declaring the variables as public so that they are only usable from iside the code.
    private:
        int front;
        int itemcount;
        int rear;
        int arr[5];
    //Member functions
    public:
        //Initialize a Circular Queue
        CircularQueue()
        {
            itemcount = 0;
            front = -1;
            rear = -1;
            for(int i = 0; i<5; i++)
            {
                arr[i]= 0;
            }
        }
        //returns whether the circular queue is Empty or not
        bool isEmpty()
        {
            if(front==-1 && rear == -1)
                return true;
            else
                return false;
        }
        //returns whether the circular queue is Full or not
        bool isFull()
        {
            if((rear+1)%5==front)
                return true;
            else
                return false;
        }
        //Add an element to the end of the queue
        void enqueue(int val)
        {
            if(isFull())
            {
                cout<<"Queue is FULL"<<endl;
                return;
            }
            else if(isEmpty())
            {
                rear = front = 0;
            }
            else
            {
                rear = (rear+1)%5;;
            }
            arr[rear] = val;
            itemcount++;
        }
        // Remove an element from the front of the queue.
        int dequeue()
        {
            int x=0;
            if(isEmpty())
            {
                cout<<"Queue is EMPTY"<<endl;
                return 0;
            }
            else if(front==rear)
            {
                x = arr[front];
                rear = -1;
                front = -1;
                itemcount--;
                return x;
            }
            else
            {
                cout<<"front Value: "<<front<<endl;
                x = arr[front];
                arr[front]=0;
                front = (front+1)%5;
                itemcount--;
                return x;
            }
        }
        //Counts the Number of Elements in the Queue
        int count()
        {
            return(itemcount);
        }
        //Displays the Queue
        void display()
        {
            cout<<"All the Values in the Queue are - "<<endl;
            for(int i =0; i<5; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
};

//This is the main function or the driver code
int main()
{
    //Making an Object for the Circular Queue Class
    CircularQueue  q1;
    int option, value;

    do
    {
        //Printing the option for the Menu of Operations which can be performed.
        cout<<"\n\nWhat operation do you want to perform? Select option Number. Enter 0 to Exit."<<endl;
        cout<<"1.Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. Clear Screen()"<<endl<<endl;

        cin>>option;

        //Menu to select which operation you want to do in or with the Circular Queue.
        switch(option)
        {
            case 0:
                break;

            case 1:
                cout<<"Enqueue Operation \nEnter an Item to Enqueue ib the Queue"<<endl;
                cin>>value;
                q1.enqueue(value);
            break;

            case 2:
                cout<<"Dequeue Operation \nDequeued Value: "<<q1.dequeue()<<endl;
            break;

            case 3:
                if(q1.isEmpty())
                    cout<<"Queue is Empty"<<endl;
                else
                    cout<<"Queue is not Empty"<<endl;
            break;

            case 4:
                if(q1.isFull())
                    cout<<"Queue is Full"<<endl;
                else
                    cout<<"Queue is not Full"<<endl;
            break;

            case 5:
                cout<<"Count operation \nCount of Items in Queue: "<<q1.count()<<endl;
            break;

            case 6:
                cout<<"Display function called - "<<endl;
                q1.display();
            break;

            case 7:
                 system("cls");
            break;

            default:
                cout<<"Give a proper Input"<<endl;
            break;
        }
    }while(option!=0);

    return 0;
}
