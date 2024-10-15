#include<thread>
#include<iostream>
using namespace std;
struct s1{
    string light;
    int duration;
};
int arrivaltime=0;
class queue1{
public:
    s1 q1[10];
    int n;
    int first,rear;
    queue1(int n1){
        n=n1;
        q1[n];
        first=rear=-1;
    }
    void addlight(int duration,string light){
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
        q1[rear].duration = duration;
        q1[rear].light = light;
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
    void switch_light()
    {
        int a=q1[first].duration;
        first=(first+1)%n;
        /*cout<<"Light:"<<q1[first].light<<endl;
        cout<<"Duration"<<q1[first].duration;*/
    }
    void display_current()
    {
        cout<<"Light:"<<q1[first].light<<endl;
        cout<<"Duration:"<<q1[first].duration<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(q1[first].duration));
        cout<<endl;
        cout<<"After "<<q1[first].duration<<" Seconds:"<<endl;
    }


};
int main()
{
    queue1 q1(3);
    q1.addlight(30 , "Red");
    q1.addlight(8 , "Green");
    q1.addlight(4 , "Yellow");
    int a=1;
    while(true)
    {

        if(a==0)
        {
            break;
        }
        else{

            q1.display_current();
            q1.switch_light();

        }
    }

}

