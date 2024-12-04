/*Question:
Problem Statement: You have a single light bulb controlled by two switches. Each switch can either be ON (1) or OFF (0). The light bulb's state (ON or OFF) depends on the toggle operations of these switches.

For 3 toggles, you are required to determine the final state of the light bulb (ON or OFF) for all possible toggle sequences of the two switches.

Rules:

The bulb starts in the OFF state.
For each toggle:
If any switch is ON (1), the bulb toggles its state (ON becomes OFF, and OFF becomes ON).
If both switches are OFF (0), the bulb remains in its current state.
Task: Write a program to:

Simulate all possible toggle sequences (8 sequences: 000 to 111).
Calculate the final state of the light bulb after 3 toggles for each sequence.
Print the toggle sequence along with the final state of the bulb (ON or OFF).
no input
Example Output:
For 3 toggles:

Toggle sequence 000: OFF
Toggle sequence 001: ON
Toggle sequence 010: ON
Toggle sequence 011: OFF
Toggle sequence 100: ON
Toggle sequence 101: OFF
Toggle sequence 110: OFF
Toggle sequence 111: ON
*/
#include <stdio.h>

int main() {

    for (int seq = 0; seq < 8; seq++) {
        int bulb_state = 0; 
        int switch1 = (seq / 4) % 2; 
        int switch2 = (seq / 2) % 2; 
        int switch3 = seq % 2; 


        if (switch1 == 1) bulb_state = 1 - bulb_state; // Toggle if switch1 is ON
        if (switch2 == 1) bulb_state = 1 - bulb_state; // Toggle if switch2 is ON
        if (switch3 == 1) bulb_state = 1 - bulb_state; // Toggle if switch3 is ON

        // Print the sequence and the final bulb state
        printf("Sequence %03d: ", seq);
        if (bulb_state == 1) {
            printf("ON\n");
        } else {
            printf("OFF\n");
        }
    }

    return 0;
}
