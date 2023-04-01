#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip> 
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class booking{
    public:

    string movie;
    int op;
    int seats[100];
    int seats_time[3]={0};
    vector<string> list={"Raju","Humpty Sharma ki Dulhania","Titanic","Sultan","Pathan"};
    vector<string> t={"1 pm","4 pm","8 pm"};
    vector<int> prices={200,300,400};
    vector<bool> mp={true,true,true};
    int n;
};

/*class moviename : public booking{
    public:
    int book(){
        int login();
        login();
        cout<<" List of movies:"<<endl;
        for(int i=0;i<list.size();++i){
            cout<<i+1<<" :"<<list[i]<<endl;
        }
        cout<<"choose one: (1/)"<<endl;
        cin>>op;
        movie=list[op-1];
    }
        /*int login();
        login();
        cout<<" List of movies:"<<endl;
        for(int i=0;i<list.size();++i){
            cout<<list[i]<<endl;
        }
        cout<<"choose one: "<<endl;
        cin>>movie;

        return 0;

    }*/
//};

class seat:public booking{
    public: 
    int n=0;
    int st[10][10]={0};
    int book(){
        int login();
        login();
        cout<<" List of movies:"<<endl;
        for(int i=0;i<list.size();++i){
            cout<<i+1<<" :"<<list[i]<<endl;
        }
        cout<<"choose one: (1/)"<<endl;
        cin>>op;
        movie=list[op-1];
        return 0;
    }
    int seatnumber(){
        cout<<"Enter the number of seats to be booked: "<<endl;
        cin>>n;//2
        int j=0,k=0;
        int row[10],col[10];//j=10 & k=10
        int i=1;
        while(i<=n){
        cout<<"\nEnter the desired " << i<< " seat row: ";//i=1
            cin>>j;//j=11
            cout<<"\nEnter the desired "<< i<< " seat column: ";
            cin>>k;
            if((st[j-1][k-1]!=1)&& (j-1)<=9  && (k-1)<=9){
                st[j-1][k-1]=1;
            }
            else if((j-1)>9 && (k-1)>9){
                cout<<"\nInvalid row or column. Please Enter again";
                continue;
            }
            else{
                cout<<"Seat already booked";
                continue;
            }
            i++;//i=1

        } //
        cout<<"\nYour seat is booked.";
        return 0;
        
    }
    int show_time=0;
    void session_time(){
            cout<<"\nBelow are the available show timings:"<<endl;
            int j=1;
            for(int i=0;i<t.size();i++,j++){
                if(mp[j-1]==true){
                    cout<<"To select "<<t[i]<<" show press " <<j<<endl;
                }
                else{
                    continue;
                }
            }
            cin>>show_time;
            seats_time[show_time-1]+=n;
            if(seats_time[show_time-1]==100){
                mp[show_time-1]=false;
            }
            cout<<n<<" seats are booked in the "<<t[show_time-1]<<" slot.";   
            sleep(1);
            system("CLS");
        }
        void details(){
        cout<<"Your booking details: "<<endl;
        cout<<"\t\t\t\t\t Ticket number: "<< rand()<<endl;
        cout<<"\t\t\t\t\t Movie name: "<< movie<<endl;
        cout<<"\t\t\t\t\t Number of seats: "<<n<<endl;
        cout<<"\t\t\t\t\t Seat numbers: "<<endl;
        int k=0;
        for(int x=0;x<10;x++){
            for(int y=0;y<10;y++){
                    if(st[x][y]!=0){
                        cout<<"\t\t\t\t\t\t row: "<<x+1<<" column: "<<y+1<<endl;
                    }
            }
        }
        cout<<"\t\t\t\t\t Time: "<<t[show_time-1]<<endl;
        cout<<"\t\t\t\t\t Per ticket price= "<< prices[show_time-1]<<endl;
        cout<<"\t\t\t\t\t GST= "<< 0.05*prices[show_time-1]<<endl;
        cout<<"\t\t\t\t\t Total ticket price: "<< prices[show_time-1]*n*1.05;
    }
};

class wel{
    public:
    int welcome(){
        ifstream in("welcome.txt");
        if(!in){
            cout<<"Cannot open file"<<endl;
        }
        char str[1000];
        while(in){
            in.getline(str,1000);
            if(in) cout<<str<<endl;
        }
        in.close();
        sleep(1);
        cout<<"\nStarting the program please wait";
        sleep(1);
        cout<<"\nloading up file";
        sleep(1);
        system("CLS");
        return 0;
    }
};
int main(){
    //wel c1;
    //c1.welcome();
    //moviename c2;
    //c2.book();
    seat s1;
    s1.book();
    s1.seatnumber();
    s1.session_time();
    s1.details();
    return 0;
    
}
int login(){
   string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t MOVIE BOOKING SYSTEM \n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t     LOGIN \n";	
   cout<<"\t\t\t\t\t------------------------------\n\n";	
   cout << "\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
   return 0;
}