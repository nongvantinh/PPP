/*
9. Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary text file into binary and one
program that reads binary and converts it to text. Test these programs by comparing a text file with what you get by
converting it to binary and back.
*/
#include "../../../std_lib_facilities.h"

void write_bytes_to(const std::string &);
void write_to(const std::string &);
std::string read_from(const std::string &);
std::string read_bytes_from(const std::string &);

int main()
{
    std::string fname = "bytesdata.txt";
    write_bytes_to(fname);
    std::cout << read_bytes_from(fname) << endl;
}
void write_to(const std::string &fname)
{
    std::ofstream ofs(fname);
    if (!ofs)
        throw std::runtime_error("Can't open file name for write operation.\n");
    ofs << "Hello world!";
    ofs.close();
}

std::string read_from(const std::string &fname)
{
    std::ifstream ifs(fname);
    if (!ifs)
        throw std::runtime_error("Can't open file name for read operation.\n");
    std::string data;
    getline(ifs, data);
    ifs.close();
    return data;
}

void write_bytes_to(const std::string &fname)
{
    std::string data = read_from("mydata.txt");
    std::ofstream ofs(fname, std::ios_base::binary);
    if (!ofs)
        throw std::runtime_error("Can't open file name for write operation.\n");
    for (char ch : data)
        ofs.write(as_bytes(ch), sizeof(char));
    ofs.close();
}

std::string read_bytes_from(const std::string &fname)
{
    std::ifstream ifs(fname, std::ios_base::binary);
    if (!ifs)
        throw std::runtime_error("Can't open file name for read operation.\n");
    std::ostringstream oss;
    for (char ch; ifs.read(as_bytes(ch), sizeof(char));)
        oss << ch;
    ifs.close();
    return oss.str();
}