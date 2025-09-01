#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <stdint.h>

#include "pico/mutex.h"

#include "data/control_report.h"

namespace common
{

/**
 * @brief Shared memory region
 *
 */
class SharedMemory
{
  public:
    /**
     * @brief Get the instance of the Shared Memory
     * @return SharedMemory& reference to the singleton instance
     */
    static SharedMemory& getInstance();

    /**
     * @brief Destroy the Shared Memory object
     */
    ~SharedMemory() = default;

    /**
     * @brief Try to write given control report into shared memory
     *
     * @param report Control Report data to copy into shared memory
     * @return true if write was successful, else false
     */
    bool try_write_control_report(const Control_Report_Msg_t& report);

    /**
     * @brief Try to read given control report from shared memory
     *
     * @param report Place to copy shared memory's report data into
     * @return true if read was successful, else false
     */
    bool try_read_control_report(Control_Report_Msg_t& report);

    /**
     * @brief Explicitly delete copy constructor
     * @param to_copy instance to copy
     */
    SharedMemory(const SharedMemory& to_copy) = delete;

    /**
     * @brief Explicitly delete copy assignment operator
     * @param to_copy instance to copy
     */
    SharedMemory& operator=(const SharedMemory& to_copy) = delete;

  private:
    /**
     * @brief Construct a new Shared Memory object
     * @note private for singleton pattern
     */
    SharedMemory();

    /**
     * @brief Generalized template for reading from shared memory
     *
     * @tparam T type of data to copy from shared memory
     * @param data_out destination of data copied out of shared memory
     * @param shared_src source in shared memory
     * @param mutex mutex associated with the shared memory entry
     * @return true if successful, otherwise false
     */
    template <typename T>
    bool try_read(T& local_data_out, const T& shared_src, mutex_t& mutex)
    {
        if (mutex_try_enter(&mutex, nullptr))
        {
            local_data_out = shared_src; // Copy data from shared memory
            mutex_exit(&mutex);
            return true;
        }
        return false; // skip if busy
    }

    /**
     * @brief Generalized template for writing to shared memory
     *
     * @tparam T type of data to copy into shared memory
     * @param data_in data to copy into shared memory
     * @param shared_dest destination in shared memory
     * @param mutex mutex associated with the shared memory entry
     * @return true if successful, otherwise false
     */
    template <typename T>
    bool try_write(const T& local_data_in, T& shared_dest, mutex_t& mutex)
    {
        if (mutex_try_enter(&mutex, nullptr))
        {
            shared_dest = local_data_in; // Copy data into shared memory
            mutex_exit(&mutex);
            return true;
        }
        return false; // skip if busy
    }

    mutex_t control_report_mutex_; /**< Mutex for control report mailbox*/
};

} // namespace common

#endif // SHARED_MEMORY_H