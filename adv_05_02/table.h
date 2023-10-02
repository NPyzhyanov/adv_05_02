#ifndef TABLE_H
#define TABLE_H

template <class T>
class Table
{
public:
    Table(int m, int n) {height = (m > 0 ? m : 1); length = (n > 0 ? n : 1); address = new T*[height]; for(int i = 0; i < height; i++) {address[i] = new T[length]();}}
    ~Table() {for (int i = 0; i < height; i++) {delete[] address[i]; address[i] = nullptr;} delete[] address; address = nullptr;}
    
    class Row;
    Row operator[](int index) const {return Row(address[index]);}
    
    class Row
    {
    public:
        Row(T* row_address_) {row_address = row_address_;}
        T &operator[](int index) {return row_address[index];}
    private:
        T* row_address;
    };
    
    int Size() const {return height * length;}
    int Size(std::string dimension) const {if (dimension == "height") {return height;} if (dimension == "length") {return length;} else return -1;}
    
private:
    int height = 0;
    int length = 0;
    
    T** address = nullptr;
    
};

#endif // TABLE_H
