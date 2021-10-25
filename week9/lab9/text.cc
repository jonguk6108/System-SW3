#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#define TEXT "song yu seok"
#define INPUT_LINE_TEST_NUM 2
using namespace std;
class StringVar{
    public:
        StringVar(int size);
        StringVar();
        StringVar(const char a[]);
        StringVar(const StringVar& string_obj);
        ~StringVar();
        int length() const;
        void input_line(istream& ins);
        friend ostream& operator <<(ostream& outs, const StringVar& the_string);
        void operator =(const StringVar& right_side);
        char *get_value();
    private:
        char *value;
        int max_length;
};

class Text{
    public:
        Text(int size);
        Text();
        Text(const char a[]);
        Text(const Text& text_obj);
        ~Text();
        int length() const;
        void input_line(istream& ins);
        friend ostream& operator <<(ostream& outs, const Text& the_string);
        void operator =(const Text& text);
    private:
        StringVar* word;
        int max_length;
};

Text::Text(int size){
    //construct with size
}
Text::Text(){
    //default constructor
}
Text::Text(const char a[]){
    //construct with array
}
Text::Text(const Text& text_obj){
    //copy constructor
}
Text::~Text(){
    //destructor
}

int Text::length() const{
    //return total stored word num
}

void Text::input_line(istream& ins){
    //get input from command line like StringVar getline
}
ostream& operator <<(ostream& outs, const Text& text){
    //operator overloading
}
void Text::operator =(const Text& right_side){
    //assignment operator overloading
}

StringVar::StringVar(int size) : max_length(size){
    value = new char[max_length + 1];
    value[0] = '\0';
}
StringVar::StringVar() : max_length(20){
    value = new char[max_length + 1];
    value[0] = '\0';
}
StringVar::StringVar(const char a[]) : max_length(strlen(a)){
    value = new char[max_length+1];
    strcpy(value,a);
}
StringVar::StringVar(const StringVar& string_object) : max_length(string_object.length()){
    value = new char[max_length+1];
    strcpy(value,string_object.value);
}
StringVar::~StringVar(){
    delete [] value;
}
int StringVar::length() const{
    return strlen(value);
}
void StringVar::input_line(istream& ins){
    ins.getline(value, max_length+1);
}
ostream& operator <<(ostream& outs, const StringVar& the_string){
    outs << the_string.value;
    return outs;
}
char* StringVar::get_value(){
    return value;
}
void StringVar::operator =(const StringVar& right_side){
    int new_length = strlen(right_side.value);
    if(new_length>max_length){
        delete[] value;
        max_length = new_length;
        value = new char[max_length+1];
    }
    for(int i=0; i<new_length; i++)
        value[i] = right_side.value[i];
    value[new_length] = '\0';
}
void conversation(int max_name_size);

int main()
{
    conversation(20);
    cout << "End of demonstration.\n";
    return 0;
}

void show_string(StringVar the_string){
    cout << the_string << endl;
}
void conversation(int max_name_size)
{
    using namespace std;
    //test deafult constructor
    Text text_default(max_name_size);
    cout << text_default << text.length() <<endl;
    //test array constructor
    Text text(TEXT);
    cout << text <<  text.length()<<endl;
    //test copy constructor
    Text text1(text);
    cout << text1 <<  text.length()<<endl;
    //test assignment operator overloading
    Text text2(2);
    text2 = text;
    cout << text2 << text2.length() <<endl;
    // test input_line
    Text text3(INPUT_LINE_TEST_NUM);
    text3.input_line(cin);
    cout << text3 << text3.length() <<endl;

}
