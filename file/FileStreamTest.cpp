//
// Created by JackyWoo on 2021/3/5.
//

#include <fstream>
#include <iostream>

using namespace std;



int main()
{
    std::ifstream in("fstream_test.txt");
    // 判断文件是否存在
    if(!in){
        std::cout<<"file not exist!";
    }
    in.close();

    std::ofstream out("fstream_test.txt", ios::trunc|ios::out);
    std::string s = "1234567890";
    byte *c = new byte[s.length()];
    for(int i=0;i<s.length();i++){
        *(c+i) = static_cast<byte>(s[i]);
    }
    out.write(reinterpret_cast<const char *>(c), 10);
    out.close();

    std::ifstream in2("fstream_test.txt", ios::binary);
    in2.seekg(0,ios::end);
    unsigned int size = in2.tellg();
    in2.seekg(0, ios::beg);

    char * b = new char[10];
    in2.read(b, size);
    in2.close();

    std::cout<<b<<std::endl;


}