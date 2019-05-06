#define NUM_NOTES 8

int buzzerPin = 3;

int melody[NUM_NOTES] = {
   262, 196, 196, 220, 196, 0, 247, 262
};

int noteDurations[NUM_NOTES] = {
   4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
}

void loop() {
   for(int noteId = 0; noteId < NUM_NOTES; noteId++){
      int noteDuration = 1000/ noteDurations[noteId];
      tone(buzzerPin, melody[noteId], noteDuration);

      int pauseBetweenNotes = noteDuration* 1.3;
      delay(pauseBetweenNotes);
      noTone(buzzerPin);
   }
}
