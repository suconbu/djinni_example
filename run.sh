#!/bin/bash

client_dir="./client"
generated_dir="./generated"
package_path="com/suconbu/example"

java -classpath "${client_dir}:${generated_dir}/java" ${package_path//\//.}.Example
