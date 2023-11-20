
#define CH1 15
#define CH2 16
#define CH3 17
#define CH4 18


void setup() {
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  pinMode(CH3, OUTPUT);
  pinMode(CH4, OUTPUT);
}

void relay_channel(const int channel, bool ch_stat)
{
  digitalWrite(channel, ch_stat);
}

void relay_batch (bool ch1, bool ch2, bool ch3, bool ch4)
{
  digitalWrite(CH1, ch1);
  digitalWrite(CH2, ch2);
  digitalWrite(CH3, ch3);
  digitalWrite(CH4, ch4);
}

void loop() {
  relay_batch(0,0,0,0);
  delay(1000);
  relay_batch(0,0,0,1);
  delay(1000);
    relay_batch(0,0,1,0);
  delay(1000);
    relay_batch(0,0,1,1);
  delay(1000);
    relay_batch(0,1,0,0);
  delay(1000);
    relay_batch(0,1,0,1);
  delay(1000);
    relay_batch(0,1,1,0);
  delay(1000);
    relay_batch(0,1,1,1);
  delay(1000);
    relay_batch(1,0,0,0);
  delay(1000);
    relay_batch(1,0,0,1);
  delay(1000);
    relay_batch(1,0,1,0);
  delay(1000);
    relay_batch(1,0,1,1);
  delay(1000);
    relay_batch(1,1,0,0);
  delay(1000);
    relay_batch(1,1,0,1);
  delay(1000);
    relay_batch(1,1,1,0);
  delay(1000);
    relay_batch(1,1,1,1);
  delay(1000);

}
