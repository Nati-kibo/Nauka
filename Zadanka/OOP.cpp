#include <iostream>
using std::string;

class AbstractUser {
    virtual void AskForPromotion() = 0;                     //method


};

class User :AbstractUser {                                //contract for class
private:

    string Name;
    string Company;
    int Age;
protected:
    //string Name;                           #we do not have to use getName later on
public:
    void setName(string name) {                             //setter
        Name = name;
    }
    string getName() {                                      //getter
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    void setAge(int age) {
        //if(age>=18)                                          condition to setAge
        Age = age;
    }
    int getAge() {
        return Age;
    }
    void IntroduceYourself() {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Company: " << Company << std::endl;
        std::cout << "Age: " << Age << std::endl;

    }
    User(string name, string company, int age) {// own constructor
        Name = name;
        Company = company;
        if (age < 18) {
            Age = 18;
        }
        else {
            Age = age;
        }
    }
    void AskForPromotion() {                            //provided implementation for contract
        if (Age > 30)
            std::cout << Name << " can be promoted." << std::endl;
        else
            std::cout << Name << " can't be promoted." << std::endl;
    }
    virtual void Work() {
        std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
    }
};

class Prouser : public User {                              //class CHILD:ADULT/ subclass:baseclass
public:
    string FavProgrammingLanguage;
    Prouser(string name, string company, int age, string language)
        :User(name, company, age), FavProgrammingLanguage(language)               //using assigned parameters from User constructor
    {
        //   FavProgrammingLanguage = language;       //assigning new parametr for only Prouser
    }
    void FixBug() {
        std::cout << getName() << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work() {
        std::cout << getName() << " is writing code in " << FavProgrammingLanguage << std::endl;
    }
};

class Megauser : public User {
public:
    string Subject;
    Megauser(string name, string company, int age, string subject)
        :User(name, company, age)
    {
        Subject = subject;
    }

    void Preparation() {
        std::cout << getName() << " prepared subject called " << Subject << std::endl;
    }
    void Work() {
        std::cout << getName() << " is teaching " << Subject << std::endl;
    }
};



 int main2()
{
    User user1 = User("Natasza", "Microsoft", 16);
    //user1.Name ="Natasza";
    //user1.Company ="Microsoft";
    //user1.Age = 16;
    user1.IntroduceYourself();
    user1.AskForPromotion();

    User user2 = User("Michal", "Riot", 40);
    user2.IntroduceYourself();
    user2.AskForPromotion();

    //user1.setAge(12);                                    setting your own Age
    std::cout << user1.getName() << " is " << user1.getAge() << " years old." << std::endl;

    Prouser prouser1 = Prouser("Nela", "Meta", 35, "c++");
    prouser1.FixBug();
    prouser1.AskForPromotion();                 //might be only used here by adding public in Prouser: User

    Megauser megauser1 = Megauser("Kate", "Meta", 45, "OOP");
    megauser1.Preparation();
    megauser1.AskForPromotion();

    prouser1.Work();
    megauser1.Work();

    User* u1 = &prouser1;                          //hold reference to class obj
    User* u2 = &megauser1;                         //pointing on derive classes form base class

    u1->Work();                                //works because Work() in User(base class)
    u2->Work();                                //is signed as virtual void and NOT void

    return 0;
}