#include <stdio.h>
#include <stdlib.h>

typedef struct set {
    float h_view_lo;
    float h_view_hi;
    float v_view_lo;
    float v_view_hi;
    int integral_steps;
    int draw_axis;
    int connect_dots;
} Settings;

Settings* createSettings();

Settings* setDefaultSettings(Settings* settings);

void showSettings(Settings* settings);