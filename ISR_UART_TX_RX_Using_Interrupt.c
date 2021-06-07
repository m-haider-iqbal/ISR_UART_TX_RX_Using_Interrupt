
#include <Arduino.h>

void uartinit();
void dataSending(char data);
void dataRecieving();

void setup()
{
uartinit();
}
void loop()
{}
void uartinit()
{
UCSR0B = 1 << 7 |1 << 6 | 1 << 3 | 1 << 4 | 0 << 3; 
UCSR0C = 0 << UMSEL00 | 1 << UCSZ01 | 1 << UCSZ00 ;
UBRR0 = 103;
}

ISR (USART_RX_vect)  // RX
{
uint8_t info1 = UDR0;
UDR0 = info1;
}
ISR(USART_TX_vect)  // TX
{}
