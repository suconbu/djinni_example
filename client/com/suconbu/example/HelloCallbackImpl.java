package com.suconbu.example;

public class HelloCallbackImpl extends HelloCallback {

    public HelloCallbackImpl() {
    }

    @Override
    public void invoke(HelloMessage msg) {
        var nContents = msg.getContents().size();
        System.out.printf("[java][HelloCallbackImpl::invoke] id:%d tag:%s #contents:%d\n", msg.getId(), msg.getTag(), nContents);
        for (var i = 0; i < nContents; i++) {
            System.out.printf("  contents[%d]: %s\n", i, msg.getContents().get(i));
        }
        System.out.printf("  data: ");
        for (var i = 0; i < msg.getData().length; i++) {
            System.out.printf("%02X", msg.getData()[i]);
        }
        System.out.printf("\n");
    }
}
