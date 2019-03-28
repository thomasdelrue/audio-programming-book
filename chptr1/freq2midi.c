#include <stdio.h>
#include <math.h>

int main() {
    double semitone_ratio;
    double c0;
    double c5; // frequency of Middle C
    double frequency, fracmidi;
    int midinote;

    semitone_ratio = pow(2.0, 1.0/12.0); // approx. 1.0594631
    // find Middle C, 3 semitones above low A = 220
    c5 = 220.0 * pow(semitone_ratio, 3.0);
    // MIDI Note 0 is C, 5 octaves below Middle C
    c0 = c5 * pow(0.5, 5.0);

    // find nearest MIDI note to a fiven frequency in Hz
    frequency = 400.0;
    fracmidi = log(frequency / c0) / log(semitone_ratio);
    // round fracmidi to the nearest whole number
    midinote = (int) (fracmidi + 0.5);    

    printf("The nearest MIDI note to the frequency %f is %d\n",
        frequency, midinote);

    return 0;
}
