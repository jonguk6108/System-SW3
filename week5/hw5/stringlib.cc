#include "stringlib.hh"

bool startsWith(std::string str, std::string prefix){
    // TODO: Fill your code!!
    for(int i = 0; i < prefix.length( ); i++)
        if(prefix[i] != str[i])
            return false;

    return true;
}

bool startsWith(std::string str, char prefix){
    // TODO: Fill your code!!
    if(prefix != str[0])
        return false;
    return true;
}


bool endsWith(std::string str, std::string suffix){
    // TODO: Fill your code!!
    int sufl = suffix.length( );
    int strl = str.length( );
    for(int i = 0; i < sufl; i++)
        if(suffix[sufl - 1 - i] != str[strl - 1 - i])
            return false;

    return true;
}

bool endsWith(std::string str, char suffix){
    // TODO: Fill your code!!
    int strl = str.length( );
    if(suffix != str[strl - 1])
        return false;

    return true;
}

std::string integerToString(int n){
    // TODO: Fill your code!!
    // Hint: Use push_back function of std::string

    std::string ans;
    if(n == 0) ans = "0";
    while(n > 0) {
        ans = char (n%10 + 48) + ans;
        n = n/10;
    }
    return ans;
}

std::string realToString(double d){
    // TODO: Fill your code!!
    std::string ans;
    double real = d;

    int ireal;
    ireal = int(d);
    while(ireal > 0) {
        ans = char(ireal%10 + 48) + ans;
        ireal = ireal/10;
    }

    ireal = int(d);
    real = d - double(ireal);

    if(ireal == 0) ans = "0";
    ans = ans + '.';
    if(real == 0) return ans;

    while(real > 0.0001) {
        real = real * 10;
        ans = ans + char( int(real)%10 + 48 );
        real = real - double( int(real)%10 );
    }

    return ans;
}

int stringToInteger(std::string str){
    // TODO: Fill your code!!
    int strl = str.length();
    int p = 0;
    int ans = 0;
    for(int i = 0; i < strl; i++) {
        if(str[i] == '.') break;
        else p++;
    }
    
    for(int i = 0; i < p; i++)
        ans = ans*10 + int ( str[i] - 48);
    return ans;
}

double stringToReal(std::string str){
    // TODO: Fill your code!!
    double ans = 0;
    int p = 0;
    int strl = str.length();
    for(int i = 0; i < strl; i++) {
        if(str[i] == '.') break;
        else p++;
    }

    double tmp = 1;
    for(int i = 0; i < p; i++)
        ans = ans*10 + double (str[i] - 48);
    for(int i = p+1; i < strl; i++) {
        tmp = tmp/10;
        ans = ans + tmp * double(str[i] -48);
    }

    return ans;
}

std::string toLowerCase(std::string str){
    // TODO: Fill your code!!
    int strl = str.length();
    std::string ans;

    for(int i = 0; i < strl; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') ans = ans + char(('a' -'A') + str[i]);
        else ans = ans + str[i];
    }
    return ans;
}

std::string toUpperCase(std::string str){
    // TODO: Fill your code!!
    int strl = str.length();
    std::string ans;

    for(int i = 0; i < strl; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') ans = ans + char(str[i]- ('a'-'A'));
        else ans = ans + str[i];
    }
    return ans;
    
}

bool comapreIgnoreCaseType(std::string s1, std::string s2){
    // TODO: Fill your code!!
    // Hint: exploit the function you already implemented, "toLowerCase" or "toUpperCase".
    s1 = toLowerCase(s1);
    s2 = toLowerCase(s2);
    int s1l = s1.length();
    int s2l = s2.length();
    
    if(s1l != s2l) return false;
    for(int i = 0; i < s1l; i++)
        if(s1[i] != s2[i])
            return false;

    return true;
}

std::vector<std::string> trim(std::string str){
    // TODO: Fill your code!!
    std::vector<std::string> ans;
    int strl = str.length();
    std::string stmp;
    for(int i = 0; i <= strl; i++) {
        if(str[i] == ' ') {
            ans.push_back(stmp);
            stmp = "";
        }
        else
            stmp = stmp + str[i];
    }
    ans.push_back(stmp);
    return ans;
}
