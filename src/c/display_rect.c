#if defined(PBL_RECT) && PBL_DISPLAY_WIDTH == 144

#include <pebble.h>
#include "display.h"

static GFont font_square_l;
static GFont font_square_m;
static GFont font_square_s;

TextLayer *text_layer_rt_title;
TextLayer *text_layer_d_title;
TextLayer *text_layer_ts_title;

void set_angles(int *start, int *end) {
	*start = (int) 235;
	*end = (int) 485;
}

//void draw_display(Window **window, Layer **gui_layer, Layer **details_layer, TextLayer **text_layer_volt, TextLayer **text_layer_current, TextLayer **text_layer_time, TextLayer **text_layer_speed,
void draw_display(Window **window, Layer **gui_layer, Layer **details_layer, TextLayer **text_layer_time, TextLayer **text_layer_speed,

	TextLayer **text_layer_mph, TextLayer **text_layer_battery, TextLayer **text_layer_temperature,
	BitmapLayer **battery_bitmap_layer, BitmapLayer **temperature_bitmap_layer,BitmapLayer **bt_bitmap_layer, Layer **arc_layer,
	TextLayer **text_layer_ride_time, TextLayer **text_layer_distance, TextLayer **text_layer_top_speed) {

	Layer *window_layer = window_get_root_layer(*window);
  GRect window_bounds = layer_get_bounds(window_layer);
	*gui_layer = layer_create(window_bounds);
	*details_layer = layer_create(window_bounds);

	font_square_l = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_SQUARE_50));
	font_square_m = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_SQUARE_20));
	font_square_s = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_SQUARE_15));
/*
*text_layer_volt = text_layer_create(GRect(-20, 20, window_bounds.size.w, 20));
text_layer_set_font(*text_layer_volt, font_square_s);
*text_layer_current = text_layer_create(GRect(0, 20, window_bounds.size.w, 20));
text_layer_set_font(*text_layer_current, font_square_s);
*/
	*text_layer_time = text_layer_create(GRect(0, 44, window_bounds.size.w, 20));
	text_layer_set_font(*text_layer_time, font_square_s);

	*bt_bitmap_layer = bitmap_layer_create(GRect(window_bounds.size.w-24, 5, 24, 24));
	bitmap_layer_set_alignment(*bt_bitmap_layer, GAlignCenter);

	*arc_layer = layer_create(GRect(10, 25, window_bounds.size.w-20, window_bounds.size.w-20));

	*text_layer_speed = text_layer_create(GRect(0, 55, window_bounds.size.w, 50));
	text_layer_set_font(*text_layer_speed, font_square_l);

	*text_layer_mph = text_layer_create(GRect(0, 103, window_bounds.size.w, 23));
	text_layer_set_font(*text_layer_mph, font_square_m);

	*temperature_bitmap_layer = bitmap_layer_create(GRect(0, window_bounds.size.h-43, window_bounds.size.w/2, 20));
	bitmap_layer_set_alignment(*temperature_bitmap_layer, GAlignCenter);

	*battery_bitmap_layer = bitmap_layer_create(GRect(window_bounds.size.w/2, window_bounds.size.h-43, window_bounds.size.w/2, 20));
	bitmap_layer_set_alignment(*battery_bitmap_layer, GAlignCenter);

	*text_layer_temperature = text_layer_create(GRect(0, window_bounds.size.h-25, window_bounds.size.w/2, 25));
	text_layer_set_font(*text_layer_temperature, font_square_m);

	*text_layer_battery = text_layer_create(GRect(window_bounds.size.w/2, window_bounds.size.h-25, window_bounds.size.w/2, 25));
	text_layer_set_font(*text_layer_battery, font_square_m);

	text_layer_rt_title = text_layer_create(GRect(0, 9, window_bounds.size.w, 22));
	*text_layer_ride_time = text_layer_create(GRect(0, 31, window_bounds.size.w, 22));
	text_layer_set_background_color(text_layer_rt_title, GColorClear);
	text_layer_set_background_color(*text_layer_ride_time, GColorClear);
/*
text_layer_set_background_color(*text_layer_volt, GColorClear);
text_layer_set_background_color(*text_layer_current, GColorClear);
text_layer_set_text(text_layer_volt, "V");
text_layer_set_text(text_layer_current, "C");
*/

	text_layer_set_text_color(text_layer_rt_title, GColorWhite);
	text_layer_set_text_color(*text_layer_ride_time, GColorLightGray);
	text_layer_set_text_alignment(text_layer_rt_title, GTextAlignmentCenter);
	text_layer_set_text_alignment(*text_layer_ride_time, GTextAlignmentCenter);
	text_layer_set_text(text_layer_rt_title, "RIDE TIME");
	text_layer_set_font(text_layer_rt_title, font_square_m);
	text_layer_set_font(*text_layer_ride_time, font_square_m);

	text_layer_d_title = text_layer_create(GRect(0, 62, window_bounds.size.w, 22));
	*text_layer_distance = text_layer_create(GRect(0, 84, window_bounds.size.w, 22));
	text_layer_set_background_color(text_layer_d_title, GColorClear);
	text_layer_set_background_color(*text_layer_distance, GColorClear);
	text_layer_set_text_color(text_layer_d_title, GColorWhite);
	text_layer_set_text_color(*text_layer_distance, GColorLightGray);
	text_layer_set_text_alignment(text_layer_d_title, GTextAlignmentCenter);
	text_layer_set_text_alignment(*text_layer_distance, GTextAlignmentCenter);
	text_layer_set_text(text_layer_d_title, "DISTANCE");
	text_layer_set_font(text_layer_d_title, font_square_m);
	text_layer_set_font(*text_layer_distance, font_square_m);

	text_layer_ts_title = text_layer_create(GRect(0, 115, window_bounds.size.w, 22));
	*text_layer_top_speed = text_layer_create(GRect(0, 137, window_bounds.size.w, 23));
	text_layer_set_background_color(text_layer_ts_title, GColorClear);
	text_layer_set_background_color(*text_layer_top_speed, GColorClear);
	text_layer_set_text_color(text_layer_ts_title, GColorWhite);
	text_layer_set_text_color(*text_layer_top_speed, GColorLightGray);
	text_layer_set_text_alignment(text_layer_ts_title, GTextAlignmentCenter);
	text_layer_set_text_alignment(*text_layer_top_speed, GTextAlignmentCenter);
	text_layer_set_text(text_layer_ts_title, "TOP SPEED");
	text_layer_set_font(text_layer_ts_title, font_square_m);
	text_layer_set_font(*text_layer_top_speed, font_square_m);

	layer_add_child(*details_layer, text_layer_get_layer(text_layer_rt_title));
	layer_add_child(*details_layer, text_layer_get_layer(*text_layer_ride_time));
	layer_add_child(*details_layer, text_layer_get_layer(text_layer_d_title));
	layer_add_child(*details_layer, text_layer_get_layer(*text_layer_distance));
	layer_add_child(*details_layer, text_layer_get_layer(text_layer_ts_title));
	layer_add_child(*details_layer, text_layer_get_layer(*text_layer_top_speed));

}

void destroy_display() {
	text_layer_destroy(text_layer_rt_title);
	text_layer_destroy(text_layer_d_title);
	text_layer_destroy(text_layer_ts_title);
	fonts_unload_custom_font(font_square_s);
	fonts_unload_custom_font(font_square_m);
	fonts_unload_custom_font(font_square_l);
}

#endif
