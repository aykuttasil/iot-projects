#define LED D4           // NodeMCU'nun üzerindeki ledin bağlı olduğu pini belirliyoruz.

void setup() {
  pinMode(LED, OUTPUT);    // Pini çıkış pini olarak ayarlıyoruz.
}

void loop() {
  digitalWrite(LED, HIGH);// Ledi Söndürüyoruz.                  
  delay(1000);            // 1 saniye bekletiyoruz.
   
  digitalWrite(LED, LOW); // Ledi Yakıyoruz.
  delay(1000);            // 1 saniye bekletiyoruz.
}
