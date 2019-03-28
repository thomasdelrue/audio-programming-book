#include <stdio.h>
#include <math.h>

int main() {
    double semitone_ratio;
    double c0, c4;
    double c5; // frequency of Middle C
    double frequency, string_length;
    int midinote;

    semitone_ratio = pow(2.0, 1.0/12.0); // approx. 1.0594631
    // find Middle C, 3 semitones above low A = 220
    c5 = 220.0 * pow(semitone_ratio, 3.0);
    // MIDI Note 0 is C, 5 octaves below Middle C
    c0 = c5 * pow(0.5, 5.0);
    c4 = c0 * pow(2.0, 4.0);


    // calculate a frequency for a given MIDI Note Number
    for (int i = 0; i <= 12; i++) {
        midinote = log(c4 / c0) / log(semitone_ratio) + 1 + i; // C# above A = 440
        frequency = c0 * pow(semitone_ratio, midinote);
        string_length = 660.0 / pow(semitone_ratio, i);

        printf("MIDI Note %d has frequency %f and string length %f\n",
            midinote, frequency, string_length);
    }

    return 0;
}
