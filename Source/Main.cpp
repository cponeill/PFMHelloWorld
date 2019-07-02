/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
using namespace std;

struct Person
{
    int age = 0;
    int height = 0;
    float hairLength{0.f};
    float GPA{0.f};
    float SATScore{0.f};
    int distanceTraveled = 0;
    int length = 0;
    int number = 0;
    
    String name;
    
    Person() { };
    
    
    Person(String personsName) : name(personsName)
    {
        DBG( "Person CTOR: " + name);
    }
    
    Person(int age)
    {
        this->age = age;
    }

    
    ~Person()
    {
        DBG( "Person DTOR: " + name);
    }
    
    int run(int howFast, bool startWithLeftFoot);
    
    void moveAndSetAge(int speed, int newAge);
    
    struct Foot
    {
        int stepForward() { return 0; }
    };
    
    Foot leftFoot;
    Foot rightFoot;
};

int Person::run(int howFast, bool startWithLeftFoot)
{
    if ( startWithLeftFoot )
    {
        return leftFoot.stepForward() + rightFoot.stepForward();
    }
    return rightFoot.stepForward() + leftFoot.stepForward();
}

void Person::moveAndSetAge(int speed, int newAge)
{
    this->run(speed, true);
    this->age = number;
}

struct Family
{
    Family() { DBG("Family ctor: "); }
    ~Family() { DBG("Family dtor: "); }
    Person mom{"mom"};
    Person dad{"dad"};
    Person child1{"ch1"};
    Person child2{"ch2"};
};

void familyFunction()
{
    Family family;
}

void doStuff()
{
    //Person p{"person"};
    Person p(6);
    p.moveAndSetAge(5, 42);
}






void functionForLearningCPP()
{
    Person a, b, c;
    
    
    vector<Person*> persons = {&a, &b, &c};
    for ( size_t i = 0; i < persons.size(); i++)
    {
        Person* p = persons[i];
        p->age = 24;
    }
    /*
     persons[i].name of member function or variable
     */
}

void addressOfFunction()
{
    Person a;
    
    Person* p1 = nullptr;
    Person* p2 = &a;
    Person* p3 = nullptr;
    
    if (p1 != nullptr)
    {
        p1->age = 42;
        (*p1).age = 42;
    }
    
    p1 = &a;
    p2 = &a;
    p3 = &a;
    
    Person b, c;
    
    p1 = &a;
    p1 = &b;
    p1 = &c;
    
    Person* personPtr; // whoops, didn't initialize
    *personPtr;
    
}



void normalCopy()
{
    Person a;
    Person b;
    a = b;
}


void copyWithPtr()
{
    Person a;
    Person b;
    Person* p1 = &a;
    *p1 = b;
}


void referenceFunction()
{
    Person a;
    Person& referenceToA = a;
}

void growOlder(Person& person)
{
    person.age += 1;
    person.height += 1;
    person.hairLength += 1.0;
    
}

void func()
{
    Person p;
    growOlder(p);
}



void gotcha(Person* & p)
{
    auto person = std::make_unique<Person>();
    p = person.get();
}

Person& getReferenceToAPerson()
{
    auto person = make_unique<Person>();
    return *person;
}

void danglingReference()
{
    Person& ref = getReferenceToAPerson();
    DBG(ref.age);
}

void func(const String& str) {}

void test()
{
    {
        const String __unnamed__{"Hello World"};
        func(__unnamed__);
    }
    func("Hello World");
}


void constFunc(const String& str)
{
    DBG(str);
}

void callingAConstFunc()
{
    String str {"Hello World"};
    constFunc(str);
    str += "hello";
    constFunc(str);
}


//==============================================================================
class HelloWorldApplication  : public JUCEApplication
{
public:
    //==============================================================================
    HelloWorldApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& commandLine) override
    {
        //familyFunction();
        //doStuff();
        //addressOfFunction();
        //danglingReference();
        callingAConstFunc();
        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainComponent class.
    */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name)  : DocumentWindow (name,
                                                    Desktop::getInstance().getDefaultLookAndFeel()
                                                                          .findColour (ResizableWindow::backgroundColourId),
                                                    DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);

           #if JUCE_IOS || JUCE_ANDROID
            setFullScreen (true);
           #else
            setResizable (true, true);
            centreWithSize (getWidth(), getHeight());
           #endif

            setVisible (true);
        }

        void closeButtonPressed() override
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (HelloWorldApplication)
