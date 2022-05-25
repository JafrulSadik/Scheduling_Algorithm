#include<bits/stdc++.h>

using namespace std;

class Process {
    public:

    string Name;
    double wt;
    double bt;
    double tt;
    double remBt;
};

void input(int n, Process a[]){
    for(int i=0; i<n; i++){
        cout << "Enter process " << i+1 << " name : "; cin >> a[i].Name;
        cout << "Enter process " << i+1 << " burst time : "; cin >> a[i].bt;

        a[i].wt = a[i].tt = 0;
        a[i].remBt = a[i].bt;
    }
}

void display(int n, Process a[]){
    cout << endl << endl;
    for(int i=0; i<n; i++){

        cout << a[i].Name << "\tBurst Time : " << a[i].bt << "\t \tWaiting Time : " << a[i].wt << "\tTurnaround Time : " << a[i].tt << endl;
    }

    cout << endl;
}

int main()
{
    int n, tq;

    cout << "Enter the number of process: "; cin >> n;
    cout << "Enter the value of Time Quantum : "; cin >> tq;

    Process a[n];

    input(n,a);

    double time =0 ;
    
    while(1){

        bool com = true;
        
        for(int i = 0; i<n; i++){

            if(a[i].remBt > 0){
                com = false;
                if(a[i].remBt > tq){
                    time += tq;
                    a[i].remBt -= tq;
                }
                else{
                    time += a[i].remBt;
                    a[i].wt = time - a[i].bt;
                    a[i].remBt = 0;
                }
            }
            
        }

        if(com == true){
            break;
        }
    }

    for(int i=0; i<n; i++){
        a[i].tt = a[i].wt + a[i].bt;
    }

    double twt = 0, avgWt =0;

    for(int i=0; i<n; i++){
        twt += a[i].wt;
    }

    avgWt = twt / (double)n;

    display(n, a);

    cout << endl << "Total Waiting Time : " << twt << endl;
    cout << "Average Waiting Time : " << avgWt << endl << endl;

}