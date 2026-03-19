#pragma once
#include <vector>
#include "HybridReactNativeNitroMemoryUtilSpec.hpp"

namespace margelo::nitro::reactnativenitromemoryutil {
class HybridReactNativeNitroMemoryUtil : public HybridReactNativeNitroMemoryUtilSpec {
    public:
        HybridReactNativeNitroMemoryUtil() : HybridObject(TAG), HybridReactNativeNitroMemoryUtilSpec() {}
       
        double sum(double a, double b) override;
    };
} // namespace margelo::nitro::reactnativenitromemoryutil
