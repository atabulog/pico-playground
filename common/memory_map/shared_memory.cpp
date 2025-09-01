#include "shared_memory.h"

// #defines for hard setting the spinlock id's for specific data entries
#define SPINLOCK_ID_CONTROL_REPORT 0

// define shared memory instances for both cores here
static volatile common::Control_Report_Msg_t control_report_shared_;

namespace common
{

SharedMemory::SharedMemory()
{
    mutex_init(&control_report_mutex_, SPINLOCK_ID_CONTROL_REPORT);
}

SharedMemory& SharedMemory::getInstance()
{
    static SharedMemory instance;
    return instance;
}

bool SharedMemory::try_write_control_report(const Control_Report_Msg_t& report)
{
    return try_write<Control_Report_Msg_t>(report, control_report_shared_, control_report_mutex_);
}

bool SharedMemory::try_read_control_report(Control_Report_Msg_t& report)
{
    return try_read<Control_Report_Msg_t>(report, control_report_shared_, control_report_mutex_);
}

} // namespace common
