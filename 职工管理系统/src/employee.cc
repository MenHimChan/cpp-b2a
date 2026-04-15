#include "employee.h"

Employee::Employee(uint32_t id, string name, uint32_t did) : Worker(id, name, did)
{

}

void Employee::showInfo() {
    cout << "职工编号: " << this->m_id
            << "\t职工姓名: " << this->m_name
            << "\t岗位: " << this->getDeptName()
            << "\t岗位职责: 完成经理交给的任务" << endl;
}


string Employee::getDeptName() {
    return string("员工");
}
