
// Pines conectados al divisor de voltaje
const int FLEX_PULGAR = A0;
const int FLEX_INDICE = A1;
const int FLEX_MEDIO = A2;
const int FLEX_ANULAR = A3;
const int FLEX_MENIQUE = A6;

const int Sensor_recto_pulgar = 423; //Flex 0 grados
const int Sensor_doblado_pulgar = 320; //Flex 90 grados

const int Sensor_recto_indice = 423; //Flex 0 grados
const int Sensor_doblado_indice = 320; //Flex 90 grados

const int Sensor_recto_medio = 423; //Flex 0 grados
const int Sensor_doblado_medio = 320; //Flex 90 grados

const int Sensor_recto_anular = 423; //Flex 0 grados
const int Sensor_doblado_anular = 320; //Flex 90 grados

const int Sensor_recto_menique = 423; //Flex 0 grados
const int Sensor_doblado_menique = 320; //Flex 90 grados

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PULGAR, INPUT);
  pinMode(FLEX_INDICE, INPUT);
  pinMode(FLEX_MEDIO, INPUT);
  pinMode(FLEX_ANULAR, INPUT);
  pinMode(FLEX_MENIQUE, INPUT);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flex_pulgar = analogRead(FLEX_PULGAR);
  Serial.print(flex_pulgar);
  //Serial.print("+");
  int flex_indice = analogRead(FLEX_INDICE);
  Serial.print(flex_indice);
  //Serial.print("+");
  int flex_medio = analogRead(FLEX_MEDIO);
  Serial.print(flex_medio);
  //Serial.print("+");
  int flex_anular = analogRead(FLEX_ANULAR);
  Serial.print(flex_anular);
  //Serial.print("+");
  int flex_menique = analogRead(FLEX_MENIQUE);
  Serial.print(flex_menique);
  //Serial.print("+");

  /* Mapeo de lectura analogica a angulo
  //float angulo_pulgar = map(flex_pulgar, Sensor_recto_pulgar, Sensor_doblado_pulgar,
                   0, 90.0);
  //float angulo_indice = map(flex_indice, Sensor_recto_indice, Sensor_doblado_indice,
                   0, 90.0);
  //float angulo_medio = map(flex_medio, Sensor_recto_medio, Sensor_doblado_medio,
                   0, 90.0);
  //float angulo_anular = map(flex_anular, Sensor_recto_anular, Sensor_doblado_anular,
                   0, 90.0);
  float angulo_menique = map(flex_menique, Sensor_recto_menique, Sensor_doblado_menique,
                   0, 90.0);
  Serial.println("Angulo: " + String(angulo_pulgar) + " grados");
  Serial.println("Angulo: " + String(angulo_indice) + " grados");
  Serial.println("Angulo: " + String(angulo_medio) + " grados");
  Serial.println("Angulo: " + String(angulo_anular) + " grados");
  Serial.println("Angulo: " + String(angulo_menique) + " grados");
*/  Serial.println();

  delay(500);
}

