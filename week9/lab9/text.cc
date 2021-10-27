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
        char *get_value() const;
    private:
        char *value;
        int max_length;
};

class Text{

    public:
        Text(int size);
        Text();
        Text(const char a[]);
        StringVar get_iword (int i) const;
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
char* StringVar::get_value() const{
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

Text::Text(int size){
    //construct with size
    max_length = size;
    word = new StringVar[max_length + 1];
    word[0] = StringVar(" ");
}
Text::Text(){
    //default constructor
    max_length = 50;
    word = new StringVar[max_length + 1];
    word[0] = StringVar(" ");
}
Text::Text(const char a[]){
    //construct with array
    int length = 0;
    for(int i = 0; i < strlen(a); i++) {
        if(i == 0)
            continue;
        if(a[i] == ' ' && a[i-1] != ' ')
            length++;
        if(i == strlen(a) - 1)
            length++;
    }

    max_length = length;
    word = new StringVar[max_length + 1];

    char ctmp[30];
    int s = 0;
    int f = 0;
    for(int i = 0; i < max_length; i++) {
        while(1) {
            if(a[f] == '\0') break;
            if(a[f] == ' ') break;
            f++;
        }
        for(int j = s; j < f; j++)
            ctmp[j-s] = a[j];
        ctmp[f-s] = '\0';
        word[i] = StringVar(ctmp);
        s = f+1;
        f = s;
    }
    word[max_length] = StringVar(" ");
}
StringVar Text::get_iword (int i) const{
    return word[i];
}
Text::Text(const Text& text_obj){
    //copy constructor
    max_length = text_obj.length();
    word = new StringVar[max_length + 1];
    for(int i = 0; i < max_length + 1; i++)
        word[i] = text_obj.get_iword(i); 
}
Text::~Text(){
    //destructor
    delete [] word;
}

int Text::length() const{
    //return total stored word num
    for(int i = 0; i < max_length; i++)
        if(strcmp( word[i].get_value(), " ") == 0)
            return i;
    return max_length;
}

void Text::input_line(istream& ins){
    //get input from command line like StringVar getline
    StringVar stmp;
    stmp.input_line(ins);

    Text ttmp(stmp.get_value());
    
    for(int i = 0; i < max_length; i++)
        word[i] = ttmp.get_iword(i).get_value();
    word[max_length] = StringVar(" ");

}
ostream& operator <<(ostream& outs, const Text& text){
    //operator overloading
    int length = text.length();
    for(int i = 0; i <= length; i++) {
        if( strcmp(text.get_iword(i).get_value(), " ") == 0)
            return outs;
        outs << text.get_iword(i).get_value() << " "; 
    }
}
void Text::operator =(const Text& right_side){
    //assignment operator overloading
    int new_length = right_side.length();
    if( new_length > max_length ) {
        delete[] word;
        max_length = new_length;
        word = new StringVar[max_length + 1];
        for(int i = 0; i < max_length + 1; i++)
            word[i] = right_side.get_iword(i); 
    }
    for( int i = 0; i < new_length; i++ )
        word[i] = right_side.get_iword(i); 
    word[new_length] = StringVar(" ");
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
    cout << text_default << text_default.length() <<endl;
    //test array constructor
    Text text(TEXT);
    cout << text <<  text.length()<<endl;
    //test copy constructor
    Text text1(text);
    cout << text1 <<  text1.length()<<endl;
    //test assignment operator overloading
    Text text2(2);
    text2 = text;
    cout << text2 << text2.length() <<endl;
    // test input_line
    Text text3(INPUT_LINE_TEST_NUM);
    text3.input_line(cin);
    cout << text3 << text3.length() <<endl;

}
