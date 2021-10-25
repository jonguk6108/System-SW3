#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#define copy
#define assignment
using namespace std;
class StringVar{
    public:
        StringVar(int size);
        StringVar();
        StringVar(const char a[]);
#ifdef copy
        StringVar(const StringVar& string_obj);
#endif
        ~StringVar();
        int length() const;
        void input_line(istream& ins);
        friend ostream& operator <<(ostream& outs, const StringVar& the_string);
#ifdef assignment
        void operator =(const StringVar& right_side);
#endif
    private:
        char *value;
        int max_length;
};

StringVar::StringVar(int size){
    //initializes the object so it can accept string values up to size
    //in length. Sets the value of the object equal to the empty string
}
StringVar::StringVar(){
    //Initializes the object so it can accept string values of length 100
    //or less. Sets the value of the object equal to the empty string.
}
StringVar::StringVar(const char a[]){
    //Precondition: The array a contains characters terminated with '\0'.
    //Initializes the object so its value is the string stroed in a and
    //so that it can later be set to string values up to strlen(a) in length.
    //hint : strcpy()
}
#ifdef copy
StringVar::StringVar(const StringVar& string_object){
    //Copy constructor.
    //hint : strcpy()
}
#endif
StringVar::~StringVar(){
    cout<<"destructor called\n";
    //Returns all the dynamic memory used by the object to the freestore.
}
int StringVar::length() const{
    //returns the length of the current string value.
    //hint : strlen()
}
void StringVar::input_line(istream& ins){
    //Action: The next text in the input stream ins, up to '\n', is copied
    //to the calling object. If there is not sufficient room, then
    //only as much as will fit is copied.
    //hint : getline()
}
ostream& operator <<(ostream& outs, const StringVar& the_string){
    //Overloads the << operator so it can be used to output values
    //of type StringVar
    //Precondition: If outs is a file output stream, then outs
    //has already benn connected to a file
}
#ifdef assignment
void StringVar::operator =(const StringVar& right_side){
    //Overloads the assignment operator = to copy a string
    //from one object to other. If left side is smaller then 
    //right side, then expend left side length to right side length.
}
#endif

void conversation(int max_name_size);

int main()
{
    conversation(30);
    cout << "End of demonstration.\n";
    return 0;
}

void show_string(StringVar the_string){
    cout <<"(show string): "<< the_string << endl;
}
void conversation(int max_name_size)
{
    using namespace std;
    //test constructor
    StringVar your_name(max_name_size), our_name("Oh-gong");

    //testing copy constructor
    StringVar clone1_name(our_name);
    show_string(clone1_name);
    cout << "our name after function call: "<< our_name<<endl;

    //testing assignment operation overloading
    StringVar clone2_name(10);
    clone2_name = our_name;
    cout << "enter the second clone's name"<<endl;
    clone2_name.input_line(cin);
    cout<< "our name after assignment: "<<our_name<<endl;
    
    cout << "What's your name?\n";
    your_name.input_line(cin);
    cout << "We are " << our_name <<" "<< clone1_name <<" "<< clone2_name << endl;
    cout << "We will meet again " << your_name << endl; 

}
