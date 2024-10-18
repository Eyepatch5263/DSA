#include<iostream>
using namespace std;
#include<string.h>
class Hero{
    public:
    int health;
    char level;
    char *name=new char[100];
    // Hero(int health,char level){
    //     this->health=health;
    //     this->level=level;
    // }

    //copy constructor
    Hero temp(Hero& temp){
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        this->health=temp.health;
        this->level=temp.level;
    }
    int getHealth(){
        return health;
    };

    char getLevel(){
        return level;
    }

    int setHealth(int health){
        this->health=health;
    }
    char setLevel(char level){
        this->level=level;
    }

    void print(){
        cout<<this->level<<endl;
        cout<<this->health<<endl;
        cout<<this->name<<endl;
    }

    void setName(char name[]){
        this->name=name;
    }
};
int main(){
    Hero Suresh;
    Suresh.setHealth(340);
    Suresh.setLevel('A');
    char name[10]="eyepatch";
    Suresh.setName(name);
    Hero mahesh(Suresh);
    mahesh.name[0]='G';
    Suresh.print();
    mahesh.print();
    



    // Hero ramesh;
    // ramesh.setHealth(54);
    // ramesh.setLevel('A');
    // char name[10]="Eyepatch";
    // ramesh.setName(name);
    // ramesh.print();
    // int health=ramesh.getHealth();
    // cout<<"health: "<<health<<endl;
    // char level=ramesh.getLevel();
    // cout<<"level: "<<level<<endl;

}