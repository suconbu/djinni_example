package com.suconbu.example;

public class Example {
    static {
        System.loadLibrary("example");
    }

    public static void main(String[] args) {
        System.out.println("[java][Example::main] begin");
        var callback = new HelloCallbackImpl();
        HelloWorld helloWorld = HelloWorld.create("Example", callback);
        System.out.println("[java][Example::main] helloWorld.msg():" + helloWorld.msg());
        System.out.println("[java][Example::main] end");
    }
}
