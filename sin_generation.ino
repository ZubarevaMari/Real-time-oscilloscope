#define W_CLK 8
#define FQ_UD 9
#define DATA 10
#define RESET 11
#define SIGNAL 2

void pin_tick(byte pin)
{
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}

void write_byte(byte x)
{
  for(int i = 0; i <= 7; i++)
  {
    digitalWrite(DATA, x & 0x01);
    x >>= 1;
    pin_tick(W_CLK);
  }
}

void set_frequency(uint32_t f)
{
  for(int i = 0; i <= 3; i++)
  {
    write_byte(f & 0xFF);
    f >>= 8;
  }
  write_byte(0x00);
  pin_tick(FQ_UD);
}

void AD9850_Init()
{
  pinMode(FQ_UD, OUTPUT);
  pinMode(W_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(RESET, OUTPUT);
  pin_tick(RESET);
  pin_tick(W_CLK);
  pin_tick(FQ_UD);
}

void setup()
{
  pinMode(SIGNAL, INPUT);
  AD9850_Init();
  set_frequency(00001010);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available () != 0)
  {
      Serial.println (analogRead (SIGNAL));
  }
  delay(20);
}
