#include <vector>

class String {
    private:
    std::vector <char> char_array;

    public:
    String();
    String(char str[]);
    String(std::vector<char> str);

    size_t len();

    char at(size_t idx);
    void set(size_t idx, char c);

    size_t find(char c);
    size_t end();

    void print();

    friend void print(String str);

    friend std::vector<String> split(String str, char divide);

    String operator + (String rhs);
    String operator + (char rhs[]);
    
    void operator += (String rhs);
    void operator += (char rhs[]);

    void operator =(char rhs[]);
    void operator =(std::vector<char> rhs);

    String operator *(unsigned rhs);
    void operator *=(unsigned rhs);

    char operator [](size_t rhs) const;

    String operator <<(size_t rhs);
    String operator >>(size_t rhs);

    bool operator ==(String rhs);
    bool operator !=(String rhs);

};
