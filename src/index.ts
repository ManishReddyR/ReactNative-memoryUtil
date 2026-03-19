import { NitroModules } from 'react-native-nitro-modules'
import type { ReactNativeNitroMemoryUtil as ReactNativeNitroMemoryUtilSpec } from './specs/react-native-nitro-memory-util.nitro'

export const ReactNativeNitroMemoryUtil =
  NitroModules.createHybridObject<ReactNativeNitroMemoryUtilSpec>('ReactNativeNitroMemoryUtil')