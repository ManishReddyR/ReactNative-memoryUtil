import type { HybridObject } from 'react-native-nitro-modules'

export interface ReactNativeNitroMemoryUtil extends HybridObject<{ ios: 'c++', android: 'c++' }> {
  getMemoryUtilization(): [number, number, number];
}