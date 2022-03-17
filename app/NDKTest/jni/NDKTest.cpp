//
// Created by rapha on 17/03/2022.
//

#include<jni.h>
#include<string.h>

jstring JAVA_com_example_ndktest_MainActivity_HelloWorld(JNIEnv* env, jobject obj)
{

return(*env)->NewStringUTF(env, "Hello World");
}