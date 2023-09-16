package com.suconbu.example;

public class HelloCallbackImpl extends HelloCallback {

    public HelloCallbackImpl() {
    }

    @Override
    public void invoke(String msg) {
        System.out.println("[java][HelloCallbackImpl::invoke] msg:" + msg);
    }
}
