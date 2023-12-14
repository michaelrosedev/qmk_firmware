// See <https://docs.qmk.fm/#/feature_rgb_matrix?id=custom-rgb-matrix-effects>

RGB_MATRIX_EFFECT(reactive_typing)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool reactive_typing(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    //for instance, loop over all keys and set a colour
    //temp implementation for now...
    // for (uint8_t i = led_min; i < led_max; i++) {
    //     if (i % 2 == 0)
    //     {
    //         rgb_matrix_set_color(i, 0x00, 0xff, 0x00); //green
    //     }
    //     else
    //     {
    //         rgb_matrix_set_color(i, 0xFF, 0xff, 0x00); //yellow
    //     }
    // }

    //set all to params colour
    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    //"splash"
    //uint8_t count = g_last_hit_tracker.count;

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS


//potentially see <https://github.com/qmk/qmk_firmware/compare/master...CsRic:qmk_firmware:obscurite_86_matrix>
