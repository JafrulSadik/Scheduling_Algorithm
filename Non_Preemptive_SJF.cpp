#include<bits/stdc++.h>

using namespace std;

class process{
    public:
        string Pname;
        double burstTime;
        double turnaroundTime;
        double waitingTime;
};

void GanttChart(process allProcess[], int no_of_process){
    cout << endl << "*****Gantt Chart********" << endl;
    cout<<"-";
    int i, nameLength,j;
    for(i=0; i<no_of_process; i++){
        nameLength = allProcess[i].Pname.size();
        for(j=0; j<(int)allProcess[i].burstTime; j++){
            cout << "--";
        }
        for(j=0; j<nameLength; j++){
            cout << "-";
        }
        cout << "-";
    }
    cout<<endl;
    cout<<"|";

    for(i=0; i<no_of_process; i++){
        nameLength = allProcess[i].Pname.size();
        for(j=0; j<(int)allProcess[i].burstTime; j++){
            cout << " ";
        }
        cout << allProcess[i].Pname;
        for(j=0; j<(int)allProcess[i].burstTime; j++){
            cout << " ";
        }
        cout << "|";
    }

    cout << endl;
    cout<<"+";

    for(i=0; i<no_of_process; i++){
        nameLength = allProcess[i].Pname.size();
        for(j=0; j<(int)allProcess[i].burstTime; j++){
            cout << "--";
        }
        for(j=0; j<nameLength; j++){
            cout << "-";
        }
        cout << "+";
    }
}

void sort(process allProcess[], int no_of_process)
{
    int i,j,temp;
    string temp1;

    for(i=0; i<no_of_process-1; i++)
    {
        for(j=0; j<no_of_process-i-1; j++)
        {
            if(allProcess[j].burstTime > allProcess[j+1].burstTime)
            {
                temp = allProcess[j].burstTime;
                allProcess[j].burstTime = allProcess[j+1].burstTime;
                allProcess[j+1].burstTime = temp;

                temp1 = allProcess[j].Pname;
                allProcess[j].Pname = allProcess[j+1].Pname;
                allProcess[j+1].Pname = temp1;
            }
        }
    }
}

void ganttchartLastline(process allProcess[], int no_of_process)
{
    cout<<0;
    int i, nameLength,j;
    for(i=0; i<no_of_process; i++){
        nameLength = allProcess[i].Pname.size();
        for(j=0; j<allProcess[i].burstTime; j++){
            cout<<"  ";
        }
        for(j=0; j<nameLength; j++){
            cout<<" ";
        }
        if(allProcess[i].turnaroundTime > 9){
            cout<<"\b";
        }
        cout<<allProcess[i].turnaroundTime;
    }
    cout<<endl;
}

void input(process allProcess[], int no_of_process)
{
    int i;
    for(i=0; i<no_of_process; i++){
        cout<<"Enter Process " << i+1 <<" Name : ";
        cin >> allProcess[i].Pname;
        cout<<"Enter Process " << i+1 <<" Burst Time : ";
        cin >> allProcess[i].burstTime;
        allProcess[i].waitingTime=allProcess[i].turnaroundTime=0;
    }
}

int main(){

    cout<< endl<< "********************Non-Preemptive SJF****************"<<endl<<endl;
    int no_of_process,i,nameLength,j;
    cout<<"Enter the number of process : ";
    cin >> no_of_process;
    process allProcess[no_of_process];

    input(allProcess, no_of_process);

    //sort the int i, nameLength,processes according to their burst time
    sort(allProcess, no_of_process);

    allProcess[0].turnaroundTime=allProcess[0].burstTime;
    for(i=1; i<no_of_process; i++){
        allProcess[i].waitingTime = allProcess[i-1].waitingTime + allProcess[i-1].burstTime;
        allProcess[i].turnaroundTime = allProcess[i].waitingTime + allProcess[i].burstTime;
    }

    double totalWaitingTime = 0;
    for(i=0; i < no_of_process; i++){
        totalWaitingTime = totalWaitingTime = allProcess[i].waitingTime;
    }

    double avgWaitingTime = totalWaitingTime / (double) no_of_process;

    GanttChart(allProcess, no_of_process);

    cout << endl;
    
    ganttchartLastline(allProcess, no_of_process);

    cout<<"*******Turnaround Time**********"<< endl;

    for(i=0; i<no_of_process; i++){
        cout<<"Process Name: " << allProcess[i].Pname << "\tTurnaround Time : "<< allProcess[i].turnaroundTime<<endl;
    }

    cout<<endl;

    cout<<"*******Waiting Time**********" << endl;

    for(i=0; i<no_of_process; i++){
        cout<<"Process Name: " << allProcess[i].Pname << "\tWaiting Time : "<< allProcess[i].waitingTime<<endl;
    }

    cout<<endl;

    cout<<"Total waiting time: " <<totalWaitingTime<<endl;
    cout<<"Average waiting time : "<<avgWaitingTime<<endl;

    
    return 0;

}