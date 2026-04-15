#include "worker.h"

class Boss : public Worker {
public:
    Boss(uint32_t id, string name, uint32_t did);
    void showInfo() override;
    string getDeptName() override;
};