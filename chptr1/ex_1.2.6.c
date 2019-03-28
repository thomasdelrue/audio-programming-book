#include <stdio.h>
#include <math.h>

int main() {
    double semitone_ratio;
    double c0;
    double c5; // frequency of Middle C
    double frequency, fracmidi;
    int midinote_above, midinote_below;
    double freq_above, freq_below;
    double bend;
    int bend_perc;

    semitone_ratio = pow(2.0, 1.0/12.0); // approx. 1.0594631
    // find Middle C, 3 semitones above low A = 220
    c5 = 220.0 * pow(semitone_ratio, 3.0);
    // MIDI Note 0 is C, 5 octaves below Middle C
    c0 = c5 * pow(0.5, 5.0);

    // find nearest MIDI note to a fiven frequency in Hz
    frequency = 430.0;
    fracmidi = log(frequency / c0) / log(semitone_ratio);
    // round fracmidi to the nearest whole number
    midinote_below = (int) (fracmidi - 0.5);
    freq_below = c0 * pow(semitone_ratio, midinote_below);
    midinote_above = (int) (fracmidi + 0.5);
    freq_above = c0 * pow(semitone_ratio, midinote_above);

    printf("The nearest MIDI notes to the frequency %f are %d (%f Hz) and %d (%f Hz)\n",
           frequency, midinote_below, freq_below,
           midinote_above, freq_above);

    bend = (freq_above - frequency) / (freq_above - freq_below);
    //printf("%f\n", bend);
    bend_perc = (int) (bend * 100);
    printf("pitchbend: %d%%\n", bend_perc);

    return 0;
}
