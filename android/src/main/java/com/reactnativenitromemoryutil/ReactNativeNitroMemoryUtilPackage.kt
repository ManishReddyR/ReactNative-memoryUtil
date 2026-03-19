package com.reactnativenitromemoryutil;

import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.module.model.ReactModuleInfoProvider;
import com.facebook.react.BaseReactPackage;
import com.margelo.nitro.reactnativenitromemoryutil.ReactNativeNitroMemoryUtilOnLoad;


public class ReactNativeNitroMemoryUtilPackage : BaseReactPackage() {
  override fun getModule(name: String, reactContext: ReactApplicationContext): NativeModule? = null

  override fun getReactModuleInfoProvider(): ReactModuleInfoProvider = ReactModuleInfoProvider { emptyMap() }

  companion object {
    init {
      ReactNativeNitroMemoryUtilOnLoad.initializeNative();
    }
  }
}
