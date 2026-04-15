#include "worker.h"

class Employee : public Worker {
public:
    Employee(uint32_t id, string name, uint32_t did);
    void showInfo() override;
    string getDeptName() override;
};