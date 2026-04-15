#include "workManager.h"
#include "manager.h"
#include "boss.h"
#include "employee.h"

void WorkerManager::showMenu() {
    cout << "****************************************" << endl;
    cout << "********  欢迎使用职工管理系统！  ********" << endl;
    cout << "**********  0.退出管理程序  **********" << endl;
    cout << "**********  1.增加职工信息  **********" << endl;
    cout << "**********  2.显示职工信息  **********" << endl;
    cout << "**********  3.删除离职职工  **********" << endl;
    cout << "**********  4.修改职工信息  **********" << endl;
    cout << "**********  5.查找职工信息  **********" << endl;
    cout << "**********  6.按照编号排序  **********" << endl;
    cout << "**********  7.清空所有文档  **********" << endl;
    cout << "****************************************" << endl;
    cout << endl;
}

WorkerManager::WorkerManager() : m_EmpArray(nullptr), m_EmpNum(0) {
    ifstream ifs;
    
    ifs.open(FILE_NAME, ios::in);               // 以读的方式打开文件
    if (!ifs.is_open()) {
        cout << "文件不存在！" << endl;
        this->m_EmpArray = nullptr;
        this->m_EmpNum = 0;
        ifs.close();
        return;
    }

    // 文件存在，读取文件中的职工信息
    string name;
    uint32_t id, did;
    
    // 跳过文件第一行的标题
    string firstLine;
    getline(ifs, firstLine);  // 跳过第一行

    while (ifs >> name >> id >> did) {
        Worker* worker = nullptr;
        switch(did) {
            case 0:
                worker = new Boss{id, name, did};
                break;
            case 1:
                worker = new Manger{id, name, did};
                break;
            case 2:
                worker = new Employee{id, name, did};
                break;
            default:
                cout << "文件中职工部门编号有误！" << endl;
        }
        if(worker != nullptr) {
            // 将新创建的职工对象指针存入员工指针数组
            Worker** newSpace = new Worker*[this->m_EmpNum + 1];
            for (uint32_t i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
            newSpace[this->m_EmpNum] = worker;

            delete[] this->m_EmpArray;       // 释放原来员工指针数组
            this->m_EmpArray = newSpace;     // 更新员工指针数组
            this->m_EmpNum++;                // 更新员工数量
        }
    }
    ifs.close();
}

WorkerManager::~WorkerManager() {
    if(m_EmpArray != nullptr) {
        for (uint32_t i = 0; i < m_EmpNum; i++) {
            delete m_EmpArray[i];    // 释放每个员工对象
        }
        delete[] m_EmpArray;       // 释放员工指针数组
        m_EmpArray = nullptr;
    }
}

void WorkerManager::exitSystem() {
    cout << "感谢使用职工管理系统！" << endl;
    exit(0);
}

void WorkerManager::addEmp() {
    cout << "请输入添加的职工数量, 不少于1个： " << endl;
    uint32_t addNum = 0;
    cin >> addNum;

    if(addNum >= 1) {
        uint32_t newSize = m_EmpNum + addNum;
        Worker** newsSpace = new Worker*[newSize];    // 开辟新空间

        // 将原来员工指针数组内容搬迁到新空间
        if(m_EmpArray != nullptr) {
            for(uint32_t i = 0; i < m_EmpNum; i++) {
                newsSpace[i] = m_EmpArray[i];          
            }
        }

        for(uint32_t i = m_EmpNum; i < newSize; i++) {
            uint32_t id, did;
            string name;
            cout << "请输入第" << i - m_EmpNum + 1 << "个新职工编号: " << endl;
            cin >> id;
            cout << "请输入第" << i - m_EmpNum + 1 << "个新职工姓名: " << endl;
            cin >> name;
            cout << "请输入第" << i - m_EmpNum + 1 << "个新职工部门编号: " << endl;
            cout << "（0：老板，1：经理，2：员工）" << endl;
            cin >> did;
            
            // 根据部门编号创建不同类型的职工对象，并将指针存入员工指针数组
            switch(did) {
                case 0:
                    newsSpace[i] = new Boss{id, name, did};
                    break;
                case 1:
                    newsSpace[i] = new Manger{id, name, did};
                    break;
                case 2:
                    newsSpace[i] = new Employee{id, name, did};
                    break;
                default:
                    cout << "输入部门编号有误！" << endl;
            }
        }

        delete[] m_EmpArray;                // 释放原来员工指针数组
        this->m_EmpNum = newSize;          // 更新员工数量
        this->m_EmpArray = newsSpace;      // 更新员工指针数组

        cout << "成功添加 " << addNum << " 个职工！" << endl;
        
        save();             // 添加完职工后保存到文件

    } else {
        cout << "输入有误！" << endl;
    }
}

void WorkerManager::showEmp() {
    if(m_EmpNum == 0) {
        cout << "当前没有职工信息！" << endl;
    } else {
        cout << "当前职工数量为: " << m_EmpNum << endl;
        for (uint32_t i = 0; i < m_EmpNum; i++) {
            m_EmpArray[i]->showInfo();
        }
    }
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILE_NAME, ios::out);   // 以写的方式打开文件
    ofs << "name, id, deptId" << endl;
    for (uint32_t i = 0; i < m_EmpNum; i++) {
        ofs << m_EmpArray[i]->m_name << " "
            << m_EmpArray[i]->m_id << " "
            << m_EmpArray[i]->m_did << endl;
    }
    ofs.close();
}

void WorkerManager::Del_Emp() {
    cout << "请输入要删除的职工编号: " << endl;
    uint32_t id;
    cin >> id;

    if(isExist(id)) {
        for (uint32_t i = 0; i < m_EmpNum; i++) {
            if(m_EmpArray[i]->m_id == id) {
                delete m_EmpArray[i];
                for (uint32_t j = i; j < m_EmpNum - 1; j++) {
                    m_EmpArray[j] = m_EmpArray[j + 1];
                }
                m_EmpNum--;
                cout << "成功删除职工！" << endl;
                save();
                return;
            }
        }
    } else {
        cout << "未找到该职工！" << endl;
    }
}

// 遍历每个员工，看其m_id是否与传入id匹配
bool WorkerManager::isExist(uint32_t id) {
    for (uint32_t i = 0; i < m_EmpNum; i++) {
        if(m_EmpArray[i]->m_id == id) {
            return true;
        }
    }
    return false;
}

