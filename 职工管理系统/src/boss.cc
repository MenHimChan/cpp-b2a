#include "boss.h"

Boss::Boss(uint32_t id, string name, uint32_t did) : Worker(id, name, did)
{

}

void Boss::showInfo() {
    cout << "职工编号: " << this->m_id
            << "\t职工姓名: " << this->m_name
            << "\t岗位: " << this->getDeptName()
            << "\t岗位职责: 布置任务给经理" << endl;
}

string Boss::getDeptName() {
    return string("老板");
}
