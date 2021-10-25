#include "Tester.hh"
#include "stringlib.hh"

int main(){

    // Set the floating-point precision to "4" lower.
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    
    Tester* tt = new Tester();

    /* 1. Test of startsWith() */
    std::string target_str = "Hello World!";
    std::string start_str = "Hel";
    std::string start_str2 = "Helo";
    char start_char = 'H';
    char start_char2 = 'C';
    
    tt->printState("Testing startsWith()");
    tt->test_startsWith<std::string, std::string>(target_str, start_str);
    tt->test_startsWith<std::string, std::string>(target_str, start_str2);
    tt->test_startsWith<std::string, char>(target_str, start_char);
    tt->test_startsWith<std::string, char>(target_str, start_char2);
    tt->printSpace();

    /* 2. Test of endsWith() */
    std::string end_str = "d!";
    std::string end_str2 = "dd!";
    char end_char = '!';
    char end_char2 = 'd';

    tt->printState("Testing endsWith()");
    tt->test_endsWith<std::string, std::string>(target_str, end_str);
    tt->test_endsWith<std::string, std::string>(target_str, end_str2);
    tt->test_endsWith<std::string, char>(target_str, end_char);
    tt->test_endsWith<std::string, char>(target_str, end_char2);
    tt->printSpace();

    
    tt->printState(" Testing a various type conversion ");
    /* 3. Test of integerToString()  */
    int n1 = 0;
    tt->test_integerToString(n1);

    /* 4. Test of realToString()  */
    double d = 18.0625;
    tt->test_realToString(d);
    
    /* 5. Test of stringToInteger()  */
    std::string str2 = "0.0000001";
    tt->test_stringToInteger(str2);

    /* 6. Test of stringToReal()  */
    std::string str3 = "0";
    tt->test_stringToReal(str3);
    tt->printSpace();


    tt->printState("Testing String Case Conversion");
    /* 7. Test of toLowerCase()  */
    std::string str4 = "Hello World!!A";
    tt->test_toLowerCase(str4);
    
    /* 8. Test of toUpperCase()  */
    std::string str5 = "Hello World!!azAZ";
    tt->test_toUpperCase(str5);

    /* 9. Test of compareIgnoreCaseType()  */
    std::string str6 = "Hello World!!a";
    std::string str7 = "HELLO World!!A";
    tt->test_compareIgnoreCaseType(str6, str7);
    tt->printSpace();

    /* 10. Test of trim()  */
    tt->printState("Testing trim()");
    std::string str8 = "Hello!! My name is Chulsoo. I am senior year at SKKU.";
    tt->test_trim(str8);
    tt->printSpace();
}
