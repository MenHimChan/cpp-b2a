#include "worker.h"

class Manger : public Worker {
public:
    Manger(uint32_t id, string name, uint32_t did);
    void showInfo() override;
    string getDeptName() override;
};