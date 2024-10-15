#include<iostream>
using namespace std;
struct s1{
    int jobid;
    int priority;
    int arrivaltime;
    int bursttime;
};
int arrivaltime=0;
class queue1{
public:
    s1 q1[100];
    int n;
    int first,rear;
    queue1(int n1){
        n=n1;
        q1[n];
        first=rear=-1;
    }
    void enque(int jobid,int priority,int bursttime){
        if(first==-1){
            first=0;
            rear=0;
        }
        else if((rear+1)%n==first){
            cout<<"Full";
            return;
        }
        else{
            rear=(rear+1)%n;
        }
        q1[rear].jobid=jobid;
        q1[rear].priority=priority;
        q1[rear].arrivaltime=arrivaltime;
        q1[rear].bursttime=bursttime;
        arrivaltime++;
        }
    s1 dequee(){
        s1 ret;
        ret=q1[first];
        if(first==-1){
            cout<<"Queue is empty";
        }

        else if(first==rear){
            first=-1;
            rear=-1;
        }
        else{
            first=(first+1)%n;
        }
        return ret;
    }


};
void process(queue1 q1){
    for(int i=0;i<=q1.rear;i++){
        int min1=i;
        for(int j=i+1;j<=q1.rear;j++){
            if(q1.q1[j].priority < q1.q1[min1].priority){
                min1=j;
            }

        }
        swap(q1.q1[min1],q1.q1[i]);

    }
    for(int i=0;i<q1.rear-1;i++)
    {
        while(q1.q1[i].priority == q1.q1[i+1].priority){
            if(q1.q1[i].arrivaltime > q1.q1[i+1].arrivaltime){
                swap(q1.q1[i],q1.q1[i+1]);
            }
            i++;
        }
    }
    for(int j=0;j<=q1.rear;j++)
    {
        cout<<endl;
        cout<<"Jobid:"<<q1.q1[j].jobid<<endl;
        cout<<"Priority:"<<q1.q1[j].priority<<endl;
        cout<<"arrival_time:"<<q1.q1[j].arrivaltime<<endl;
        cout<<"Burst_time:"<<q1.q1[j].bursttime<<endl;
    }
}
int main(){
    int size;
    cout << "Enter the maximum size of the queue: ";
    cin >> size;

    queue1 q1(size);
    int numTasks;
    cout << "Enter the number of tasks to enqueue: ";
    cin >> numTasks;

    for (int i = 0; i < numTasks; ++i) {
        int id, priority, time;
        cout << "Enter Task ID, Priority, and Time (space-separated): ";
        cin >> id >> priority >> time;
        q1.enque(id, priority, time);
    }

    cout << endl << "Starting to process tasks..." << endl;
    process(q1);

    return 0;


}
