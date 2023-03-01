// Define a constant named 'ledR' with a value of 12
#define ledR 12

// Declare a variable named 'interrCount' of type 'int' and initialize it to 0
int interrCount = 0;

// This function is called once at the beginning of the program
void setup()
{
    // Set the pin with the number stored in 'ledR' as an output
    pinMode(ledR, OUTPUT);

    // Set the pin with the number stored in 'ledR' to a low voltage (0V)
    digitalWrite(ledR, 0);

    // Attach an interrupt function to the external interrupt 0, which is triggered on a rising edge (i.e., from low to high)
    attachInterrupt(0, interruptChange, RISING);
}

// This function is called repeatedly while the program is running
void loop()
{
    // Increment the value of the 'interrCount' variable by 1
    interrCount++;

    // Set the pin with the number stored in 'ledR' to a high voltage (5V)
    digitalWrite(ledR, 1);

    // Set the pin with the number stored in 'ledR' to a low voltage (0V)
    digitalWrite(ledR, 0);

    // Wait for 300 milliseconds
    delay(300);

    // If the value of 'interrCount' is equal to 10, reset it to 0 and turn off the LED
    if (interrCount == 10)
    {
        interrCount = 0;
        digitalWrite(ledR, 0);
    }
}

// This function is called when an interrupt on external interrupt 0 occurs (i.e., when the input on pin 2 changes from low to high)
void interruptChange()
{
    // Set the pin with the number stored in 'ledR' to a high voltage (5V)
    digitalWrite(ledR, 1);
}
