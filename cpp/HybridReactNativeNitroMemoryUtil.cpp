#include "HybridReactNativeNitroMemoryUtil.hpp"

#if defined(__APPLE__)
#include <mach/mach.h>
#include <sys/sysctl.h>
#elif defined(__ANDROID__)
#include <unistd.h>
#include <sys/sysinfo.h>
#include <fstream>
#endif

namespace margelo::nitro::reactnativenitromemoryutil {

    std::tuple<double, double, double> HybridReactNativeNitroMemoryUtil::getMemoryUtilization() {
    #if defined(__APPLE__)
        task_vm_info_data_t vmInfo;
        mach_msg_type_number_t count = TASK_VM_INFO_COUNT;
        kern_return_t result = task_info(
            mach_task_self(),
            TASK_VM_INFO,
            reinterpret_cast<task_info_t>(&vmInfo),
            &count
        );

        uint64_t processBytes = 0;
        if (result == KERN_SUCCESS) {
            processBytes = static_cast<uint64_t>(vmInfo.phys_footprint);
        }

        uint64_t totalBytes = 0;
        size_t size = sizeof(totalBytes);
        sysctlbyname("hw.memsize", &totalBytes, &size, nullptr, 0);

        double utilization = 0.0;
        if (totalBytes > 0) {
            utilization =
                (static_cast<double>(processBytes) / static_cast<double>(totalBytes)) * 100.0;
        }

        return {
            static_cast<double>(processBytes),
            static_cast<double>(totalBytes),
            utilization
        };

    #elif defined(__ANDROID__)
        long pageSize = sysconf(_SC_PAGESIZE);
        uint64_t processBytes = 0;

        std::ifstream statm("/proc/self/statm");
        uint64_t sizePages = 0;
        uint64_t residentPages = 0;
        if (statm.is_open()) {
            statm >> sizePages >> residentPages;
            processBytes = residentPages * static_cast<uint64_t>(pageSize);
        }

        struct sysinfo memInfo {};
        uint64_t totalBytes = 0;
        if (sysinfo(&memInfo) == 0) {
            totalBytes = static_cast<uint64_t>(memInfo.totalram) * memInfo.mem_unit;
        }

        double utilization = 0.0;
        if (totalBytes > 0) {
            utilization =
                (static_cast<double>(processBytes) / static_cast<double>(totalBytes)) * 100.0;
        }

        return {
            static_cast<double>(processBytes),
            static_cast<double>(totalBytes),
            utilization
        };
    #else
        return {0.0, 0.0, 0.0};
    #endif
    }

} // namespace margelo::nitro::reactnativenitromemoryutil
