#ifndef CONTROL_REPORT_H
#define CONTROL_REPORT_H

#include <stdint.h>

namespace common
{

/**
 * @brief PID control report message structure
 */
typedef struct
{
    float target;              ///< System target value
    float current;             ///< Current value
    float k_p;                 ///< Proportional gain
    float k_i;                 ///< Integral gain
    float k_d;                 ///< Derivative gain
    float total_error;         ///< Total error
    float proportional_signal; ///< Proportional signal contribution
    float integral_signal;     ///< Integral signal contribution
    float derivative_signal;   ///< Derivative signal contribution
    uint32_t loop_time_us;     ///< elapsed loop time in microseconds
} Control_Report_Msg_t;

} // namespace common

#endif // CONTROL_REPORT_H