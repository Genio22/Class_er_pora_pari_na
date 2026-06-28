/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/**
 *
 * @author ahnaf
 */
public class TV {

    private int channel;
    private int volumeLevel;
    private boolean on;

    public TV() {
        this.channel = 1;
        this.volumeLevel = 1;
        this.on = false;
    }

    public void turnOn() {
        on = true;
    }

    public void turnOff() {
        on = false;
    }

    public void setChannel(int newChannel) {
        if (on && newChannel >= 1 && newChannel <= 120) {
            channel = newChannel;
        }
    }

    public void setVolume(int newVolumeLevel) {
        if (on && newVolumeLevel >= 1 && newVolumeLevel <= 7) {
            volumeLevel = newVolumeLevel;
        }
    }

    public void channelUp() {
        if (on && channel < 120) {
            channel++;
        }
    }

    public void channelDown() {
        if (on && channel > 1) {
            channel--;
        }
    }

    public void volumeUp() {
        if (on && volumeLevel < 7) {
            volumeLevel++;
        }
    }

    public void volumeDown() {
        if (on && volumeLevel > 1) {
            volumeLevel--;
        }
    }

    public void displayTVState() {
        System.out.println("TV is " + (on ? "ON" : "OFF"));
        if (on) {
            System.out.println("Channel: " + channel);
            System.out.println("Volume Level: " + volumeLevel);
        }
        System.out.println();
    }

}
