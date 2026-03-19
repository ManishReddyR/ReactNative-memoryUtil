#pragma once
#include <vector>
#include "HybridReactNativeNitroMemoryUtilSpec.hpp"

namespace margelo::nitro::reactnativenitromemoryutil {
class HybridReactNativeNitroMemoryUtil : public HybridReactNativeNitroMemoryUtilSpec {
    public:
        HybridReactNativeNitroMemoryUtil() : HybridObject(TAG), HybridReactNativeNitroMemoryUtilSpec() {}
       
        std::tuple<double, double, double> getMemoryUtilization() override;
    };
} // namespace margelo::nitro::reactnativenitromemoryutil
