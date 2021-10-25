/*
 * This interface exports several useful string functions that are not
 * included in the C++ string library.
 */
#ifndef _stringlib_h
#define _stringlib_h

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

/**
 * @brief Returns true if the string str starts with the specified prefix, which
 * may be either a string or a character.
 * 
 * @Usage: if (startsWith(str, prefix)) . . .
 * 
 * @param str 
 * @param prefix 
 * @return true 
 * @return false 
 */
bool startsWith(std::string str, std::string prefix);
bool startsWith(std::string str, char prefix);

/**
 * @brief Returns true if the string str ends with the specified suffix, which may
 * be either a string or a character.
 * 
 * @Usage: if (endsWith(str, suffix)) . . .
 * 
 * @param str 
 * @param suffix 
 * @return true 
 * @return false 
 */
bool endsWith(std::string str, std::string suffix);
bool endsWith(std::string str, char suffix);

/**
 * @brief Converts an integer into the corresponding string of digits.
 * For example, calling integerToString(123) returns the string "123". 
 * 
 * @Usage: std::string str = integerToString(n);
 *
 * @param n: an interger to be converted into string type.
 * @return std::string 
 */
std::string integerToString(int n);

/**
 * @brief Converts a floating-point number into the corresponding string form. 
 * For example, calling realToString(23.45) returns the string "23.45".
 * 
 * @Usage: string s = realToString(d);
 * 
 * @param d : a double  to be converted into string type.
 * @return std::string 
 */
std::string realToString(double d);

/**
 * @brief Converts a string of digits into an integer.  If the string is not a
 * legal integer or contains extraneous characters other than whitespace,
 * stringToInteger calls error with an appropriate message.
 * 
 * @Useage int n = stringToInteger(str);
 * 
 * @param str : a string to be converted into int type.
 * @return int 
 */
int stringToInteger(std::string str);

/**
 * @brief Converts a string representing a real number into its corresponding
 * value.  If the string is not a legal floating-point number or contains
 * extraneous characters other than whitespace, stringToReal calls error
 * with an appropriate message.
 * 
 * @Usage: double d = stringToReal(str);
 * 
 * @param str : a string to be converted into double type.
 * @return double 
 */
double stringToReal(std::string str);

/**
 * @brief Returns a new string in which all uppercase characters have been
 * converted into their lowercase equivalents.
 * 
 * @Usage: string s = toLowerCase(str);
 * 
 * @param str 
 * @return std::string 
 */
std::string toLowerCase(std::string str);

/**
 * @brief Returns a new string in which all lowercase characters have been
 * converted into their uppercase equivalents.
 * 
 * @Usage: std::string s = toUpperCase(str);
 * 
 * @param str 
 * @return std::string 
 */
std::string toUpperCase(std::string str);

/**
 * @brief Returns true if s1 and s2 are equal. Note that this functino is case-insensitive.
 * 
 * @Usage: if (comapreIgnoreCaseType(s1, s2)) . . .
 * 
 * @param s1 
 * @param s2 
 * @return true
 * @return false
 */
bool comapreIgnoreCaseType(std::string s1, std::string s2);

/**
 * @brief Divide the sentence by white space. 
 * And returns the divided strings in form of a string container.
 * 
 * @Usage: vecotr<string> trimmed = trim(str);
 * 
 * @param str 
 * @return A container of strings
 */
std::vector<std::string> trim(std::string str);

#endif