# Arduino-Music-Box

### Project Motivation

The Arduino-Music-Box project is inspired by the desire to modernize the nostalgic experience of traditional music boxes. This project aims to blend the sentimental value of music boxes with the versatility and interactivity of modern technology, offering a customizable and interactive musical experience.

### Required Components

1. **ESP32 Module**: For wireless connectivity and control logic.
2. **Photoresistor**: To detect the opening of the music box.
3. **Small DC Motor**: To rotate the figure inside the music box. *Servor Motor*
4. **Breadboard and Jumper Wires**: For assembling the circuit.
5. **Resistors**: To regulate current and voltage in the circuit. *10k Ohm resistor (for the photoresistor circuit)*
6. **Buzzer**: For music output. *Piezo Speaker*
7. **Power Supply**: To power the ESP32 and other components. 

### Wiring Instructions

1. **ESP32 to Photoresistor**: 

   - Choose an analog input pin on the ESP32 for the photoresistor (e.g., GPIO 34).
   - Place the photoresistor on the breadboard.
   - Connect one leg of the photoresistor to the GPIO 34. (yellow)
   - Connect the other leg of the photoresistor to a GND pin on the ESP32. (black)
   - Add a pull-up resistor to this circuit. Connect one end of a 10k Ohm resistor to the same leg of the photoresistor that's connected to GPIO 34.
   - Connect the other end of the 10k Ohm resistor to the power pin on the ESP32. (This creates a voltage divider circuit, which is necessary for the analog input to read changes in light accurately.)
   - Overall just summerize, ESP32 GPIO (e.g., 34) -> Photoresistor one leg, Other leg of Photoresistor -> GND, Also from ESP32 GPIO (34) through 10k Ohm resistor to ESP32 3.3V.

2. **ESP32 to Motor**: Connect the motor to a digital output on the ESP32. (Might need to use a transistor if the motor requires more current than the ESP32 can provide.)

   - Connect the power wire (red) of the servo to the 5V pin on the ESP32.
   - Connect the ground wire (black) to a GND pin on the ESP32.
   - Connect the signal wire (yellow) to a digital GPIO pin on the ESP32 (e.g., GPIO 25).

3. **ESP32 to Speakers**: Connect the speakers to the appropriate audio output pins on the ESP32.

   - Connect one lead of the piezo speaker to a digital GPIO pin on the ESP32 (e.g., GPIO 23).


   - Connect the other lead to a GND pin on the ESP32.
   - (Probably need to connect w/ resistor, as last time I nearly burnt the piezo part.)


### Software Setup

1. **Arduino IDE Installation**: Install the Arduino IDE and configure it for the ESP32.
2. **Programming the ESP32**: Write or upload the control script to handle sensor input, motor control, and music playback.
3. **Interface Design**: Develop the music selection and creation interface using suitable software tools.
4. **Wireless Connectivity Setup**: Configure the ESP32 for Wi-Fi connectivity to enable remote interactions.

### User Interface and Interaction

1. **Song Selection and Upload**: Through the interface, users can select from a predefined list, upload their MP3 files, or create custom music.
2. **Music Composition Tool**: Users can input notes using a keyboard interface, record their compositions, and save them on the device.
3. **Music Box Interaction**: The music box plays music when opened, detected via the photoresistor. The internal figure, driven by the motor, begins to whirl, synchronized with the music.

### How to Interact

1. **Opening the Music Box**: Automatically triggers music playback and the motion of the figure.
2. **Using the Interface**: Choose or upload songs, or compose music through the connected laptop or a mobile device.
3. **Music Playback**: Use the interface to play, pause, or stop the music. The progress is shown on a progress bar.



