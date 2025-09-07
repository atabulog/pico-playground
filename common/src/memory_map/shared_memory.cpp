#include "shared_memory.h"

namespace common
{

// define shared memory instances for both cores here
Control_Report_Msg_t control_report_shared_{}; /**< control report data stored in generic shared memory*/

SharedMemory::SharedMemory()
{
    mutex_init(&control_report_mutex_);
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
