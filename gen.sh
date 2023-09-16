#!/bin/bash

client_dir="./client"
server_dir="./server"
generated_dir="./generated"
package_path="com/suconbu/example"

./djinni --idl ${server_dir}/example.idl \
    --jni-out ${generated_dir}/jni/ \
    --cpp-out ${generated_dir}/cpp/ \
    --java-out ${generated_dir}/java/${package_path} \
        --java-package ${package_path//\//.} \
        --ident-jni-class NativeFooBar \
        --ident-jni-file NativeFooBar

cmake -S. -Bbuild
cmake --build build

javac -sourcepath "${client_dir}:${generated_dir}/java" ${client_dir}/${package_path}/Example.java
