LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ndktest
LOCAL_SCR_FILES := ndktest.cpp

include $(BUILD_SHARED_LIBRARY)