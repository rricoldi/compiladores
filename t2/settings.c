#include <stdio.h>
#include "settings.h"

Settings* createSettings() {
    Settings* settings = (Settings*) malloc(sizeof(Settings));

    settings = setDefaultSettings(settings);

    return settings;
}

Settings* setDefaultSettings(Settings* settings) {
    settings->h_view_lo = -6.500000;
    settings->h_view_hi = 6.500000;
    settings->v_view_lo = -3.500000;
    settings->v_view_hi = 3.500000;
    settings->integral_steps = 1000;
    settings->draw_axis = 1;
    settings->connect_dots = 0;

    return settings;
}

Settings* setSettings(Settings* settings, float h_view_lo, float h_view_hi, float v_view_lo, float v_view_hi, int integral_steps, int draw_axis, int connect_dots) {
    settings->h_view_lo = h_view_lo;
    settings->h_view_hi = h_view_hi;
    settings->v_view_lo = v_view_lo;
    settings->v_view_hi = v_view_hi;
    settings->integral_steps = integral_steps;
    settings->draw_axis = draw_axis;
    settings->connect_dots = connect_dots;

    return settings;
}

void showSettings(Settings* settings) {
    printf(
        "\nh_view_lo: %.6f\nh_view_hi: %.6f\nv_view_lo: %.6f\nv_view_hi: %.6f\nintegral_steps: %d\n",
        settings->h_view_lo, settings->h_view_hi, settings->v_view_lo, settings->v_view_hi, settings->integral_steps
    );

    if(settings->draw_axis) {
        printf("\nDraw Axis: ON.");
    } else {
        printf("\nDraw Axis: OFF.");
    }

    if(settings->connect_dots) {
        printf("\nConnect Dots: ON.");
    } else {
        printf("\nConnect Dots: OFF.");
    }

    printf("\n\n");
}