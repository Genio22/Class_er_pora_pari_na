/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/**
 *
 * @author ahnaf
 */
public class oProblem5 {

    public static void main(String[] args) {

        TV tv1 = new TV();
        tv1.turnOn();
        tv1.setChannel(30);
        tv1.setVolume(3);
        tv1.channelUp();
        tv1.volumeUp();
        System.out.println("TV 1:");
        tv1.displayTVState();

        TV tv2 = new TV();
        tv2.turnOn();
        tv2.setChannel(3);
        tv2.setVolume(2);
        tv2.channelDown();
        tv2.volumeDown();
        System.out.println("TV 2:");
        tv2.displayTVState();
    }
}
