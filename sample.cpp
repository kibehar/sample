#include <iostream>
#include <cstring>

using namespace std;




struct patientInfo{
     string name,tipFromDoc,recommend;
     int phone;
     char address;
     char bloodType;
     int age,weight,height;
     int id;
     string passcode2,passcode;
};

struct doctor{
     string name;
     int phone;
     char address;
    string passcode;

}d[1000];


void Administrator();
void menu();
void patient();
void newPatient();
void oldPatient();
void doctor();
void hospital();
void medicalTip();
void edit();
int c = 0;
int id = 1;

struct patientInfo p[1000];

int main()
{
    int id;
    int c=0;
    menu();

return 0;
}

void menu(){
char opp;
system("cls");
cout<<"menu"<<endl;
cout<<"1.Administrator"<<endl;
cout<<"2.patient"<<endl;
cout<<"3.doctor"<<endl;
cout<<"4.hospital"<<endl;
cout<<"5.exit"<<endl;


cout<<"enter your choice: ";
enter:
cin>>opp;
if(opp=='1'||opp=='2'||opp=='3'||opp=='4'){
switch(opp){
case '1':
    system("cls");
    Administrator();
    break;
case '2':
    system("cls");
    patient();
    break;
case '3':
    system("cls");
    doctor();
    break;
case '4':
    system("cls");
    hospital();
    break;
case '5':
    system("cls");
    exit(0);
}}
 else
   {
    cout<<"\nwrong input try again: ";
    goto enter;}

}


void patient(){
char c;

cout<<"1.register"<<endl;
cout<<"2.login"<<endl;
cout<<"3.edit"<<endl;
cout<<"4.back "<<endl;
cout<<"enter your choice: ";
enter:
cin>>c;
if(c=='1'||c=='2'||c=='3'||c=='4'){
switch(c){
case '1':
    system("cls");
    newPatient();
    break;
case '2':
    oldPatient();
    break;
 case '3':
     system("cls");
    edit();
    break;
 case '4':
      menu();
    break;
    }}
    else {
    cout<<"\nwrong input try again: ";
    goto enter;
    }
}


//registration
void newPatient(){

int response;


  for (int i = 0; i<1; i++){
    cout<<"enter your name: ";
    cin.ignore();
    getline(cin,p[i+c].name);
    cout<<"enter your age: ";
    cin>>p[i+c].age;
      trya:
    cout<<"\ncreate password: ";
    cin.ignore();
    getline (cin,p[i+c].passcode);

    cout<<"\nRe-enter your password";
    getline(cin,p[i+c].passcode2);
    fflush(stdin);
    if(p[i+c].passcode == p[i+c].passcode2)
        cout<<"\npassword successfully created";
    else
    {
        cout<<"passwords doesn't match please try again : \n";
        goto trya;
    }
    p[i+c].id=id;
    c++;
    id++;
  }
  cout<<"\n\nregistered successfully";



   do{
    cout<<"\n\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     patient();
}
//display registered patients
void display(){

int response;
    for(int i =0; i<c; i++){
        cout<<"patient ID: ";
        cout<<p[i].id;
        cout<<"\npatient name: ";
        cout<<p[i].name<<endl;
        cout<<"patient age: ";
        cout<<p[i].age<<endl;
        cout<<"\n";
    }
    cout<<"total: "<<c;

       do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     doctor();
}
//login if already registered
void oldPatient(){

    int response;
string pass;
    cout<<"\nenter passcode";
    cin>>pass;

    for(int i = 0; i<c; i++){
    if( pass==p[i].passcode && pass==p[i].passcode2){

        cout<<"patient ID: ";
        cout<<p[i].id;
        cout<<"\npatient name: ";
        cout<<p[i].name<<endl;
        cout<<"patient age: ";
        cout<<p[i].age<<endl;
        cout<<"doctor recommendation: ";
        cout<<p[i].recommend<<endl;
        cout<<"doctor top: ";
        cout<<p[i].tipFromDoc<<endl;
        cout<<"\n";

    }
    }

    do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     patient();





}
//doctor
void doctor(){
    char c;
 cout<<"1.display patients\n";
 cout<<"2.Medical tips\n";
 cout<<"3.back\n";

 cout<<"enter your choice: ";
 enter:
 cin>>c;
 cout<<endl;
if(c=='1'||c=='2'||c=='3'||c=='4'){
 switch(c){
 case '1':
     system("cls");
     display();

     break;
 case '2':
     system("cls");
     medicalTip();
    break;

case '3':
     system("cls");
     menu();
    break;
 }}
 else {
    cout<<"\nwrong input try again: ";
    goto enter;
 }

}
void medicalTip(){

    int response;
    string rec,tip;
    int pid;
    cout<<"enter patient ID: ";
    cin>>pid;

     for(int i=0; i<c; i++){
        if(pid==p[i].id){

        cout<<"patient ID: ";
        cout<<p[i].id;
        cout<<"\npatient name: ";
        cout<<p[i].name<<endl;
        cout<<"patient age: ";
        cout<<p[i].age<<endl;
        cout<<"\n";
        }
     }

     cout<<"enter tip\n";
     getline (cin,tip);

     cout<<"enter recommendation\n";
     getline (cin,rec);

      for(int i=0; i<c; i++){
        if(pid==p[i].id){
             p[i].tipFromDoc = tip;
             p[i].recommend = rec;
        }
        }

    do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     doctor();

}
void edit()
{
int ch,pid,age1,response;
  string name1;
system ("cls");
cout<<"enter your id : ";
cin>>pid;
for(int i=0; i<c;i++){
        if(pid==p[i].id){
cout<<"\n[1].name : ";
cout<<"\n[2].age : ";
cout<<"\n[3].back : ";
cout<<"\n\nenter your option to edit : \n";
enter:
cin>>ch;
if(ch=='1'||ch=='2'||ch=='3'||ch=='4'){
switch(ch)
{
case '1':

    cout<<"enter the new name : ";
    cin>>name1;
    p[i].name=name1;
    break;

case '2':
    cout<<"\nenter the new age : ";
    cin>>age1;
    p[i].age=age1;
    break;
    }
    }
else  {
        cout<<"\nwrong input try again: ";
    goto enter;
 }

}}

do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     patient();
}
//hospital
void Administrator()
{
int pidd,response;
bool deletes=false;
char cho;
cout<<"For administrator side please enter the id of patient you want to clear(delete) information : ";
cin>>pidd;
for(int i=0; i<c;i++){
        if(pidd==p[i].id){
cout<<"\n[1].name : ";
cout<<"\n[2].age : ";
cout<<"\n\nplease enter the specific option you want to delete : ";
enter:
cin>>cho;
if(cho=='1'||cho=='2'||cho=='3'||cho=='4'){
switch(cho)
{
case '1':
    p[i].name=deletes;
    cout<<"\nName deleted successfully!";
    break;

case '2':

    p[i].age=deletes;
    cout<<"\nAge deleted successfully!";
    break;}}
else  {
        cout<<"\nwrong input try again: ";
    goto enter;
 }


}}
do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     menu();
}

void hospital(){




}
