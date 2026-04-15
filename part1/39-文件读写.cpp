#include <iostream>
#include <fstream>
using namespace std;


// 读写文件： fstream类
// 打开时候需要指定打开的路径和打开方式
// 写文件和cout 差不多， 只不过是写到文件里了
// 操作完毕要关闭文件
void test_write() {
    ofstream ofs("test.txt", ios::out);
    if (!ofs) {
        cout << "文件打开失败！" << endl;
        return;
    }

    ofs << "Hello, World!" << endl;
    ofs << "This is a test file." << endl;
    ofs << "C++ file I/O is easy!" << endl;
    ofs << "End of file." << endl;

    ofs.close();
}

void test_read() {
    // 1 创建输入文件流对象
    ifstream ifs;
    // 2 打开文件
    ifs.open("test.txt", ios::in);
    // 3 判断文件是否成功打开
    if (!ifs) {
        cout << "文件打开失败！" << endl;
        return;
    }
    // 4 读取文件内容
    // (1) char 数组接收
    // char buffer[1024] = {0};
    // // 以空格为分割符，读取文件内容到 buffer 中，直到遇到空格或换行符
    // ifs >> buffer;
    // cout << "读取到的内容 (char数组): " << buffer << endl;
    // for(int i = 0; buffer[i] != '\0'; i++) {
    //     cout << "buffer[" << i << "] = " << buffer[i] << endl;
    // }

    // ifs >> buffer; // 继续读取下一个单词
    // cout << "继续读取到的内容 (char数组): " << buffer << endl;
    // for(int i = 0; buffer[i] != '\0'; i++) {
    //     cout << "buffer[" << i << "] = " << buffer[i] << endl;
    // }

    // (2) string对象接收
    // string line;
    // // 以行的方式读取文件内容到 line 中，直到遇到换行
    // while(getline(ifs, line)) {
    //     cout << "读取到的内容 (string对象): " << line << endl;
    // }

    // (3) char数组接收
    // char buffer[1024] = {0};
    // while(ifs.getline(buffer, sizeof(buffer))) {
    //     cout << "读取到的内容 (char数组): " << buffer << endl;
    // }


    // (4) 单个char读取
    // 逐个字符读取文件内容，直到文件末尾
    char ch;
    while(ifs.get(ch)) {
        cout << ch;
    }
    ifs.close();
}

int main() {
    // test_write();
    test_read();
    return 0;
}