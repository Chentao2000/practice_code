/******************************************************************************

 4 _6 文件结构的 “  图”

问题描述  : 在计算机中你看到的文件结构 通常很有用 ，我们用程序来模拟它吧

输入数据 ： 编写一个程序 ，读取一些测试的数据，每组测试表示一个计算机的文件结构，
每组测试数据 以 * 结尾，而 合理的输入数据 以 # 结尾，一组测试数据包含一些文件目录
的名字，（虽然在输入中没有给出，但是总假设 ROOT 目录 是最外层目录）
在输入以 ] 表示一个目录的结束， 目录的名字第一个字母是 "d" 文件名字的第一个
字母是 " f " 文件名可能有扩展名也可能没有 文件和目录的名字都不包含空格 

输出要求： 在显示一个目录内容，先显示其中子目录（如果有的话）
然后再显示文件 ，文件按照名字的字母表顺序显示 （目录不用按照名字 字母表顺序线显示）
需要按照目录出现的先后顺序显示
....


输入样例 ：
 file1
 file2
 dir3
 dir2
 file1
 file2
 ]
 ]
 file4
 dir1
 ]
 file3
 file2
 file1
 *
 #
 
 输出样例 :
 DATA SET1 : 
 
 ROOT 
 |  dir3 
 |  |    dir2
 |  |    file1
 |  |    file2
 |  dir1 
 file1
 file2
 file3
 file4
 
 DATA SET2 :
 ROOT
 file1
 file2
 
 
*******************************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std ;
int fileStructure(int level,string dir, int nCase){
    vector<string>v ; // 用一个vector 存储文件
    for (int i = 0; i <=level; i++) {
        count << " | ";
    if(level !=0) count << dir <<endl;
        int t = 0;
    while(TRUE){
        string s;
        cin >> s;
        if(s[0] == "#")return 0;
        if(t == 0 && level == 0 ){
            cout << " Data SET"<<nCase << ":" <<endl;
            std::cout << dir << std::endl;
            t = 1;
        }
        
    }
}
