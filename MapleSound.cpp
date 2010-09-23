//   Anyone can use this code for fun or profit

/* 
 *************************
 * Created 9 Aug. 2010   *
 * by James Wilson       *
 *                       *
 *************************
 _______________________________________
 */



// ************************************************************************
//    Sound generator
//*******************************************************

//   this will generate a square wave at a given frequency on the pin 
//   defined by the "SPEAKER_PIN" definition.   I used Timer number 2 but
//  if you need to you can change that as well.
//   cheers.

//   I clipped this from a working program and modified it a little so 
//   if you have any problems with it let me know.

//  use : enter in a frequency in to playTone(int playfreq)
//        and turn the tone on or off with SoundGen( {true / false} );

//    

#include <stdlib.h>

void SoundGen (int soundOn);
void playTone(int playfreq);
void handler_speaker(void); 


#define SPEAKER_PIN  13    // you can change this if you want this is the pin that the sound comes out.

#define SOUND_PERIOD  2000  // Start period for the sound in microseconds  this is just a test frequency.
                            // this frequency is used if none is set in playtone()

byte toggle = 0;           // the present state of the speaker pin

void setup()
{

  // Set up the speaker to make a tone
  pinMode(SPEAKER_PIN, OUTPUT);

  // Setup Timer
  Timer2.setChannel1Mode(TIMER_OUTPUTCOMPARE);
  Timer2.setPeriod(SOUND_PERIOD);                            // in microseconds
  Timer2.setCompare1(1);                                     // overflow might be small
  Timer2.attachCompare1Interrupt(handler_speaker);
  Timer2.pause();
  
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//   MAIN program

// Main program
int play=FALSE;
void loop(){
  
   if (play = FALSE) {   // only want to start playing the sound once
     playTone(1000);    //enter frequiency here
     SoundGen(TRUE);    // turn it on or off here
   }
 
   play=TRUE;
}


//************************************************************************
// Turn sound generator on or off
//************************************************************************

void SoundGen (int soundOn){
  if (soundOn)    // turn the sound on or off
  {
    Timer2.resume();
    //SerialUSB.println("SoundOn");
  }
  else
  {
    Timer2.pause();
  }
}


//************************************************************************
// The playTone command
// Possible change here
//   incorporate a duration value
//************************************************************************
void playTone(int playfreq){
  char freq[6];

  playfreq = 1000000/playfreq;    //change it to period

  Timer2.setPeriod(playfreq);
  
  

}

//************************************************************************
//  interrupt handler for speaker
//************************************************************************
void handler_speaker(void) {

  toggle ^= 1;
  digitalWrite(SPEAKER_PIN, toggle);
}

