#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 学生结构体定义
struct Student {
    string name;
    int score;
    int age;
};

// 首先按分数 (score) 从高到低排序。
// 如果分数相同，按年龄 (age) 从小到大排序。
// 如果分数和年龄都相同，按名字 (name) 的字典序从小到大排序。

class Solution {
public:
    /**
     * @param students 学生列表
     * @return 排序后的学生列表
     */
    void sortStudents(vector<Student>& students) {
        // 简单来说：容器里装的是什么，Lambda 的形参就是什么。
        sort(students.begin(), students.end(), [] (const Student& a, const Student& b) -> bool {
            // 分数不一样，按分数高到低排序
            if(a.score != b.score) {
                return a.score > b.score;
            }

            // 分数相同，年龄不同，年龄从小到达排序
            if(a.age != b.age) return a.age < b.age;

            // 分数年龄均相同，按名字排序
            return a.name < b.name;
        });
    }
};

// --- 测试代码 ---
int main() {
    vector<Student> students = {
        {"Alice", 90, 20},
        {"Bob", 85, 18},
        {"Charlie", 90, 18},
        {"David", 90, 18}
    };

    Solution sol;
    sol.sortStudents(students);

    for (const auto& s : students) {
        cout << "Name: " << s.name << ", Score: " << s.score << ", Age: " << s.age << endl;
    }

    return 0;
}