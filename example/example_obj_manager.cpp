#include "umt/umt.hpp"
#include <iostream>

/// 查找一个已经存在的命名共享对象并修改其值
void func(){
    auto str = umt::ObjManager<std::string>::find("str-0");
    if(str) *str = "666";
}

/// 创建一个已经存在的命名共享对象，创建失败
void error0(){
    auto str = umt::ObjManager<std::string>::create("str-0");
    if(!str) std::cout << "create fail!" << std::endl;
}

/// 查找一个不存在的命名共享对象，查找失败
void error1(){
    auto str = umt::ObjManager<std::string>::find("str-1");
    if(!str) std::cout << "find fail!" << std::endl;
}

int main(){
    auto str = umt::ObjManager<std::string>::create("str-0", "Hello,World!");
    std::cout << "after create: [" << *str << "]" << std::endl;
    func();
    std::cout << "after func: [" << *str << "]" << std::endl;
    error0();
    error1();
    return 0;
}