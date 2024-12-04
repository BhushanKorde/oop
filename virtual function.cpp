//student database 
#include<iostream> 
#include<iomanip> 
using namespace std; 
class student 
{ 
    public: 
    int roll,i,ns; 
    string name,sub[10]; 
    void accept() 
    { 
        cout<<"Enter name:"; 
        cin>>name; 
        cout<<"Enter roll no:"; 
        cin>>roll; 
        cout<<"Enter no.of subject:"; 
        cin>>ns; 
        for(i=0;i<ns;i++) 
        { 
            cout<<i+1<<"]subject-"<<i+1<<":"; 
            cin>>sub[i]; 
        } 
    } 
}; 
class data:public student 
{ 
 public: 
 int code[10],assign[3],internal=0,external,j; 
 void acceptMarks() 
 { 
    cout<<"Enter Subject code:"<<endl; 
    for(i=0;i<ns;i++) 
    { 
        cout<<i+1<<"]"<<sub[i]<<":"; 
        cin>>code[i]; 
    } 
    cout<<"Enter marks for each assignment(out of 10):"<<endl; 
    for(i=0;i<ns;i++) 
    { 
        cout<<i+1<<"]"<<sub[i]<<":"<<endl; 
        for(j=0;j<3;j++) 
        { 
            cout<<j+1<<"]Assignment-"<<j+1<<":"; 
            cin>>assign[j]; 
            internal+=assign[j]; 
        } 
    } 
    internal=(internal*100)/30; 
    cout<<"Enter external marks(out of 70):"; 
    cin>>external; 
 } 
 
 void display(int sr) 
 { 
    //sr roll name assign internal external total 
    cout<<sr<<"\t"<<roll<<"\t\t"<<name<<"\t"; 
    cout<<setw(13)<<internal<<setw(15)<<external<<setw(16)<<internal+external; 
    cout<<"\t\t"<<"assign-"<<1<<":"<<assign[0]<<endl; 
    for(i=1;i<3;i++) 
    { 
        cout<<right<<setw(95)<<"assign-"<<i+1<<":"<<assign[i]<<"\n"; 
    } 
    cout<<endl; 
 } 
}; 
int main() 
{ 
    class data s; 
    s.accept(); 
    s.acceptMarks(); 
    cout<<"Sr\tRoll no\t\tName\t\tInternal\tExternal\tTotal\t\tAssignment"<<endl; 
    s.display(1); 
}