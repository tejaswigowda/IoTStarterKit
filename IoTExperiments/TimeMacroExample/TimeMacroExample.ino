String x, y;

void setup() {
  // put your setup code here, to run once:
  x = F(__DATE__);
  y = F(__TIME__);

  Serial.begin(115200);
  Serial.println(x);
  Serial.println(y);

}

void loop() {
  // put your main code here, to run repeatedly:

}
