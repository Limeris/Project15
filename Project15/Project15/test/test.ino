int str1 = 1;
int str2 = 2;
int str3 = 3;
int str4 = 4;
int pos1= 5;
int pos2= 6;
int pos3= 7;
int pos4= 8;
int pos5= 9;
int pos6= 10;
int pos7= 11;

void setup() {
pinMode(str1, OUTPUT);
pinMode(str2, OUTPUT);
pinMode(str3, OUTPUT);
pinMode(str4, OUTPUT);
pinMode(pos1, OUTPUT);
pinMode(pos2, OUTPUT);
pinMode(pos3, OUTPUT);
pinMode(pos4, OUTPUT);
pinMode(pos5, OUTPUT);
pinMode(pos6, OUTPUT);
pinMode(pos7, OUTPUT);
digitalWrite(pos1, HIGH);digitalWrite(pos2, HIGH);digitalWrite(pos3, HIGH);digitalWrite(pos4, HIGH);digitalWrite(pos5, HIGH);digitalWrite(pos6, HIGH);digitalWrite(pos7, HIGH);
}

void loop() {
digitalWrite(str1, HIGH); //string
digitalWrite(pos1, LOW); //string
digitalWrite(pos2, LOW); //string
digitalWrite(pos3, LOW); //string
digitalWrite(pos4, LOW); //string
digitalWrite(pos5, LOW); //string
digitalWrite(pos6, LOW); //string
digitalWrite(pos7, LOW); //string
delay(500);
digitalWrite(str1, LOW); //string
digitalWrite(pos1, HIGH); //string
digitalWrite(pos2, HIGH); //string
digitalWrite(pos3, HIGH); //string
digitalWrite(pos4, HIGH); //string
digitalWrite(pos5, HIGH); //string
digitalWrite(pos6, HIGH); //string
digitalWrite(pos7, HIGH); //string
digitalWrite(str4, HIGH);
digitalWrite(pos6, LOW);
delay(500);
digitalWrite(str4, LOW);
digitalWrite(pos6, HIGH);
digitalWrite(str4, HIGH);
digitalWrite(pos6, LOW);
delay(500);
digitalWrite(str4, LOW);
digitalWrite(pos6, HIGH);
digitalWrite(str4, HIGH);
digitalWrite(pos7, LOW);
delay(500);
digitalWrite(str4, LOW);
digitalWrite(pos7, HIGH);
digitalWrite(str3, HIGH);
digitalWrite(pos1, LOW);
delay(500);
digitalWrite(str3, LOW);
digitalWrite(pos1, HIGH);
digitalWrite(str3, HIGH);
digitalWrite(pos1, LOW);
delay(500);
digitalWrite(str3, LOW);
digitalWrite(pos1, HIGH);
digitalWrite(str3, HIGH);
digitalWrite(pos2, LOW);
delay(500);
digitalWrite(str3, LOW);
digitalWrite(pos2, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos3, LOW);
delay(500);
digitalWrite(str1, LOW);
digitalWrite(pos3, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos3, LOW);
delay(500);
digitalWrite(str1, LOW);
digitalWrite(pos3, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos4, LOW);
delay(500);
digitalWrite(str1, LOW);
digitalWrite(pos4, HIGH);
delay(2000); // Rest
digitalWrite(str1, HIGH); //string
digitalWrite(pos1, LOW); //string
digitalWrite(pos2, LOW); //string
digitalWrite(pos3, LOW); //string
digitalWrite(pos4, LOW); //string
digitalWrite(pos5, LOW); //string
digitalWrite(pos6, LOW); //string
digitalWrite(pos7, LOW); //string
delay(500);
digitalWrite(str1, LOW); //string
digitalWrite(pos1, HIGH); //string
digitalWrite(pos2, HIGH); //string
digitalWrite(pos3, HIGH); //string
digitalWrite(pos4, HIGH); //string
digitalWrite(pos5, HIGH); //string
digitalWrite(pos6, HIGH); //string
digitalWrite(pos7, HIGH); //string
digitalWrite(str1, HIGH);
digitalWrite(pos1, LOW);
delay(500);
digitalWrite(str1, LOW);
digitalWrite(pos1, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos1, LOW);
delay(500);
digitalWrite(str1, LOW);
digitalWrite(pos1, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos1, LOW);
delay(500);
digitalWrite(str1, LOW);
digitalWrite(pos1, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos3, LOW);
delay(500);
digitalWrite(str1, LOW);
digitalWrite(pos3, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos3, LOW);
delay(250);
digitalWrite(str1, LOW);
digitalWrite(pos3, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos5, LOW);
delay(250);
digitalWrite(str1, LOW);
digitalWrite(pos5, HIGH);
digitalWrite(str1, HIGH);
digitalWrite(pos6, LOW);
delay(250);
digitalWrite(str1, LOW);
digitalWrite(pos6, HIGH);
digitalWrite(str2, HIGH); //string
digitalWrite(pos1, LOW); //string
digitalWrite(pos2, LOW); //string
digitalWrite(pos3, LOW); //string
digitalWrite(pos4, LOW); //string
digitalWrite(pos5, LOW); //string
digitalWrite(pos6, LOW); //string
digitalWrite(pos7, LOW); //string
delay(250);
digitalWrite(str2, LOW); //string
digitalWrite(pos1, HIGH); //string
digitalWrite(pos2, HIGH); //string
digitalWrite(pos3, HIGH); //string
digitalWrite(pos4, HIGH); //string
digitalWrite(pos5, HIGH); //string
digitalWrite(pos6, HIGH); //string
digitalWrite(pos7, HIGH); //string
digitalWrite(str2, HIGH);
digitalWrite(pos1, LOW);
delay(250);
digitalWrite(str2, LOW);
digitalWrite(pos1, HIGH);
digitalWrite(str2, HIGH);
digitalWrite(pos1, LOW);
delay(250);
digitalWrite(str2, LOW);
digitalWrite(pos1, HIGH);
digitalWrite(str2, HIGH);
digitalWrite(pos2, LOW);
delay(250);
digitalWrite(str2, LOW);
digitalWrite(pos2, HIGH);
digitalWrite(str2, HIGH);
digitalWrite(pos3, LOW);
delay(250);
digitalWrite(str2, LOW);
digitalWrite(pos3, HIGH);
digitalWrite(str2, HIGH);
digitalWrite(pos4, LOW);
delay(250);
digitalWrite(str2, LOW);
digitalWrite(pos4, HIGH);
digitalWrite(str2, HIGH);
digitalWrite(pos5, LOW);
delay(250);
digitalWrite(str2, LOW);
digitalWrite(pos5, HIGH);
delay(2000); // Rest
delay(500); // Rest
delay(500); // Rest
delay(1000); // Rest
delay(2000); // Rest
delay(4000); // Rest
delay(4000); // Rest
delay(4000); // Rest
delay(4000); // Rest
}